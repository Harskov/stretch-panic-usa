# RUNNER-REPORT — 2026-09-19-008 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T07:29:03Z / 2026-09-19T07:33:08Z
- **Functions:** 12 attempted · 6 matched · 5 parked · 1 error
- **Cost:** $0.1484 · 5,588,957 tokens · $0.0247 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 97 | 98.7 | 2005464 | 0.044476 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 30 | 97.6 | 754292 | 0.038851 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.6 at wip/func_00172F60/attempt-6.c |
| func_00166D90 | 80 | parked | 107 | 99.9 | 2268313 | 0.042763 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.9 at wip/func_00166D90/attempt-21.c |
| func_0017A3D0 | 40 | matched | 1 | 100.0 | 21110 | 0.000580 | marked from wip/func_0017A3D0/attempt-1.c |
| func_0017A5B0 | 36 | matched | 1 | 100.0 | 20991 | 0.000562 | marked from wip/func_0017A5B0/attempt-1.c |
| func_0017A640 | 40 | matched | 1 | 100.0 | 20930 | 0.000552 | marked from wip/func_0017A640/attempt-1.c |
| func_0017A950 | 40 | matched | 1 | 100.0 | 20796 | 0.000532 | marked from wip/func_0017A950/attempt-1.c |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_0017BEE0 | 8 | matched | 1 | 100.0 | 20357 | 0.000409 | marked from wip/func_0017BEE0/attempt-1.c |
| func_00152630 | 16 | matched | 2 | 100.0 | 39377 | 0.000364 | marked from wip/func_00152630/attempt-2.c |
| func_00152600 | 36 | parked | 10 | 97.9 | 220591 | 0.009543 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.9 at wip/func_00152600/attempt-6.c |
| func_001525D0 | 36 | parked | 9 | 97.4 | 196736 | 0.009745 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.25s; configure.py: rc=0 61.46s; check_build.py: rc=0 1.91s
- attempts per rung: deepseek-flash/none 21, deepseek-flash/high 14, deepseek-v4-pro/max 21

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
