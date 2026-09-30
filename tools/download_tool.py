#!/usr/bin/env python3
"""download_tool.py — fetch the pinned build tools into tools/ (configure.py calls it).

Every download is checked against the sha256 in config/<SERIAL>/build.json before it is
used. Standard library only: a Debian .deb is an `ar` archive holding data.tar.*, read here
without dpkg.

    wibo       https://github.com/decompals/wibo (runs the Windows compiler on Linux)
    compiler   the pinned Metrowerks CodeWarrior for PS2 build (decompme/compilers releases)
    binutils   the MIPS assembler and linker the project settled on (Debian's
               binutils-mipsel-linux-gnu; its as and ld need their own libbfd, found through
               LD_LIBRARY_PATH)
    mwccgap    https://github.com/mkst/mwccgap at a pinned commit, when a C file includes
               assembly (INCLUDE_ASM)
    objdiff    objdiff-cli (https://github.com/encounter/objdiff), for `ninja report`: the
               progress report of every C file against splat's disassembly of its range
"""

import hashlib
import io
import lzma
import os
import stat
import subprocess
import sys
import tarfile
import urllib.request
from pathlib import Path


def fetch(url, sha256=None, retries=3):
    last = None
    for _ in range(retries):
        try:
            with urllib.request.urlopen(url, timeout=120) as r:
                data = r.read()
            if sha256 and hashlib.sha256(data).hexdigest() != sha256:
                raise RuntimeError(f"{url}: sha256 {hashlib.sha256(data).hexdigest()} is not the pinned {sha256}")
            return data
        except Exception as e:  # retry network errors; a hash mismatch is final
            last = e
            if isinstance(e, RuntimeError):
                break
    raise SystemExit(f"download failed: {url}: {last}")


def ar_members(data):
    """{name: bytes} of a System V / GNU ar archive (a .deb)."""
    if data[:8] != b"!<arch>\n":
        raise SystemExit("not an ar archive")
    out, i = {}, 8
    while i + 60 <= len(data):
        hdr = data[i:i + 60]
        name = hdr[:16].decode().strip().rstrip("/")
        size = int(hdr[48:58].decode().strip())
        out[name] = data[i + 60:i + 60 + size]
        i += 60 + size + (size & 1)
    return out


def extract_tar(blob, dest, name_hint=""):
    mode = "r:xz" if name_hint.endswith(".xz") else ("r:gz" if name_hint.endswith(".gz") else "r:*")
    with tarfile.open(fileobj=io.BytesIO(blob), mode=mode) as tf:
        for m in tf.getmembers():
            p = (dest / m.name).resolve()
            if not str(p).startswith(str(dest.resolve())):
                raise SystemExit(f"refusing to extract {m.name} outside {dest}")
        tf.extractall(dest)


def make_exec(p):
    p.chmod(p.stat().st_mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)


def ensure_all(tools, specs, compiler, mwccgap=None, offline=False):
    """{wibo, mwcc, as, ld, binutils_lib, mwccgap}: absolute paths, downloading what is missing."""
    tools.mkdir(parents=True, exist_ok=True)
    out = {}
    # wibo
    w = tools / "wibo"
    if not w.is_file():
        if offline:
            raise SystemExit("tools/wibo missing (run without --no-download)")
        print(f"download: wibo {specs['wibo'].get('version', '')}")
        w.write_bytes(fetch(specs["wibo"]["url"], specs["wibo"].get("sha256")))
        make_exec(w)
    out["wibo"] = w
    # the compiler
    cdir = tools / "compilers" / compiler["id"]
    exe = next(iter(sorted(cdir.rglob("mwccps2.exe"))), None) if cdir.is_dir() else None
    if exe is None:
        if offline:
            raise SystemExit(f"tools/compilers/{compiler['id']} missing (run without --no-download)")
        print(f"download: compiler {compiler['id']}")
        cdir.mkdir(parents=True, exist_ok=True)
        extract_tar(fetch(compiler["url"], compiler.get("sha256")), cdir, compiler["url"])
        exe = next(iter(sorted(cdir.rglob("mwccps2.exe"))), None)
        if exe is None:
            raise SystemExit(f"no mwccps2.exe in {compiler['url']}")
    out["mwcc"] = exe
    # binutils (.deb)
    bspec = specs["binutils"]
    bdir = tools / "binutils"
    prefix = bspec.get("bin_prefix", "usr/bin/mipsel-linux-gnu-")
    if not (bdir / (prefix + "as")).is_file():
        if offline:
            raise SystemExit("tools/binutils missing (run without --no-download)")
        print(f"download: binutils {bspec.get('version', '')}")
        members = ar_members(fetch(bspec["url"], bspec.get("sha256")))
        data = next((k for k in members if k.startswith("data.tar")), None)
        if data is None:
            raise SystemExit("no data.tar in the binutils package")
        bdir.mkdir(parents=True, exist_ok=True)
        extract_tar(members[data], bdir, data)
    for tool in ("as", "ld", "objcopy"):
        p = bdir / (prefix + tool)
        if p.is_file():
            make_exec(p)
    out["as"], out["ld"] = bdir / (prefix + "as"), bdir / (prefix + "ld")
    out["binutils_lib"] = bdir / bspec.get("lib", "usr/lib/x86_64-linux-gnu")
    # objdiff-cli, for `ninja report`
    ospec = specs.get("objdiff") or {}
    if ospec.get("url"):
        o = tools / "objdiff-cli"
        if not o.is_file():
            if offline:
                raise SystemExit("tools/objdiff-cli missing (run without --no-download)")
            print(f"download: objdiff-cli {ospec.get('version', '')}")
            o.write_bytes(fetch(ospec["url"], ospec.get("sha256")))
            make_exec(o)
        out["objdiff"] = o
    # mwccgap, only when the sources need it
    if mwccgap and uses_include_asm(tools.parent / "src"):
        gdir = tools / "mwccgap"
        if not (gdir / "mwccgap.py").is_file():
            if offline:
                raise SystemExit("tools/mwccgap missing (run without --no-download)")
            print(f"download: mwccgap {mwccgap['commit'][:10]}")
            subprocess.run(["git", "clone", "-q", mwccgap["url"], str(gdir)], check=True)
            subprocess.run(["git", "-C", str(gdir), "checkout", "-q", mwccgap["commit"]], check=True)
        # the two fixes the build applies to mwccgap (dps2build.patch_mwccgap: v2 jump-table labels, v3 the temporary file)
        import dps2build
        try:
            dps2build.patch_mwccgap(gdir)
        except dps2build.BuildError as e:
            raise SystemExit(str(e))
        out["mwccgap"] = gdir / "mwccgap.py"
    return out


def uses_include_asm(src):
    # every C and C++ unit: a C++ translation unit is unit_<ADDR>.cpp
    for p in [q for q in src.rglob("*") if q.suffix in (".c", ".cp", ".cpp", ".cc")] if src.is_dir() else []:
        if "INCLUDE_ASM(" in p.read_text(encoding="utf-8", errors="replace"):
            return True
    return False


if __name__ == "__main__":
    print(__doc__)
    sys.exit(0)
