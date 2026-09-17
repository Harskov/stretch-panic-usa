# Friction Report — 2026-09-17-007-match-batch

**Job folder:** `2026-09-17-007-match-batch`  
**Log:** `friction-log.jsonl` (3 entries; opened 2026-09-17T14:04:11Z, exported 2026-09-17T14:17:45Z)  
**Skills build:** 2026-09-17-007-match-batch  
**Severity counts:** major 1, minor 2  

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
| Stage R RESUME | attested clear |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 3 entries + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-2 — [major / doc-gap] no C form defined for VU0 macro-mode vector ops (lqc2/vadd.xyz/sqc2)

- **Stage:** Stage E EXECUTE | **Function:** `func_001636C0` | **Tool:** `lint_c.py` | **Logged:** 2026-09-17T14:15:49Z
- **Observed (fact):** func_001636C0 and func_00165800 (game_01) both contain addiu v1,a0,0xA0; addiu v0,a0,0xB0; lqc2 vf1,0(v1); lqc2 vf2,0(v0); vadd.xyz vf1,vf1,vf2; sqc2 vf1,0(v1). K1 has no entry for COP2 macro mode; inline asm is barred as final C; mwccps2 2.3.3 refused an asm{} block using C pointer operands (illegal operand). Parked at 9.9 and 85.3.
- **Expected:** K1 names the source form the pinned compiler turns into these ops (an intrinsic, a header of inline-asm helpers, or an asm-function policy) and lint's stance on it
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the shipping source used Sony's libvu0-style inline helpers or MW's asm functions; without a defined form every VU0-using function in game_01 parks

### F-1 — [minor / tool-bug] m2c has no reading for VU0 macro-mode instructions

- **Stage:** Stage E EXECUTE | **Function:** `func_001636C0` | **Tool:** `match.py` | **Logged:** 2026-09-17T14:09:24Z
- **Observed (fact):** wip/func_001636C0/m2c.c: four M2C_ERROR rows for lqc2 $vf1, lqc2 $vf2, vadd.xyz, sqc2; target.s 20 insns
- **Expected:** a seed C body or a documented intrinsic mapping
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** m2c's mipsee target does not model COP2 macro-mode loads/stores; the pinned mwccps2 2.3.3 likely needs inline asm or a compiler intrinsic for vadd

### F-3 — [minor / doc-gap] 1.0f/(float)n compiles with the cvt.s.w after the constant; target converts first

- **Stage:** Stage E EXECUTE | **Function:** `func_00163B60` | **Logged:** 2026-09-17T14:15:49Z
- **Observed (fact):** func_00163B60 attempt-11 (95.3) and func_00165800 attempt-1: target lwc1 f0,n; cvt.s.w f1,f0; lui v1,0x3f80; mtc1 v1,f0; div.s f0,f0,f1 — compiled lwc1 f1,n; lui; mtc1 f0; nop; cvt.s.w f1,f1; div.s. Float local, implicit cast, -1.0f/n, double literal (calls dpdiv), permuter 120 s: unchanged
- **Expected:** a K1 note on the source shape that makes the pinned 2.3.3 build convert before materialising the constant
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** the conversion sat in its own expression whose result the compiler kept distinct — a helper or a macro taking the int, or a different flag on that source file

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-17-007-match-batch",
  "exported": "2026-09-17T14:17:45Z",
  "build": "2026-09-17-007-match-batch",
  "entry_count": 3,
  "severity_counts": {
    "major": 1,
    "minor": 2
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "3 entries + attested complete",
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
      "id": "F-2",
      "stage": "E",
      "severity": "major",
      "category": "doc-gap",
      "title": "no C form defined for VU0 macro-mode vector ops (lqc2/vadd.xyz/sqc2)",
      "tool": "lint_c.py",
      "function": "func_001636C0"
    },
    {
      "id": "F-1",
      "stage": "E",
      "severity": "minor",
      "category": "tool-bug",
      "title": "m2c has no reading for VU0 macro-mode instructions",
      "tool": "match.py",
      "function": "func_001636C0"
    },
    {
      "id": "F-3",
      "stage": "E",
      "severity": "minor",
      "category": "doc-gap",
      "title": "1.0f/(float)n compiles with the cvt.s.w after the constant; target converts first",
      "function": "func_00163B60"
    }
  ]
}
```
