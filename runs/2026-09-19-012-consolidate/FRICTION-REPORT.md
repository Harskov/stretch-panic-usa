# Friction Report — 2026-09-19-012-consolidate

**Job folder:** `2026-09-19-012-consolidate`  
**Log:** `friction-log.jsonl` (1 entry; opened 2026-09-19T08:48:35Z, exported 2026-09-19T09:00:35Z)  
**Skills build:** dsstep 0.1.0  
**Severity counts:** minor 1  

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
| Stage E EXECUTE | attested clear |
| Stage V SHIP | 1 entry + attested complete |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-1 — [minor / environment] device_bash bridge dropped mid-SHIP for ~3 calls; run_report.py had to be re-run *(amended)*

- **Stage:** Stage V SHIP | **Tool:** `-` | **Logged:** 2026-09-19T09:00:03Z
- **Observed (fact):** run_report.py --repo targets/stretch-panic-usa --run 2026-09-19-012-consolidate --what-changed '<~1700-char paragraph>' returned 'Device did not respond within 190s' with timeout_ms 180000; RUN-REPORT.md was not written. The two following calls failed with 'not connected to the bridge'; the third, after sleep 20, succeeded. The ledger at this point holds 2027 function records.
- **Expected:** run_report.py finishes inside the 180 s cap; the bridge stays up across calls.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** The bridge dropped; the script is not implicated. Re-run on the same run folder and the same 2027-record ledger, timed: rc=0 in 0 s, 'RUN-REPORT.md written: 56 lines'. The first call's 190 s was the bridge failing to answer, and the two 'not connected' calls that followed are the same outage; a sleep 20 restored it. Nothing to fix in run_report.py.
- **Repro:** `python3 skills/dps2-qa/scripts/run_report.py --repo targets/stretch-panic-usa --run 2026-09-19-012-consolidate`
- **Amended through the tool:** `hypothesis` at 2026-09-19T09:00:35Z (the timing probe disproved the first hypothesis (a slow whole-ledger scan)); `title` at 2026-09-19T09:00:35Z (the title named the wrong cause); `tool` at 2026-09-19T09:00:35Z (not a defect of run_report.py)

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-012-consolidate",
  "exported": "2026-09-19T09:00:35Z",
  "build": "dsstep 0.1.0",
  "entry_count": 1,
  "severity_counts": {
    "minor": 1
  },
  "stages": {
    "R": "attested clear",
    "S": "attested clear",
    "E": "attested clear",
    "V": "1 entry + attested complete",
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
      "id": "F-1",
      "stage": "V",
      "severity": "minor",
      "category": "environment",
      "title": "device_bash bridge dropped mid-SHIP for ~3 calls; run_report.py had to be re-run",
      "tool": "-"
    }
  ]
}
```
