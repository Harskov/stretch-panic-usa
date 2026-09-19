# RUNNER-REPORT — 2026-09-19-009 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T07:45:41Z / 2026-09-19T07:51:29Z
- **Functions:** 12 attempted · 3 matched · 8 parked · 1 error
- **Cost:** $0.2541 · 7,366,055 tokens · $0.0847 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152600 | 36 | parked | 19 | 97.9 | 418626 | 0.017845 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_001525D0 | 36 | parked | 19 | 98.7 | 417968 | 0.019036 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_00162900 | 36 | parked | 105 | 98.7 | 2181080 | 0.050752 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_00172F60 | 264 | parked | 40 | 97.6 | 1015274 | 0.053091 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.6 at wip/func_00172F60/attempt-6.c |
| func_00166D90 | 80 | parked | 117 | 99.9 | 2502091 | 0.056076 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.9 at wip/func_00166D90/attempt-21.c |
| func_00152500 | 196 | parked | 10 | 7.6 | 268104 | 0.021520 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 7.6 at wip/func_00152500/attempt-9.c |
| func_00152380 | 116 | parked | 10 | 99.4 | 249258 | 0.017238 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00152300 | 128 | parked | 10 | 99.2 | 254494 | 0.017731 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.2 at wip/func_00152300/attempt-3.c |
| func_001522E0 | 32 | matched | 1 | 100.0 | 19902 | 0.000368 | marked from wip/func_001522E0/attempt-1.c |
| func_00152030 | 8 | matched | 1 | 100.0 | 19629 | 0.000246 | marked from wip/func_00152030/attempt-1.c |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_001518B0 | 8 | matched | 1 | 100.0 | 19629 | 0.000240 | marked from wip/func_001518B0/attempt-1.c |

## Batches

- batch 1: 3 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.25s; configure.py: rc=0 58.64s; check_build.py: rc=0 0.59s
- attempts per rung: deepseek-flash/none 26, deepseek-flash/high 24, deepseek-v4-pro/max 30

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
