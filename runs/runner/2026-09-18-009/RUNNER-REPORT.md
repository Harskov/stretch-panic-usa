# RUNNER-REPORT — 2026-09-18-009 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-18T22:49:29Z / 2026-09-18T22:52:00Z
- **Functions:** 12 attempted · 6 matched · 6 parked · 0 error
- **Cost:** $0.0385 · 3,066,389 tokens · $0.0064 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 59 | 97.8 | 1199634 | 0.016356 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.8 at wip/func_00162900/attempt-8.c |
| func_00166D90 | 80 | parked | 53 | 99.9 | 1105778 | 0.014546 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 10 | 80.0 | 186113 | 0.001480 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016F790 | 184 | parked | 3 | - | 63858 | 0.001462 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016F9F0 | 8 | matched | 2 | 100.0 | 36478 | 0.000331 | marked from wip/func_0016F9F0/attempt-2.c |
| func_0016FA00 | 12 | matched | 1 | 100.0 | 18093 | 0.000220 | marked from wip/func_0016FA00/attempt-1.c |
| func_0016FA10 | 8 | matched | 1 | 100.0 | 17997 | 0.000205 | marked from wip/func_0016FA10/attempt-1.c |
| func_0016FA20 | 12 | matched | 1 | 100.0 | 18054 | 0.000215 | marked from wip/func_0016FA20/attempt-1.c |
| func_0016FA30 | 8 | matched | 1 | 100.0 | 17988 | 0.000201 | marked from wip/func_0016FA30/attempt-1.c |
| func_0016FA40 | 8 | matched | 1 | 100.0 | 17980 | 0.000200 | marked from wip/func_0016FA40/attempt-1.c |
| func_0016FA50 | 40 | parked | 10 | - | 201584 | 0.001651 | dsstep 0.1.0: attempt cap 10 reached |
| func_0016FA80 | 48 | parked | 9 | - | 182832 | 0.001640 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.22s; configure.py: rc=0 54.92s; check_build.py: rc=0 1.51s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
