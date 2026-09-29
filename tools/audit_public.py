#!/usr/bin/env python3
"""audit_public.py — nothing from the game may be tracked in this repository.

    python3 tools/audit_public.py                 # audit every file git tracks (exit 1 on a hit)
    python3 tools/audit_public.py --self-test     # plant a game-shaped fixture; the audit MUST fail on it
    python3 tools/audit_public.py --files a b c   # audit these paths (no git)

The workflow `.github/workflows/audit.yml` runs it on every push and pull request, so a
game-derived file arriving through a merged pull request is caught on GitHub and not only
on the maintainer's machine. Four rules, each a line `<rule>  <path>  <why>` on a hit:

  path      a tracked file in a class the repository ignores by name: anything under orig/
            (except orig/<SERIAL>/.gitkeep), asm/, build/, expected/, assets/, nonmatchings/,
            or with an object, executable, disc-image or assembly extension
            (.o .obj .a .elf .exe .dll .so .iso .bin .cue .img .s .S .asm .pyc .lock)
  magic     a tracked file whose first bytes are an executable or archive: ELF (`\\x7fELF` —
            every MIPS object the PS2 compiler writes is one), a Unix archive (`!<arch>`),
            a PE/DOS executable (`MZ`), or an ISO 9660 image (`CD001` at offset 0x8001)
  checksum  a tracked file whose SHA-1 equals a hash recorded in config/<SERIAL>/checksum.sha1
            (the original executable and its loaded image) — the game itself, whatever it is
            called
  size      a tracked file over the ceiling no source file reaches: 1 MiB for src/, include/,
            config/, symbols/, tools/ and the top-level documents; 16 MiB for
            progress/report.json, the generated objdiff report (the largest file in a
            projection today is that report at 1.3 MB; the largest C file is under 100 KB)

Exit 0 when every tracked file passes, 1 on any hit, 2 on usage. `--self-test` writes a
fixture under a temporary directory with one file per rule (an ELF-headed file under orig/,
an assembly file, an oversized text file, a file whose SHA-1 the planted checksum.sha1
records) and a clean fixture (a C file, a header, the .gitkeep); it exits 0 only when the
audit fails on the first and passes on the second.
"""

import argparse
import hashlib
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

IGNORED_DIRS = ("orig/", "asm/", "build/", "expected/", "assets/", "nonmatchings/")
IGNORED_EXT = {".o", ".obj", ".a", ".elf", ".exe", ".dll", ".so", ".iso", ".bin", ".cue", ".img",
               ".s", ".S", ".asm", ".pyc", ".lock"}
GITKEEP_RE = re.compile(r"^orig/[^/]+/\.gitkeep$")
MAGIC = ((b"\x7fELF", 0, "ELF executable or object"), (b"!<arch>\n", 0, "Unix archive"),
         (b"MZ", 0, "PE/DOS executable"), (b"CD001", 0x8001, "ISO 9660 disc image"))
CEILING = 1 << 20
REPORT_CEILING = 16 << 20
REPORT_RE = re.compile(r"^progress/report\.json$")
SHA1_LINE_RE = re.compile(r"^([0-9a-fA-F]{40})\s+\*?(\S.*)$")


def tracked_files(root):
    cp = subprocess.run(["git", "-C", str(root), "ls-files", "-z"], capture_output=True, check=True)
    return [f for f in cp.stdout.decode("utf-8", "replace").split("\0") if f]


def recorded_hashes(root):
    """Every SHA-1 written in config/*/checksum.sha1, with the path it was recorded for."""
    out = {}
    for p in sorted(Path(root).glob("config/*/checksum.sha1")):
        for line in p.read_text(encoding="utf-8", errors="replace").splitlines():
            m = SHA1_LINE_RE.match(line.strip())
            if m:
                out[m.group(1).lower()] = f"{p.relative_to(root)}: {m.group(2)}"
    return out


def head_bytes(path, n):
    with open(path, "rb") as f:
        return f.read(n)


def audit(root, files):
    root = Path(root)
    hashes = recorded_hashes(root)
    hits = []
    for rel in files:
        p = root / rel
        if not p.is_file():
            continue                                   # a deleted or unmerged path; git shows it, the tree does not
        if any(rel.startswith(d) for d in IGNORED_DIRS) and not GITKEEP_RE.match(rel):
            hits.append(("path", rel, f"under {rel.split('/')[0]}/, an ignored folder"))
        elif p.suffix in IGNORED_EXT:
            hits.append(("path", rel, f"{p.suffix} is an ignored class"))
        size = p.stat().st_size
        head = head_bytes(p, 0x8001 + 5)
        for magic, off, what in MAGIC:
            if head[off:off + len(magic)] == magic:
                hits.append(("magic", rel, what))
                break
        if hashes and size:
            h = hashlib.sha1()
            with open(p, "rb") as f:
                for chunk in iter(lambda: f.read(1 << 20), b""):
                    h.update(chunk)
            if h.hexdigest() in hashes:
                hits.append(("checksum", rel, f"SHA-1 recorded in {hashes[h.hexdigest()]}"))
        ceiling = REPORT_CEILING if REPORT_RE.match(rel) else CEILING
        if size > ceiling:
            hits.append(("size", rel, f"{size} bytes, over the {ceiling >> 20} MiB ceiling"))
    return hits


def report(hits, n):
    for rule, rel, why in hits:
        print(f"{rule:<9} {rel}  {why}")
    rules = sorted({r for r, _, _ in hits})
    if hits:
        print(f"audit: {len(hits)} hit(s) in {n} tracked file(s) — rule(s) {', '.join(rules)}. "
              "Nothing from the game is tracked here; remove the file(s) from the change.")
        return 1
    print(f"audit: {n} tracked file(s), no game-derived file")
    return 0


def self_test():
    ok = True
    with tempfile.TemporaryDirectory(prefix="audit-fixture-") as td:
        root = Path(td)
        elf = b"\x7fELF\x01\x01\x01\x00" + b"\x00" * 8 + b"\x02\x00\x08\x00" + bytes(range(256)) * 4
        (root / "orig/SLUS_000.00").mkdir(parents=True)
        (root / "orig/SLUS_000.00/SLUS_000.00").write_bytes(elf)              # path + magic
        (root / "config/SLUS_000.00").mkdir(parents=True)
        (root / "src").mkdir()
        (root / "src/blob.c").write_bytes(elf)                                 # magic + checksum
        (root / "config/SLUS_000.00/checksum.sha1").write_text(
            f"{hashlib.sha1(elf).hexdigest()}  orig/SLUS_000.00/SLUS_000.00\n", encoding="utf-8")
        (root / "asm").mkdir()
        (root / "asm/main.s").write_text("glabel func\n  jr $ra\n  nop\n", encoding="utf-8")   # path
        (root / "include").mkdir()
        (root / "include/huge.h").write_bytes(b"/* */\n" * (CEILING // 6 + 1))               # size
        planted = ["orig/SLUS_000.00/SLUS_000.00", "src/blob.c", "asm/main.s", "include/huge.h",
                   "config/SLUS_000.00/checksum.sha1"]
        hits = audit(root, planted)
        rules = {r for r, _, _ in hits}
        print(f"self-test: planted fixture -> {len(hits)} hit(s), rules {sorted(rules)}")
        if rules != {"path", "magic", "checksum", "size"}:
            print("self-test: FAIL — a rule did not fire on its planted file")
            ok = False
    with tempfile.TemporaryDirectory(prefix="audit-clean-") as td:
        root = Path(td)
        (root / "src").mkdir()
        (root / "src/main.c").write_text("int main(void) { return 0; }\n", encoding="utf-8")
        (root / "include").mkdir()
        (root / "include/common.h").write_text("typedef unsigned char u8;\n", encoding="utf-8")
        (root / "orig/SLUS_000.00").mkdir(parents=True)
        (root / "orig/SLUS_000.00/.gitkeep").write_text("", encoding="utf-8")
        (root / "config/SLUS_000.00").mkdir(parents=True)
        (root / "config/SLUS_000.00/checksum.sha1").write_text("0" * 40 + "  orig/SLUS_000.00/SLUS_000.00\n", encoding="utf-8")
        clean = ["src/main.c", "include/common.h", "orig/SLUS_000.00/.gitkeep", "config/SLUS_000.00/checksum.sha1"]
        hits = audit(root, clean)
        print(f"self-test: clean fixture -> {len(hits)} hit(s)")
        if hits:
            print("self-test: FAIL — the clean fixture was flagged: " + "; ".join(f"{r} {p}" for r, p, _ in hits))
            ok = False
    print("self-test: " + ("PASS — the audit fails on the planted fixture and passes on the clean one" if ok else "FAIL"))
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("--root", default=".", help="repository root (default: the current directory)")
    ap.add_argument("--files", nargs="*", help="audit these paths instead of `git ls-files`")
    ap.add_argument("--self-test", action="store_true", dest="self_test")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    root = Path(a.root).resolve()
    if a.files is not None:
        files = a.files
    else:
        if not (root / ".git").exists():
            print(f"audit: {root} is not a git checkout (pass --files, or run from the repository root)", file=sys.stderr)
            return 2
        files = tracked_files(root)
    return report(audit(root, files), len(files))


if __name__ == "__main__":
    sys.exit(main())
