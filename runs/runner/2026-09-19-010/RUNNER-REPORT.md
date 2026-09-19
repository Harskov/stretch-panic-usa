# RUNNER-REPORT — 2026-09-19-010 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T08:01:57Z / 2026-09-19T08:09:15Z
- **Functions:** 12 attempted · 4 matched · 8 parked · 0 error
- **Cost:** $0.3773 · 9,441,317 tokens · $0.0943 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 20 | 99.2 | 504496 | 0.033974 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.2 at wip/func_00152300/attempt-3.c |
| func_00152600 | 36 | parked | 29 | 98.0 | 640104 | 0.026517 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.0 at wip/func_00152600/attempt-24.c |
| func_001525D0 | 36 | parked | 29 | 98.7 | 637440 | 0.026890 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_00152380 | 116 | parked | 20 | 99.4 | 492599 | 0.031961 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 115 | 98.7 | 2405433 | 0.060175 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 50 | 97.9 | 1278668 | 0.065559 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.9 at wip/func_00172F60/attempt-46.c |
| func_00166D90 | 80 | matched | 126 | 100.0 | 2708716 | 0.064054 | marked from wip/func_00166D90/attempt-129.c |
| func_00151820 | 144 | parked | 10 | 95.6 | 243631 | 0.013746 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 95.6 at wip/func_00151820/attempt-1.c |
| func_00151530 | 208 | parked | 10 | 62.9 | 469920 | 0.053261 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 62.9 at wip/func_00151530/attempt-6.c |
| func_001514A0 | 44 | matched | 1 | 100.0 | 20183 | 0.000416 | marked from wip/func_001514A0/attempt-1.c |
| func_00151460 | 52 | matched | 1 | 100.0 | 20285 | 0.000441 | marked from wip/func_00151460/attempt-1.c |
| func_00151060 | 8 | matched | 1 | 100.0 | 19842 | 0.000280 | marked from wip/func_00151060/attempt-1.c |

## Batches

- batch 1: 4 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 58.67s; check_build.py: rc=0 1.83s
- attempts per rung: deepseek-flash/none 28, deepseek-flash/high 29, deepseek-v4-pro/max 35

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
