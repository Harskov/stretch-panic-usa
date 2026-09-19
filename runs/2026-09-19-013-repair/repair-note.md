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
function to `0x2A8` and demoted the `jal` target `0x00178B30` — which has its own prologue
(`addiu $sp, $sp, -0x70; sq $ra, 0x60($sp)`, called from `asm/game_01_107.s:614`) — to an
`alabel`. The ledger had the two functions right all along (sizes 20 and 648); nothing reconciles
the ledger against the emitted asm, so the disagreement only surfaced as a `prepare` failure.

## Fix

| # | Action | Evidence |
|---|---|---|
| 1 | `gen_splat_yaml.py --from-segments --force`, `configure.py --build` — the rebuild batch 016 never reached | `check.json` `unlinked_matches: ["func_0014EAB0"]`; ledger record score 100.0, `linked: true` |
| 2 | Two explicit sizes appended to `config/symbol_addrs.txt`: `func_00178B10` `size:0x14`, `func_00178B30` `size:0x288` | `asm/game_01_94.s:1012-1189` (`nonmatching func_00178B10, 0x2A8` … `alabel func_00178B30`); ledger sizes 20 and 648; `jal func_00178B30` at `asm/game_01_107.s:614` |
| 3 | `wip/func_00172F60/runner.json` `state: running` → `parked`, note recording the abort | Batch dead: no `state/runner.lock`, no `runs/runner/2026-09-19-016/`, no `-016` record in `state/runner-steps.jsonl`; `select_batch.py:80` escalates only `state == "parked"` |

Nothing was unmarked. `diff_count` was 0 throughout, so no match was ever in question — the red
was a stale link, not a bad object.

## Result

- `check_build.py`: `OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800
  (5896192 bytes); regime full`. splat 81.4 s, build 34.7 s, 128 asm objects + 113 C objects.
- `func_00178B30` now emits `glabel func_00178B30` (`asm/game_01_95.s:1027`) and
  `match.py prepare` succeeds: `target.s` 162 instructions (648 bytes, the ledger's size),
  `target.o` 1892 bytes. This is the check that fails on the pre-fix tree.
- `func_00172F60` (best 98.5, `wip/func_00172F60/attempt-65.c`, 107 attempts) is back in
  `select_batch.py`'s escalation set, which is where a function over the 95 floor belongs.

Pre-fix copies: `~/symbol_addrs.pre-013.txt`, `~/runner-172F60.pre-013.json` (scratch, outside
the repo; both files are tracked, so `git show` is the durable record).

## Not done here

Neither `select_batch.py` (no handling for `running` or `error` runner states, F-3) nor dsstep's
`provider._post` (no retry or guard around the chunked read, F-1) was changed. Both are
remediation-lane work; F-1 is in the app, which is outside every target repository.
