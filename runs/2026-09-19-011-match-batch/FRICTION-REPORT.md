# Friction Report — 2026-09-19-011-match-batch

**Job folder:** `2026-09-19-011-match-batch`  
**Log:** `friction-log.jsonl` (2 entries; opened 2026-09-19T06:27:15Z, exported 2026-09-19T06:44:22Z)  
**Skills build:** dsstep ladder + S6 match-batch 2026-09-19  
**Severity counts:** minor 2  

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
| Stage E EXECUTE | 1 entry + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-1 — [minor / doctrine-gap] out-of-run change to config/policy.json found uncommitted at RESUME (same as fate run 014 F-1)

- **Stage:** Stage R RESUME | **Logged:** 2026-09-19T06:27:15Z
- **Observed (fact):** git status showed ' M config/policy.json' (DeepSeek runner ladder + usd_cap_per_function 0.25->2.5, usd_cap_per_queue 10->50, changed outside any run). git_sync.sh pull refuses a dirty tree, so it was committed first as cd0b1d8.
- **Expected:** dps2-step RESUME has a rule for uncommitted runner batches and none for an out-of-run edit to config/.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** Same defect as fate-unlimited-codes-jp run 2026-09-19-014 F-1; filed on both targets because the fix belongs in the shared RESUME doctrine, not in one repo.

### F-2 — [minor / tool-gap] a compile error from match.py try is unreadable: wibo thread chatter floods the compiler diagnostic

- **Stage:** Stage E EXECUTE | **Tool:** `match.py` | **Logged:** 2026-09-19T06:41:41Z
- **Observed (fact):** match.py try on func_0016F790 printed 'compile error (attempt #8)' followed by ~10 lines of '[thread 7] GetCurrentThreadId() -> 7' and nothing else; the actual diagnostic (mwccps2 'illegal operand' at 'lqc2 vf2, 0(arg1)') only appeared after re-running the pinned compile command by hand and piping through grep -v GetCurrentThreadId. Two tool calls were spent recovering an error message the tool already had.
- **Expected:** try prints the compiler's diagnostic lines on a compile error.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** wibo emits GetCurrentThreadId tracing on stdout/stderr and match.py tails the combined stream, so the tail window fills with chatter. Filtering lines matching 'GetCurrentThreadId' / '^\[thread ' before tailing, or preferring the lines between '### mwccps2.exe Compiler:' markers, would fix it.
- **Repro:** `python3 skills/dps2-toolkit/scripts/match.py --repo targets/stretch-panic-usa try func_0016F790 wip/func_0016F790/attempt-9.c`

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-011-match-batch",
  "exported": "2026-09-19T06:44:22Z",
  "build": "dsstep ladder + S6 match-batch 2026-09-19",
  "entry_count": 2,
  "severity_counts": {
    "minor": 2
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "1 entry + attested complete",
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
      "id": "F-1",
      "stage": "R",
      "severity": "minor",
      "category": "doctrine-gap",
      "title": "out-of-run change to config/policy.json found uncommitted at RESUME (same as fate run 014 F-1)"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "minor",
      "category": "tool-gap",
      "title": "a compile error from match.py try is unreadable: wibo thread chatter floods the compiler diagnostic",
      "tool": "match.py"
    }
  ]
}
```
