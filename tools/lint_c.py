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
Rules (advisory, need an evidence note in the ledger): volatile, goto.

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


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def lint_text(text, path=""):
    findings = []
    for lineno, line in enumerate(strip_comments(text).splitlines(), 1):
        hits = [(rule, sev) for rule, sev, rx in RULES if rx.search(line)]
        if ("reinterpret-lvalue", "error") in hits:  # `*(T *)&x[0]` is one finding, not two
            hits = [h for h in hits if h[0] != "overlay-cast"]
        for rule, sev in hits:
            findings.append({"path": path, "line": lineno, "rule": rule, "severity": sev, "source": line.strip()})
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
