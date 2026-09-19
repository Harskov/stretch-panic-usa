# RUNNER-REPORT — 2026-09-18-006 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-18T22:24:58Z / 2026-09-18T22:27:22Z
- **Functions:** 12 attempted · 6 matched · 6 parked · 0 error
- **Cost:** $0.0269 · 2,040,513 tokens · $0.0045 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 37 | 97.8 | 736257 | 0.010142 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 34 | 99.9 | 698642 | 0.009416 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BE80 | 24 | matched | 1 | 100.0 | 18319 | 0.000285 | marked from wip/func_0016BE80/attempt-1.c |
| func_0016BEA0 | 8 | matched | 1 | 100.0 | 18204 | 0.000253 | marked from wip/func_0016BEA0/attempt-1.c |
| func_0016BEB0 | 24 | parked | 4 | 80.0 | 75050 | 0.000707 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016C260 | 56 | matched | 1 | 100.0 | 18759 | 0.000362 | marked from wip/func_0016C260/attempt-1.c |
| func_0016C710 | 8 | matched | 1 | 100.0 | 18187 | 0.000231 | marked from wip/func_0016C710/attempt-1.c |
| func_0016C780 | 8 | matched | 1 | 100.0 | 18110 | 0.000219 | marked from wip/func_0016C780/attempt-1.c |
| func_0016D0D0 | 20 | parked | 6 | 73.0 | 116428 | 0.001345 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016D240 | 8 | matched | 2 | 100.0 | 36306 | 0.000308 | marked from wip/func_0016D240/attempt-2.c |
| func_0016D250 | 76 | parked | 10 | 86.3 | 208191 | 0.002533 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 86.3 at wip/func_0016D250/attempt-2.c |
| func_0016D510 | 68 | parked | 4 | 17.7 | 78060 | 0.001120 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 54.14s; check_build.py: rc=0 1.46s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
