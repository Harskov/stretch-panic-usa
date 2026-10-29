#!/usr/bin/env python3
"""configure.py — set up the build of this decompilation from the repository alone.

    python3 -m pip install -r requirements.txt     # splat, ninja (once)
    python3 configure.py                           # tools, split, build.ninja, objdiff.json
    ninja                                          # build, then check against the original

Needs Linux x86-64 (WSL2 on Windows works), Python 3.9 or newer, and your own copy of the
game's executable. The README's version table lists every release this source builds; put
yours at orig/<SERIAL>/<SERIAL> (config/<SERIAL>/checksum.sha1 names it). configure.py
configures every supported release it finds there (or the ones --version names), downloads
the pinned tools into tools/ the first time (config/<SERIAL>/build.json lists each URL and
its sha256): wibo, the pinned Metrowerks compiler, the MIPS binutils, and mwccgap when a
source file includes assembly. It then runs splat to split each executable (asm/ for the
main release, asm/<id>/ for another; gitignored: nothing from the game is in this
repository), writes build.ninja, and writes objdiff.json so the objdiff GUI can diff every
matched file against the original code.

`ninja` compiles every matched C file with the pinned compiler and flags, assembles the
rest, links, and checks the result: the rebuilt executable's loaded image must equal the
original's byte for byte (tools/check.py; config/<SERIAL>/checksum.sha1 pins both the input
and the image). The build graph is tools/dps2build.py, the same module the maintainer's
pipeline builds with, so the two cannot disagree.

    python3 configure.py --version ID    configure that release only (repeatable)
    python3 configure.py --no-download   use tools already in tools/
    python3 configure.py --no-split      keep asm/ from the last split (build.ninja only)
    ninja report                         objdiff-cli's progress report, build/report.json
"""

import argparse
import hashlib
import json
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tools"))
import dps2build  # noqa: E402
import download_tool  # noqa: E402


def fail(msg):
    print(f"configure.py: {msg}", file=sys.stderr)
    sys.exit(1)


def configs():
    """[(config dir, build.json)] of every supported release, the primary first."""
    hits = []
    for p in sorted(ROOT.glob("config/*/build.json")):
        b = json.loads(p.read_text(encoding="utf-8"))
        b.setdefault("version", b["serial"])
        b.setdefault("primary", True)
        b.setdefault("asm_root", "asm")
        b.setdefault("build_root", "build")
        hits.append((p.parent, b))
    if not hits:
        fail("no config/<SERIAL>/build.json")
    return sorted(hits, key=lambda h: (not h[1]["primary"], h[1]["version"]))


def checksum_want(cfg_dir, path):
    for ln in (cfg_dir / "checksum.sha1").read_text(encoding="utf-8").splitlines():
        p = ln.split()
        if len(p) == 2 and p[1] == path:
            return p[0]
    return None


def present(cfg_dir, b):
    """The release's executable when it is in orig/ with the pinned sha1, None when absent; a wrong file stops."""
    serial = b["serial"]
    orig = ROOT / "orig" / serial / serial
    if not orig.is_file():
        return None
    want = checksum_want(cfg_dir, f"orig/{serial}/{serial}")
    got = hashlib.sha1(orig.read_bytes()).hexdigest()
    if want and got != want:
        fail(f"{orig.relative_to(ROOT)} has sha1 {got}, not {want}: a release this source does not build (the README lists the ones it does)")
    return orig


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("--version", action="append", help="a release id or serial (repeatable); default every one present in orig/")
    ap.add_argument("--no-download", action="store_true")
    ap.add_argument("--no-split", action="store_true")
    a = ap.parse_args()
    allc = configs()
    chosen = []
    for cfg_dir, b in allc:
        if a.version and b["version"] not in a.version and b["serial"] not in a.version:
            continue
        orig = present(cfg_dir, b)
        if orig is None:
            if a.version:
                fail(f"copy the executable {b['serial']} from your disc to orig/{b['serial']}/{b['serial']} first")
            continue
        chosen.append((cfg_dir, b, orig))
    if not chosen:
        rows = "\n".join(f"  orig/{b['serial']}/{b['serial']}   ({b.get('region') or b['version']})" for _d, b in allc)
        fail("no supported executable in orig/: copy the one from your disc to its folder:\n" + rows)
    b0 = chosen[0][1]
    tools = ROOT / "tools"
    t = download_tool.ensure_all(tools, b0["tools"], b0["compiler"], b0.get("mwccgap"), offline=a.no_download)
    env = f"LD_LIBRARY_PATH={shlex.quote(str(t['binutils_lib']))} " if t.get("binutils_lib") else ""
    cc = (f"{shlex.quote(str(t['wibo']))} {shlex.quote(str(t['mwcc']))} -c {b0['compiler']['flags']} -nostdinc -stderr -i include")
    gap = None
    if t.get("mwccgap"):
        gap = dps2build.mwccgap_command(python=sys.executable, mwccgap=t["mwccgap"], wibo=t["wibo"], mwcc=t["mwcc"],
                                        as_path=t["as"], as_flags=b0["assembler"]["as_flags"], cflags=b0["compiler"]["flags"])
    vsrc = f"{shlex.quote(sys.executable)} tools/dps2build.py vsrc --version $version --asm-root $asmroot $in $out"
    text, units, expected_all = "", [], []
    for i, (cfg_dir, b, orig) in enumerate(chosen):
        serial, basename = b["serial"], b.get("basename", b["serial"])
        broot, aroot = b["build_root"], b["asm_root"]
        if not a.no_split:
            try:
                import splat  # noqa: F401
            except ImportError:
                fail("splat is not installed: python3 -m pip install -r requirements.txt")
            print(f"splat: splitting {serial} into {aroot}/ ...")
            cp = subprocess.run([sys.executable, "-m", "splat", "split", str(cfg_dir / "splat.yaml")], cwd=ROOT)
            if cp.returncode != 0:
                fail(f"splat failed on {serial}")
        ld = ROOT / broot / f"{basename}.ld"
        if not ld.is_file():
            fail(f"{ld.relative_to(ROOT)} missing: run without --no-split")
        dps2build.patch_subalign(ld)
        dps2build.fix_nonmatchings(ROOT, aroot)
        dps2build.fix_jtbl_zero_words(ROOT, aroot)
        ld_text = ld.read_text(encoding="utf-8")
        try:
            for stub in dps2build.missing_bss_stubs(ROOT, (cfg_dir / "splat.yaml").read_text(encoding="utf-8"), ld_text, broot):
                print(f"bss: {stub} written")
        except dps2build.BuildError as e:
            fail(str(e))
        objs = dps2build.objects_from_ld(ld_text)
        ld_scripts = [str(p.relative_to(ROOT)) for p in (cfg_dir / "undefined_syms.txt", cfg_dir / "undefined_funcs_auto.txt",
                                                         cfg_dir / "undefined_syms_auto.txt") if p.is_file()]
        expected = []
        if i == 0:
            # objdiff targets for the first release configured: splat's full disassembly of every C file
            for o in objs:
                src, _cpp = dps2build.source_for_object(ROOT, o, broot)
                if not o.startswith(f"{broot}/src/") or src.endswith(".s"):
                    continue
                name = str(Path(o[len(broot) + len("/src/"):-len(".o")]).with_suffix(""))
                full = ROOT / aroot / f"{name}.s"
                if full.is_file():
                    exp = f"{broot}/expected/{name}.o"
                    expected.append((exp, str(full.relative_to(ROOT))))
                    units.append({"name": name, "target_path": exp, "base_path": o, "metadata": {"source_path": src}})
            expected_all = expected
        check = {"cmd": f"{shlex.quote(sys.executable)} tools/check.py --elf $in --orig {shlex.quote(str(orig.relative_to(ROOT)))} "
                        f"--checksum {shlex.quote(str((cfg_dir / 'checksum.sha1').relative_to(ROOT)))} --image {broot}/{basename}.image --ok $out",
                 "out": f"{broot}/{basename}.ok"}
        try:
            part = dps2build.ninja_text(ROOT, basename, objs, as_path=t["as"], as_flags=b0["assembler"]["as_flags"], ld_path=t["ld"],
                                        cc_prefix=cc, env_prefix=env, ld_scripts=ld_scripts, mwccgap=gap, check=check, expected=expected,
                                        build_root=broot, version=None if b["primary"] else b["version"],
                                        vsrc_cmd=vsrc, rules=(i == 0), asm_root=aroot, primary_version=b["version"] if b["primary"] else None,
                                        header=f"# build.ninja for {', '.join(x[1]['serial'] for x in chosen)}; written by configure.py, do not edit")
        except dps2build.BuildError as e:
            fail(str(e))
        text += part + "\n"
        n_c = sum(1 for o in objs if o.endswith((".c.o", ".cp.o", ".cpp.o", ".cc.o")))
        print(f"{serial}: {len(objs) - n_c} assembly and {n_c} C object(s)")
    if t.get("objdiff") and units:
        deps = " ".join([u["base_path"] for u in units] + [u["target_path"] for u in units])
        text += ("\nrule report\n"
                 f"  command = {shlex.quote(str(t['objdiff']))} report generate -p . -o $out -f json\n"
                 "  description = objdiff report $out\n"
                 f"build build/report.json: report objdiff.json | {deps}\n"
                 "build report: phony build/report.json\n")
    (ROOT / "build.ninja").write_text(text, encoding="utf-8")
    objdiff = {"$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
               "custom_make": "ninja", "build_target": True, "build_base": True,
               "watch_patterns": ["*.c", "*.cp", "*.cpp", "*.cc", "*.h", "*.s"], "units": units}
    (ROOT / "objdiff.json").write_text(json.dumps(objdiff, indent=2) + "\n", encoding="utf-8")
    print(f"build.ninja: {len(chosen)} release(s) ({', '.join(b['serial'] for _d, b, _o in chosen)}); objdiff.json: {len(units)} unit(s)")
    print("next: ninja   (builds, then checks every configured release against its original)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
