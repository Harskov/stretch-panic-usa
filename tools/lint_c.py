#!/usr/bin/env python3
"""lint_c.py — flag C that matches but is not what a programmer writes (the PS2 pack's lint verb).

    python3 tools/lint_c.py --repo . [FILE ...] [--json]      (from a target or public repository's root: the contributor copy)
    python3 platforms/ps2-mwcc/scripts/lint_c.py --target <slug> [FILE ...] [--json]   (from the project folder; the pack's verb)

The shared rules every pack implements (platforms/CONTRACT.md): process-comment, trace-leftover (a printf-family call the
function's draft beside it, wip/<fn>/draft.c or m2c.c, does not have), fake-body-unexplained, placeholder-left (TODO, FIXME,
XXX, ??? in a comment; an m2c placeholder identifier M2C_*). Ported from the PS2 project's lint_c.py (remediation 7 and later
rounds there; the K-numbers in its comments are that project's: K1 is this pack's knowledge/primer.md, K9 its cookbook.md).

A matching decompilation is judged by two things: the object is byte-identical, and
the C reads as the original could have been written. The first is `ledger.py mark`'s
gate. This script is the check for the second, on the constructs the community
rejects as "fakematching" (a cast of an element address to a second, overlapping
struct; byte arithmetic on a pointer to reach a field; reinterpreting an lvalue
through a pointer cast; inline asm). Default scope: every C and C++ source under src/
(`.c`, and `.cp`, `.cpp`, `.cc` — the extension is what selects CodeWarrior's C++ front
end; a C++ translation unit is `unit_<ADDR>.cpp`, remediation 30) and include/**/*.h;
FILE arguments narrow it (a wip attempt before `mark`, say).

Rules (error): overlay-cast, byte-offset, reinterpret-lvalue, inline-asm, do-while-zero,
typedef-redeclare, process-comment, fake-body-unexplained, member-offset, register-name (a decompiler's
register or stack temporary kept as a name: temp_v0, var_s0, phi_a1, saved_reg_s0, sp1C; remediation 2026-10-17-remediation-34)
(a struct member named for an offset, `unk_1EC`, that its declaration puts elsewhere;
remediation 19). byte-offset has two spellings: the cast on the expression,
`(u8 *)p + 0x1c`, and the cast on the declaration, `*(s32 *)(p + 0x5D0)` with `p`
declared `char *` / `u8 *` / `void *` in the function or at file scope — m2c's seed for
an argument it cannot type (remediation 30, fate-unlimited-codes-jp run
2026-09-30-024 F-2).
Rules (advisory, need an evidence note in the ledger): volatile, goto, vu0-asm, fpu-asm,
kernel-asm, register-local, assign-in-condition, self-extern, register-pin, fake-body,
extern-redeclare (one data object declared twice in a file, spelled differently; remediation 2026-10-15-remediation-19),
comment-named-field (a comment above a struct says what an offset holds while its member keeps the placeholder;
remediation 2026-10-15-remediation-20). byte-offset's third spelling, the escape: a byte pointer plus or minus a
constant returned, assigned or passed on (`return p + 0x10;`), unless the function subscripts it or steps it.
(the full list with severities is RULES below and lint_text(); remediation 33, audit K33-8).

The one asm form that is not an error is a VU0 macro-mode block (remediation 10,
stretch-panic-usa run 007 F-2): a CodeWarrior `asm { ... }` block whose every
instruction is a COP2 instruction (`lqc2`, `sqc2`, `cfc2`, `ctc2`, `qmfc2`, `qmtc2` —
the four transfers also with the interlock suffix `.ni`/`.i` the assembler prints,
remediation 22 — and the `v*` vector ops). The pinned compiler has no C spelling for
those instructions — the block over `register` locals is the only source form it
accepts (K9 C3) — so such a block is reported as `vu0-asm` (advisory) on its
first line. One COP1 transfer per scalar belongs to that form (remediation 22,
stretch-panic-usa run 018 F-3): `mfc1 <gpr>, <f32>` whose GPR a later `qmtc2 <gpr>,
vfN` in the same block moves into VU0 (the libvu0 scale shape), and its mirror,
`mtc1 <gpr>, <f32>` whose GPR an earlier `qmfc2 <gpr>, vfN` took out of it. An
`mfc1`/`mtc1` whose GPR is no such transfer's operand in the block, or is written again
in between, stays foreign. A `nop`, and `.set noreorder` / `.set reorder` around the
scalar transfer, belong to the block as well (remediation 28, stretch-panic-usa run
2026-09-30-023 F-1: without the directive pair the pinned assembler adds a hazard nop the
target does not have); the block still needs a COP2 instruction. So does the MMI transpose
(remediation 34, stretch-panic-usa run 2026-09-30-029 F-1): a `pextlw`/`pextuw`/`pcpyld`/
`pcpyud` whose result a later `qmtc2` in the block moves into VU0 — directly or through
another of the four — and an `lq` that loads a row one of them reads. The pinned 2.3.3 has
no C spelling for them (`_pextlw` is a `jal`; K1 §6 item 12). Since remediation-32 (fate run
2026-10-17-040 F-2, stretch-panic run 2026-10-17-039 F-2) the block's GPR side belongs to it as well:
the `lw`/`lwu`/`ld` words and the `dsll32`/`or` that pack a vector into a `qmtc2`, the `dsrl32`/MMI
unpack of a `qmfc2` result, the `sw`/`sd`/`sq` of a value on either path (the transposed rows
included), a word copied through one GPR by a load and the store right after it, and `.set noat` /
`.set at`. On fate's 3.0.1 the MMI intrinsics compile, but its target moves the vector through `$at`,
which the compiler never allocates (the C spelling 32.48; the round's `probe/`). An `lq` straight
into a `qmtc2` and any other GPR op stay foreign.
The second such form is a COP1 float-to-int block (remediation 17, run
2026-09-19-015 F-4): a block whose every instruction is in the conversion set
(`cvt.w.s`, `cvt.s.w`, `trunc.w.s`, `round.w.s`, `ceil.w.s`, `floor.w.s`, and the
`mfc1`/`mtc1` that move the value in and out). The pinned 2.3.3 build compiles every
C spelling of `(int)f` to a `jal` to the `fptosi` helper — seven spellings across
seven flag sets, and C++ too — while the image inlines `0x46000024` at all 31 of its
conversion sites, so the block is the only source form that reaches those bytes under
the pinned build (K9 C12). Reported as `fpu-asm` (advisory).
The third form is the EE kernel macro block (remediation 28, fate-unlimited-codes-jp run
2026-09-30-022 F-1): `sync` (`.l`/`.p`), `ei`, `di` and nothing else — the SDK's
ExitHandler() at the end of an interrupt handler, and EI()/DI(). Reported as `kernel-asm`
(advisory).
The one asm FUNCTION that is not an error is the VU0 float return (remediation 33,
stretch-panic-usa run 2026-09-30-027 F-1): `asm f32 f(...) { ... }` whose body is the VU0
form above and ends `jr ra` with the result's `mtc1 g, f0` in the delay slot, paired with an
earlier `qmfc2 g, vfN`. The pinned compiler keeps a block's `mtc1` ahead of the `jr` and puts
a `nop` in the slot, so no block or C spelling reaches those bytes (K1 §6 item 11). Reported as
`vu0-asm` (advisory).
A block with any other instruction inside, a GNU `asm(...)` / `__asm__(...)`
statement, and any other CodeWarrior `asm` function are `inline-asm` (error).

Readability debt at bank time (round 26, WP8; BFM's inversions in this project's terms):
`register-pin` (advisory) — a function whose body keeps a `register` declaration, or an
`asm { }` block of nothing but register-to-register moves and `nop`s, used only to force
the allocation order; reported once per function, on the function's line, with the pinned
lines listed. `fake-body` (advisory) — the `// !FAKE: <why>` marker above or inside a
function whose body is kept only because it matches (the convention, K2 §4b: the reason
after the colon names what a programmer would have written); `fake-body-unexplained`
(error) when the reason is missing. `readability_debt(text)` returns the pinned and the
fake function names; `progress.py` publishes them as `pinned_functions` / `fake_bodies`.
Nothing is unbanked over either: it is a published debt, counted.

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
# every C and C++ source the build compiles (dps2_common.CPP_SUFFIXES; this file ships
# alone as tools/lint_c.py, so it carries its own copy)
SOURCE_SUFFIXES = (".c", ".cp", ".cpp", ".cc")
# byte-offset, the declaration spelling (remediation 30, fate run 2026-09-30-024 F-2): a name
# declared a byte pointer (`char *p`, `u8 *arg0`, `void *q`; not `char **`, not `char *f(`)...
BYTE_DECL = re.compile(r"(?<![\w*])(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char|void)\s*\*\s*"
                       r"(?:const\s+)?([A-Za-z_]\w*)\b(?!\s*\()")
# ...then read as another type at a byte count from it: `(T *)(p + 0x5D0)`, `(T *)(p - n)`
BYTE_PTR_USE = re.compile(r"\(\s*(?:const\s+)?(?:struct\s+)?([A-Za-z_]\w*)\s*\*+\s*\)\s*\(\s*([A-Za-z_]\w*)\s*[+-]\s*"
                          r"(?:0[xX][0-9A-Fa-f]+|\d+|[A-Za-z_]\w*)")
BYTE_CASTS = {"u8", "s8", "char", "void"}  # a cast back to bytes reinterprets nothing

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
    # a decompiler's register or stack temporary kept as a name (m2c's temp_v0, var_s0, phi_a1, saved_reg_s0, sp1C): the
    # readability gate every pack carries (50-readability-gates; K1 §12), which this lint lacked (remediation 2026-10-17-
    # remediation-34, ps2-pack-4: 13 such names stood in accepted stretch-panic and fate source)
    ("register-name", "error", re.compile(r"\b(?:temp|var|phi|saved_reg)_(?:[avtsk][0-9]|at|ra|fp|gp|sp|lo|hi|f[0-9]{1,2})(?:_[0-9]+)?\b"
                                          r"|\bsp[0-9A-F]{2,4}\b")),
]

# the shared rules of the contract the PS2 project's lint did not carry (remediation 2026-10-14-remediation-16, the migration):
# a placeholder a draft or an operator left, and a debug print the function's draft does not have
PLACEHOLDER = re.compile(r"\b(?:TODO|FIXME|XXX)\b|\?\?\?")
M2C_PLACEHOLDER = re.compile(r"\bM2C_[A-Z_]+\b")
TRACE_CALL = re.compile(r"\b(?:printf|scePrintf|sceDevConsPrintf|puts|Kprintf)\s*\(")

# A basic type re-declared in a source file instead of taken from include/types.h
# (remediation 20: 27 matched files carried their own `typedef unsigned char u8;` block).
TYPEDEF_REDECLARE = re.compile(r"^\s*typedef\s+[\w\s]+?\s+(u8|u16|u32|u64|u128|s8|s16|s32|s64|s128|f32|f64)\s*;", re.M)
# A comment that narrates the pipeline instead of the code: run and round ids, knowledge-file
# sections, friction ids, calibration candidates, tool names (remediation 20; the community
# asks that machine output stay out of comments — doldecomp/melee CONTRIBUTING).
# the pipeline in a comment: a run, an attempt, a score, a knowledge file (K1-K9), a script or project file, a tool name
# (remediation 2026-10-16-remediation-24, fate run 2026-10-16-032 F-7: an evidence sentence carried "the pack's synonym" and
# "sce-symbol-scanner data via PS2Recomp" into source; K9 escaped `K[1-8]`). `retried` is not on it: the game's own loops
# retry a load (stretch-panic run 2026-10-16-038 F-1), and the one narration that used it also named its run
PROCESS_COMMENT = re.compile(r"\brun \d{3}\b|\bruns?/|\bwip/|\b\d{4}-\d{2}-\d{2}-\d{3}\b|\bK[1-9]\s*§?\s*\d|\bcalibration candidate\b|\bremediation\b"
                             r"|\bF-\d+\b|\bRUN-|\b[A-Za-z_]\w*\.py\b|\bpermuter\b|\battempt[- ]#?\d|\bMatchRunner\b"
                             r"|\bobjdiff\b|\bscor(?:e|ed)(?: at)?\s*[:=]?\s*\d|\bmatch\w*\s+(?:at\s+)?\d{1,3}(?:\.\d+)?\s?%"
                             r"|\b\d{1,3}(?:\.\d+)?\s?%\s+match|\breference/|\b(?:MANIFEST|pack)\.json\b|\bthe pack'?s\b"
                             r"|\bGhidra\b|\bPS2Recomp\b|\bsce-symbol-scanner\b|\bm2c\b|\bmwccgap\b", re.I)
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
FUNC_DEF = re.compile(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*(?:\([^()]*\)[^;{}()]*)*\)\s*\{")
# `extern` the storage class on a function this file defines — not the C++ linkage
# specification `extern "C"`, which a .cp function needs to keep its symbol unmangled,
# on the definition or on a declaration before it (K1 §12; remediation 22, run 018 F-5).
# `[ \t]*`, not `\s*`: `\s` let the match start on a blank line above and put the
# finding one line early.
EXTERN_FUNC = re.compile(r'^[ \t]*extern\b(?![ \t]*"C(?:\+\+)?")[^;]*?\b([A-Za-z_]\w*)\s*\(', re.M)
EXTERN_DATA = re.compile(r'^[ \t]*extern\b(?![ \t]*"C(?:\+\+)?")([^;(]*?)\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\]\s*)*);', re.M)
NOT_FUNCS = {"if", "while", "for", "switch", "return", "sizeof", "do", "else"}

# CodeWarrior's block form, `asm { ... }` (the paren form above is GNU's, which the
# pinned mwccps2 does not accept). The block is one finding on its opening line.
ASM_BLOCK = re.compile(r"(?<![\w.])(?:__asm__|__asm|asm)\s*(?:volatile\s*)?\{")
# a CodeWarrior asm function: `asm void f(...)` / `asm int f(...)`
ASM_FUNC = re.compile(r"(?<![\w.])asm\s+[A-Za-z_][\w\s\*]*\b[A-Za-z_]\w*\s*\(")
# COP2 (VU0 macro mode): the vector-unit loads/stores and moves, and every `v*` op. The
# four GPR<->VU0 transfers take the interlock suffix the assembler prints (`qmtc2.ni`,
# `ctc2.i`): 153 of stretch-panic-usa's 291 COP2 functions and 16 of fate's 28 carry one
# (remediation 22, run 018 F-2). match.py imports this definition.
COP2_MNEMONIC = re.compile(r"^(?:lqc2|sqc2|(?:cfc2|ctc2|qmfc2|qmtc2)(?:\.n?i)?|v[a-z0-9]+(?:\.[xyzw]{1,4})?)$", re.I)
# the scalar transfer (remediation 22, run 018 F-3): an FPU value reaches a VU0 register
# only through a GPR, so the block carries one COP1 move per scalar, paired with a
# quadword transfer through that GPR
QMTC2 = re.compile(r"^qmtc2(?:\.n?i)?$", re.I)
QMFC2 = re.compile(r"^qmfc2(?:\.n?i)?$", re.I)
GPR_WRITERS = re.compile(r"^(?:mfc1|(?:qmfc2|cfc2)(?:\.n?i)?)$", re.I)
# the four EE MMI ops of the sceVu0 matrix transpose (remediation 34, stretch-panic-usa run
# 2026-09-30-029 F-1): part of a VU0 block only on their way into a qmtc2 (mmi_transfers)
MMI_TRANSPOSE = re.compile(r"^(?:pextlw|pextuw|pcpyld|pcpyud)$", re.I)
# the GPR side of a VU0 block (remediation 2026-10-17-remediation-32: fate run 2026-10-17-040 F-2, stretch-panic run
# 2026-10-17-039 F-2): the words a vector is packed from on its way into a qmtc2 (`lwu` x3, `dsll32`/`or`, `pcpyld`), the
# unpack of a qmfc2 result (`dsrl32`, `pcpyud`) and the stores of a vector's words or rows (vector_stores), and a word copied
# through one GPR (word_copies)
VEC_PACK = re.compile(r"^(?:dsll32|or)$", re.I)
VEC_UNPACK = re.compile(r"^(?:dsrl32|pextlw|pextuw|pcpyld|pcpyud)$", re.I)
WORD_LOAD = re.compile(r"^(?:lw|lwu|ld|lq)$", re.I)
WORD_STORE = re.compile(r"^(?:sw|sd|sq)$", re.I)
LOAD_STORE = {"lw": "sw", "lwu": "sw", "ld": "sd", "lq": "sq"}
# COP1 float<->int conversion (remediation 17): the conversion itself, plus the moves
# that carry the value between an FPU register and a GPR. `mfc1`/`mtc1` alone are NOT a
# conversion block — COP1_CONV_ONLY is what makes one of these a conversion rather than
# a hand-written register shuffle, which stays `inline-asm` (error).
COP1_CONV_ONLY = re.compile(r"^(?:cvt\.[ws]\.[ws]|trunc\.w\.[sd]|round\.w\.[sd]|ceil\.w\.[sd]|floor\.w\.[sd])$", re.I)
COP1_CONV_MNEMONIC = re.compile(r"^(?:cvt\.[ws]\.[ws]|trunc\.w\.[sd]|round\.w\.[sd]|ceil\.w\.[sd]|floor\.w\.[sd]|mfc1|mtc1)$", re.I)
# EE kernel macro instructions (remediation 28, fate-unlimited-codes-jp run 2026-09-30-022 F-1):
# the SDK's ExitHandler() (`sync; ei`) at the end of an INTC handler, and EI()/DI(). No C
# spelling emits them, so a block of nothing else is reported as `kernel-asm` (advisory).
KERNEL_MNEMONIC = re.compile(r"^(?:sync(?:\.[lp])?|ei|di)$", re.I)


def vu0_neutral(mn, ops):
    """A statement a VU0 block may carry besides COP2 instructions and the scalar transfer
    (remediation 28, stretch-panic-usa run 2026-09-30-023 F-1): `nop` (padding the target
    carries, 112 of 112 bytes on func_00121A60 with it) and `.set noreorder` / `.set reorder`,
    which keep the pinned assembler from putting a hazard nop between `mfc1 g, f` and
    `qmtc2 g, vfN` (36 of 36 bytes on func_0012EE90 and func_0012EA50 with the pair scoped), and `.set noat` / `.set at`
    around a block that moves a vector through `$at` (fate's func_00302978, 100 with the pair; remediation-32)."""
    low = mn.lower()
    return low == "nop" or (low == ".set" and ops in (["reorder"], ["noreorder"], ["at"], ["noat"]))


def asm_statements(text):
    """(line_no, [(mnemonic, [operand, ...])]) for every `asm { ... }` block in
    comment-stripped text; operands lower-cased, a leading `$` dropped."""
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
        out.append((text.count("\n", 0, m.start()) + 1, _statements(text[m.end():i])))
    return out


def _statements(body):
    """[(mnemonic, [operand, ...])] for one asm body; operands lower-cased, a leading `$` dropped."""
    stmts = []
    for stmt in re.split(r"[;\n]", body):
        stmt = stmt.strip()
        if not stmt or stmt.endswith(":"):  # empty, or a label
            continue
        parts = stmt.split(None, 1)
        ops = [o.strip().lstrip("$").lower() for o in parts[1].split(",")] if len(parts) > 1 else []
        stmts.append((parts[0], [o for o in ops if o]))
    return stmts


def asm_function_statements(text):
    """(line_no, [(mnemonic, [operand, ...])]) for every CodeWarrior asm function definition,
    `asm f32 f(Vec *a, Vec *b) { ... }`, in comment-stripped text; a prototype has no body and is skipped."""
    out = []
    for m in ASM_FUNC.finditer(text):
        i, depth = m.end(), 1
        while i < len(text) and depth:
            depth += {"(": 1, ")": -1}.get(text[i], 0)
            i += 1
        while i < len(text) and text[i].isspace():
            i += 1
        end = _body_end(text, i) if i < len(text) and text[i] == "{" else -1
        if end >= 0:
            out.append((text.count("\n", 0, m.start()) + 1, _statements(text[i + 1:end])))
    return out


def vu0_float_return(stmts):
    """True for an asm function body that is a VU0 macro-mode sequence returning a float
    (remediation 33, stretch-panic-usa run 2026-09-30-027 F-1): COP2 instructions, scalar
    transfers and neutral statements, ending `jr ra` with the `mtc1 g, f0` in its delay slot
    that moves the result an earlier `qmfc2 g, vfN` took out of VU0. The pinned compiler keeps an
    `asm { }` block's `mtc1` ahead of the `jr` and fills the slot with a `nop` (80.0-84.0 on
    func_0012E970/E950/E920/E870, 100 as the function), so the function form is the only one
    that reaches those bytes (K1 §6 item 11). Any other asm function stays `inline-asm` (error)."""
    body = list(stmts)
    while body and body[-1][0].lower() == ".set":
        body.pop()                                   # a closing `.set reorder`
    if len(body) < 3:
        return False
    (jr, jops), (slot, sops) = body[-2], body[-1]
    if jr.lower() != "jr" or jops not in (["ra"], ["31"]) or slot.lower() != "mtc1" or sops[1:] != ["f0"]:
        return False
    scalar = scalar_transfers(body)
    rest = [(mn, ops) for i, (mn, ops) in enumerate(body[:-2]) if i not in scalar]
    return (len(body) - 1 in scalar and any(COP2_MNEMONIC.match(mn) for mn, _ in rest)
            and all(COP2_MNEMONIC.match(mn) or vu0_neutral(mn, ops) for mn, ops in rest))


def asm_blocks(text):
    """(line_no, [mnemonics]) for every `asm { ... }` block in comment-stripped text."""
    return [(ln, [mn for mn, _ in stmts]) for ln, stmts in asm_statements(text)]


def scalar_transfers(stmts):
    """Indices of the `mfc1`/`mtc1` statements of one asm block that carry a scalar
    between the FPU and VU0 through a GPR (K9 C3; remediation 22, run 018 F-3): an
    `mfc1 g, f` whose `g` a later `qmtc2 g, vfN` moves into VU0, or an `mtc1 g, f` whose
    `g` an earlier `qmfc2 g, vfN` took out of it, with nothing writing `g` in between.
    `stmts` is one block from asm_statements()."""
    paired = set()
    for i, (mn, ops) in enumerate(stmts):
        low = mn.lower()
        if len(ops) != 2 or low not in ("mfc1", "mtc1"):
            continue
        g = ops[0]
        rng, want = (range(i + 1, len(stmts)), QMTC2) if low == "mfc1" else (range(i - 1, -1, -1), QMFC2)
        for j in rng:
            mn2, ops2 = stmts[j]
            if want.match(mn2) and ops2[:1] == [g]:
                paired.add(i)
                break
            if GPR_WRITERS.match(mn2) and ops2[:1] == [g]:
                break  # g is rewritten before the transfer reads it (or after the one that set it)
    return paired


def mmi_transfers(stmts):
    """Indices of the statements of one asm block that transpose rows in GPRs on their way into
    VU0 (remediation 34, stretch-panic-usa run 2026-09-30-029 F-1: func_0012C950 and func_0012C9C0,
    100 as one block, 0.0 with the `_pextlw` intrinsics): a `pextlw`/`pextuw`/`pcpyld`/`pcpyud`
    whose result a later `qmtc2` moves into VU0, directly or through another of the four, and an
    `lq` that loads a row one of them reads. Since remediation-32 the same chain packs a vector from
    words (fate's func_00302978, 100: `lwu` x3, `dsll32`, `or`, `pcpyld`, `qmtc2`): a `dsll32`/`or`
    on the chain and an `lw`/`lwu`/`ld` that loads a word it reads. A load straight into a `qmtc2`
    stays foreign (`lqc2` is the VU0 load). Found backwards from each `qmtc2` operand; a GPR
    written again in between ends its chain. `stmts` is one block from asm_statements()."""
    to_vu0, to_mmi, keep = set(), set(), set()
    for i in range(len(stmts) - 1, -1, -1):
        mn, ops = stmts[i]
        if not ops:
            continue
        g = ops[0]
        if QMTC2.match(mn):
            to_vu0.add(g)
        elif MMI_TRANSPOSE.match(mn) and len(ops) == 3:
            feeds = g in to_vu0 or g in to_mmi
            to_vu0.discard(g)
            to_mmi.discard(g)
            if feeds:
                keep.add(i)
                to_mmi.update(ops[1:])   # after the destination is retired: `pextlw t0, t1, t0` reads t0
        elif VEC_PACK.match(mn) and len(ops) == 3:
            feeds = g in to_vu0 or g in to_mmi
            to_vu0.discard(g)
            to_mmi.discard(g)
            if feeds:
                keep.add(i)
                to_mmi.update(ops[1:2] if mn.lower() == "dsll32" else ops[1:])   # dsll32's third operand is the shift
        elif WORD_LOAD.match(mn) and len(ops) == 2:
            if g in to_mmi:
                keep.add(i)
            to_vu0.discard(g)
            to_mmi.discard(g)
        elif GPR_WRITERS.match(mn):
            to_vu0.discard(g)
            to_mmi.discard(g)
    return keep


def vector_stores(stmts, into=None):
    """Indices of the statements of one asm block that take a vector's words out of VU0 or store a row on its way in
    (remediation-32): the `dsrl32`/MMI unpack of a `qmfc2` result (every register it reads on that path) and an `sw`/`sd`/`sq`
    of a value on it — a `qmfc2` result, an unpacked word, or a transposed row a `qmtc2` also moves (`into`, mmi_transfers):
    fate's func_00302978 (`qmfc2`, `dsrl32`, `pcpyud`, three `sw`) and stretch-panic's func_0012CA90 (the rows of the
    sceVu0InversMatrix transpose stored with `sq`), both 100 as one block. Found forwards; a GPR written again ends its value."""
    into = mmi_transfers(stmts) if into is None else into
    vec, keep = set(), set()
    for i, (mn, ops) in enumerate(stmts):
        if not ops:
            continue
        g = ops[0]
        if WORD_STORE.match(mn) and len(ops) == 2:
            if g in vec:
                keep.add(i)
        elif QMTC2.match(mn) or mn.lower().startswith(("ctc2", "sqc2", "lqc2")):
            continue                                   # reads its GPR (or moves a vf register): writes no GPR
        elif QMFC2.match(mn):
            vec.add(g)
        elif i in into and MMI_TRANSPOSE.match(mn):
            vec.add(g)
        elif VEC_UNPACK.match(mn) and len(ops) == 3 and all(o in vec for o in ops[1:] if not re.fullmatch(r"(?:0x)?[0-9a-f]+", o)):
            keep.add(i)
            vec.add(g)
        else:
            vec.discard(g)
    return keep


def word_copies(stmts):
    """Indices of the load/store pairs of one asm block that copy a word through one GPR and nothing else (remediation-32,
    stretch-panic run 2026-10-17-039 F-2: func_0012CA90's `lw t0, 0x40(m)` / `sw t0, 0x40(out)` ahead of the VU0 code, 100 in
    the block, 99.66 with the copy in C, where the compiler picks v1): a load followed at once by the store of the same width
    and register, whose register the block reads nowhere else before writing it again."""
    keep = set()
    for i in range(len(stmts) - 1):
        (m1, o1), (m2, o2) = stmts[i], stmts[i + 1]
        if len(o1) != 2 or len(o2) != 2 or LOAD_STORE.get(m1.lower()) != m2.lower() or o1[0] != o2[0]:
            continue
        g, clean = o1[0], True
        for mn, ops in stmts[i + 2:]:
            reads = any(o == g or o.endswith(f"({g})") for o in ops[1:]) or (
                ops[:1] == [g] and (WORD_STORE.match(mn) or QMTC2.match(mn) or mn.lower().startswith("ctc2")))
            if reads:
                clean = False
                break
            if ops[:1] == [g]:
                break                                  # written again: the copy's value is dead
        if clean:
            keep.update((i, i + 1))
    return keep


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


def _strip_parens(text):
    """File-scope text with every parenthesised group emptied, so a prototype's parameter
    names do not read as file-scope declarations."""
    prev = None
    while prev != text:
        prev, text = text, re.sub(r"\([^()]*\)", "()", text)
    return text


# byte-offset, the escape spelling (remediation 2026-10-15-remediation-20; Stretch Panic's `void *func_00122480(char *p)
# { return p + 0x10; }` passed every rule): a byte pointer plus or minus a constant that leaves the expression whole —
# returned, assigned to another name, or passed as an argument — is a member's address spelled as bytes. A pointer the
# function subscripts (`p[i]`) is a buffer, and `p = p + 1` steps a cursor: neither is reported.
BYTE_ESCAPE = re.compile(r"(?:\breturn\s+|(?:\b(?P<lhs>[A-Za-z_]\w*)\s*)?(?<![=!<>+\-*/%&|^])=\s*|[(,]\s*)\(?\s*(?P<name>[A-Za-z_]\w*)\s*[+-]\s*"
                         r"(?P<k>0[xX][0-9A-Fa-f]+|[1-9]\d*)\s*\)?\s*(?=[;,)])")


def byte_pointer_findings(stripped, path=""):
    """byte-offset, the declaration spelling: `(T *)(p + N)` where `p` is declared a byte
    pointer in the enclosing function (parameters and locals) or at file scope; and the escape
    spelling, `return p + N;` / `q = p + N;` / `f(p + N)`."""
    lines = stripped.splitlines()
    scope = {}
    buffers = {}
    for _name, a, b in function_spans(stripped):
        body = "\n".join(lines[a - 1:b])
        names = set(BYTE_DECL.findall(body))
        subscripted = {n for n in names if re.search(r"\b" + re.escape(n) + r"\s*\[", body)}
        for ln in range(a, b + 1):
            scope[ln] = names
            buffers[ln] = subscripted
    file_names = set(BYTE_DECL.findall(_strip_parens("\n".join(l for i, l in enumerate(lines, 1) if i not in scope))))
    out = []
    for lineno, line in enumerate(lines, 1):
        names = file_names | scope.get(lineno, set())
        hit = False
        for m in BYTE_PTR_USE.finditer(line) if names else ():
            if m.group(1) not in BYTE_CASTS and m.group(2) in names:
                out.append({"path": path, "line": lineno, "rule": "byte-offset", "severity": "error",
                            "source": f"{line.strip()}  [{m.group(2)} is declared a byte pointer]"})
                hit = True
                break
        if hit or lineno not in scope:
            continue
        for m in BYTE_ESCAPE.finditer(line) if names else ():
            nm = m.group("name")
            if nm in names and nm not in buffers.get(lineno, set()) and m.group("lhs") != nm:
                out.append({"path": path, "line": lineno, "rule": "byte-offset", "severity": "error",
                            "source": f"{line.strip()}  [{nm} is a byte pointer: {nm} {m.group(0).strip()[-12:]} is a member's address "
                                      "spelled in bytes; `&o->unk_N` on the struct that holds it is the plain spelling]"})
                break
    return out


# --- comment-named-field (remediation 2026-10-15-remediation-20) ------------------------------------
# A comment above a struct that says what an offset holds ("the flag word at +0x4") while that member
# keeps its placeholder: the analysis is done and stranded in prose. Advisory: name the member through
# `ledger.py rename --kind field` with the facts the comment cites, or let the comment say less.
CITED_OFFSET = re.compile(r"\+\s*0x([0-9A-Fa-f]+)\b|\bat\s+0x([0-9A-Fa-f]+)\b|\boffset\s+0x([0-9A-Fa-f]+)\b", re.I)
SYSTEMATIC_MEMBER = re.compile(r"^(?:unk|field|f|i|v|x|vec)_?(?:0x)?([0-9A-Fa-f]+)$")


def comment_field_findings(text, path=""):
    out = []
    stripped = strip_comments(text)
    for m in AGGREGATE.finditer(stripped):
        before = text[:m.start()].rstrip()
        if before.endswith("*/"):
            start = before.rfind("/*")
            comment = before[start:] if start >= 0 else ""
        else:
            tail = []
            for ln in reversed(before.splitlines()):
                if ln.strip().startswith("//"):
                    tail.append(ln)
                else:
                    break
            comment = "\n".join(reversed(tail))
        cited = {int(next(g for g in c if g), 16) for c in CITED_OFFSET.findall(comment)}
        if not cited:
            continue
        end = _body_end(stripped, m.end() - 1)
        if end < 0:
            continue
        body_start = m.end()
        for decl in re.finditer(r"[^;{}]+;", stripped[body_start:end]):
            nm = re.search(r"([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;$", decl.group(0).strip())
            if not nm:
                continue
            sm = SYSTEMATIC_MEMBER.match(nm.group(1))
            if sm and int(sm.group(1), 16) in cited:
                lead = decl.group(0)[:len(decl.group(0)) - len(decl.group(0).lstrip())]      # the newlines before the member
                ln = stripped.count("\n", 0, body_start + decl.start()) + 1 + lead.count("\n")
                out.append({"path": path, "line": ln, "rule": "comment-named-field", "severity": "advisory",
                            "source": f"{nm.group(1)}: the comment above says what +0x{int(sm.group(1), 16):X} holds; name the member "
                                      "through ledger.py rename --kind field with those facts, or say less in the comment"})
    return out


def lint_text(text, path="", draft=None):
    findings = []
    stripped = strip_comments(text)
    lines = stripped.splitlines()
    for lineno, stmts in asm_statements(stripped):
        mnemonics = [mn for mn, _ in stmts]
        src = lines[lineno - 1].strip() if lineno <= len(lines) else "asm {"
        into = mmi_transfers(stmts)
        scalar = scalar_transfers(stmts) | into | vector_stores(stmts, into) | word_copies(stmts)
        foreign = [mn for i, (mn, ops) in enumerate(stmts)
                   if not COP2_MNEMONIC.match(mn) and i not in scalar and not vu0_neutral(mn, ops)]
        foreign_fpu = [x for x in mnemonics if not COP1_CONV_MNEMONIC.match(x)]
        if mnemonics and not foreign and any(COP2_MNEMONIC.match(x) for x in mnemonics):
            findings.append({"path": path, "line": lineno, "rule": "vu0-asm", "severity": "advisory",
                             "source": f"{src}  [{', '.join(mnemonics)}]"})
        elif mnemonics and not foreign_fpu and any(COP1_CONV_ONLY.match(x) for x in mnemonics):
            # a float-to-int conversion block: no C spelling reaches the inline
            # 0x46000024 under the pinned 2.x build (K9 C12, remediation 17)
            findings.append({"path": path, "line": lineno, "rule": "fpu-asm", "severity": "advisory",
                             "source": f"{src}  [{', '.join(mnemonics)}]"})
        elif mnemonics and all(KERNEL_MNEMONIC.match(x) for x in mnemonics):
            # the SDK's ExitHandler() / EI() / DI(): no C spelling (remediation 28)
            findings.append({"path": path, "line": lineno, "rule": "kernel-asm", "severity": "advisory",
                             "source": f"{src}  [{', '.join(mnemonics)}]"})
        else:
            hint = ""
            if any(x.lower() in ("mfc1", "mtc1") for x in foreign) and any(COP2_MNEMONIC.match(x) for x in mnemonics):
                hint = ("; an mfc1/mtc1 is part of a VU0 block only as the scalar transfer whose GPR a qmtc2/qmfc2"
                        " in the same block moves (K9 C3)")
            elif any(MMI_TRANSPOSE.match(x) or x.lower() in ("lq", "sq") for x in foreign) and any(COP2_MNEMONIC.match(x) for x in mnemonics):
                hint = ("; pextlw/pextuw/pcpyld/pcpyud, the loads and dsll32/or they pack from, and the sw/sd/sq of their"
                        " rows are part of a VU0 block only on the path of a qmtc2/qmfc2 in the same block (K1 §6 item 12)")
            findings.append({"path": path, "line": lineno, "rule": "inline-asm", "severity": "error",
                             "source": f"{src}  [not COP2: {', '.join(foreign) or 'empty block'}{hint}]"})
    vu0_fn = {ln: stmts for ln, stmts in asm_function_statements(stripped) if vu0_float_return(stmts)}
    for lineno, line in enumerate(lines, 1):
        if ASM_FUNC.search(line) and lineno in vu0_fn:
            # the VU0 float return: the one asm function that reaches its bytes (K1 §6 item 11, remediation 33)
            findings.append({"path": path, "line": lineno, "rule": "vu0-asm", "severity": "advisory",
                             "source": f"{line.strip()}  [asm function, VU0 float return: {', '.join(mn for mn, _ in vu0_fn[lineno])}]"})
        elif ASM_FUNC.search(line):
            findings.append({"path": path, "line": lineno, "rule": "inline-asm", "severity": "error", "source": line.strip()})
        hits = [(rule, sev) for rule, sev, rx in RULES if rx.search(line)]
        if ("reinterpret-lvalue", "error") in hits:  # `*(T *)&x[0]` is one finding, not two
            hits = [h for h in hits if h[0] != "overlay-cast"]
        for rule, sev in hits:
            findings.append({"path": path, "line": lineno, "rule": rule, "severity": sev, "source": line.strip()})
    cast_spelled = {f["line"] for f in findings if f["rule"] == "byte-offset"}
    findings.extend(f for f in byte_pointer_findings(stripped, path) if f["line"] not in cast_spelled)
    if not str(path).endswith("types.h"):
        for m in TYPEDEF_REDECLARE.finditer(stripped):
            findings.append({"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "typedef-redeclare",
                             "severity": "error", "source": f"{m.group(0).strip()}  [use include/types.h]"})
    defined = {m.group(1) for m in FUNC_DEF.finditer(stripped)} - NOT_FUNCS
    for m in EXTERN_FUNC.finditer(stripped):
        if m.group(1) in defined:
            findings.append({"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "self-extern",
                             "severity": "advisory", "source": f"extern declaration of {m.group(1)}, which this file defines"})
    # one data object declared twice, spelled differently (`extern int D_x[];` beside `extern s32 D_x[];`): one declaration
    # per object (remediation 2026-10-15-remediation-19, fate run 031 F-5 and NEW-8)
    first = {}
    for m in EXTERN_DATA.finditer(stripped):
        decl, ln = " ".join(m.group(0).split()), stripped.count("\n", 0, m.start()) + 1
        if m.group(2) in first and first[m.group(2)][1] != decl:
            findings.append({"path": path, "line": ln, "rule": "extern-redeclare", "severity": "advisory",
                             "source": f"{decl}  [line {first[m.group(2)][0]} declares it as {first[m.group(2)][1]}]"})
        first.setdefault(m.group(2), (ln, decl))
    for m in COMMENT.finditer(text):
        pm = PROCESS_COMMENT.search(m.group(0))
        if pm:
            ln = text.count("\n", 0, m.start() + pm.start()) + 1
            findings.append({"path": path, "line": ln, "rule": "process-comment", "severity": "error",
                             "source": " ".join(m.group(0).split())[:100] + "  [a comment says what the code does, not how it was matched]"})
    for m in COMMENT.finditer(text):
        ph = PLACEHOLDER.search(m.group(0))
        if ph:
            findings.append({"path": path, "line": text.count("\n", 0, m.start() + ph.start()) + 1, "rule": "placeholder-left", "severity": "error",
                             "source": " ".join(m.group(0).split())[:100] + "  [a placeholder left in accepted source]"})
    for m in M2C_PLACEHOLDER.finditer(stripped):
        findings.append({"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "placeholder-left", "severity": "error",
                         "source": f"{m.group(0)}  [an m2c placeholder: write what the instructions do]"})
    findings.extend(trace_findings(text, stripped, path, draft))
    findings.extend(member_offset_findings(text, path))
    findings.extend(comment_field_findings(text, path))
    findings.extend(readability_debt(text, path)[0])
    if any(f["rule"] in ("vu0-asm", "fpu-asm", "kernel-asm", "inline-asm") for f in findings):
        # an asm block's operands are `register` locals by necessity (the VU0 exception,
        # K9 C3): register-local says nothing new there
        findings = [f for f in findings if f["rule"] != "register-local"]
    findings.sort(key=lambda f: (f["line"], f["rule"]))
    return findings


# --- readability debt (round 26, WP8) ---------------------------------------------------
FAKE_MARK = re.compile(r"//[ \t]*!FAKE:?[ \t]*([^\n]*)")
MOVE_MNEMONIC = re.compile(r"^(?:move|nop|or|addu|daddu|dmove)$", re.I)


def function_spans(stripped):
    """[(name, start_line, end_line)] for every function definition in comment-stripped text."""
    spans = []
    for m in FUNC_DEF.finditer(stripped):
        if m.group(1) in NOT_FUNCS:
            continue
        end = _body_end(stripped, m.end() - 1)
        spans.append((m.group(1), stripped.count("\n", 0, m.start()) + 1, stripped.count("\n", 0, end) + 1))
    return spans


def _function_at(spans, line):
    for name, a, b in spans:
        if a <= line <= b:
            return name
    return None


def readability_debt(text, path=""):
    """(findings, pinned, fake): the register-pin / fake-body findings for one file and the
    names of the functions they sit in."""
    stripped = strip_comments(text)
    spans = function_spans(stripped)
    lines = stripped.splitlines()
    pins = {}
    for lineno, line in enumerate(lines, 1):
        if re.match(r"^\s*register\b", line):
            fn = _function_at(spans, lineno)
            if fn:
                pins.setdefault(fn, []).append(lineno)
    necessary = set()          # functions whose `register` locals feed a VU0 / FPU block (K9 C3, C12)
    for lineno, stmts in asm_statements(stripped):
        mnemonics = [mn for mn, _ in stmts]
        fn = _function_at(spans, lineno)
        if mnemonics and all(MOVE_MNEMONIC.match(mn) for mn in mnemonics):
            if fn:
                pins.setdefault(fn, []).append(lineno)
        elif mnemonics and all(COP2_MNEMONIC.match(mn) or COP1_CONV_MNEMONIC.match(mn) or vu0_neutral(mn, ops)
                               for mn, ops in stmts):
            if fn:
                necessary.add(fn)
    for fn in necessary:
        pins.pop(fn, None)
    findings = []
    for name, a, _b in spans:
        if name in pins:
            findings.append({"path": path, "line": a, "rule": "register-pin", "severity": "advisory",
                             "source": f"{name}: register pin at line(s) {', '.join(map(str, pins[name]))}"})
    fake = []
    for m in FAKE_MARK.finditer(text):
        ln = text.count("\n", 0, m.start()) + 1
        # the marker sits above the function (its line is before the definition) or inside it
        fn = _function_at(spans, ln) or next((n for n, a, _b in spans if a > ln), None)
        why = m.group(1).strip()
        if not why:
            findings.append({"path": path, "line": ln, "rule": "fake-body-unexplained", "severity": "error",
                             "source": "// !FAKE: without a reason — say what a programmer would have written"})
        else:
            findings.append({"path": path, "line": ln, "rule": "fake-body", "severity": "advisory",
                             "source": f"{fn or '?'}: !FAKE: {why[:80]}"})
        if fn:
            fake.append(fn)
    return findings, sorted(pins), sorted(set(fake))


def draft_beside(p):
    """The draft a wip attempt was written from (wip/<fn>/draft.c, else m2c.c), or None: an accepted unit has none beside it."""
    p = Path(p)
    for name in ("draft.c", "m2c.c"):
        d = p.parent / name
        if d.is_file() and d.resolve() != p.resolve():
            return d.read_text(encoding="utf-8", errors="replace")
    return None


def trace_findings(text, stripped, path, draft):
    """trace-leftover: a printf-family call beyond the count in the function's draft; nothing without a draft."""
    if draft is None:
        return []
    want = len(TRACE_CALL.findall(strip_comments(draft)))
    hits = list(TRACE_CALL.finditer(stripped))
    return [{"path": path, "line": stripped.count("\n", 0, m.start()) + 1, "rule": "trace-leftover", "severity": "error",
             "source": f"{m.group(0)}  [a debug print the draft does not have]"} for m in hits[want:]]


def lint_file(p, rel=None):
    return lint_text(p.read_text(encoding="utf-8", errors="replace"), rel or str(p), draft_beside(p))


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0], formatter_class=argparse.RawDescriptionHelpFormatter, epilog=__doc__)
    ap.add_argument("--repo")
    ap.add_argument("--target", help="a registered target (the pack's verb; reads the project's registry)")
    ap.add_argument("files", nargs="*")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    if a.target:
        reg = Path(__file__).resolve().parents[3] / "targets" / "registry.json"
        hit = [t for t in (json.loads(reg.read_text(encoding="utf-8")).get("targets") or []) if t.get("slug") == a.target] if reg.is_file() else []
        if not hit:
            print(f"{a.target!r} is not a registered target", file=sys.stderr)
            return 2
        a.repo = hit[0]["live"]
    home = Path(__file__).resolve().parent.parent
    if not a.repo and (home / "src").is_dir():
        a.repo = str(home)   # the contributor copy at tools/lint_c.py lints the repository it sits in
    if not a.repo:
        print("--repo <path> or --target <slug> is required", file=sys.stderr)
        return 2
    repo = Path(a.repo).resolve()
    if not repo.is_dir():
        print(f"no such repo: {repo}", file=sys.stderr)
        return 2
    if a.files:
        paths = [Path(f) if Path(f).is_absolute() else repo / f for f in a.files]
    else:
        paths = (sorted(p for p in (repo / "src").rglob("*") if p.suffix in SOURCE_SUFFIXES and p.is_file())
                 + sorted((repo / "include").rglob("*.h")))
    findings = []
    for p in paths:
        if not p.is_file():
            print(f"not a file: {p}", file=sys.stderr)
            return 2
        rel = str(p.relative_to(repo)) if p.is_relative_to(repo) else str(p)
        findings.extend(lint_file(p, rel))
    errors = [f for f in findings if f["severity"] == "error"]
    for f in findings:   # the contract's finding shape beside this lint's own keys
        f.setdefault("level", "error" if f["severity"] == "error" else "advisory")
        f.setdefault("text", f["source"])
    if a.json:
        print(json.dumps({"files": len(paths), "findings": findings, "errors": len(errors)}))
    else:
        for f in findings:
            print(f"{f['path']}:{f['line']}: {f['rule']}{'' if f['severity'] == 'error' else ' (advisory)'}: {f['source']}")
        print(f"lint_c: {len(paths)} file(s), {len(errors)} error finding(s), {len(findings) - len(errors)} advisory")
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
