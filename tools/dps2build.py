#!/usr/bin/env python3
"""dps2build.py — the build graph of this decompilation: how splat's linker script becomes
build.ninja, and how the rebuilt executable is checked against the original. It is ONE
module shared by the public repository's configure.py and the maintainer's pipeline (the
PS2 pack's build verb imports it from its public template), so the build a contributor runs
and the build every change is verified with cannot drift apart. Standard library only.

One source tree builds every supported version of the game. The primary version splits
into asm/ and builds into build/; a sibling version (another region or revision) splits
into asm/<id>/ and builds into build/<id>/, its symbols named after the primary's
(config/<SERIAL>/symbol_addrs.txt maps each to the sibling's address). Before a sibling
compiles a C file, `vsrc` writes the file as that version sees it: its INCLUDE_ASM paths
pointed at asm/<id>/, and every `#if`/`#ifdef` on a VERSION_<ID> macro resolved, because
mwccgap reads INCLUDE_ASM lines as text and would otherwise take the other version's
assembly too.

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


def source_for_object(root, obj, build_root="build"):
    """(source path, is_cpp) for <build_root>/<path>.o: a `.c` object whose `.c` is absent but whose
    `.cp`/`.cpp`/`.cc` exists is C++."""
    src = obj[len(build_root) + 1:-2]
    if src.endswith(".c") and not (Path(root) / src).is_file():
        for suf in CPP_SUFFIXES:
            alt = src[:-2] + suf
            if (Path(root) / alt).is_file():
                return alt, True
    # a C++ translation unit is src/<seg>/<unit>.cpp, splat's `cpp` segment (round 23, WP2)
    return src, Path(src).suffix.lower() in CPP_SUFFIXES


def missing_bss_stubs(root, yaml_text, ld_text, build_root="build"):
    """Write the `.s` splat did not for a bss subsegment; returns the paths written. Raises
    BuildError when several are missing and their sizes cannot be told apart."""
    root = Path(root)
    missing = [o for o in objects_from_ld(ld_text) if o.endswith(".bss.s.o") and not (root / o[len(build_root) + 1:-2]).is_file()]
    if not missing:
        return []
    sizes, subs = BSS_SIZE_RE.findall(yaml_text), BSS_SUB_RE.findall(yaml_text)
    if len(missing) != 1 or len(sizes) != 1 or len(subs) != 1:
        raise BuildError(f"{len(missing)} bss subsegment file(s) missing after splat "
                         f"({', '.join(o[len('build/'):-2] for o in missing)}) but the YAML has {len(subs)} bss "
                         f"subsegment(s) and {len(sizes)} bss_size: the size of each reservation is ambiguous")
    src = root / missing[0][len(build_root) + 1:-2]
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


INCLUDE_FILE_RE = re.compile(r'^\s*INCLUDE_(?:ASM|RODATA)\s*\(\s*"([^"]+)"\s*,\s*([A-Za-z_]\w*)\s*\)', re.M)
LOCAL_INCLUDE_RE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


def local_headers(root, src, include_dirs=("include",)):
    """Every local header a C source includes (`#include "..."`), resolved against its own folder and then include/,
    followed through the headers it includes: repo-relative paths, sorted. An object depends on them: a header edit changes
    every unit that includes it."""
    root = Path(root)
    base_root = root.resolve()
    seen, todo = set(), [root / src]
    while todo:
        p = todo.pop()
        try:
            text = p.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        for inc in LOCAL_INCLUDE_RE.findall(text):
            for base in (p.parent, *(root / d for d in include_dirs)):
                q = (base / inc).resolve()
                if q.is_file():
                    try:
                        rel = q.relative_to(base_root).as_posix()
                    except ValueError:
                        break
                    if rel not in seen:
                        seen.add(rel)
                        todo.append(q)
                    break
    return sorted(seen)


def asm_stamp(root, src, stamp, asm_root="asm"):
    """The stamp (repo-relative) of the .s files a source's INCLUDE_ASM / INCLUDE_RODATA lines name (pointed at `asm_root`
    for a sibling release): their sha256s, written only when one changed; None for a source that names none. splat rewrites
    every .s at each split, so a file's own time says nothing, and an object listing them would be rebuilt at every build;
    the stamp moves only when an included function's assembly did. A callee's rename changes its callers' `jal`, and the
    object compiled before it still called the old name at the link (fate run 2026-10-16-032 F-3)."""
    root = Path(root)
    text = (root / src).read_text(encoding="utf-8", errors="replace")
    rows = []
    for folder, name in INCLUDE_FILE_RE.findall(text):
        if asm_root != "asm" and folder.startswith("asm/"):
            folder = asm_root + folder[3:]
        f = root / folder / f"{name}.s"
        rows.append(f"{hashlib.sha256(f.read_bytes()).hexdigest() if f.is_file() else 'missing'}  {folder}/{name}.s")
    if not rows:
        return None
    body = "\n".join(rows) + "\n"
    sp = root / stamp
    if not sp.is_file() or sp.read_text(encoding="utf-8") != body:
        sp.parent.mkdir(parents=True, exist_ok=True)
        sp.write_text(body, encoding="utf-8")
    return stamp


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


def fix_nonmatchings(root, asm_root="asm"):
    """splat writes the INCLUDE_ASM sources of C segments (asm/nonmatchings/) with rabbitizer's
    GNU mode off, so a VU0 macro instruction's accumulator operand reads `ACC`, which GNU as
    rejects ("invalid operands `vopmula.xyz ACC,$vf1,$vf2'"); the asm segments carry `$ACC`
    (round 23 WP2, 08-wp2-migrate-stretch-panic-usa.txt). Rewritten after every split;
    idempotent. Returns the number of files changed."""
    n = 0
    d = Path(root) / asm_root / "nonmatchings"
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
    WP2, 07-wp2-unit-experiment.txt: "unrecognized option '-EL -no-pad-sections -G0'").

    The command closes its stdin: mwccgap reads the source from a stdin that is not a terminal,
    which hangs a compile on an open pipe or, fed data, takes $in for the output file."""
    q = shlex.quote
    extra = [f for f in shlex.split(as_flags) if not f.startswith(("-march=", "-mabi="))]
    return (f"{q(str(python))} {q(str(mwccgap))} --use-wibo --wibo-path={q(str(wibo))} --mwcc-path={q(str(mwcc))} "
            f"--as-path={q(str(as_path))} --as-march=r5900 --as-mabi=eabi --as-flags {' '.join(q(f) for f in extra)} "
            f"--macro-inc-path=include/macro.inc $in $out {cflags} -nostdinc -stderr -i include < /dev/null")


VERSION_IF = re.compile(r"^\s*#\s*(if|ifdef|ifndef|elif|else|endif)\b(.*)$")
VERSION_COND = re.compile(r"^(?:defined\s*\(?\s*VERSION_([A-Z0-9_]+)\s*\)?|VERSION_([A-Z0-9_]+))$")


def _version_truth(kind, cond, vid):
    """True/False for a condition on VERSION_<ID> macros alone (`#ifdef VERSION_EU`, `#if VERSION_EU || VERSION_JP`,
    `#if !defined(VERSION_US)`), None for any other condition (left to the compiler)."""
    want = vid.upper()
    # a trailing comment is not part of the condition (`#if VERSION_EU /* Freak Out */`; remediation 2026-10-17-remediation-34,
    # ps2-pack-8: it was left to a compiler that has no VERSION_ macro defined)
    cond = re.sub(r"/\*.*?\*/", " ", re.sub(r"//.*$", "", cond)).strip()
    if kind in ("ifdef", "ifndef"):
        m = re.fullmatch(r"\s*VERSION_([A-Z0-9_]+)\s*", cond)
        if not m:
            return None
        hit = m.group(1) == want
        return hit if kind == "ifdef" else not hit
    terms = [x.strip() for x in re.split(r"\|\|", cond.strip())]
    vals = []
    for term in terms:
        neg = term.startswith("!")
        term = term.lstrip("!").strip().strip("()").strip()
        m = VERSION_COND.fullmatch(term)
        if not m:
            return None
        hit = (m.group(1) or m.group(2)) == want
        vals.append(not hit if neg else hit)
    return any(vals)


def version_source(text, vid, asm_root="asm"):
    """A C file as version `vid` sees it: a conditional on VERSION_<ID> macros resolved (the lines of the other branches
    blanked, so line numbers stay), any other preprocessor line kept for the compiler, and the INCLUDE_ASM / INCLUDE_RODATA
    paths under asm/ pointed at `asm_root` (asm/<id> for a sibling)."""
    out, stack = [], []          # stack of [handled: None|bool(any branch taken), active: bool, ours: bool]
    for ln in text.split("\n"):
        m = VERSION_IF.match(ln)
        live = all(f[1] for f in stack)
        if m:
            kind, cond = m.group(1), m.group(2)
            if kind in ("if", "ifdef", "ifndef"):
                truth = _version_truth(kind, cond, vid)
                if truth is None and "VERSION_" in cond:
                    # the compiler defines no VERSION_ macro, so it would take the wrong branch in silence (remediation-34)
                    raise BuildError(f"#{kind} {cond.strip()} mixes a VERSION_ condition with another: write the VERSION_ test as its own #if")
                if truth is None:
                    stack.append([None, True, False])
                    out.append(ln)
                else:
                    stack.append([truth, truth, True])
                    out.append("")
                continue
            if not stack:
                out.append(ln)
                continue
            top = stack[-1]
            if not top[2]:
                if kind == "endif":
                    stack.pop()
                out.append(ln)
                continue
            if kind == "elif":
                truth = _version_truth("if", cond, vid)
                if truth is None:
                    raise BuildError(f"#elif {cond.strip()} mixes a VERSION_ condition with another: write it as its own #if")
                top[1] = (not top[0]) and truth
                top[0] = top[0] or truth
            elif kind == "else":
                top[1] = not top[0]
                top[0] = True
            elif kind == "endif":
                stack.pop()
            out.append("")
            continue
        if not live:
            out.append("")
            continue
        if asm_root != "asm" and ("INCLUDE_ASM" in ln or "INCLUDE_RODATA" in ln):
            ln = re.sub(r'(INCLUDE_(?:ASM|RODATA)\(\s*")asm/', lambda mm: mm.group(1) + asm_root + "/", ln)
        out.append(ln)
    if stack:
        raise BuildError("an #if on a VERSION_ macro is not closed")
    return "\n".join(out)


def ninja_text(root, basename, objs, *, as_path, as_flags, ld_path, cc_prefix, env_prefix="", ld_scripts=(),
               header="", mwccgap=None, check=None, expected=None, build_root="build", version=None, vsrc_cmd=None, rules=True,
               asm_root=None, primary_version=None):
    """build.ninja for one executable (`primary_version`: the primary's release id, for its own VERSION_ conditionals).

    as_path/ld_path    the MIPS assembler and linker; env_prefix goes before both
                       (LD_LIBRARY_PATH for the Debian binutils' libbfd)
    cc_prefix          the compile command up to the source: `<wibo> <mwccps2.exe> -c <flags>
                       -nostdinc -stderr -i include`; empty when no compiler is pinned
    ld_scripts         extra -T files (undefined_syms.txt and splat's two auto lists)
    mwccgap            the command (with $in and $out in place) that compiles a C file
                       carrying INCLUDE_ASM, or None (such a file is then a build error, named)
    check              {"cmd": ..., "out": ...}: a check edge after the link, made the default
    expected           [(object, asm source)] assembled for objdiff only, never linked

    build_root         build/ for the primary, build/<id> for a sibling version
    version, vsrc_cmd  a sibling version: every C file is first written as that version sees it
                       (`vsrc_cmd` with $in, $out, $version and $asmroot: tools/dps2build.py vsrc)
                       under <build_root>/vsrc/, and compiled from there
    asm_root           the sibling's asm folder (asm/<id>)
    rules              False when another version's text already defined the rules (one
                       build.ninja holding several versions)

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
    ldtag = f"ld_{version}" if version else "ld"
    lines = [header or f"# build.ninja for {basename}; do not edit, re-run configure.py"] if rules else [f"# {basename} ({version or 'primary'})"]
    if not rules:
        lines += _version_edges(root, basename, objs, build_root=build_root, version=version, vsrc_cmd=vsrc_cmd, mwccgap=mwccgap,
                                ld_scripts=ld_scripts, check=check, expected=expected, env_prefix=env_prefix, ld_path=ld_path, ldtag=ldtag,
                                asm_root=asm_root, primary_version=primary_version)
        return "\n".join(lines) + "\n"
    lines += [f"asflags = {as_flags}",
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
              f"  command = {env_prefix}{shlex.quote(str(ld_path))} -EL -T $ldscript $ldscripts -Map $ldmap -o $out",
              "  description = ld $out",
              "rule check", "  command = $checkcmd", "  description = check $in"]
    if vsrc_cmd:
        lines += ["rule vsrc", f"  command = {vsrc_cmd}", "  description = vsrc $in"]
    lines.append("")
    lines += _version_edges(root, basename, objs, build_root=build_root, version=version, vsrc_cmd=vsrc_cmd, mwccgap=mwccgap,
                            ld_scripts=ld_scripts, check=check, expected=expected, env_prefix=env_prefix, ld_path=ld_path, ldtag=ldtag,
                            asm_root=asm_root, primary_version=primary_version)
    return "\n".join(lines) + "\n"


def _version_edges(root, basename, objs, *, build_root, version, vsrc_cmd, mwccgap, ld_scripts, check, expected, env_prefix,
                   ld_path, ldtag, asm_root=None, primary_version=None):
    """The build edges of one version: every object, the link, the check, the default target."""
    lines, gap_missing = [], []
    for o in objs:
        src, is_cpp = source_for_object(root, o, build_root)
        if src.endswith(".s"):
            lines.append(f"build {o}: as {src}")
            continue
        gap = uses_include_asm(root / src)
        # implicit inputs: the local headers and, for an INCLUDE_ASM unit, the stamp of the .s files it includes
        deps = local_headers(root, src)
        if gap:
            st = asm_stamp(root, src, f"{build_root}/stamps/{src}.asm", asm_root or (f"asm/{version}" if version else "asm"))
            if st:
                deps.append(st)
        imp = (" | " + " ".join(deps)) if deps else ""
        # the primary resolves its own VERSION_ conditionals too, in a source that has one (`#if VERSION_US` was false in the
        # primary's build: remediation-34, ps2-pack-8); a source without one compiles as it is
        vid = version or (primary_version if primary_version and "VERSION_" in (root / src).read_text(encoding="utf-8", errors="replace") else None)
        if vid and vsrc_cmd:
            vs = f"{build_root}/vsrc/{src}"
            lines += [f"build {vs}: vsrc {src}", f"  version = {vid}", f"  asmroot = {asm_root or ('asm/' + version if version else 'asm')}"]
            src = vs
        if gap:
            if mwccgap:
                lines.append(f"build {o}: {'ccgapp' if is_cpp else 'ccgap'} {src}{imp}")
            else:
                gap_missing.append(src)
                lines.append(f"build {o}: {'ccp' if is_cpp else 'cc'} {src}{imp}")
        elif is_cpp:
            lines.append(f"build {o}: ccp {src}{imp}")
        else:
            lines.append(f"build {o}: cc {src}{imp}")
    if gap_missing:
        raise BuildError(f"{len(gap_missing)} C file(s) carry INCLUDE_ASM but no mwccgap is configured: {', '.join(gap_missing[:4])}")
    ld_extra = list(ld_scripts)
    elf = f"{build_root}/{basename}.elf"
    lines.append(f"build {elf}: ld {' '.join(objs)} | {build_root}/{basename}.ld {' '.join(ld_extra)}")
    lines.append(f"  ldscript = {build_root}/{basename}.ld")
    lines.append(f"  ldmap = {build_root}/{basename}.map")
    lines.append("  ldscripts = " + " ".join(f"-T {p}" for p in ld_extra))
    for obj, src in expected or ():
        lines.append(f"build {obj}: as {src}")
    if expected:
        lines.append(f"build expected{('_' + version) if version else ''}: phony " + " ".join(o for o, _s in expected))
    if check:
        # ninja expands an edge's own variables before $in and $out exist: the edge's paths go in literally
        cmd = check["cmd"].replace("$in", elf).replace("$out", check["out"])
        lines.append(f"build {check['out']}: check {elf}")
        lines.append(f"  checkcmd = {cmd}")
        lines.append(f"default {check['out']}")
    else:
        lines.append(f"default {elf}")
    return lines


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


def main(argv=None):
    """`python3 tools/dps2build.py vsrc --version ID [--asm-root asm/ID] IN OUT`: IN as version ID sees it (ninja runs it)."""
    import argparse
    ap = argparse.ArgumentParser(description="the build graph's command-line helpers")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("vsrc", help="write a C file as one version sees it")
    p.add_argument("--version", required=True)
    p.add_argument("--asm-root")
    p.add_argument("src")
    p.add_argument("out")
    a = ap.parse_args(argv)
    text = Path(a.src).read_text(encoding="utf-8")
    try:
        new = version_source(text, a.version, a.asm_root or f"asm/{a.version}")
    except BuildError as e:
        raise SystemExit(f"{a.src}: {e}")
    Path(a.out).parent.mkdir(parents=True, exist_ok=True)
    if not Path(a.out).is_file() or Path(a.out).read_text(encoding="utf-8") != new:
        Path(a.out).write_text(new, encoding="utf-8")
    return 0


if __name__ == "__main__":
    import sys
    sys.exit(main())
