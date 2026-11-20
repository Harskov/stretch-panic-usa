#!/usr/bin/env python3
"""lint_rules.py — which matched functions also pass the code rules (AGENTS.md).

    python3 tools/lint_rules.py                  every C/C++ file under src/ and include/
    python3 tools/lint_rules.py --list           also list every function's status
    python3 tools/lint_rules.py --json           the same report as JSON
    python3 tools/lint_rules.py --strict         exit 1 on any MATCH-PENDING function

A function is matched when the pinned compiler rebuilds it to the original's bytes; that is
the build's check (ninja, tools/check.py). This script answers the second question: does the
source that produced those bytes pass the [match] rules? A function whose bytes match but
which breaks one is MATCH-PENDING: reported, and not counted as matched under the rules.

The [match] rows (AGENTS.md has the rules and what this project changes in them):

    R1   one declaration per type     a type name defined in two files with different bodies;
                                      class/struct keyword mismatch; a cast between two structs
                                      one of which repeats the other's leading members; an
                                      element address cast to a second struct (lint_c overlay-cast)
    R2   one declaration per global   an `extern` object declared in a unit instead of a header;
                                      one global declared with two types
    R4   no offset casts              a constant added to a byte-pointer cast and dereferenced
                                      (lint_c byte-offset)
    R13  real vtables                 a virtual named pad/dummy (the binary's vtables are not
                                      in this repository, so the slot count is not checked here)
    R17  no fake code                 a `// !FAKE:` body; `volatile` on a local or parameter, or
                                      on a member or global without a `// volatile: <evidence>`
                                      note; an empty if/else block; a bare `;` statement;
                                      `do { } while (0)` outside a macro; self-assignment;
                                      `+ 0`, `* 1`; a local declared and never used; a padding
                                      member not named for its offset (`pad_<HEX>`)
    R18  no assembly bodies           inline assembly other than the listed forms (below)

Assembly the original itself had is not a violation. tools/lint_c.py classifies it:
a block of VU0 macro-mode, float-to-int or EI/DI instructions inside a C function is a
listed helper (the function is counted, and listed); a whole `asm` function of that form is
ORIGINAL-ASM (listed apart, counted neither as matched nor in the total).

The advisory rows do not block a match: open naming (R7), prototypes declared inside units
and declarations with empty parentheses (R25), functions without a header comment (R33),
braceless bodies and assignments in conditions (R35), `#if 0` (R37), `goto` (R14), `register`
used only to pin an allocation (Section F), and a type defined identically in several units (R1).

Exit status: 0 when every [match] finding sits in a function that discloses it with
`// !FAKE: <what the original probably wrote>`; 1 when an undisclosed one exists, or with
--strict when any MATCH-PENDING function exists; 2 on a usage error.
"""

import argparse
import collections
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import lint_c  # noqa: E402  (the readability lint: its asm classification and offset-cast rules)

SOURCE_SUFFIXES = (".c", ".cp", ".cpp", ".cc")
LISTED_ASM = {"vu0-asm", "fpu-asm", "kernel-asm"}
PLACEHOLDER = re.compile(r"^(?:func|D|unk|pad|sub|FUN|DAT|field|param|local|var)_?[0-9A-Fa-f]+(?:_\d+)?$|"
                         r"^[A-Za-z]+_[0-9A-Fa-f]{6,8}(?:_\d+)?$|^(?:Obj|Sub|Elem|Node|Blk)[0-9A-Fa-f]*$|^m\d+$|^arg\d+$")
BAD_PAD = re.compile(r"^(?:_?pad\d*|_pad\w*|pad[0-9A-Fa-f]+|padding\w*|filler\w*|dummy\w*)$")
GOOD_PAD = re.compile(r"^pad_[0-9A-Fa-f]+$")


def blank_comments(text):
    """The text with comments and string contents blanked, every offset and newline kept."""
    def rep(m):
        s = m.group(0)
        return re.sub(r"[^\n]", " ", s) if s[0] == "/" else s[0] + re.sub(r"[^\n]", " ", s[1:-1]) + s[-1]
    return re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', rep, text, flags=re.S)


def items(code):
    """Top-level items of comment-blanked code as (start, end, kind)."""
    out, i, n = [], 0, len(code)
    while i < n:
        while i < n and code[i].isspace():
            i += 1
        if i >= n:
            break
        st = i
        if code[i] == "#":
            j = code.find("\n", i)
            while j != -1 and code[j - 1] == "\\":
                j = code.find("\n", j + 1)
            j = n if j == -1 else j
            out.append((st, j, "pp"))
            i = j
            continue
        m = re.match(r'extern\s+"[^"\n]*"\s*\{', code[i:])   # the string's contents are blanked
        if m:
            i += m.end()
            continue
        if code[i] == "}":
            i += 1
            continue
        depth, j = 0, i
        while j < n:
            ch = code[j]
            if ch in "{(":
                depth += 1
            elif ch in "})":
                depth -= 1
                if depth == 0 and ch == "}":
                    head = code[i:j].split("{")[0]
                    tail = re.match(r"[^;{}()=]*;", code[j + 1:])
                    is_type = re.match(r"\s*(typedef\b|struct\b|union\b|enum\b|class\b|static\s|extern\b|const\b)", head) and "(" not in head
                    if tail and (is_type or "=" in head):
                        j += tail.end()
                    break
            elif ch == ";" and depth == 0:
                break
            j += 1
        out.append((st, min(j + 1, n), "decl"))
        i = j + 1
    return out


TYPE_HEAD = re.compile(r"(typedef\s+)?(struct|union|enum|class)\s+(\w+)?\s*(?::[^{]*)?\{")


def classify(s):
    """(kind, name, keyword) of one top-level declaration: type, fwd, extern, proto, func, data, asm or other."""
    s1 = " ".join(s.split())
    if s1.startswith(("INCLUDE_ASM", "INCLUDE_RODATA")):
        return "include_asm", (re.search(r",\s*(\w+)\s*\)", s1) or [None, None])[1], None
    m = TYPE_HEAD.match(s1)
    if m and s1.endswith(";"):
        tail = s1[s1.rindex("}") + 1:-1].strip()
        if m.group(1) or not tail:
            return "type", (tail if (m.group(1) and tail) else m.group(3)), m.group(2)
        return "data", None, None
    if s1.endswith(";") and "{" not in s1:
        body = s1[:-1]
        m = re.match(r"(?:typedef\s+)?(struct|union|class)\s+(\w+)(?:\s+(\w+))?$", body)
        if m and (not m.group(3) or m.group(3) == m.group(2)):
            return "fwd", m.group(2), m.group(1)
        if body.startswith("typedef "):
            m = re.search(r"\(\s*\*\s*(\w+)\s*\)", body) or re.search(r"(\w+)\s*(?:\[[^\]]*\])*$", body)
            return "typedef", m.group(1) if m else None, None
        ext = body.startswith("extern ")
        b2 = body[7:] if ext else body
        if "(" in b2 and not re.search(r"\(\s*\*", b2):
            m = re.match(r"(.*?)(\w+)\s*\((.*)\)$", b2)
            if m and "=" not in m.group(1):
                return "proto", m.group(2), None
        m = re.match(r"(.*?)(\w+)\s*((?:\[[^\]]*\])*)(\s*=.*)?$", b2)
        if m:
            return ("extern" if ext else "data"), m.group(2), None
    if s1.endswith("}"):
        head = s1.split("{")[0]
        m = re.search(r"(\w+)\s*\([^()]*(?:\([^()]*\)[^()]*)*\)\s*$", head)
        if m:
            return "func", m.group(1), ("asm" if re.match(r"asm\b", head.strip()) else None)
    return "other", None, None


class File:
    def __init__(self, path, rel):
        self.path, self.rel = path, rel
        self.text = path.read_text(encoding="utf-8", errors="replace")
        self.code = blank_comments(self.text)
        self.is_unit = path.suffix in SOURCE_SUFFIXES
        self.items = []
        for st, en, kind in items(self.code):
            k, name, extra = classify(self.code[st:en]) if kind == "decl" else (kind, None, None)
            self.items.append({"start": st, "end": en, "kind": k, "name": name, "extra": extra,
                               "line": self.text.count("\n", 0, st) + 1, "end_line": self.text.count("\n", 0, en) + 1,
                               "clean": " ".join(self.code[st:en].split())})

    def line_of(self, offset):
        return self.text.count("\n", 0, offset) + 1

    def in_cpp_branch(self, offset):
        """True when the offset sits under an `#ifdef __cplusplus` / `#else` pair (a header written for both languages)."""
        depth = 0
        for m in re.finditer(r"^[ \t]*#[ \t]*(ifdef|ifndef|if|else|elif|endif)\b([^\n]*)", self.code[:offset], re.M):
            kind, cond = m.group(1), m.group(2)
            if kind in ("ifdef", "ifndef", "if"):
                depth = depth + 1 if (depth or "__cplusplus" in cond) else 0
            elif kind == "endif" and depth:
                depth -= 1
        return depth > 0


def members(body):
    """The member declarations of a struct body, normalised, in order."""
    inner = body[body.index("{") + 1:body.rindex("}")]
    return [" ".join(x.split()) for x in inner.split(";") if x.strip() and "(" not in x and ":" not in x.split()[0]]


def collect(repo):
    paths = (sorted(p for p in (repo / "src").rglob("*") if p.suffix in SOURCE_SUFFIXES and p.is_file())
             + sorted((repo / "include").rglob("*.h")))
    return [File(p, p.relative_to(repo).as_posix()) for p in paths]


def lint(repo):
    files = collect(repo)
    findings = []          # {path, line, rule, tier, text, function}
    types = collections.defaultdict(list)       # name -> [(file, item)] with a body
    keywords = collections.defaultdict(set)     # name -> {(keyword, rel, line)}
    externs = collections.defaultdict(list)     # name -> [(file, item)]
    protos = collections.defaultdict(list)
    functions = []                               # {file, item, name, status, rules}

    def add(f, line, rule, tier, text, name=None):
        findings.append({"path": f.rel, "line": line, "rule": rule, "tier": tier, "text": text, "function": name})

    for f in files:
        for it in f.items:
            if it["kind"] == "type" and it["name"]:
                types[it["name"]].append((f, it))
                if it["extra"] in ("struct", "class"):
                    keywords[it["name"]].add((it["extra"], f.rel, it["line"]))
            elif it["kind"] == "fwd" and it["extra"] in ("struct", "class"):
                keywords[it["name"]].add((it["extra"], f.rel, it["line"]))
            elif it["kind"] == "extern":
                externs[it["name"]].append((f, it))
            elif it["kind"] == "proto":
                protos[it["name"]].append((f, it))
            elif it["kind"] == "func":
                functions.append({"file": f, "item": it, "name": it["name"], "rules": set(), "asm": it["extra"] == "asm",
                                  "helpers": set(), "disclosed": False})

    by_file = collections.defaultdict(list)
    for fn in functions:
        by_file[fn["file"].rel].append(fn)

    def function_at(f, line):
        for fn in by_file.get(f.rel, ()):
            if fn["item"]["line"] <= line <= fn["item"]["end_line"]:
                return fn
        return None

    def users(name):
        """The matched functions whose text names an identifier."""
        pat = re.compile(r"\b%s\b" % re.escape(name))
        return [fn for fn in functions if pat.search(fn["file"].code[fn["item"]["start"]:fn["item"]["end"]])]

    def blame(fns, rule):
        for fn in fns:
            fn["rules"].add(rule)

    # R1: one declaration per type
    bad_types = {}
    for name, ds in sorted(types.items()):
        bodies = {}
        for f, it in ds:
            if not f.in_cpp_branch(it["start"]) or len({x[0].rel for x in ds}) > 1:
                bodies.setdefault(it["clean"], (f, it))
        split = {f.rel for f, it in ds}
        if len(bodies) > 1 and len(split) > 1:
            f, it = ds[0]
            where = ", ".join(sorted("%s:%d" % (g.rel, i["line"]) for g, i in ds))
            add(f, it["line"], "R1", "match", "type %s is defined %d different ways: %s" % (name, len(bodies), where))
            bad_types[name] = True
            blame(users(name), "R1")
        elif len(split) > 1:
            f, it = ds[0]
            add(f, it["line"], "R1", "advisory", "type %s is defined identically in %d files: move it to a header (%s)"
                % (name, len(split), ", ".join(sorted(split))))
    for name, ks in sorted(keywords.items()):
        if len({k for k, _r, _l in ks}) > 1:
            k, rel, line = sorted(ks)[0]
            f = next(x for x in files if x.rel == rel)
            add(f, line, "R1", "match", "type %s is declared both `class` and `struct`: %s"
                % (name, ", ".join("%s at %s:%d" % x for x in sorted(ks))))
            blame(users(name), "R1")
    layouts = {name: members(ds[0][1]["clean"]) for name, ds in types.items() if "{" in ds[0][1]["clean"]}
    cast = re.compile(r"\(\s*(?:struct\s+)?(\w+)\s*\*\s*\)\s*(\w+)\b")
    for fn in functions:
        f, it = fn["file"], fn["item"]
        code = f.code[it["start"]:it["end"]]
        declared = dict((m.group(2), m.group(1)) for m in re.finditer(r"\b(\w+)\s*\*\s*(?:volatile\s+|const\s+)?(\w+)\s*[,;)=]", code))
        for m in cast.finditer(code):
            to, var = m.group(1), m.group(2)
            frm = declared.get(var)
            if not frm or frm == to or to not in layouts or frm not in layouts:
                continue
            a, b = layouts[to], layouts[frm]
            k = min(len(a), len(b))
            if k and a[:k] == b[:k]:
                add(f, f.line_of(it["start"] + m.start()), "R1", "match",
                    "%s is read through a cast to %s, which repeats its leading members" % (var, to), fn["name"])
                fn["rules"].add("R1")

    # R2: one declaration per global
    for name, ds in sorted(externs.items()):
        decls = {it["clean"] for _f, it in ds}
        if len(decls) > 1:
            f, it = ds[0]
            add(f, it["line"], "R2", "match", "global %s is declared %d ways: %s" % (name, len(decls), " | ".join(sorted(decls))))
            blame(users(name), "R2")
        for f, it in ds:
            if f.is_unit:
                add(f, it["line"], "R2", "match", "`%s` is declared in a unit: declare it once, in a header" % it["clean"])
                blame([fn for fn in users(name) if fn["file"] is f], "R2")

    # lint_c: offset casts (R4), overlay casts (R1), assembly (R18), disclosed fake bodies, register pins
    for f in files:
        for x in lint_c.lint_file(f.path, f.rel):
            fn = function_at(f, x["line"])
            name = fn["name"] if fn else None
            if x["rule"] == "byte-offset":
                add(f, x["line"], "R4", "match", "an offset from a byte pointer reaches a member: " + x["source"].strip()[:120], name)
                blame([fn] if fn else [], "R4")
            elif x["rule"] == "overlay-cast":
                add(f, x["line"], "R1", "match", "an element address is cast to a second struct: " + x["source"].strip()[:120], name)
                blame([fn] if fn else [], "R1")
            elif x["rule"] == "inline-asm":
                add(f, x["line"], "R18", "match", "inline assembly outside the listed forms: " + x["source"].strip()[:120], name)
                blame([fn] if fn else [], "R18")
            elif x["rule"] in LISTED_ASM and fn:
                fn["helpers"].add(x["rule"])
            elif x["rule"] in ("register-pin", "goto", "assign-in-condition"):
                rule = {"register-pin": "F", "goto": "R14", "assign-in-condition": "R35"}[x["rule"]]
                add(f, x["line"], rule, "advisory", x["rule"] + ": " + x["source"].strip()[:120], name)

    # R13: padded vtables
    for f in files:
        for m in re.finditer(r"\bvirtual\b[^;{]*\b(pad|dummy)\w*\s*\(", f.code):
            add(f, f.line_of(m.start()), "R13", "match", "a virtual named %s is not a slot the original declared" % m.group(1))
            blame([fn for fn in functions if fn["file"] is f], "R13")

    # R17: fake code
    for f in files:
        # the project's own marker: a body kept only because it matches
        for m in re.finditer(r"//\s*!FAKE\b[^\n]*", f.text):
            line = f.line_of(m.start())
            fn = function_at(f, line) or next((x for x in by_file.get(f.rel, ()) if 0 < x["item"]["line"] - line <= 4), None)
            add(f, line, "R17", "match", "disclosed fake body: " + m.group(0)[2:].strip()[:140], fn["name"] if fn else None)
            if fn:
                fn["rules"].add("R17")
                fn["disclosed"] = True
        # volatile on a member or a global needs its evidence
        for it in f.items:
            if it["kind"] in ("type", "extern", "data") and re.search(r"\bvolatile\b", it["clean"]):
                above = "\n".join(f.text[:it["start"]].split("\n")[-7:])     # one note may head a short run of declarations
                rest = f.text[it["end"]:].split("\n")[0]
                if not re.search(r"(?://|/\*)\s*volatile:", above + rest):
                    add(f, it["line"], "R17", "match", "`volatile` without a `// volatile: <evidence>` note: " + it["clean"][:100])
                    blame(users(it["name"]) if it["name"] else [], "R17")
            if it["kind"] == "type" and "{" in it["clean"]:
                for mm in re.finditer(r"\b(\w+)\s*(?:\[[^\]]*\])*\s*;", it["clean"][it["clean"].index("{"):]):
                    if BAD_PAD.match(mm.group(1)) and not GOOD_PAD.match(mm.group(1)):
                        add(f, it["line"], "R17", "match", "padding member `%s` of %s is not named for its offset (pad_<HEX>)"
                            % (mm.group(1), it["name"]))
                        blame(users(it["name"]) if it["name"] else [], "R17")
    for fn in functions:
        f, it = fn["file"], fn["item"]
        if fn["asm"]:
            continue
        code = f.code[it["start"]:it["end"]]
        brace = code.index("{")
        head, body = code[:brace], code[brace:]
        base = it["start"] + brace

        def hit(off, text, _fn=fn, _f=f, _base=base):
            add(_f, _f.line_of(_base + off), "R17", "match", text, _fn["name"])
            _fn["rules"].add("R17")
        if re.search(r"\bvolatile\b", head):
            add(f, it["line"], "R17", "match", "`volatile` on a parameter of %s" % fn["name"], fn["name"])
            fn["rules"].add("R17")
        for m in re.finditer(r"\bvolatile\b", body):
            before = body[:m.start()].rstrip()
            if before.endswith("("):          # a cast to a hardware address: *(volatile u64 *)0x12000070
                continue
            hit(m.start(), "`volatile` on a local of %s" % fn["name"])
        for m in re.finditer(r"\bif\s*\((?:[^(){};]|\([^(){};]*(?:\([^(){};]*\)[^(){};]*)*\))*\)\s*\{\s*\}|\belse\s*\{\s*\}", body):
            hit(m.start(), "an empty if/else block")
        depth = 0
        prev = ""
        for i, ch in enumerate(body):
            if ch in "([":
                depth += 1
            elif ch in ")]":
                depth -= 1
            if ch == ";" and depth == 0 and prev in (";", "{") and i > 1:
                hit(i, "a bare `;` statement")
            if not ch.isspace():
                prev = ch
        asm_free = re.sub(r"\basm\s*\{[^}]*\}", lambda m: re.sub(r"[^\n]", " ", m.group(0)), body)
        for m in re.finditer(r"\bwhile\s*\(\s*0\s*\)", asm_free):
            hit(m.start(), "`do { } while (0)` outside a macro")
        for m in re.finditer(r"(?<![\w.>\]])((?:\w+)(?:(?:->|\.)\w+|\[\w+\])*)\s*=\s*\1\s*;", asm_free):
            hit(m.start(), "self-assignment `%s`" % " ".join(m.group(0).split()))
        for m in re.finditer(r"[\w)\]]\s*\+\s*0(?![\w.])|[\w)\]]\s*\*\s*1(?![\w.])", asm_free):
            hit(m.start(), "`%s`: an operation that changes nothing" % " ".join(m.group(0).split()))
        for m in re.finditer(r"(?:^|[;{}])\s*(?:register\s+)?(?:const\s+)?(?:unsigned\s+|signed\s+|struct\s+)?\w+[\s\*]+(\w+)\s*;", asm_free):
            name = m.group(1)
            if name in ("return", "break", "continue") or re.match(r"\s*(?:return|goto|else|case)\b", m.group(0).lstrip(";{} \n\t")):
                continue
            if len(re.findall(r"\b%s\b" % re.escape(name), body)) == 1:
                hit(m.start(1), "local `%s` is declared and never used" % name)

    # advisory rows
    counts = collections.Counter()
    for f in files:
        for it in f.items:
            if it["kind"] == "pp" and re.match(r"#\s*if\s+0\b", f.code[it["start"]:it["end"]]):
                add(f, it["line"], "R37", "advisory", "`#if 0`: a block no build compiles is not source")
            if it["kind"] == "proto" and f.is_unit:
                counts["R25 prototypes declared inside a unit"] += 1
                if f.path.suffix == ".c" and re.search(r"\(\s*\)\s*;$", it["clean"]):
                    counts["R25 declarations with empty parentheses (no prototype)"] += 1
    for fn in functions:
        f, it = fn["file"], fn["item"]
        above = f.text[:it["start"]].rstrip()
        if not (above.endswith("*/") or above.split("\n")[-1].lstrip().startswith("//")):
            counts["R33 functions without a header comment"] += 1
        if PLACEHOLDER.match(fn["name"] or ""):
            counts["R7 functions with a placeholder name"] += 1
        code = f.code[it["start"]:it["end"]]
        counts["R35 braceless if/else/loop bodies"] += len(re.findall(r"\b(?:if|while|for)\s*\([^\n]*\)[ \t]*\n(?![ \t]*\{)[ \t]*[^\s{]", code)) \
            + len(re.findall(r"\belse[ \t]*\n(?![ \t]*\{)[ \t]*[^\s{i]", code))
    counts["R7 types with a placeholder name"] = sum(1 for t in types if PLACEHOLDER.match(t))
    counts["R7 globals with a placeholder name"] = len({n for n in externs if PLACEHOLDER.match(n)})

    rows = []
    for fn in functions:
        ok_asm = fn["asm"] and not fn["rules"] - {"R1", "R2"} and "R18" not in fn["rules"]
        status = "ORIGINAL-ASM" if ok_asm else ("MATCH-PENDING" if fn["rules"] else "matched")
        rows.append({"function": fn["name"], "path": fn["file"].rel, "line": fn["item"]["line"], "status": status,
                     "rules": sorted(fn["rules"]), "asm_helpers": sorted(fn["helpers"]), "disclosed": fn["disclosed"]})
    return {"files": len(files), "findings": findings, "functions": rows, "advisory_counts": dict(counts)}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("--repo", default=str(Path(__file__).resolve().parent.parent))
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--list", action="store_true", help="list every function with its status")
    ap.add_argument("--strict", action="store_true", help="exit 1 on any MATCH-PENDING function, disclosed or not")
    a = ap.parse_args()
    repo = Path(a.repo).resolve()
    if not (repo / "src").is_dir():
        print(f"no src/ under {repo}", file=sys.stderr)
        return 2
    r = lint(repo)
    fns = r["functions"]
    asm = [x for x in fns if x["status"] == "ORIGINAL-ASM"]
    pending = [x for x in fns if x["status"] == "MATCH-PENDING"]
    counted = [x for x in fns if x["status"] != "ORIGINAL-ASM"]
    helpers = [x for x in counted if x["asm_helpers"]]
    undisclosed = [x for x in r["findings"] if x["tier"] == "match"
                   and not any(p["function"] == x["function"] and p["path"] == x["path"] and p["disclosed"] for p in pending)]
    r["summary"] = {"bytes_matched": len(counted), "matched_under_the_rules": len(counted) - len(pending),
                    "match_pending": len(pending), "original_asm": len(asm), "with_listed_asm_helpers": len(helpers),
                    "match_findings": sum(1 for x in r["findings"] if x["tier"] == "match"), "undisclosed": len(undisclosed)}
    if a.json:
        print(json.dumps(r, indent=1))
    else:
        for x in r["findings"]:
            where = f" {x['function']}:" if x["function"] else ""
            print(f"{x['path']}:{x['line']}: {x['rule']} [{x['tier']}]{where} {x['text']}")
        if a.list:
            for x in fns:
                extra = (" " + ",".join(x["rules"])) if x["rules"] else ""
                extra += (" (" + ",".join(x["asm_helpers"]) + ")") if x["asm_helpers"] else ""
                print(f"{x['path']}:{x['line']}: {x['function']}: {x['status']}{extra}")
        for x in pending:
            print(f"MATCH-PENDING {x['function']} ({x['path']}:{x['line']}): {', '.join(x['rules'])}"
                  + ("" if x["disclosed"] else "  [not disclosed with // !FAKE:]"))
        for k, v in sorted(r["advisory_counts"].items()):
            print(f"open: {v} {k}")
        s = r["summary"]
        print(f"lint_rules: {r['files']} file(s); bytes matched {s['bytes_matched']}; matched under the rules "
              f"{s['matched_under_the_rules']}; MATCH-PENDING {s['match_pending']}; ORIGINAL-ASM {s['original_asm']} "
              f"(listed apart); {s['with_listed_asm_helpers']} counted function(s) use a listed assembly helper")
    if undisclosed or (a.strict and pending):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
