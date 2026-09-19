# Friction Report — 2026-09-19-013-repair

**Job folder:** `2026-09-19-013-repair`  
**Log:** `friction-log.jsonl` (3 entries; opened 2026-09-19T12:41:31Z, exported 2026-09-19T12:47:17Z)  
**Skills build:** run 2026-09-19-013-repair (S9) on stretch-panic-usa; splat 81.4s + build 34.7s; check.json ok  
**Severity counts:** major 3  

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
| Stage R RESUME | 1 entry + attested complete |
| Stage S SELECT | attested clear |
| Stage E EXECUTE | 2 entries + attested complete |
| Stage V SHIP | attested clear |
| Cross-cutting / environment | attested clear |

## Entries (most severe first)

### F-1 — [major / environment] external MatchRunner batch 2026-09-19-016 aborted on a truncated HTTP response, leaving check.json red and a function at state=running

- **Stage:** Stage R RESUME | **Function:** `func_00172F60` | **Tool:** `_external/dsstep/dsstep/provider.py` | **Logged:** 2026-09-19T12:41:31Z
- **Observed (fact):** dsstep 0.1.0 exited with http.client.IncompleteRead(0 bytes read) raised from provider.py:193 _post -> r.read() while on [6/12] func_00172F60 attempt 108. No runs/runner/2026-09-19-016/ and no 2026-09-19-016 record in state/runner-steps.jsonl (last record 2026-09-19-015 at 12:25:20Z). wip/func_00172F60/runner.json: state=running, batch_run_id=2026-09-19-016, batch_start_n=99, yet finished=2026-09-19T12:19:16Z. Batch 016 had already marked func_0014EAB0 matched score 100.0 linked=true but crashed before its end-of-batch rebuild, so check_build.py reports RED (UNLINKED) with unlinked_matches=[func_0014EAB0], diff_count 0, rebuilt_size == original_size 5896192.
- **Expected:** A provider transport error aborts the one function, the batch continues or ends cleanly, the end-of-batch rebuild runs, state/runner-steps.jsonl gains a 2026-09-19-016 record and no runner.json is left at state=running.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** dsstep's provider._post has no retry or exception guard around the chunked-response read, so a mid-stream disconnect from the provider propagates out of runner.do_function, past run_batch, to the CLI top level, skipping the batch's finalisation (record write and rebuild).

### F-2 — [major / false-signal] splat swallows func_00178B30 into the preceding jr-$t9 thunk, so every external batch wastes a slot on a prepare that cannot succeed

- **Stage:** Stage E EXECUTE | **Function:** `func_00178B30` | **Tool:** `gen_splat_yaml.py / select_batch.py` | **Logged:** 2026-09-19T12:42:51Z
- **Observed (fact):** asm/game_01_94.s:1012-1189 emits 'nonmatching func_00178B10, 0x2A8' / 'glabel func_00178B10' ... 'alabel func_00178B30' ... 'endlabel func_00178B10'. ledger/functions.jsonl has them as two functions: func_00178B10 addr 0x00178B10 size 20 status wip, func_00178B30 addr 0x00178B30 size 648 status asm. func_00178B10 is 5 instructions ending 'jr $t9; nop' at 0x00178B20 followed by 3 nop pads; func_00178B30 opens 'addiu $sp, $sp, -0x70; sq $ra, 0x60($sp)' — its own prologue. asm/game_01_107.s:614 has 'jal func_00178B30'. Neither symbol is in config/symbol_addrs.txt. wip/func_00178B30/runner.json: state=error, attempts 0, note 'prepare failed: ERROR: func_00178B30: asm not found in asm/*.s'; state/runner-steps.jsonl records errors:1 for batches 2026-09-19-013, -014 and -015, the same function each time.
- **Expected:** A ledger function has a glabel in asm/ and match.py prepare can cut its target.s; a function the batch selector cannot prepare is not re-selected batch after batch.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** splat's function-boundary heuristic ends a function at 'jr $ra' and does not treat 'jr $t9' (a virtual-dispatch thunk tail) as a return, so it runs func_00178B10 to the next detected boundary and demotes the known start 0x00178B30 to an alabel. Nothing reconciles the resulting asm against ledger/functions.jsonl, so the disagreement is invisible until prepare fails, and the selector has no 'unpreparable' state to park the function in.
- **Repro:** `grep -n 'alabel func_00178B30' targets/stretch-panic-usa/asm/game_01_94.s` — *as of the Logged time above, mid-run; re-run it on the committed tree before building on this entry's numbers.*

### F-3 — [major / tool-gap] a runner.json left at state=running by an aborted batch silently de-escalates a >=95 function out of select_batch's escalation set

- **Stage:** Stage E EXECUTE | **Function:** `func_00172F60` | **Tool:** `select_batch.py` | **Logged:** 2026-09-19T12:45:55Z
- **Observed (fact):** select_batch.py:78-80 reads only two runner states: skipped_runner = state=='matched', escalated = state=='parked' and best_score >= policy.runner.escalate_min_score (95). wip/func_00172F60/runner.json carries state='running' with best_score 98.5 (best_attempt wip/func_00172F60/attempt-65.c, 107 attempts), so it falls in neither set and ranks as an ordinary pool function despite clearing the escalation floor by 3.5 points. No other state value is handled; there is no 'error' handling either, which is why func_00178B30 (state=error) stayed selectable across batches 013, 014 and 015.
- **Expected:** A function whose external-lane attempts have stopped is either parked (and escalated when best_score >= escalate_min_score) or excluded; no runner state leaves a function silently mis-ranked.
- **Operator hypothesis — UNVERIFIED, verify against the artifacts before building on it:** select_batch.py was written against the states a batch that finishes normally produces (matched, parked) and never against the states an aborted or erroring batch leaves behind, so 'running' and 'error' both fall through to the default branch instead of being treated as stale-or-unusable.

## Suggested remediation order

Blockers and majors first, then whichever minor/papercut fixes share a root cause with them (fixing one layer often clears several entries — and mis-locating the layer often "fixes" none; see rule 2 of the consumption contract).

## Evidence accounting

Cited artifacts: 0 — 0 present, 0 inside a checkpoint archive, 0 on another filesystem, 0 ephemeral (declared or retired), 0 unexplained. Archives searched: no checkpoint archives in the job folder.

## Machine-readable summary

```json
{
  "job": "2026-09-19-013-repair",
  "exported": "2026-09-19T12:47:17Z",
  "build": "run 2026-09-19-013-repair (S9) on stretch-panic-usa; splat 81.4s + build 34.7s; check.json ok",
  "entry_count": 3,
  "severity_counts": {
    "major": 3
  },
  "stages": {
    "R": "1 entry + attested complete",
    "S": "attested clear",
    "E": "2 entries + attested complete",
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
      "severity": "major",
      "category": "environment",
      "title": "external MatchRunner batch 2026-09-19-016 aborted on a truncated HTTP response, leaving check.json red and a function at state=running",
      "tool": "_external/dsstep/dsstep/provider.py",
      "function": "func_00172F60"
    },
    {
      "id": "F-2",
      "stage": "E",
      "severity": "major",
      "category": "false-signal",
      "title": "splat swallows func_00178B30 into the preceding jr-$t9 thunk, so every external batch wastes a slot on a prepare that cannot succeed",
      "tool": "gen_splat_yaml.py / select_batch.py",
      "function": "func_00178B30"
    },
    {
      "id": "F-3",
      "stage": "E",
      "severity": "major",
      "category": "tool-gap",
      "title": "a runner.json left at state=running by an aborted batch silently de-escalates a >=95 function out of select_batch's escalation set",
      "tool": "select_batch.py",
      "function": "func_00172F60"
    }
  ]
}
```
