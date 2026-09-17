#!/usr/bin/env python3
"""lint_c.py — flag C that matches but is not what a programmer writes (remediation 7).

    lint_c.py --repo R [FILE ...] [--json]

A matching decompilation is judged by two things: the object is byte-identical, and
the C reads as the original could have been written. The first is `ledger.py mark`'s
gate. This script is the check for the second, on the constructs the community
rejects as "fakematching" (a cast of an element address to a second, overlapping
struct; byte arithmetic on a pointer to reach a field; reinterpreting an lvalue
through a pointer cast; inline asm). Default scope: src/**/*.c and include/**/*.h;
FILE arguments narrow it (a wip attempt before `mark`, say).

Rules (error): overlay-cast, byte-offset, reinterpret-lvalue, inline-asm.
Rules (advisory, need an evidence note in the ledger): volatile, goto, vu0-asm.

The one asm form that is not an error is a VU0 macro-mode block (remediation 10,
stretch-panic-usa run 007 F-2): a CodeWarrior `asm { ... }` block whose every
instruction is a COP2 instruction (`lqc2`, `sqc2`, `cfc2`, `ctc2`, `qmfc2`, `qmtc2`,
the `v*` vector ops). The pinned compiler has no C spelling for those instructions —
the block over `register` pointer locals is the only source form it accepts (K1 §6
item 11) — so such a block is reported as `vu0-asm` (advisory) on its first line.
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
]

# CodeWarrior's block form, `asm { ... }` (the paren form above is GNU's, which the
# pinned mwccps2 does not accept). The block is one finding on its opening line.
ASM_BLOCK = re.compile(r"(?<![\w.])(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\{")
# a CodeWarrior asm function: `asm void f(...)` / `asm int f(...)`
ASM_FUNC = re.compile(r"(?<![\w.])asm\s+[A-Za-z_][\w\s\*]*\b[A-Za-z_]\w*\s*\(")
# COP2 (VU0 macro mode): the vector-unit loads/stores and moves, and every `v*` op
COP2_MNEMONIC = re.compile(r"^(?:lqc2|sqc2|cfc2|ctc2|qmfc2|qmtc2|v[a-z0-9]+(?:\.[xyzw]{1,4})?)$", re.I)


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


def lint_text(text, path=""):
    findings = []
    stripped = strip_comments(text)
    lines = stripped.splitlines()
    for lineno, mnemonics in asm_blocks(stripped):
        src = lines[lineno - 1].strip() if lineno <= len(lines) else "asm {"
        foreign = [x for x in mnemonics if not COP2_MNEMONIC.match(x)]
        if mnemonics and not foreign:
            findings.append({"path": path, "line": lineno, "rule": "vu0-asm", "severity": "advisory",
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
        paths = sorted((repo / "src").rglob("*.c")) + sorted((repo / "include").rglob("*.h"))
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
