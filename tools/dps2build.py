#!/usr/bin/env python3
"""dps2build.py — the build graph of this decompilation: how splat's linker script becomes
build.ninja, and how the rebuilt executable is checked against the original. It is ONE
module shared by the public repository's configure.py and the maintainer's pipeline
(.claude/skills/dps2-toolkit/scripts/configure.py imports it from templates/public-repo/tools/), so
the build a contributor runs and the build every change is verified with cannot drift apart
(operator brief 2026-09-28, WP1). Standard library only.

What it knows, each learned the hard way (the maintainer's K1/K2):
  * splat's linker script says SUBALIGN(16); both assemblers' .text carry sh_addralign 16,
    so every input section would be padded to 16 and a function whose size is not a
    multiple of 16 would shift the rest of the image: patch_subalign() rewrites it to 4
  * splat 0.50 lists `<name>.bss.s.o` for a bss subsegment but writes no .s:
    missing_bss_stubs() writes `.section .bss` + `.space <bss_size>`
  * splat names a C subsegment's object `<name>.c.o` whatever the source's extension; a
    `.cp` source is C++ (CodeWarrior picks the front end from the extension) and is built
    with `-Cpp_exceptions off`: source_for_object() resolves it
  * a C file carrying INCLUDE_ASM (a translation unit with functions not yet matched) is
    compiled through mwccgap, which compiles the C with nops in place of each INCLUDE_ASM
    function and transplants the assembled function back (github.com/mkst/mwccgap)
  * the check compares the LOADED IMAGE (every PT_LOAD segment's file bytes at its
    address), not the ELF container, whose section headers and .comment differ
"""

import hashlib
import re
import shlex
import struct
from pathlib import Path

CPP_SUFFIXES = (".cp", ".cpp", ".cc")
CPP_FLAGS = ["-Cpp_exceptions", "off"]
SUBALIGN_RE = re.compile(r"SUBALIGN\((\d+)\)")
BSS_SUB_RE = re.compile(r"^\s*-\s*\[\s*(0x[0-9A-Fa-f]+)\s*,\s*bss\s*,\s*([A-Za-z0-9_./-]+)\s*\]", re.M)
BSS_SIZE_RE = re.compile(r"^\s*bss_size:\s*(0x[0-9A-Fa-f]+)", re.M)
INCLUDE_ASM_RE = re.compile(r"^\s*INCLUDE_ASM\s*\(", re.M)


class BuildError(Exception):
    pass


def patch_subalign(ld_path, value=4):
    """Rewrite SUBALIGN(N) in splat's linker script to SUBALIGN(value); returns the number of
    directives rewritten (0 when already patched)."""
    ld_path = Path(ld_path)
    text = ld_path.read_text(encoding="utf-8")
    new, _n = SUBALIGN_RE.subn(lambda m: f"SUBALIGN({value})" if int(m.group(1)) != value else m.group(0), text)
    changed = sum(1 for m in SUBALIGN_RE.finditer(text) if int(m.group(1)) != value)
    if changed:
        ld_path.write_text(new, encoding="utf-8")
    return changed


def objects_from_ld(ld_text):
    """Every build/<path>.o the linker script mentions."""
    return sorted(set(re.findall(r"(build/[^\s()*]+\.o)\b", ld_text)))


def source_for_object(root, obj):
    """(source path, is_cpp) for build/<path>.o: a `.c` object whose `.c` is absent but whose
    `.cp`/`.cpp`/`.cc` exists is C++."""
    src = obj[len("build/"):-2]
    if src.endswith(".c") and not (Path(root) / src).is_file():
        for suf in CPP_SUFFIXES:
            alt = src[:-2] + suf
            if (Path(root) / alt).is_file():
                return alt, True
    # a C++ translation unit is src/<seg>/<unit>.cpp, splat's `cpp` segment (round 23, WP2)
    return src, Path(src).suffix.lower() in CPP_SUFFIXES


def missing_bss_stubs(root, yaml_text, ld_text):
    """Write the `.s` splat did not for a bss subsegment; returns the paths written. Raises
    BuildError when several are missing and their sizes cannot be told apart."""
    root = Path(root)
    missing = [o for o in objects_from_ld(ld_text) if o.endswith(".bss.s.o") and not (root / o[len("build/"):-2]).is_file()]
    if not missing:
        return []
    sizes, subs = BSS_SIZE_RE.findall(yaml_text), BSS_SUB_RE.findall(yaml_text)
    if len(missing) != 1 or len(sizes) != 1 or len(subs) != 1:
        raise BuildError(f"{len(missing)} bss subsegment file(s) missing after splat "
                         f"({', '.join(o[len('build/'):-2] for o in missing)}) but the YAML has {len(subs)} bss "
                         f"subsegment(s) and {len(sizes)} bss_size: the size of each reservation is ambiguous")
    src = root / missing[0][len("build/"):-2]
    src.parent.mkdir(parents=True, exist_ok=True)
    src.write_text(f".section .bss\n.space {sizes[0]}\n", encoding="utf-8")
    return [str(src.relative_to(root)).replace("\\", "/")]


def uses_include_asm(path):
    try:
        return bool(INCLUDE_ASM_RE.search(Path(path).read_text(encoding="utf-8", errors="replace")))
    except OSError:
        return False


# mwccgap (github.com/mkst/mwccgap, MIT) at the pinned commit 147598b, and the two fixes this
# project applies to it after checkout (v2 jump-table labels, v3 the temporary file) (round 23, WP2, 08-wp2-migrate-fate-unlimited-codes-jp.txt):
# when it copies an included function's .text relocations into the unit's object it keeps each
# relocation symbol's section index from the assembled object, and only .rodata relocations are
# repointed. A global label inside the function -- a `jlabel` that a jump table in another object
# names -- then sits in an unrelated section of the unit, and every branch to it overflows at the
# link ("relocation truncated to fit: R_MIPS_PC16 against `.L00171D50'"). The fix repoints such a
# symbol to the function's own section, as the .rodata path already does.
MWCCGAP_COMMIT = "147598b36b198f267e80adbe04dd5804d070dbb3"
MWCCGAP_PY_SHA256 = "21a5723e16ff68202be24285e4c11bdd5b32f76d0c80a5fc8cca7774cf87392d"  # mwccgap/mwccgap.py at that commit
_GAP_FIX = [
    # the assembled .text by identity: TextSection.from_section does not carry the section name,
    # and mwccgap's section list includes the NULL header, so its position is the ELF index
    ("        asm_functions = assembled_elf.get_functions()\n",
     "        asm_functions = assembled_elf.get_functions()\n"
     "        asm_text_shndx = next((k for k, s in enumerate(assembled_elf.sections) if asm_functions and s is asm_functions[0]), None)  # dps2 fix v2\n"),
    ("                if has_text and i == 0:\n                    force = False\n                else:\n                    force = True\n",
     "                if has_text and i == 0:\n                    force = False\n"
     "                    # dps2 fix v2 (round 23): a global label inside the included function keeps the\n"
     "                    # assembled object's section index otherwise; branches to it overflow at link\n"
     "                    if symbol.bind != 0 and asm_text_shndx is not None and symbol.st_shndx == asm_text_shndx:\n"
     "                        symbol.st_shndx = text_section_index\n"
     "                else:\n                    force = True\n"),
]


# Fix v3 (run 2026-09-28-018-tu-migrate, F-1): step 3 of process_c_file writes its temporary C
# file beside the unit (dir=c_file.parent) and deletes it on close. On the Cowork mount, the
# runtime until 2026-09-30, a delete was refused ("[Errno 1] Operation not permitted"), so every
# INCLUDE_ASM unit failed there; the round-23 experiments ran only in VM scratch. The file goes to the system temp directory, where
# the compiler's own temporary objects already go; every header a unit includes resolves through
# `-i include`, so the directory of the temporary source changes no include lookup.
_GAP_FIX_V3 = [
    ('    with tempfile.NamedTemporaryFile(suffix=".c", dir=c_file.parent) as temp_c_file:\n        temp_c_file.write(',
     '    with tempfile.NamedTemporaryFile(suffix=".c") as temp_c_file:  # dps2 fix v3: not beside the unit (the mount refuses the delete)\n        temp_c_file.write('),
]


def patch_mwccgap(root):
    """Apply the fixes above to a checkout of mwccgap at MWCCGAP_COMMIT: 'patched', or 'already'
    when they are in place. A checkout carrying only fix v2 gets fix v3 on top. BuildError when
    the file is not the pinned one (nothing is written)."""
    p = Path(root) / "mwccgap" / "mwccgap.py"
    t = p.read_text(encoding="utf-8")
    if "dps2 fix v3" in t:
        return "already"
    if "dps2 fix v2" not in t:
        if hashlib.sha256(t.encode("utf-8")).hexdigest() != MWCCGAP_PY_SHA256 or any(t.count(old) != 1 for old, _new in _GAP_FIX):
            raise BuildError(f"{p} is not mwccgap {MWCCGAP_COMMIT[:7]}'s; the jump-table label fix does not apply")
        for old, new in _GAP_FIX:
            t = t.replace(old, new, 1)
    if any(t.count(old) != 1 for old, _new in _GAP_FIX_V3):
        raise BuildError(f"{p} is not mwccgap {MWCCGAP_COMMIT[:7]}'s; the temp-file fix does not apply")
    for old, new in _GAP_FIX_V3:
        t = t.replace(old, new, 1)
    p.write_text(t, encoding="utf-8")
    return "patched"


ACC_OPERAND_RE = re.compile(r"(?<![$\w])ACC(?=\s*(?:,|$))")
# The VU0 special registers Q, I and R are bare in the same sources (`vdiv Q, $vf0w, $vf2x`,
# `vaddq.x $vf1, $vf0, Q`), which GNU as rejects as well; rewritten on VU0 instructions only.
VU_SPECIAL_OPERAND_RE = re.compile(r"(?<![$\w])([QIR])(?=\s*(?:,|$))")
VU_INSN_RE = re.compile(r"\*/\s+v\w")


def _fix_vu_operands(ln):
    ln = ACC_OPERAND_RE.sub("$ACC", ln)
    if VU_INSN_RE.search(ln):
        head, sep, ops = ln.partition("*/")
        ln = head + sep + VU_SPECIAL_OPERAND_RE.sub(r"$\1", ops)
    return ln


def fix_nonmatchings(root):
    """splat writes the INCLUDE_ASM sources of C segments (asm/nonmatchings/) with rabbitizer's
    GNU mode off, so a VU0 macro instruction's accumulator operand reads `ACC`, which GNU as
    rejects ("invalid operands `vopmula.xyz ACC,$vf1,$vf2'"); the asm segments carry `$ACC`
    (round 23 WP2, 08-wp2-migrate-stretch-panic-usa.txt). Rewritten after every split;
    idempotent. Returns the number of files changed."""
    n = 0
    d = Path(root) / "asm" / "nonmatchings"
    for p in sorted(d.rglob("*.s")) if d.is_dir() else []:
        t = p.read_text(encoding="utf-8")
        new = "\n".join(_fix_vu_operands(ln) if "*/" in ln and not ln.lstrip().startswith((".", "glabel", "jlabel", "dlabel")) else ln
                        for ln in t.split("\n"))
        if new != t:
            p.write_text(new, encoding="utf-8")
            n += 1
    return n


def mwccgap_command(*, python, mwccgap, wibo, mwcc, as_path, as_flags, cflags):
    """The ninja command (with $in and $out) that compiles a C file carrying INCLUDE_ASM:
    mwccgap's own options, the source and the object, then the compiler flags it passes on
    (mkst/mwccgap README: `mwccgap input.c output.o [ -O4,p ... ]`, "Any additional
    arguments will be passed through to the MWCC executable").

    mwccgap parses its own options with `~` as the prefix character after rewriting `--` to
    `~~`, and --as-flags takes `nargs="*"`: the assembler flags follow it as separate words
    and another `--` option must come next, or the list runs on into the positionals. One
    quoted `--as-flags='-EL -G0'` reaches the assembler as a single unknown option (round 23
    WP2, 07-wp2-unit-experiment.txt: "unrecognized option '-EL -no-pad-sections -G0'")."""
    q = shlex.quote
    extra = [f for f in shlex.split(as_flags) if not f.startswith(("-march=", "-mabi="))]
    return (f"{q(str(python))} {q(str(mwccgap))} --use-wibo --wibo-path={q(str(wibo))} --mwcc-path={q(str(mwcc))} "
            f"--as-path={q(str(as_path))} --as-march=r5900 --as-mabi=eabi --as-flags {' '.join(q(f) for f in extra)} "
            f"--macro-inc-path=include/macro.inc $in $out {cflags} -nostdinc -stderr -i include")


def ninja_text(root, basename, objs, *, as_path, as_flags, ld_path, cc_prefix, env_prefix="", ld_scripts=(),
               header="", mwccgap=None, check=None, expected=None):
    """build.ninja for one executable.

    as_path/ld_path    the MIPS assembler and linker; env_prefix goes before both
                       (LD_LIBRARY_PATH for the Debian binutils' libbfd)
    cc_prefix          the compile command up to the source: `<wibo> <mwccps2.exe> -c <flags>
                       -nostdinc -stderr -i include`; empty when no compiler is pinned
    ld_scripts         extra -T files (undefined_syms.txt and splat's two auto lists)
    mwccgap            the command (with $in and $out in place) that compiles a C file
                       carrying INCLUDE_ASM, or None (such a file is then a build error, named)
    check              {"cmd": ..., "out": ...}: a check edge after the link, made the default
    expected           [(object, asm source)] assembled for objdiff only, never linked

    Every compiled object is merged with `ld -r` before the link: mwccps2 emits one .text
    section per function, each with sh_addralign 16, and the linker script's SUBALIGN(4)
    (patch_subalign) would pack a multi-function object's sections 4-aligned. `ld -r`
    honours each section's alignment and fills with zeros, so a translation unit enters the
    link as one .text laid out as the compiler meant it (round 23 WP2,
    07-wp2-unit-experiment.txt: a five-function unit 32 bytes short before, byte-identical
    after). A one-function object is unchanged by it.
    """
    root = Path(root)
    no_cc = "echo 'no compiler pinned (run calibrate)'; false"
    merge = f" && {env_prefix}{shlex.quote(str(ld_path))} -EL -r -o $out $out.sections.o"
    lines = [header or f"# build.ninja for {basename}; do not edit, re-run configure.py",
             f"asflags = {as_flags}",
             "rule as",
             f"  command = {env_prefix}{shlex.quote(str(as_path))} $asflags -I include -o $out $in",
             "  description = as $in",
             "rule cc",
             f"  command = {cc_prefix} $in -o $out.sections.o{merge}" if cc_prefix else f"  command = {no_cc}",
             "  description = cc $in",
             # C++ (a .cp source): the same pinned build and flags plus -Cpp_exceptions off, which
             # removes the .exceptix section the original image has no room for and leaves .text
             # byte-identical (K1 §12)
             "rule ccp",
             f"  command = {cc_prefix} " + " ".join(CPP_FLAGS) + f" $in -o $out.sections.o{merge}" if cc_prefix else f"  command = {no_cc}",
             "  description = c++ $in"]
    if mwccgap:
        # the template carries $in and $out where mwccgap wants them: its own options,
        # then the source and the object, then the flags it passes to the compiler
        gap_cmd = mwccgap.replace(" $out ", " $out.sections.o ", 1)
        lines += ["rule ccgap", f"  command = {env_prefix}{gap_cmd}{merge}", "  description = cc (INCLUDE_ASM) $in"]
        # a C++ unit through mwccgap: it hands the compiler a preprocessed `.c`, so the language
        # is forced with -lang c++ (mwccps2 picks the front end from the extension otherwise;
        # round 23 WP2: the pinned 2.3.3 build accepts `-lang c++`, and C++ in a .c fails without it)
        lines += ["rule ccgapp", f"  command = {env_prefix}{gap_cmd} -lang c++ " + " ".join(CPP_FLAGS) + merge,
                  "  description = c++ (INCLUDE_ASM) $in"]
    lines += ["rule ld",
              f"  command = {env_prefix}{shlex.quote(str(ld_path))} -EL -T build/{basename}.ld $ldscripts -Map build/{basename}.map -o $out",
              "  description = ld $out"]
    if check:
        lines += ["rule check", f"  command = {check['cmd']}", "  description = check $in"]
    lines.append("")
    gap_missing = []
    for o in objs:
        src, is_cpp = source_for_object(root, o)
        if src.endswith(".s"):
            lines.append(f"build {o}: as {src}")
        elif uses_include_asm(root / src):
            if mwccgap:
                lines.append(f"build {o}: {'ccgapp' if is_cpp else 'ccgap'} {src}")
            else:
                gap_missing.append(src)
                lines.append(f"build {o}: {'ccp' if is_cpp else 'cc'} {src}")
        elif is_cpp:
            lines.append(f"build {o}: ccp {src}")
        else:
            lines.append(f"build {o}: cc {src}")
    if gap_missing:
        raise BuildError(f"{len(gap_missing)} C file(s) carry INCLUDE_ASM but no mwccgap is configured: {', '.join(gap_missing[:4])}")
    ld_extra = [p for p in ld_scripts]
    elf = f"build/{basename}.elf"
    lines.append(f"build {elf}: ld {' '.join(objs)} | build/{basename}.ld {' '.join(ld_extra)}")
    lines.append("  ldscripts = " + " ".join(f"-T {p}" for p in ld_extra))
    for obj, src in expected or ():
        lines.append(f"build {obj}: as {src}")
    if expected:
        lines.append("build expected: phony " + " ".join(o for o, _s in expected))
    if check:
        lines.append(f"build {check['out']}: check {elf}")
        lines.append(f"default {check['out']}")
    else:
        lines.append(f"default {elf}")
    return "\n".join(lines) + "\n"


# ----------------------------------------------------------------------------- the check

def load_segments(path):
    """[(vaddr, file bytes, memsz)] of every PT_LOAD segment with file data."""
    b = Path(path).read_bytes()
    if b[:4] != b"\x7fELF":
        raise BuildError(f"{path} is not an ELF")
    E = "<" if b[5] == 1 else ">"
    e_phoff, = struct.unpack_from(E + "I", b, 28)
    e_phentsize, e_phnum = struct.unpack_from(E + "HH", b, 42)
    segs = []
    for i in range(e_phnum):
        p_type, p_offset, p_vaddr, _pa, p_filesz, p_memsz, _fl, _al = struct.unpack_from(E + "IIIIIIII", b, e_phoff + i * e_phentsize)
        if p_type == 1 and p_filesz:
            segs.append((p_vaddr, b[p_offset:p_offset + p_filesz], p_memsz))
    return segs


def image(segs):
    lo = min(v for v, _, _ in segs)
    hi = max(v + len(d) for v, d, _ in segs)
    buf = bytearray(hi - lo)
    for v, d, _ in segs:
        buf[v - lo:v - lo + len(d)] = d
    return lo, hi, bytes(buf)


def compare_images(built, original, limit=20):
    """{ok, image_start, image_end, first_diff_addr, diff_count, diff_ranges, rebuilt_extent}:
    the rebuilt image read at the original's addresses over the original's extent."""
    olo, ohi, oimg = image(load_segments(original))
    bsegs = load_segments(built)
    blo, bhi, _b = image(bsegs)
    cmp_b = bytearray(len(oimg))
    for v, d, _ in bsegs:
        s = v - olo
        if s < 0 or s >= len(oimg):
            continue
        d = d[:len(oimg) - s]
        cmp_b[s:s + len(d)] = d
    ranges, count, i, n = [], 0, 0, len(oimg)
    while i < n:
        if oimg[i] != cmp_b[i]:
            j = i
            while j < n and oimg[j] != cmp_b[j]:
                j += 1
            count += j - i
            if len(ranges) < limit:
                ranges.append([f"0x{olo + i:08X}", f"0x{olo + j:08X}"])
            i = j
        else:
            i += 1
    return {"ok": count == 0 and blo == olo and bhi == ohi, "image_start": f"0x{olo:08X}", "image_end": f"0x{ohi:08X}",
            "first_diff_addr": ranges[0][0] if ranges else None, "diff_count": count, "diff_ranges": ranges,
            "rebuilt_extent": [f"0x{blo:08X}", f"0x{bhi:08X}"], "image_sha1": hashlib.sha1(bytes(cmp_b)).hexdigest()}


def image_sha1(path):
    """sha1 of an ELF's loaded image (what checksum.sha1's second line pins)."""
    return hashlib.sha1(image(load_segments(path))[2]).hexdigest()
