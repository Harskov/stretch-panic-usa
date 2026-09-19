# RUNNER-REPORT — 2026-09-19-007 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T07:19:52Z / 2026-09-19T07:23:54Z
- **Functions:** 12 attempted · 8 matched · 4 parked · 0 error
- **Cost:** $0.1092 · 4,800,670 tokens · $0.0137 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 87 | 98.7 | 1779664 | 0.034368 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_00162900/attempt-90.c |
| func_00172F60 | 264 | parked | 20 | 97.6 | 490849 | 0.022497 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.6 at wip/func_00172F60/attempt-6.c |
| func_00166D90 | 80 | parked | 97 | 99.9 | 2043244 | 0.033237 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.9 at wip/func_00166D90/attempt-21.c |
| func_00179870 | 64 | matched | 3 | 100.0 | 61833 | 0.000880 | marked from wip/func_00179870/attempt-3.c |
| func_00179CF0 | 8 | matched | 1 | 100.0 | 19587 | 0.000234 | marked from wip/func_00179CF0/attempt-1.c |
| func_00179D00 | 8 | matched | 1 | 100.0 | 19587 | 0.000234 | marked from wip/func_00179D00/attempt-1.c |
| func_00179D10 | 8 | matched | 2 | 100.0 | 39318 | 0.000341 | marked from wip/func_00179D10/attempt-2.c |
| func_00179D20 | 8 | matched | 1 | 100.0 | 19396 | 0.000205 | marked from wip/func_00179D20/attempt-1.c |
| func_00179D30 | 72 | matched | 2 | 100.0 | 41586 | 0.000860 | marked from wip/func_00179D30/attempt-2.c |
| func_00179D80 | 104 | parked | 10 | 60.1 | 244131 | 0.015219 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 60.1 at wip/func_00179D80/attempt-9.c |
| func_00179DF0 | 48 | matched | 1 | 100.0 | 20506 | 0.000521 | marked from wip/func_00179DF0/attempt-1.c |
| func_00179E80 | 56 | matched | 1 | 100.0 | 20969 | 0.000613 | marked from wip/func_00179E80/attempt-1.c |

## Batches

- batch 1: 8 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.22s; configure.py: rc=0 65.71s; check_build.py: rc=0 1.73s
- attempts per rung: deepseek-flash/none 24, deepseek-flash/high 12, deepseek-v4-pro/max 16

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
