# Friction Report — 2026-09-19-015-calibrate

**Job folder:** `2026-09-19-015-calibrate`  
**Log:** `friction-log.jsonl` (6 entries; opened 2026-09-19T14:26:20Z, exported 2026-09-19T14:48:21Z)  
**Skills build:** mwcps2-2.3.3-000906 / -O3,p -sdatathreshold 0 / 21 mwcps2 builds in manifest  
**Severity counts:** blocker 1, major 4, minor 1  

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

### F-6 — [blocker / tool-bug] pin rewrites every candidate's ledger record: it demoted two library functions to wip and unlinked four linked matches

- **Stage:** Stage E EXECUTE | **Tool:** `calibrate_compiler.py` | **Logged:** 2026-09-19T14:45:09Z
- **Observed (fact):** Before pin: func_00103628 library (sdk_libgraph), func_001185E8 library (sdk_libc), and func_00131740 / func_00145A10 / func_00157650 / func_00164E80 matched with linked=true and score 100.0. After 'calibrate_compiler.py pin --run 2026-09-19-015-calibrate --compiler mwcps2-2.3.3-000906 --flags "-O3,p -sdatathreshold 0"' (which printed 'ledger: 4 matched, 7 wip'): the two library functions are status wip in their sdk segments, and all four matched functions are linked=false — ledger.py stats now prints 'matched, not linked: 4'. The pin was a re-calibrate of an already-calibrated target with 121 matched functions and a green check.json, so these records existed long before this run.
- **Expected:** pin records candidates that have no better record and leaves a stronger one alone: a library classification is not downgraded to wip, and a matched function keeps linked=true. Re-pinning the build and flags a target already uses should be a no-op for the ledger.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** pin was written for the first calibrate on a fresh target, where every candidate is new and a blanket write is harmless; on a re-calibrate it overwrites by candidate name without reading the existing status or linked flag. Left unrepaired it would turn the SHIP build red (configure.py exits 2, or check_build.py reports RED (UNLINKED)) for four functions.
- **Repro:** `python3 skills/dps2-toolkit/scripts/calibrate_compiler.py --repo targets/stretch-panic-usa pin --run <run> --compiler mwcps2-2.3.3-000906 --flags '-O3,p -sdatathreshold 0'; python3 skills/dps2-toolkit/scripts/ledger.py --repo targets/stretch-panic-usa stats` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-1 — [major / tool-gap] candidates finds only leaf functions, which cannot separate compiler builds on call or conversion idioms

- **Stage:** Stage E EXECUTE | **Tool:** `calibrate_compiler.py` | **Logged:** 2026-09-19T14:30:16Z
- **Observed (fact):** calibrate_compiler.py candidates selects 'short leaf functions with no calls, no branches outside themselves, no global or $gp-relative memory access'; calibration/candidates.json chose 8 such functions. Run 2026-09-19-014 F-4 and F-6 show the two boundaries that actually separate builds on this target are a two-load vtable dispatch (jalr $t9 vs $v0, 449 of 460 jalr sites) and a float-to-int conversion (inline cvt.w.s vs a jal to an fptosi helper, 31 conversion sites) — neither can appear in a candidate with no calls. The previous calibrate pinned mwcps2-2.3.3-000906 with chosen_by 'operator override'.
- **Expected:** candidates, or a sibling subcommand, can also select small non-leaf functions carrying a named idiom, so the calibration table has cells that discriminate rather than tie.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The leaf-only filter was written for S2 on a fresh target, where the goal is a cell that compiles at all; it was never revisited for a re-calibrate whose purpose is to separate builds that already tie on leaf cells.
- **Artifact:** `../../calibration/candidates.json` (exists)
- **Repro:** `python3 skills/dps2-toolkit/scripts/calibrate_compiler.py --repo targets/stretch-panic-usa candidates --max 10` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-2 — [major / doctrine-gap] the target is C++: a vtable dispatch is a virtual call, and K1 has no C++ idiom section

- **Stage:** Stage E EXECUTE | **Function:** `func_00159EE0` | **Logged:** 2026-09-19T14:41:13Z
- **Observed (fact):** calibration/func_00159EE0/attempt.c as a C function-pointer field compiles to 'lw v0,0(a0); lw v0,8(v0); jalr v0' under every one of the 21 mwcps2 builds (matrix in the run folder). The same function written as C++ with a real 'virtual void fn(int)' and compiled by the PINNED build mwcps2-2.3.3-000906 with the PINNED flags -O3,p -sdatathreshold 0 gives .text 27bdfff0 7fbf0000 8c8400b0 10800005 00000000 8c990000 8f390008 0320f809 24050001 7bbf0000 03e00008 27bd0010, byte-identical to calibration/func_00159EE0/target.o (12 of 12 instructions). Run 014 F-4 filed the t9/v0 difference as toolchain-drift and reported 449 of 460 jalr sites in the image share this shape.
- **Expected:** K1 carries the C++ idioms of a CodeWarrior PS2 target — a virtual call through $t9, the two-load vtable fetch, this-pointer passing — so a batch recognises them instead of parking them as a compiler mismatch.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The project's doctrine was written for a C target (m2c emits C, the toolkit compiles .c, K1 §3 and §6 describe C idioms only), so no run had a reason to test a C++ spelling; the t9 register then looked like a build difference because every C spelling reproduces it identically.
- **Repro:** `tools/wibo tools/compilers/mwcps2-2.3.3-000906/mwccps2.exe -c -O3,p -sdatathreshold 0 -nostdinc -stderr -i include <file>.cp -o out.o` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-3 — [major / tool-gap] no C++ path in the toolkit: prepare, try, mark, gen_splat_yaml and configure assume a .c source compiled as C

- **Stage:** Stage E EXECUTE | **Tool:** `match.py` | **Logged:** 2026-09-19T14:41:14Z
- **Observed (fact):** match.py prepare writes wip/<fn>/m2c.c and the compile command from config/compiler.json is 'mwccps2.exe -c <flags> -nostdinc -stderr -i include <in.c> -o <out.o>' with no dialect option; compiling calibration/func_00159EE0/attempt.c with -dialect c++ emits the symbol func_00159EE0__FP3Obj, not func_00159EE0, so objdiff's symbol match and the linker's symbol_addrs entry both miss. Compiling the 8 existing leaf candidates with and without -dialect c++ under 2.3.3 gives identical .text for all 8, so the dialect is codegen-neutral for plain C and only the mangling differs.
- **Expected:** A function can be written and matched as C++ (extern "C" plus -dialect c++, or a .cp source), so the 449 virtual-dispatch sites are reachable.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Adding -dialect c++ to config/compiler.json alone would mangle every existing symbol and turn the link red across the 121 matched functions; the change needs extern "C" in the emitted C and a toolkit that knows about it, which is remediation work, not a step's.

### F-4 — [major / evidence-gap] float-to-int: not a build difference — no available build produces both the image's sq $ra frame and an inline cvt.w.s

- **Stage:** Stage E EXECUTE | **Function:** `func_00125C90` | **Logged:** 2026-09-19T14:41:14Z
- **Observed (fact):** Idiom matrix over all 21 mwcps2 builds (-O3,p -sdatathreshold 0): ra is saved with sq only by mwcps2-2.3.3-000906 and mwcps2-2.4-001213; every 3.0.x build uses sd. Float-to-int is the fptosi helper in 2.3.3, 2.4, 3.0-011126 and 3.0.1-020123, and inline 0x46000024 in every build from 3.0.1b44-030325 on. An image census of asm/: every game segment uses sq $ra (180 in game_00, 182 in game_00_1, 0 sd anywhere in game code) while every sdk segment uses sd $ra; the 16 functions containing an inline 0x46000024 are all in game segments and the 10 of them that have a frame all use sq $ra. Seven C spellings of the cast (int, long, short, unsigned, double, split local, reordered multiply) across -O0,p/-O2,p/-O3,p/-O4,p, -opt intrinsics, -fp single and -dialect c++ all give the helper under 2.3.3.
- **Expected:** One build and flag set reproduces both idioms, or the doctrine records what source construct produces an inline cvt.w.s under a 2.x build.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The 16 inline sites come from a source construct rather than a different compiler — an SDK or game macro containing an asm block or an EE intrinsic (the surrounding code packs a float scaled by 128.0f and shifted left 4 into a 64-bit field, which is the GS 12.4 fixed-point vertex form). The plain asm-block spelling 'asm { cvt.w.s x, x }' is rejected by 2.3.3's parser, so the operand form still has to be found.
- **Repro:** `python3 - <<'P' ... census over targets/stretch-panic-usa/asm/**/*.s counting sq $ra, sd $ra and 46000024 per segment (reproduced in the run's idiom-matrix.md) P` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-5 — [minor / false-signal] a failed probe compile left the previous object in place and the disassembly read as a result

- **Stage:** Stage E EXECUTE | **Logged:** 2026-09-19T14:41:14Z
- **Observed (fact):** Probing '-dialect cplus' (an invalid keyword; the compiler expects c, c++, ec++ or objc) returned a usage error and rc!=0, but the scratch .o from the previous probe was still on disk, so the disassembly printed the earlier build's output under the new label — it showed 'sd ra' for mwcps2-2.3.3-000906, which that build never emits. A second parsing slip in the same session classified every cell of a 21-build matrix as FAIL because the grep patterns used spaces where objdump writes tabs.
- **Expected:** A probe that compiles into a scratch object removes the object first and reports the compiler's exit code beside the disassembly.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Ad-hoc probe loops written inside a run have no fixture discipline; calibrate_compiler.py itself does delete and re-assemble a 0-byte target.o (run 2026-09-17-003 F-4), so the lesson exists in the toolkit but not in the operator's hand-written probes.
- **Repro:** `tools/wibo tools/compilers/<id>/mwccps2.exe -c -O3,p -dialect cplus ... ; echo $? ; objdump -d <stale .o>` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 1 — 1 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-015-calibrate",
  "exported": "2026-09-19T14:48:21Z",
  "build": "mwcps2-2.3.3-000906 / -O3,p -sdatathreshold 0 / 21 mwcps2 builds in manifest",
  "entry_count": 6,
  "severity_counts": {
    "blocker": 1,
    "major": 4,
    "minor": 1
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "6 entries + attested complete",
    "V": "attested clear",
    "X": "attested clear"
  },
  "artifact_accounting": {
    "total": 1,
    "present": 1,
    "archived": 0,
    "other_fs": 0,
    "ephemeral": 0,
    "missing": 0
  },
  "retired_artifacts": [],
  "entries": [
    {
      "id": "F-6",
      "stage": "E",
      "severity": "blocker",
      "category": "tool-bug",
      "title": "pin rewrites every candidate's ledger record: it demoted two library functions to wip and unlinked four linked matches",
      "tool": "calibrate_compiler.py"
    },
    {
      "id": "F-1",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "candidates finds only leaf functions, which cannot separate compiler builds on call or conversion idioms",
      "tool": "calibrate_compiler.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "major",
      "category": "doctrine-gap",
      "title": "the target is C++: a vtable dispatch is a virtual call, and K1 has no C++ idiom section",
      "function": "func_00159EE0"
    },
    {
      "id": "F-3",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "no C++ path in the toolkit: prepare, try, mark, gen_splat_yaml and configure assume a .c source compiled as C",
      "tool": "match.py"
    },
    {
      "id": "F-4",
      "stage": "E",
      "severity": "major",
      "category": "evidence-gap",
      "title": "float-to-int: not a build difference — no available build produces both the image's sq $ra frame and an inline cvt.w.s",
      "function": "func_00125C90"
    },
    {
      "id": "F-5",
      "stage": "E",
      "severity": "minor",
      "category": "false-signal",
      "title": "a failed probe compile left the previous object in place and the disassembly read as a result"
    }
  ]
}
```
