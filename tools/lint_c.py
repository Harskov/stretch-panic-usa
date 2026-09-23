#!/usr/bin/env python3
"""lint_c.py — flag C that matches but is not what a programmer writes (remediation 7).

    lint_c.py --repo R [FILE ...] [--json]

A matching decompilation is judged by two things: the object is byte-identical, and
the C reads as the original could have been written. The first is `ledger.py mark`'s
gate. This script is the check for the second, on the constructs the community
rejects as "fakematching" (a cast of an element address to a second, overlapping
struct; byte arithmetic on a pointer to reach a field; reinterpreting an lvalue
through a pointer cast; inline asm). Default scope: src/**/*.c, src/**/*.cp (C++ —
the extension is what selects CodeWarrior's C++ front end) and include/**/*.h;
FILE arguments narrow it (a wip attempt before `mark`, say).

Rules (error): overlay-cast, byte-offset, reinterpret-lvalue, inline-asm, member-offset
(a struct member named for an offset, `unk_1EC`, that its declaration puts elsewhere;
remediation 19).
Rules (advisory, need an evidence note in the ledger): volatile, goto, vu0-asm, fpu-asm.

The one asm form that is not an error is a VU0 macro-mode block (remediation 10,
stretch-panic-usa run 007 F-2): a CodeWarrior `asm { ... }` block whose every
instruction is a COP2 instruction (`lqc2`, `sqc2`, `cfc2`, `ctc2`, `qmfc2`, `qmtc2`,
the `v*` vector ops). The pinned compiler has no C spelling for those instructions —
the block over `register` pointer locals is the only source form it accepts (K1 §6
item 11) — so such a block is reported as `vu0-asm` (advisory) on its first line.
The second such form is a COP1 float-to-int block (remediation 17, run
2026-09-19-015 F-4): a block whose every instruction is in the conversion set
(`cvt.w.s`, `cvt.s.w`, `trunc.w.s`, `round.w.s`, `ceil.w.s`, `floor.w.s`, and the
`mfc1`/`mtc1` that move the value in and out). The pinned 2.3.3 build compiles every
C spelling of `(int)f` to a `jal` to the `fptosi` helper — seven spellings across
seven flag sets, and C++ too — while the image inlines `0x46000024` at all 31 of its
conversion sites, so the block is the only source form that reaches those bytes under
the pinned build (K1 §6.20). Reported as `fpu-asm` (advisory).
A block with any other instruction inside, a GNU `asm(...)` / `__asm__(...)`
statement, and a CodeWarrior `asm` function are `inline-asm` (error).

Prints `path:line: rule: source line`; exit 0 clean, 1 error findings, 2 usage.
`ledger.py mark` runs the error rules on the C it accepts and records the findings on
the match record (`match.lint`) with a note, so S8 consolidate finds them;
`progress.py` counts matched records that carry findings.
"""

import argparse
import json
import re
import sys
from pathlib import Path

CAST_TYPE = r"\(\s*(?:const\s+)?(?:struct\s+)?[A-Za-z_]\w*\s*\*+\s*\)"
BYTE_TYPE = r"\(\s*(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char)\s*\*\s*\)"

RULES = [
    # ((Ent *)&D_x[i])->f  — an element address re-typed as a different, overlapping struct
    ("overlay-cast", "error", re.compile(CAST_TYPE + r"\s*&\s*[A-Za-z_]\w*\s*\[")),
    # (u8 *)p + 0x1c, (char *)this + 1  — bytes counted from a pointer to reach a field
    ("byte-offset", "error", re.compile(BYTE_TYPE + r"\s*\(?\s*[A-Za-z_][\w>.-]*\s*\)?\s*[+-]\s*(?:0[xX][0-9A-Fa-f]+|\d+|[A-Za-z_]\w*)")),
    # *(int *)&x  — an lvalue read through another type
    ("reinterpret-lvalue", "error", re.compile(r"\*\s*" + CAST_TYPE + r"\s*&\s*[A-Za-z_]")),
    ("inline-asm", "error", re.compile(r"(?<![\w.])(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\(")),
    ("volatile", "advisory", re.compile(r"\bvolatile\b")),
    ("goto", "advisory", re.compile(r"\bgoto\b")),
    # community-alignment rules (remediation 20): the shapes the decomp community names as
    # machine-made C (zeldaret/tww "Avoid Ghidra-isms"; permuter debris)
    ("do-while-zero", "error", re.compile(r"\bwhile\s*\(\s*0\s*\)")),
    ("register-local", "advisory", re.compile(r"^\s*register\b")),
    ("assign-in-condition", "advisory", re.compile(r"\b(?:if|while)\s*\((?:[^()]|\([^()]*\))*?(?<![=!<>+\-*/%&|^])=(?!=)")),
]

# A basic type re-declared in a source file instead of taken from include/types.h
# (remediation 20: 27 matched files carried their own `typedef unsigned char u8;` block).
TYPEDEF_REDECLARE = re.compile(r"^\s*typedef\s+[\w\s]+?\s+(u8|u16|u32|u64|u128|s8|s16|s32|s64|s128|f32|f64)\s*;", re.M)
# A comment that narrates the pipeline instead of the code: run and round ids, knowledge-file
# sections, friction ids, calibration candidates, tool names (remediation 20; the community
# asks that machine output stay out of comments — doldecomp/melee CONTRIBUTING).
PROCESS_COMMENT = re.compile(r"\brun \d{3}\b|\bruns?/|\bK[1-8]\s*§?\s*\d|\bcalibration candidate\b|\bremediation\b"
                             r"|\bF-\d+\b|\bRUN-|\b(?:ledger|match|lint_c|next_step|select_batch)\.py\b|\bpermuter\b|\battempt-\d|\bMatchRunner\b"
                             r"|\bre-?tried\b|\bobjdiff\b|\bscor(?:e|ed) \d", re.I)
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
FUNC_DEF = re.compile(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*(?:\([^()]*\)[^;{}()]*)*\)\s*\{")
EXTERN_FUNC = re.compile(r"^\s*extern\b[^;]*?\b([A-Za-z_]\w*)\s*\(", re.M)
NOT_FUNCS = {"if", "while", "for", "switch", "return", "sizeof", "do", "else"}

# CodeWarrior's block form, `asm { ... }` (the paren form above is GNU's, which the
# pinned mwccps2 does not accept). The block is one finding on its opening line.
ASM_BLOCK = re.compile(r"(?<![\w.])(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\{")
# a CodeWarrior asm function: `asm void f(...)` / `asm int f(...)`
ASM_FUNC = re.compile(r"(?<![\w.])asm\s+[A-Za-z_][\w\s\*]*\b[A-Za-z_]\w*\s*\(")
# COP2 (VU0 macro mode): the vector-unit loads/stores and moves, and every `v*` op
COP2_MNEMONIC = re.compile(r"^(?:lqc2|sqc2|cfc2|ctc2|qmfc2|qmtc2|v[a-z0-9]+(?:\.[xyzw]{1,4})?)$", re.I)
# COP1 float<->int conversion (remediation 17): the conversion itself, plus the moves
# that carry the value between an FPU register and a GPR. `mfc1`/`mtc1` alone are NOT a
# conversion block — COP1_CONV_ONLY is what makes one of these a conversion rather than
# a hand-written register shuffle, which stays `inline-asm` (error).
COP1_CONV_ONLY = re.compile(r"^(?:cvt\.[ws]\.[ws]|trunc\.w\.[sd]|round\.w\.[sd]|ceil\.w\.[sd]|floor\.w\.[sd])$", re.I)
COP1_CONV_MNEMONIC = re.compile(r"^(?:cvt\.[ws]\.[ws]|trunc\.w\.[sd]|round\.w\.[sd]|ceil\.w\.[sd]|floor\.w\.[sd]|mfc1|mtc1)$", re.I)


def asm_blocks(text):
    """(line_no, [mnemonics]) for every `asm { ... }` block in comment-stripped text."""
    out = []
    for m in ASM_BLOCK.finditer(text):
        depth, i = 0, m.end() - 1
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        body = text[m.end():i]
        mnemonics = []
        for stmt in re.split(r"[;\n]", body):
            stmt = stmt.strip()
            if not stmt or stmt.endswith(":"):  # empty, or a label
                continue
            mnemonics.append(stmt.split()[0])
        out.append((text.count("\n", 0, m.start()) + 1, mnemonics))
    return out


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


# --- member-offset (remediation 19, fate run 2026-09-23-016 F-1) --------------------
# A struct member whose name states its offset (`unk_1EC`, `unk1EC`, `pad_1E8`) and whose
# declared position puts it somewhere else is C that tells the reader a wrong layout, and
# it is how a high-scoring wrong layout survives: objdiff scores instruction shape, so a
# member one word off still reads as a near-miss. func_001A04B0's parked runner attempt
# (98.4 after 76 attempts) declared unk1E0, unk1E4, unk1EC, unk1F4 back to back, so
# unk1EC sat at 0x1E8 and unk1F4 at 0x1EC; the same statements over a struct with its
# members at their named offsets matched on the first try. The layout below is
# CodeWarrior's for the EE (K1 §1): natural alignment, 16 for the 128-bit types. A struct
# holding anything it cannot size (an unknown type, a bitfield, a nested anonymous
# aggregate) is skipped whole, so the rule reports only what it can prove.
SCALAR_LAYOUT = {
    "char": 1, "signed char": 1, "unsigned char": 1, "s8": 1, "u8": 1, "bool": 1, "_Bool": 1,
    "short": 2, "unsigned short": 2, "signed short": 2, "s16": 2, "u16": 2,
    "int": 4, "unsigned": 4, "unsigned int": 4, "signed int": 4, "signed": 4, "long": 4,
    "unsigned long": 4, "s32": 4, "u32": 4, "f32": 4, "float": 4, "size_t": 4,
    "long long": 8, "unsigned long long": 8, "s64": 8, "u64": 8, "double": 8, "f64": 8,
    "u128": 16, "s128": 16, "__int128": 16, "unsigned __int128": 16,
}
OFFSET_NAME = re.compile(r"^_?unk_?(?:0x)?([0-9A-Fa-f]+)$")
AGGREGATE = re.compile(r"\b(typedef\s+)?(struct|union)\s*(\w+)?\s*\{")


def _body_end(text, i):
    depth = 0
    while i < len(text):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def _const(expr):
    """An array dimension: a decimal or hex literal, or + - * / of them in parentheses
    (`[0x540 - 0x1F8]`). Anything else (a macro, sizeof) is None: not sized here."""
    if not re.fullmatch(r"[\s0-9A-Fa-fxX()+\-*/]+", expr):
        return None
    try:
        v = eval(re.sub(r"\b0[xX]([0-9A-Fa-f]+)|\b(\d+)\b",
                        lambda m: str(int(m.group(1), 16)) if m.group(1) else m.group(2), expr).replace("/", "//"),
                 {"__builtins__": {}}, {})
    except Exception:
        return None
    return v if isinstance(v, int) and v >= 0 else None


def _dims(s):
    n = 1
    for d in re.findall(r"\[([^\]]*)\]", s):
        v = _const(d.strip())
        if v is None:
            return None
        n *= v
    return n


def struct_layouts(text):
    """{name: (size, align)} for every aggregate in `text` it can size, plus a list of
    (struct name, line, [(member, offset)]) for the structs, in order of appearance."""
    known = dict((k, (v, v)) for k, v in SCALAR_LAYOUT.items())
    for m in re.finditer(r"\btypedef\s+([A-Za-z_][\w ]*?)\s+(\w+)\s*;", text):
        base = " ".join(m.group(1).split())
        if base in known:
            known[m.group(2)] = known[base]
    structs = []
    for m in AGGREGATE.finditer(text):
        end = _body_end(text, m.end() - 1)
        if end < 0:
            continue
        body = text[m.end():end]
        tail = re.match(r"\s*(\w+)?\s*;", text[end + 1:])
        names = [n for n in (m.group(3), tail.group(1) if (tail and m.group(1)) else None) if n]
        if "{" in body or ":" in re.sub(r"::", "", body):
            continue  # nested aggregate or bitfield: not sized here
        members, off, align, ok = [], 0, 1, True
        for decl in body.split(";"):
            decl = " ".join(decl.split())
            if not decl:
                continue
            fp = re.match(r"^[\w\s\*]+\(\s*\*\s*(\w+)\s*\)\s*\(.*\)(\s*\[.*\])?$", decl)
            if fp:
                items = [(fp.group(1), (4, 4), _dims(fp.group(2) or ""))]
            else:
                items = []
                parts = [p.strip() for p in decl.split(",")]
                hm = re.match(r"^(.*[^\w])(\w+)\s*((?:\[[^\]]*\]\s*)*)$", parts[0])
                if not hm:
                    ok = False
                    break
                base_raw = hm.group(1)
                stars0 = base_raw.count("*")
                base = " ".join(w for w in base_raw.replace("*", " ").split() if w not in ("const", "volatile", "struct", "union"))
                decls = [(stars0, hm.group(2), hm.group(3))]
                for p in parts[1:]:
                    pm = re.match(r"^(\**)\s*(\w+)\s*((?:\[[^\]]*\]\s*)*)$", p)
                    if not pm:
                        ok = False
                        break
                    decls.append((len(pm.group(1)), pm.group(2), pm.group(3)))
                for stars, nm, dims in decls:
                    if stars:
                        lay = (4, 4)
                    elif base.startswith("enum "):
                        lay = (4, 4)
                    elif base in known:
                        lay = known[base]
                    else:
                        ok = False
                        break
                    items.append((nm, lay, _dims(dims)))
            if not ok:
                break
            for name, (sz, al), n in items:
                if n is None:
                    ok = False
                    break
                off = (off + al - 1) // al * al
                members.append((name, off))
                off += sz * n
                align = max(align, al)
            if not ok:
                break
        if not ok or not members:
            continue
        if m.group(2) == "union":
            continue  # a union's members all sit at 0: nothing to check, and not sized here
        size = (off + align - 1) // align * align
        for n in names:
            known[n] = (size, align)
            known["struct " + n] = (size, align)
        structs.append((names[-1] if names else "<anonymous>", text.count("\n", 0, m.start()) + 1, members))
    return known, structs


def member_offset_findings(text, path=""):
    out = []
    _, structs = struct_layouts(strip_comments(text))
    for sname, line, members in structs:
        for name, off in members:
            mm = OFFSET_NAME.match(name)
            if mm and int(mm.group(1), 16) != off:
                out.append({"path": path, "line": line, "rule": "member-offset", "severity": "error",
                            "source": f"struct {sname}: {name} is at 0x{off:X}, its name says 0x{int(mm.group(1), 16):X}"})
    return out


def lint_text(text, path=""):
    findings = []
    stripped = strip_comments(text)
    lines = stripped.splitlines()
    for lineno, mnemonics in asm_blocks(stripped):
        src = lines[lineno - 1].strip() if lineno <= len(lines) else "asm {"
        foreign = [x for x in mnemonics if not COP2_MNEMONIC.match(x)]
        foreign_fpu = [x for x in mnemonics if not COP1_CONV_MNEMONIC.match(x)]
        if mnemonics and not foreign:
            findings.append({"path": path, "line": lineno, "rule": "vu0-asm", "severity": "advisory",
                             "source": f"{src}  [{', '.join(mnemonics)}]"})
        elif mnemonics and not foreign_fpu and any(COP1_CONV_ONLY.match(x) for x in mnemonics):
            # a float-to-int conversion block: no C spelling reaches the inline
            # 0x46000024 under the pinned 2.x build (K1 §6.20, remediation 17)
            findings.append({"path": path, "line": lineno, "rule": "fpu-asm", "severity": "advisory",
                             "source": f"{src}  [{', '.join(mnemonics)}]"})
        else:
            findings.append({"path": path, "line": lineno, "rule": "inline-asm", "severity": "error",
                             "source": f"{src}  [not COP2: {', '.join(foreign) or 'empty block'}]"})
    for lineno, line in enumerate(lines, 1):
        if ASM_FUNC.search(line):
            findings.append({"path": path, "line": lineno, "rule": "inline-asm", "severity": "error", "source": line.strip()})
        hits = [(rule, sev) for rule, sev, rx in RULES if rx.search(line)]
        if ("reinterpret-lvalue", "error") in hits:  # `*(T *)&x[0]` is one finding, not two
            hits = [h for h in hits if h[0] != "overlay-cast"]
        for rule, sev in hits:
            findings.append({"path": path, "line": lineno, "rule": rule, "severity": sev, "source": line.strip()})
    if not str(path).endswith("types.h"):
        for m in TYPEDEF_REDECLARE.finditer(stripped):
            findings.append({"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "typedef-redeclare",
                             "severity": "error", "source": f"{m.group(0).strip()}  [use include/types.h]"})
    defined = {m.group(1) for m in FUNC_DEF.finditer(stripped)} - NOT_FUNCS
    for m in EXTERN_FUNC.finditer(stripped):
        if m.group(1) in defined:
            findings.append({"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "self-extern",
                             "severity": "advisory", "source": f"extern declaration of {m.group(1)}, which this file defines"})
    for m in COMMENT.finditer(text):
        pm = PROCESS_COMMENT.search(m.group(0))
        if pm:
            ln = text.count("\n", 0, m.start() + pm.start()) + 1
            findings.append({"path": path, "line": ln, "rule": "process-comment", "severity": "error",
                             "source": " ".join(m.group(0).split())[:100] + "  [a comment says what the code does, not how it was matched]"})
    findings.extend(member_offset_findings(text, path))
    if any(f["rule"] in ("vu0-asm", "fpu-asm", "inline-asm") for f in findings):
        # an asm block's operands are `register` locals by necessity (the VU0 exception,
        # K1 §6 item 11): register-local says nothing new there
        findings = [f for f in findings if f["rule"] != "register-local"]
    findings.sort(key=lambda f: (f["line"], f["rule"]))
    return findings


def lint_file(p, rel=None):
    return lint_text(p.read_text(encoding="utf-8", errors="replace"), rel or str(p))


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--repo", required=True)
    ap.add_argument("files", nargs="*")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    repo = Path(a.repo).resolve()
    if not repo.is_dir():
        print(f"no such repo: {repo}", file=sys.stderr)
        return 2
    if a.files:
        paths = [Path(f) if Path(f).is_absolute() else repo / f for f in a.files]
    else:
        paths = (sorted((repo / "src").rglob("*.c")) + sorted((repo / "src").rglob("*.cp"))
                 + sorted((repo / "include").rglob("*.h")))
    findings = []
    for p in paths:
        if not p.is_file():
            print(f"not a file: {p}", file=sys.stderr)
            return 2
        rel = str(p.relative_to(repo)) if p.is_relative_to(repo) else str(p)
        findings.extend(lint_file(p, rel))
    errors = [f for f in findings if f["severity"] == "error"]
    if a.json:
        print(json.dumps({"files": len(paths), "findings": findings, "errors": len(errors)}, indent=1))
    else:
        for f in findings:
            print(f"{f['path']}:{f['line']}: {f['rule']}{'' if f['severity'] == 'error' else ' (advisory)'}: {f['source']}")
        print(f"lint_c: {len(paths)} file(s), {len(errors)} error finding(s), {len(findings) - len(errors)} advisory")
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
