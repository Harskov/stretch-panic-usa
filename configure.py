#!/usr/bin/env python3
"""configure.py — set up the build of this decompilation from the repository alone.

    python3 -m pip install -r requirements.txt     # splat, ninja (once)
    python3 configure.py                           # tools, split, build.ninja, objdiff.json
    ninja                                          # build, then check against the original

Needs Linux x86-64 (WSL2 on Windows works), Python 3.8 or newer, and your own copy of the
game's executable at orig/<SERIAL>/<SERIAL> (config/<SERIAL>/checksum.sha1 names it).
configure.py downloads the pinned tools into tools/ the first time (config/<SERIAL>/build.json
lists each URL and its sha256): wibo, the pinned Metrowerks compiler, the MIPS binutils, and
mwccgap when a source file includes assembly. It then runs splat to split the executable into
asm/ (gitignored: nothing from the game is in this repository), writes build.ninja, and writes
objdiff.json so the objdiff GUI can diff every matched file against the original code.

`ninja` compiles every matched C file with the pinned compiler and flags, assembles the rest,
links, and checks the result: the rebuilt executable's loaded image must equal the original's
byte for byte (tools/check.py; config/<SERIAL>/checksum.sha1 pins both the input and the
image). The build graph is tools/dps2build.py, the same module the maintainer's pipeline
builds with, so the two cannot disagree.

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


def find_config():
    hits = sorted(ROOT.glob("config/*/build.json"))
    if len(hits) != 1:
        fail(f"expected one config/<SERIAL>/build.json, found {len(hits)}")
    return hits[0].parent, json.loads(hits[0].read_text(encoding="utf-8"))


def verify_original(cfg_dir, serial):
    orig = ROOT / "orig" / serial / serial
    if not orig.is_file():
        fail(f"copy the executable {serial} from your disc to {orig.relative_to(ROOT)} first")
    want = None
    for ln in (cfg_dir / "checksum.sha1").read_text(encoding="utf-8").splitlines():
        p = ln.split()
        if len(p) == 2 and p[1] == f"orig/{serial}/{serial}":
            want = p[0]
    got = hashlib.sha1(orig.read_bytes()).hexdigest()
    if want and got != want:
        fail(f"{orig.relative_to(ROOT)} has sha1 {got}, not {want}: this is another version of the game")
    return orig


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("--no-download", action="store_true")
    ap.add_argument("--no-split", action="store_true")
    a = ap.parse_args()
    cfg_dir, b = find_config()
    serial, basename = b["serial"], b.get("basename", b["serial"])
    orig = verify_original(cfg_dir, serial)
    tools = ROOT / "tools"
    t = download_tool.ensure_all(tools, b["tools"], b["compiler"], b.get("mwccgap"), offline=a.no_download)
    if not a.no_split:
        try:
            import splat  # noqa: F401
        except ImportError:
            fail("splat is not installed: python3 -m pip install -r requirements.txt")
        print("splat: splitting the executable into asm/ ...")
        cp = subprocess.run([sys.executable, "-m", "splat", "split", str(cfg_dir / "splat.yaml")], cwd=ROOT)
        if cp.returncode != 0:
            fail("splat failed")
    ld = ROOT / "build" / f"{basename}.ld"
    if not ld.is_file():
        fail(f"{ld.relative_to(ROOT)} missing: run without --no-split")
    dps2build.patch_subalign(ld)
    dps2build.fix_nonmatchings(ROOT)
    ld_text = ld.read_text(encoding="utf-8")
    yaml_text = (cfg_dir / "splat.yaml").read_text(encoding="utf-8")
    try:
        for stub in dps2build.missing_bss_stubs(ROOT, yaml_text, ld_text):
            print(f"bss: {stub} written")
    except dps2build.BuildError as e:
        fail(str(e))
    objs = dps2build.objects_from_ld(ld_text)
    env = f"LD_LIBRARY_PATH={shlex.quote(str(t['binutils_lib']))} " if t.get("binutils_lib") else ""
    cc = (f"{shlex.quote(str(t['wibo']))} {shlex.quote(str(t['mwcc']))} -c {b['compiler']['flags']} "
          f"-nostdinc -stderr -i include")
    gap = None
    if t.get("mwccgap"):
        gap = dps2build.mwccgap_command(python=sys.executable, mwccgap=t["mwccgap"], wibo=t["wibo"], mwcc=t["mwcc"],
                                        as_path=t["as"], as_flags=b["assembler"]["as_flags"], cflags=b["compiler"]["flags"])
    ld_scripts = [str(p.relative_to(ROOT)) for p in (cfg_dir / "undefined_syms.txt", cfg_dir / "undefined_funcs_auto.txt",
                                                     cfg_dir / "undefined_syms_auto.txt") if p.is_file()]
    # objdiff targets: splat's full disassembly of every C file (make_full_disasm_for_code)
    expected, units = [], []
    for o in objs:
        src, _cpp = dps2build.source_for_object(ROOT, o)
        if not o.startswith("build/src/") or src.endswith(".s"):
            continue
        name = str(Path(o[len("build/src/"):-len(".o")]).with_suffix(""))  # <seg>/<unit> of .c.o or .cpp.o
        full = ROOT / "asm" / f"{name}.s"
        if full.is_file():
            exp = f"build/expected/{name}.o"
            expected.append((exp, str(full.relative_to(ROOT))))
            units.append({"name": name, "target_path": exp, "base_path": o, "metadata": {"source_path": src}})
    check = {"cmd": f"{shlex.quote(sys.executable)} tools/check.py --elf $in --orig {shlex.quote(str(orig.relative_to(ROOT)))} "
                    f"--checksum {shlex.quote(str((cfg_dir / 'checksum.sha1').relative_to(ROOT)))} --image build/{basename}.image --ok $out",
             "out": f"build/{basename}.ok"}
    try:
        text = dps2build.ninja_text(ROOT, basename, objs, as_path=t["as"], as_flags=b["assembler"]["as_flags"], ld_path=t["ld"],
                                    cc_prefix=cc, env_prefix=env, ld_scripts=ld_scripts, mwccgap=gap, check=check,
                                    expected=expected, header=f"# build.ninja for {serial}; written by configure.py, do not edit")
    except dps2build.BuildError as e:
        fail(str(e))
    if t.get("objdiff") and units:
        # `ninja report`: objdiff-cli reads objdiff.json and the built objects of every unit
        deps = " ".join([u["base_path"] for u in units] + [u["target_path"] for u in units])
        text += ("\nrule report\n"
                 f"  command = {shlex.quote(str(t['objdiff']))} report generate -p . -o $out -f json\n"
                 "  description = objdiff report $out\n"
                 f"build build/report.json: report objdiff.json | {deps}\n"
                 "build report: phony build/report.json\n")
    (ROOT / "build.ninja").write_text(text, encoding="utf-8")
    # build_target: objdiff asks ninja for build/expected/<unit>.o (assembled from splat's full
    # disassembly), which the default target does not build
    objdiff = {"$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
               "custom_make": "ninja", "build_target": True, "build_base": True,
               "watch_patterns": ["*.c", "*.cp", "*.h", "*.s"], "units": units}
    (ROOT / "objdiff.json").write_text(json.dumps(objdiff, indent=2) + "\n", encoding="utf-8")
    n_c = sum(1 for o in objs if o.endswith(".c.o"))
    print(f"build.ninja: {len(objs) - n_c} assembly and {n_c} C object(s); objdiff.json: {len(units)} unit(s)")
    print("next: ninja   (builds, then checks the image against the original)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
