# Friction Report — 2026-09-17-003-calibrate

**Job folder:** `2026-09-17-003-calibrate`  
**Log:** `friction-log.jsonl` (5 entries; opened 2026-09-17T03:16:46Z, exported 2026-09-17T03:28:30Z)  
**Skills build:** mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0; wibo 1.2.0; objdiff v3.7.3; binutils-mips-ps2-decompals v0.10  
**Severity counts:** major 2, minor 2, papercut 1  

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

**Severity vocabulary:** **blocker** = stopped the pipeline or forced a forbidden action (e.g. a hand-edit); **major** = wrong output, missed detection, or substantial rework; **minor** = friction worked around within the sanctioned toolset; **papercut** = annoyance; no rework, but worth fixing.

**Category vocabulary:** **tool-bug** = a toolkit script or third-party tool (wibo, mwccps2, objdiff, splat, m2c, permuter) produced wrong output or crashed on sanctioned input; **tool-gap** = a needed capability is missing from the toolkit or the pinned toolchain; **toolchain-drift** = compiler, assembler, linker or objdiff behaviour differs from tools/manifest.json or from the doctrine in K1/K2 (a version that differs from the manifest, a preset that does not exist for the compiler); **doc-gap** = K1-K8, a SKILL.md or PROJECT-INSTRUCTIONS.md is silent or wrong where the run needed guidance; **doctrine-gap** = a step procedure in dps2-step is unclear or contradicts observed behaviour (a segment boundary found wrong, an entry state next_step.py misjudged); **evidence-gap** = a status, name, type or address could not be grounded in an artifact (no cited evidence for a name; objdiff could not read a compile that succeeded under wibo); **environment** = the VM bit: the ~3-minute device_bash cap, memory, network, the no-delete mount, host binutils without R5900; **operator-drift** = the operator caught itself outside the step: wanting to start a second step, a report over its length target, an unplanned subagent, instructed-looking re-checking of its own work; **false-signal** = a check false-positived or false-negatived (objdiff 100 but check.json red; check.json green with a wrong segment).

## Stage attestation

Silence is not evidence of frictionlessness: a stage is either attested (`clear-stage` recorded, with or without entries) or UNATTESTED (never examined — the operator never said). Entries without a `clear-stage` mean friction was seen and the review was not finished. UNATTESTED stages are holes in this report's coverage, not clean bills of health.

| Stage | Status |
|---|---|
| Stage R RESUME | 1 entry + attested complete |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 4 entries + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-3 — [major / tool-bug] calibrate: target.s includes macro.inc, which only S3 writes

- **Stage:** Stage E EXECUTE | **Tool:** `calibrate_compiler.py` | **Logged:** 2026-09-17T03:22:06Z
- **Observed (fact):** calibrate_compiler.py:219 emits '.include "macro.inc"' and 'glabel <fn>' into calibration/<fn>/target.s; include/macro.inc is written by gen_splat_yaml.py:215, which runs in S3 split-baseline, one step after S2. On a fresh target (stretch-panic-usa, include/ empty) all 8 cells failed at 'target assembly failed ... can't open macro.inc for reading' + 'unrecognized opcode glabel'; 0 rows reached objdiff
- **Expected:** S2 assembles its own target.s without an artifact from a later step
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the script was written against fate-unlimited-codes-jp, whose include/macro.inc already existed from S3 when S2 was re-run; the S2-before-S3 ordering was never exercised on a fresh repo
- **Repro:** `python3 skills/dps2-toolkit/scripts/calibrate_compiler.py --repo targets/stretch-panic-usa run --run 2026-09-17-003-calibrate --flagsets sweep`

### F-4 — [major / tool-bug] calibrate: failed target assembly leaves a 0-byte target.o that the resume then trusts

- **Stage:** Stage E EXECUTE | **Tool:** `calibrate_compiler.py` | **Logged:** 2026-09-17T03:23:44Z
- **Observed (fact):** After F-3 the assembler had written 8 zero-byte calibration/<fn>/target.o files. calibrate_compiler.py:342 guards reassembly with 'if not tgt_o.is_file()', so the next run skipped assembly and scored against the empty files: all 168 cells recorded score=null with objdiff_error 'Loading .../target.o ... Could not read file magic', and the sweep still reported '168/168 cells done' (exit 0)
- **Expected:** a failed assembly leaves no target.o, or the guard tests for a non-empty/valid object; a sweep in which no cell could be scored does not report done
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** assemble_s lets the assembler create the output file before it errors, and the is_file() guard plus the (function, compiler, flags, c_sha256) done-key make the poisoned state sticky across runs
- **Repro:** `truncate -s 0 calibration/<fn>/target.o; calibrate_compiler.py run --flagsets sweep`

### F-2 — [minor / doc-gap] K1 cheat sheet: lq/sq is not produced by a 16-byte struct copy

- **Stage:** Stage E EXECUTE | **Tool:** `knowledge/K1-ps2-mwcc-matching-primer.md` | **Logged:** 2026-09-17T03:21:30Z
- **Observed (fact):** K1 §8 row: 'lq/sq $r, off($p) | 128-bit copy (u128, a 16-byte struct copy)'. Probe with mwcps2-2.4-001213 -O4,p -lang c: 'typedef struct Q { unsigned int w[4]; } Q; void copyA(Q *d, Q *s){ d[0]=s[0]; d[1]=s[1]; }' compiles to 8x lwc1 + 8x swc1, no lq/sq; a 0x40-byte struct of those compiles to an 8-byte lw/sw loop. 'typedef __int128 q128; void f(q128 *d, q128 *s){ d[0]=s[0]; }' compiles to 'lq v1,0(a1); jr ra; sq v1,0(a0)'. Spellings accepted: __int128, unsigned __int128; rejected: long128, u_long128, __uint128_t
- **Expected:** the cheat sheet names the C construct that actually produces lq/sq, so an attempt.c for an lq/sq function is written right the first time
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** mwccps2 emits lq/sq only for types whose alignment it knows to be 16, which a struct of ints does not have; the K1 row was written from reading target asm rather than from a probe compile
- **Repro:** `wibo mwccps2.exe -c -O4,p -lang c probe.c; objdump -d -m mips:5900`

### F-5 — [minor / tool-bug] calibrate --rescore runs before targets are assembled and does not recompute bytes_equal

- **Stage:** Stage E EXECUTE | **Tool:** `calibrate_compiler.py` | **Logged:** 2026-09-17T03:24:20Z
- **Observed (fact):** The --rescore block is calibrate_compiler.py:311-328, the 'assemble targets once' loop is :338-346. With target.o absent, --rescore reported 'rescored 168 cell(s)' and every cell kept score=null with objdiff_error 'No such file or directory (os error 2)'; target.o (880 bytes) was assembled immediately afterwards in the same invocation. The rescore block also writes only r['score'], leaving bytes_equal=false and target_size=null from the poisoned pass — the two fields 'pin' counts
- **Expected:** --rescore assembles missing targets first and recomputes bytes_equal/target_size, so a rescored cell is as trustworthy as a freshly swept one
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** --rescore was written as a cheap objdiff-only repair for cells whose objdiff invocation failed, not for cells whose target object was itself bad
- **Repro:** `rm calibration/<fn>/target.o; calibrate_compiler.py run --flagsets sweep --rescore`

### F-1 — [papercut / environment] git_sync.sh pull skipped: working tree dirty

- **Stage:** Stage R RESUME | **Logged:** 2026-09-17T03:16:46Z
- **Observed (fact):** git_sync.sh $R pull printed 'pull skipped: working tree dirty — commit first (runner batches?)'; git status --short showed only ' M state/next-step.json', written by the next_step.py RESUME call itself
- **Expected:** RESUME's pull runs; a state file the RESUME call itself rewrote should not block it
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** git_sync.sh tests the whole tree for dirt; state/next-step.json is regenerated by every next_step.py invocation, so RESUME's own read makes the tree dirty before the pull

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-003-calibrate",
  "exported": "2026-09-17T03:28:30Z",
  "build": "mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0; wibo 1.2.0; objdiff v3.7.3; binutils-mips-ps2-decompals v0.10",
  "entry_count": 5,
  "severity_counts": {
    "major": 2,
    "minor": 2,
    "papercut": 1
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "4 entries + attested complete",
    "V": "attested clear",
    "X": "attested clear"
  },
  "artifact_accounting": {
    "total": 0,
    "present": 0,
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
      "category": "tool-bug",
      "title": "calibrate: target.s includes macro.inc, which only S3 writes",
      "tool": "calibrate_compiler.py"
    },
    {
      "id": "F-4",
      "stage": "E",
      "severity": "major",
      "category": "tool-bug",
      "title": "calibrate: failed target assembly leaves a 0-byte target.o that the resume then trusts",
      "tool": "calibrate_compiler.py"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "minor",
      "category": "doc-gap",
      "title": "K1 cheat sheet: lq/sq is not produced by a 16-byte struct copy",
      "tool": "knowledge/K1-ps2-mwcc-matching-primer.md"
    },
    {
      "id": "F-5",
      "stage": "E",
      "severity": "minor",
      "category": "tool-bug",
      "title": "calibrate --rescore runs before targets are assembled and does not recompute bytes_equal",
      "tool": "calibrate_compiler.py"
    },
    {
      "id": "F-1",
      "stage": "R",
      "severity": "papercut",
      "category": "environment",
      "title": "git_sync.sh pull skipped: working tree dirty"
    }
  ]
}
```
