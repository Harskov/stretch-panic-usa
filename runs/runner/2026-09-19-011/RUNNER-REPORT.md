# RUNNER-REPORT — 2026-09-19-011 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T11:09:54Z / 2026-09-19T11:16:38Z
- **Functions:** 12 attempted · 2 matched · 9 parked · 1 error
- **Cost:** $0.3757 · 8,477,992 tokens · $0.1879 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 30 | 99.3 | 752854 | 0.048054 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.3 at wip/func_00152300/attempt-29.c |
| func_00152600 | 36 | matched | 36 | 100.0 | 789058 | 0.030590 | marked from wip/func_00152600/attempt-36.c |
| func_001525D0 | 36 | parked | 39 | 98.7 | 857029 | 0.034542 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_00151820 | 144 | parked | 17 | 95.6 | 405014 | 0.022312 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_00152380 | 116 | parked | 30 | 99.4 | 734603 | 0.044124 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 125 | 98.7 | 2628645 | 0.068709 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 60 | 98.2 | 1542366 | 0.078728 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.2 at wip/func_00172F60/attempt-58.c |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_001502A0 | 140 | parked | 10 | 84.9 | 247717 | 0.014910 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 84.9 at wip/func_001502A0/attempt-5.c |
| func_0014F060 | 100 | parked | 10 | 99.0 | 252621 | 0.017748 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.0 at wip/func_0014F060/attempt-3.c |
| func_0014ECF0 | 116 | parked | 10 | 70.1 | 247819 | 0.015619 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 70.1 at wip/func_0014ECF0/attempt-8.c |
| func_0014EAF0 | 56 | matched | 1 | 100.0 | 20266 | 0.000401 | marked from wip/func_0014EAF0/attempt-1.c |

## Batches

- batch 1: 2 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.24s; configure.py: rc=0 66.9s; check_build.py: rc=0 1.76s
- attempts per rung: deepseek-flash/none 28, deepseek-flash/high 31, deepseek-v4-pro/max 36

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
