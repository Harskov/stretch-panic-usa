# Friction Report — 2026-09-19-014-match-batch

**Job folder:** `2026-09-19-014-match-batch`  
**Log:** `friction-log.jsonl` (6 entries; opened 2026-09-19T12:56:33Z, exported 2026-09-19T13:24:29Z)  
**Skills build:** mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0; splat/ninja on the mount  
**Severity counts:** major 3, minor 3  

## How to consume this report (for the remediating model)

You are reading an operator's friction log from one run (one step) of the
Decompilation Assistant (PS2) project. Before you implement anything,
internalize the rules the sibling projects' remediation rounds paid for:

1. **Reproduce every claim from its artifacts before implementing its fix.**
   Each entry separates OBSERVED (facts the operator saw, with artifact paths)
   from HYPOTHESIS (the operator's guess at the cause — explicitly unverified).
   A sibling project's report once proposed a remedy that verification showed
   would have turned 8 false positives into 31 false negatives. Reproduce first.
2. **Right symptom, wrong layer is the common failure.** Three diagnoses in
   one sibling remediation round were correct about the symptom and wrong
   about which layer owned the defect (instructions / knowledge / skill script
   / template), and each proposed fix would have passed its own test while
   leaving the defect in place. Trace the defect to the layer that owns it.
3. **A fix without a discriminating check is not a fix.** Every fix ships with
   a check that fails on the pre-fix version: a script test, a build-evidence
   transcript, or a `check.json` / ledger record that the old build could not
   have produced. A check that passes when the fix is absent tests nothing.
4. **Measure thresholds before shipping them.** Every cutoff you change in
   config/policy.json (batch size, attempt cap, permuter timeout) should cite
   the ledger or friction evidence that justifies it, in the commit message.
5. **Structural truncation check on every revised file:** no definitions lost,
   and growth accounted for. Never let a revised file ship truncated.
6. **Entries are review sites, not verdicts.** An operator can misread a tool
   (see any entry whose category is `operator-drift` or `evidence-gap`).
   Rejecting an entry with a reasoned refutation is a legitimate resolution —
   record it.
7. **Every measurement is as of the moment it was logged**, which is mid-run:
   the run kept working afterwards, and the step an entry was logged in is
   often the step that fixes what it describes. A repro that now comes back
   empty can mean the run resolved it, not that the entry was wrong. Re-measure
   on the committed tree and resolve the entry on the re-measurement — in the
   two rounds before this rule was written, one entry quoted a census its own
   completed rename pass had invalidated, and another cited ten duplicate
   typedefs its own consolidate had already merged.

**Severity vocabulary:** **blocker** = stopped the pipeline or forced a forbidden action (e.g. a hand-edit); **major** = wrong output, missed detection, or substantial rework; **minor** = friction worked around within the sanctioned toolset; **papercut** = annoyance; no rework, but worth fixing.

**Category vocabulary:** **tool-bug** = a toolkit script or third-party tool (wibo, mwccps2, objdiff, splat, m2c, permuter) produced wrong output or crashed on sanctioned input; **tool-gap** = a needed capability is missing from the toolkit or the pinned toolchain; **toolchain-drift** = compiler, assembler, linker or objdiff behaviour differs from tools/manifest.json or from the doctrine in K1/K2 (a version that differs from the manifest, a preset that does not exist for the compiler); **doc-gap** = K1-K8, a SKILL.md or PROJECT-INSTRUCTIONS.md is silent or wrong where the run needed guidance; **doctrine-gap** = a step procedure in dps2-step is unclear or contradicts observed behaviour (a segment boundary found wrong, an entry state next_step.py misjudged); **evidence-gap** = a status, name, type or address could not be grounded in an artifact (no cited evidence for a name; objdiff could not read a compile that succeeded under wibo); **environment** = the VM bit: the ~3-minute device_bash cap, memory, network, the no-delete mount, host binutils without R5900; **operator-drift** = the operator caught itself outside the step: wanting to start a second step, a report over its length target, an unplanned subagent, instructed-looking re-checking of its own work; **false-signal** = a check false-positived or false-negatived (objdiff 100 but check.json red; check.json green with a wrong segment).

## Stage attestation

Silence is not evidence of frictionlessness: a stage is either attested (`clear-stage` recorded, with or without entries) or UNATTESTED (never examined — the operator never said). Entries without a `clear-stage` mean friction was seen and the review was not finished. UNATTESTED stages are holes in this report's coverage, not clean bills of health.

| Stage | Status |
|---|---|
| Stage R RESUME | attested clear |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 6 entries + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-3 — [major / tool-gap] match.py permute cannot preprocess an attempt that includes a project header

- **Stage:** Stage E EXECUTE | **Function:** `func_0016C720` | **Tool:** `match.py` | **Logged:** 2026-09-19T13:04:01Z
- **Observed (fact):** match.py permute func_0016C720 exited rc=1 after building permuter/base.c from wip/func_0016C720/attempt-100.c, which starts with #include "common.h". decomp-permuter's src/preprocess.py runs ['cpp','-P','-nostdinc','-DPERMUTER', base.c] with no -I: cpp reports 'common.h: No such file or directory', CalledProcessError, no candidates produced. A self-contained rewrite (wip/func_0016C720/attempt-103.c, no include) did not route around it: permute rebuilds base.c from the EARLIEST attempt at the best score and all four attempts tie at 99.09091, so it kept attempt-100.c and failed identically. Copying include/common.h and include/types.h into wip/func_0016C720/permuter/ (cpp resolves a quoted include beside the including file) made the run work: 328 iterations in 120 s, nothing better.
- **Expected:** permute to preprocess the base the way the compile does — match.py's own compile line passes -nostdinc -i include -i wip/<fn>, so the same include path should reach cpp (or the base should be preprocessed before it is handed to the permuter).
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Two defects. (1) preprocess.py's cpp call gets no -I, so any attempt that includes a project header — which the consolidate doctrine asks for — cannot be permuted; passing -I <repo>/include -I <repo>/wip/<fn> fixes it. (2) match.py permute picks the earliest attempt among ties at the best score, so a self-contained rewrite cannot be used as an escape; preferring the newest fixes it. The copy-the-headers workaround is confirmed and is what this run used.
- **Artifact:** `../../wip/func_0016C720/permuter/permuter.log` (exists)
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa permute func_0016C720` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*
- **Amended through the tool:** `observed` at 2026-09-19T13:07:08Z (second permute run after the header-copy workaround; the earliest-attempt selection is part of the defect); `hypothesis` at 2026-09-19T13:07:08Z (same)

### F-4 — [major / toolchain-drift] two-load vtable dispatch: the shipping build calls through $t9, the pinned build through $v0, on every spelling

- **Stage:** Stage E EXECUTE | **Function:** `func_00159EE0` | **Logged:** 2026-09-19T13:09:45Z
- **Observed (fact):** Three batch functions are a vtable dispatch (lw t9,0(obj); lw t9,K(t9); jalr t9) and all three stop with those three rows as the only diff: func_0016C720 99.09, func_00159EE0 98.33, func_0015D4E0 98.33. Seven spellings across them compile to jalr v0: direct chain call, a Method local, a Vtbl local, a self-contained rewrite, a non-void method return type, an array-of-function-pointers vtbl (c->vtbl[2]), and (*p)(...). decomp-permuter ran 328 iterations on func_0016C720 and found nothing better. Image census over targets/stretch-panic-usa/asm/ (460 jalr sites): 449 of the 460 jalr $t9 have exactly two chained loads into t9 in the preceding four instructions, and 37 of the 38 jalr $v0 have exactly one — the shipping build's split is by chain depth, and every two-load site in the image uses $t9. The pinned mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0 emitted $v0 for the two-load shape in all seven spellings and has no matched function with an indirect call to compare against (0 of 116 src files).
- **Expected:** The pinned compiler to reproduce the shipping build's register choice for the two-load dispatch, as it does for the one-load case; K1 has no entry for indirect-call register selection.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Not a source-level property: the shipping build's own split is purely by chain depth, so the C is already the right shape and no spelling will move it (the same reading as K1 §6.12's cvt-constant schedule). The candidates are a different mwccps2 build than the pinned 2.3.3-000906, or the shipping source being C++ compiled with -lang c++ where the two-load shape is a virtual-method call and mwcc's C++ path reserves $t9. Both are calibrate-step questions: this is worth an S2 calibrate whose candidate set includes a two-load dispatch function, because 449 call sites in the image carry the shape and every function containing one is capped below 100 until it is settled.
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa try func_00159EE0 wip/func_00159EE0/attempt-100.c` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-6 — [major / toolchain-drift] float-to-int: the shipping build inlines cvt.w.s, the pinned build always calls the fptosi helper

- **Stage:** Stage E EXECUTE | **Function:** `func_0014E490` | **Logged:** 2026-09-19T13:20:52Z
- **Observed (fact):** func_0014E490 converts its f32 parameter with 'cvt.w.s $f0, $f12; mfc1 $s1, $f0'. Every C spelling compiled by the pinned mwcps2-2.3.3-000906 emits 'jal fptosi' instead (R_MIPS_26 to fptosi in wip/func_0014E490/attempt-1.o at 0xd0). A probe over four flag sets — the pinned -O3,p -sdatathreshold 0, plus -O4,p, -fp single and -inline auto — produced cvt.w.s 0 times and fptosi 1 time in all four. A second probe on a four-line file ((int)f, (unsigned)f, (short)f, implicit) produced jal fptosi, jal fptoui, jal fptosi, jal fptosi and no cvt.w.s. Image census over asm/: 31 cvt.w.s, 0 trunc.w.s, 238 cvt.s.w, spread over 36 functions, and no fptosi/fptoui symbol or string anywhere in the image — the shipping build inlined every one of its conversions. The extra call also changes the register allocation downstream (the object lands in s3 not s2, the switch constants in v0 not v1, and the loop strength-reduces to a walking pointer), so the function parks at 74.47 with 436 bytes against 440 and the structure otherwise correct.
- **Expected:** The pinned compiler to inline the conversion as the shipping build does, or K1 to name the C spelling that reaches cvt.w.s.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Same root as F-4 and pointing the same way: mwcps2-2.3.3-000906 is probably not the build that shipped this game. A later mwccps2 inlines float-to-int (and uses $t9 for the two-load dispatch). This is a calibrate question, and a calibrate whose candidate set includes one function with a float-to-int conversion and one with a vtable dispatch would settle both at once. No source spelling is a candidate: the helper call is a whole extra instruction the permuter cannot remove, which is why this function was parked without a permute run.
- **Repro:** `cd targets/stretch-panic-usa && tools/wibo tools/compilers/mwcps2-2.3.3-000906/mwccps2.exe -c -O3,p -sdatathreshold 0 -nostdinc -stderr -i include -i wip/func_0014E490 wip/func_0014E490/attempt-1.c -o /tmp/probe.o` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-1 — [minor / doc-gap] quad copied whole then read lane by lane: the union spelling is not in K1 §6

- **Stage:** Stage E EXECUTE | **Function:** `func_00152300` | **Logged:** 2026-09-19T12:59:11Z
- **Observed (fact):** func_00152300 copies 16 bytes with lq 0x270(a0)/sq 0x20(a1) and then negates three floats at 0x20/0x24/0x28 of the same destination. The external lane spent 80 attempts and $0.124 and parked at 99.3 (best wip/func_00152300/attempt-29.c). One attempt declaring the field as union { u128 q; Vec v; } scored 100 byte-identical (wip/func_00152300/attempt-81.c, lint 0 findings).
- **Expected:** K1 §6's spellings-already-scored table, which the runner prompt and the operator both read, to carry the two-widths-one-field row; the precedent exists only in targets/stretch-panic-usa/include/game_01/obj430.h (union Quad420, written in run 012).
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The union shape is recorded as a header comment on one object rather than as a general spelling in K1 §6/§8, so neither the runner's prompt nor a fresh reading of the primer reaches it; a K1 §6 row plus a K1 §8 cheat-sheet line for 'lq/sq over a field also read as floats' would have closed this in one attempt.
- **Artifact:** `../../wip/func_00152300/attempt-81.c` (exists)
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa try func_00152300 wip/func_00152300/attempt-81.c` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-2 — [minor / doc-gap] consecutive quads loaded before the first store are one struct assignment, not N u128 assignments

- **Stage:** Stage E EXECUTE | **Function:** `func_001525D0` | **Logged:** 2026-09-19T13:01:03Z
- **Observed (fact):** func_001525D0 (lq 0x80/0x90/0xA0 of a1, then sq 0x3A0/0x3B0/0x3C0 of a0 — all three loads before the first store) and func_00162900 (the same shape into 0x310/0x320/0x330). The external lane parked both at 98.7: 62 attempts on func_001525D0, 116 on func_00162900, all spelling the region as three separate u128 fields or byte-offset casts, which interleaves lq/sq. One attempt each declaring the region as a struct of three u128s and assigning it whole scored 100 byte-identical (wip/func_001525D0/attempt-100.c, wip/func_00162900/attempt-200.c).
- **Expected:** K1 §8's lq/sq row, and a K1 §6 spelling row, to say that N consecutive quads whose loads are all hoisted above the first store are one struct-typed field assigned in one statement; the row currently covers only the single 128-bit access.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The primer describes lq/sq per access, so both the runner's prompt and a fresh reading reproduce it per field; the hoisted-load shape is the compiler's signature for a whole-struct copy and naming it in K1 §8 plus a §6 row would close this class in one attempt.
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa try func_00162900 wip/func_00162900/attempt-200.c` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-5 — [minor / doc-gap] a float constant compared inline takes $f1; as a named local it takes $f0

- **Stage:** Stage E EXECUTE | **Function:** `func_00179E20` | **Logged:** 2026-09-19T13:12:11Z
- **Observed (fact):** func_00179E20's first guard is c.eq.s against 0.0f. Written inline — 'if (o->unk_2F0 != 0.0f && o->unk_2E4 > 0.7f)' — the compiler puts the field in $f0 and the constant in $f1 and the one differing row is '0010 target: c.eq.s fv1, fv0 / yours: c.eq.s fv0, fv1' (99.565, attempt-1). Early-return guards (attempt-2) and nested ifs (attempt-5) give the same row; swapping the source operands to '0.0f != o->unk_2F0' does not swap the registers (mwcc normalises it) and breaks the second compare instead (94.3, attempt-3: c.lt.s/bc1f for c.le.s/bc1t). Declaring 'f32 zero; zero = 0.0f;' and comparing against it — attempt-4 — is 100 byte-identical. Note the second guard's 0.7f, an inline literal in every attempt, is in $f0 and correct throughout: only the 0.0f moved.
- **Expected:** K1 §6's spellings table to carry the float-constant register rule, next to §6.1 'register allocation via variable ordering', which covers integer locals only.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** mwcc allocates float registers in order of creation, and a literal inside the compare expression is created after the field load while a named local is created before it, so the constant takes $f0. If so the rule generalises to any float compare whose target puts the constant in the lower register, and is a cheap first thing to try on a one-row c.\*.s diff.
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa try func_00179E20 wip/func_00179E20/attempt-1.c` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 2 — 2 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-014-match-batch",
  "exported": "2026-09-19T13:24:29Z",
  "build": "mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0; splat/ninja on the mount",
  "entry_count": 6,
  "severity_counts": {
    "major": 3,
    "minor": 3
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "6 entries + attested complete",
    "V": "attested clear",
    "X": "attested clear"
  },
  "artifact_accounting": {
    "total": 2,
    "present": 2,
    "archived": 0,
    "other_fs": 0,
    "ephemeral": 0,
    "missing": 0
  },
  "retired_artifacts": [],
  "entries": [
    {
      "id": "F-3",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "match.py permute cannot preprocess an attempt that includes a project header",
      "tool": "match.py",
      "function": "func_0016C720"
    },
    {
      "id": "F-4",
      "stage": "E",
      "severity": "major",
      "category": "toolchain-drift",
      "title": "two-load vtable dispatch: the shipping build calls through $t9, the pinned build through $v0, on every spelling",
      "function": "func_00159EE0"
    },
    {
      "id": "F-6",
      "stage": "E",
      "severity": "major",
      "category": "toolchain-drift",
      "title": "float-to-int: the shipping build inlines cvt.w.s, the pinned build always calls the fptosi helper",
      "function": "func_0014E490"
    },
    {
      "id": "F-1",
      "stage": "E",
      "severity": "minor",
      "category": "doc-gap",
      "title": "quad copied whole then read lane by lane: the union spelling is not in K1 §6",
      "function": "func_00152300"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "minor",
      "category": "doc-gap",
      "title": "consecutive quads loaded before the first store are one struct assignment, not N u128 assignments",
      "function": "func_001525D0"
    },
    {
      "id": "F-5",
      "stage": "E",
      "severity": "minor",
      "category": "doc-gap",
      "title": "a float constant compared inline takes $f1; as a named local it takes $f0",
      "function": "func_00179E20"
    }
  ]
}
```
