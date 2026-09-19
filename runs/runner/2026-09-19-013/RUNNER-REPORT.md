# RUNNER-REPORT — 2026-09-19-013 (dsstep 0.1.0)

- **Model:** deepseek:ladder · prompt ds-v1 `0d9bb441e13f`
- **Ladder:** deepseek-flash/none x3 -> deepseek-flash/high x3 -> deepseek-v4-pro/max xrest
- **Started / finished:** 2026-09-19T11:23:26Z / 2026-09-19T11:29:31Z
- **Functions:** 12 attempted · 1 matched · 10 parked · 1 error
- **Cost:** $0.4771 · 10,856,098 tokens · $0.4771 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00152300 | 128 | parked | 50 | 99.3 | 1255791 | 0.078917 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.3 at wip/func_00152300/attempt-29.c |
| func_001525D0 | 36 | parked | 59 | 98.7 | 1295757 | 0.049250 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 98.7 at wip/func_001525D0/attempt-14.c |
| func_0014EAB0 | 56 | parked | 20 | 96.8 | 459567 | 0.019884 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 96.8 at wip/func_0014EAB0/attempt-1.c |
| func_00151820 | 144 | parked | 37 | 95.6 | 888130 | 0.042998 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 95.6 at wip/func_00151820/attempt-1.c |
| func_00152380 | 116 | parked | 50 | 99.4 | 1224040 | 0.070484 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.4 at wip/func_00152380/attempt-4.c |
| func_00162900 | 36 | parked | 142 | 98.7 | 3003384 | 0.081502 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_00172F60 | 264 | parked | 78 | 98.5 | 2006092 | 0.099433 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_00178B30 | 648 | error | 0 | - | 0 | 0.000000 | prepare failed: ERROR: func_00178B30: asm not found in asm/*.s |
| func_0017EC80 | 208 | parked | 10 | 77.3 | 262763 | 0.017134 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 77.3 at wip/func_0017EC80/attempt-1.c |
| func_00159340 | 48 | parked | 10 | 78.3 | 214466 | 0.007130 | dsstep 0.1.0: 2 byte-identical resubmissions in a row on deepseek-v4-pro/max, the top of t |
| func_0016DC40 | 64 | matched | 1 | 100.0 | 20322 | 0.000418 | marked from wip/func_0016DC40/attempt-1.c |
| func_00172C00 | 84 | parked | 10 | 91.2 | 225786 | 0.009997 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 91.2 at wip/func_00172C00/attempt-1.c |

## Batches

- batch 1: 1 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.24s; configure.py: rc=0 57.19s; check_build.py: rc=0 1.88s
- attempts per rung: deepseek-flash/none 26, deepseek-flash/high 35, deepseek-v4-pro/max 35

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
