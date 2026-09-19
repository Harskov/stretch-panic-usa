# RUNNER-REPORT — 2026-09-19-012 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T11:17:04Z / 2026-09-19T11:23:16Z
- **Functions:** 12 attempted · 4 matched · 8 parked · 0 error
- **Cost:** $0.4159 · 9,435,788 tokens · $0.1040 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 40 | 99.3 | 1003100 | 0.063276 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.3 at wip/func_00152300/attempt-29.c |
| func_001525D0 | 36 | parked | 49 | 98.7 | 1075817 | 0.041663 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_00151820 | 144 | parked | 27 | 95.6 | 648301 | 0.033286 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 95.6 at wip/func_00151820/attempt-1.c |
| func_00152380 | 116 | parked | 40 | 99.4 | 978460 | 0.056879 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 135 | 98.7 | 2852681 | 0.077471 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 70 | 98.5 | 1804498 | 0.091690 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.5 at wip/func_00172F60/attempt-65.c |
| func_0014F060 | 100 | matched | 11 | 100.0 | 273755 | 0.018122 | marked from wip/func_0014F060/attempt-11.c |
| func_0014EAB0 | 56 | parked | 10 | 96.8 | 231131 | 0.010464 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 96.8 at wip/func_0014EAB0/attempt-1.c |
| func_0014EA70 | 56 | matched | 9 | 100.0 | 202802 | 0.008745 | marked from wip/func_0014EA70/attempt-9.c |
| func_0014E460 | 44 | matched | 5 | 100.0 | 108248 | 0.001878 | marked from wip/func_0014E460/attempt-5.c |
| func_0014E120 | 112 | parked | 10 | 84.5 | 236022 | 0.011915 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 84.5 at wip/func_0014E120/attempt-2.c |
| func_0014DF80 | 112 | matched | 1 | 100.0 | 20973 | 0.000536 | marked from wip/func_0014DF80/attempt-1.c |

## Batches

- batch 1: 4 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 57.19s; check_build.py: rc=0 1.87s
- attempts per rung: deepseek-flash/none 28, deepseek-flash/high 33, deepseek-v4-pro/max 35

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
