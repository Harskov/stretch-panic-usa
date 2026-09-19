# Run 2026-09-19-013-repair — repair

- Target: stretch-panic-usa
- Step: repair (S9) — proposed by next_step.py
- Started: 2026-09-19T12:41:20Z · Finished: 2026-09-19T12:46:52Z
- Commit: the commit whose message starts `run 2026-09-19-013-repair:` (git log --grep)

## What changed

- Ledger: no status changes.
- The red check was never a byte disagreement: check.json carried diff_count 0 and rebuilt_size == original_size == 5896192, and its reason was unlinked_matches [func_0014EAB0] — the external batch 2026-09-19-016 marked that function at score 100 and then died on a truncated HTTP response before its end-of-batch rebuild. The smallest action that fits that evidence is the re-split and rebuild, not an unmark, so nothing was unmarked and the ledger is untouched. Two further pieces of state the aborted batch left behind were repaired in the same pass. func_00178B30 had failed prepare in every batch since 2026-09-19-013 ('asm not found in asm/*.s') because splat merged it into func_00178B10: that function's tail is jr $t9, a virtual-dispatch thunk rather than a return, which the boundary heuristic does not end on, so it ran to 0x2A8 and demoted the jal target 0x00178B30 to an alabel even though the ledger had both functions at 20 and 648 bytes. Two explicit sizes in config/symbol_addrs.txt restore the split; the discriminating check is that prepare now cuts target.s at 162 instructions (648 bytes) where it previously exited 1. And wip/func_00172F60/runner.json was left at state=running, which matters because select_batch.py escalates only state=parked: a function parked at 98.5 after 107 attempts, well over the 95 floor, was ranking as ordinary pool work. It is parked now and escalated. The three friction entries are all about the external lane rather than the step: the app has no guard around its chunked response read (F-1), select_batch.py has no handling for the running or error states an aborted batch leaves (F-3), and nothing reconciles ledger/functions.jsonl against the labels splat actually emits (F-2). The proposal is S6 match-batch; the escalated func_00172F60 at 98.5 and the now-preparable func_00178B30 are both in that pool.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T12:45:08Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

# Repair note — run 2026-09-19-013-repair

## Cause

The external MatchRunner batch `2026-09-19-016` aborted mid-function on a truncated HTTP
response from the provider (`http.client.IncompleteRead(0 bytes read)`, raised out of
`_external/dsstep/dsstep/provider.py:193` `_post` → `r.read()`, while on `[6/12] func_00172F60`
attempt 108). The exception propagated past `runner.do_function` and `run_batch` to the CLI top
level, so the batch never ran its finalisation. It left three things behind:

1. `func_0014EAB0` marked `matched`, score 100.0, `linked: true` in `ledger/functions.jsonl`,
   with `src/game_01/func_0014EAB0.c` written — but no rebuild, so the YAML had no `c`
   subsegment for it. `check_build.py` reported `RED (UNLINKED)`, `unlinked_matches:
   ["func_0014EAB0"]`, `diff_count: 0`, `rebuilt_size == original_size == 5896192`. The image
   bytes were never wrong; the link was stale.
2. `wip/func_00172F60/runner.json` at `state: "running"`, `batch_run_id: "2026-09-19-016"`,
   contradicting its own `finished: 2026-09-19T12:19:16Z`.
3. No `runs/runner/2026-09-19-016/` and no `2026-09-19-016` record in `state/runner-steps.jsonl`
   (last record `2026-09-19-015` at 12:25:20Z).

A second, older defect was found while diagnosing and is repaired in the same re-split: every
external batch since `2026-09-19-013` reported `errors: 1`, always the same function.
`wip/func_00178B30/runner.json` gave the reason — `prepare failed: ERROR: func_00178B30: asm not
found in asm/*.s`. `func_00178B10` is a five-instruction virtual-dispatch thunk whose tail is
`jr $t9`, not `jr $ra`; splat's boundary heuristic does not treat that as a return, so it ran the

(first 25 lines; every row is in `repair-note.md`)

## Proposed next step

S6 match-batch — 1242 game function(s) still asm/wip; batch size 12
- note: external lane: 24 runner batch(es), 93 matched, $4.11 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

3 entries (major 3); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [major/environment] external MatchRunner batch 2026-09-19-016 aborted on a truncated HTTP response, leaving check.json red and a function at state=running
- F-2 [major/false-signal] splat swallows func_00178B30 into the preceding jr-$t9 thunk, so every external batch wastes a slot on a prepare that cannot succeed
- F-3 [major/tool-gap] a runner.json left at state=running by an aborted batch silently de-escalates a >=95 function out of select_batch's escalation set
