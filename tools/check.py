#!/usr/bin/env python3
"""check.py — the build's last step (ninja runs it): does the rebuilt executable match?

    python3 tools/check.py --elf build/<SERIAL>.elf --orig orig/<SERIAL>/<SERIAL> \
        --checksum config/<SERIAL>/checksum.sha1 --image build/<SERIAL>.image --ok build/<SERIAL>.ok

Compares the LOADED IMAGE of the two executables: every PT_LOAD segment's file bytes at its
address, over the original's extent (the ELF containers differ in section headers and
.comment, which the console never loads). Writes the rebuilt image to --image, then checks
every line of checksum.sha1 (`<sha1>  <path>`, the sha1sum format: the original executable
and the image), so `sha1sum -c config/<SERIAL>/checksum.sha1` agrees after a build. On a
match writes --ok; otherwise prints the first differing addresses and exits 1.
"""

import argparse
import hashlib
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import dps2build  # noqa: E402


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--elf", required=True)
    ap.add_argument("--orig", required=True)
    ap.add_argument("--checksum", required=True)
    ap.add_argument("--image", required=True)
    ap.add_argument("--ok", required=True)
    a = ap.parse_args()
    res = dps2build.compare_images(a.elf, a.orig)
    olo, ohi, _oimg = dps2build.image(dps2build.load_segments(a.orig))
    built = bytearray(ohi - olo)
    for v, d, _m in dps2build.load_segments(a.elf):
        s = v - olo
        if 0 <= s < len(built):
            d = d[:len(built) - s]
            built[s:s + len(d)] = d
    Path(a.image).parent.mkdir(parents=True, exist_ok=True)
    Path(a.image).write_bytes(bytes(built))
    bad = []
    for ln in Path(a.checksum).read_text(encoding="utf-8").splitlines():
        p = ln.split()
        if len(p) != 2:
            continue
        f = Path(p[1])
        got = hashlib.sha1(f.read_bytes()).hexdigest() if f.is_file() else "missing"
        print(f"{p[1]}: {'OK' if got == p[0] else 'FAILED'}")
        if got != p[0]:
            bad.append(p[1])
    if res["ok"] and not bad:
        Path(a.ok).write_text("ok\n", encoding="utf-8")
        print(f"check: OK — the rebuilt image equals the original's ({res['image_start']}-{res['image_end']})")
        return 0
    print(f"check: FAILED — first difference at {res['first_diff_addr']}, {res['diff_count']} byte(s) differ"
          + (f"; checksum lines failing: {', '.join(bad)}" if bad else ""), file=sys.stderr)
    for r in res["diff_ranges"][:5]:
        print(f"  {r[0]}..{r[1]}", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
