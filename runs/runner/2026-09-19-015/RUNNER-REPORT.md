# RUNNER-REPORT — 2026-09-19-015 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T12:14:45Z / 2026-09-19T12:25:20Z
- **Functions:** 12 attempted · 1 matched · 10 parked · 1 error
- **Cost:** $0.6606 · 14,577,849 tokens · $0.6606 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 70 | 99.3 | 1753531 | 0.110071 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.3 at wip/func_00152300/attempt-29.c |
| func_001525D0 | 36 | parked | 79 | 98.7 | 1737374 | 0.065532 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_0014EAB0 | 56 | parked | 40 | 96.8 | 916294 | 0.036849 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 96.8 at wip/func_0014EAB0/attempt-1.c |
| func_00151820 | 144 | matched | 53 | 100.0 | 1266329 | 0.054588 | marked from wip/func_00151820/attempt-53.c |
| func_00152380 | 116 | parked | 70 | 99.4 | 1709652 | 0.095504 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 161 | 98.7 | 3425249 | 0.096503 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_00172F60 | 264 | parked | 98 | 98.5 | 2529459 | 0.123759 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.5 at wip/func_00172F60/attempt-65.c |
| func_0016C720 | 88 | parked | 20 | 98.9 | 439473 | 0.015927 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.9 at wip/func_0016C720/attempt-3.c |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_00177D00 | 644 | parked | 10 | 69.7 | 367542 | 0.045357 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 69.7 at wip/func_00177D00/attempt-2.c |
| func_00159EE0 | 48 | parked | 10 | 98.3 | 216892 | 0.008312 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.3 at wip/func_00159EE0/attempt-1.c |
| func_0015D4E0 | 48 | parked | 10 | 98.3 | 216054 | 0.008240 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.3 at wip/func_0015D4E0/attempt-1.c |

## Batches

- batch 1: 1 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.77s; configure.py: rc=0 138.13s; check_build.py: rc=0 5.13s
- attempts per rung: deepseek-flash/none 27, deepseek-flash/high 39, deepseek-v4-pro/max 39

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
