# RUNNER-REPORT — 2026-09-19-014 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T11:29:40Z / 2026-09-19T11:37:04Z
- **Functions:** 12 attempted · 0 matched · 11 parked · 1 error
- **Cost:** $0.5762 · 12,783,683 tokens · n/a per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 60 | 99.3 | 1504018 | 0.095483 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.3 at wip/func_00152300/attempt-29.c |
| func_001525D0 | 36 | parked | 69 | 98.7 | 1517174 | 0.057731 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_0014EAB0 | 56 | parked | 30 | 96.8 | 689441 | 0.029111 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 96.8 at wip/func_0014EAB0/attempt-1.c |
| func_00151820 | 144 | parked | 47 | 95.6 | 1129900 | 0.052795 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 95.6 at wip/func_00151820/attempt-1.c |
| func_00152380 | 116 | parked | 60 | 99.4 | 1466131 | 0.082892 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 152 | 98.7 | 3226689 | 0.089694 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 88 | 98.5 | 2266786 | 0.111239 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.5 at wip/func_00172F60/attempt-65.c |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_0016C720 | 88 | parked | 10 | 98.9 | 220269 | 0.008465 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.9 at wip/func_0016C720/attempt-3.c |
| func_0016B6B0 | 120 | parked | 10 | 58.5 | 225175 | 0.009001 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 58.5 at wip/func_0016B6B0/attempt-5.c |
| func_00176F80 | 148 | parked | 10 | 93.6 | 240905 | 0.013668 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 93.6 at wip/func_00176F80/attempt-5.c |
| func_0016E790 | 400 | parked | 10 | 57.2 | 297195 | 0.026153 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 57.2 at wip/func_0016E790/attempt-6.c |

## Batches

- batch 1: 0 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.24s; configure.py: rc=0 57.73s; check_build.py: rc=0 1.89s
- attempts per rung: deepseek-flash/none 28, deepseek-flash/high 36, deepseek-v4-pro/max 46

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
