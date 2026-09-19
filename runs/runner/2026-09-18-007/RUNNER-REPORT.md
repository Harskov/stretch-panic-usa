# RUNNER-REPORT — 2026-09-18-007 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-18T22:33:27Z / 2026-09-18T22:36:20Z
- **Functions:** 12 attempted · 6 matched · 6 parked · 0 error
- **Cost:** $0.0362 · 2,404,425 tokens · $0.0060 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 47 | 97.8 | 949305 | 0.013048 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.8 at wip/func_00162900/attempt-8.c |
| func_00166D90 | 80 | parked | 42 | 99.9 | 871222 | 0.011667 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 6 | 80.0 | 112071 | 0.000965 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016D510 | 68 | parked | 9 | 17.7 | 209354 | 0.007102 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016D660 | 8 | matched | 1 | 100.0 | 17982 | 0.000200 | marked from wip/func_0016D660/attempt-1.c |
| func_0016D670 | 8 | matched | 1 | 100.0 | 17982 | 0.000200 | marked from wip/func_0016D670/attempt-1.c |
| func_0016D680 | 8 | matched | 1 | 100.0 | 17978 | 0.000200 | marked from wip/func_0016D680/attempt-1.c |
| func_0016D690 | 24 | matched | 1 | 100.0 | 18212 | 0.000263 | marked from wip/func_0016D690/attempt-1.c |
| func_0016D6B0 | 48 | parked | 4 | 56.5 | 77752 | 0.001085 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016D900 | 8 | matched | 2 | 100.0 | 36196 | 0.000306 | marked from wip/func_0016D900/attempt-2.c |
| func_0016D9F0 | 44 | parked | 3 | - | 58248 | 0.000888 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016DC30 | 8 | matched | 1 | 100.0 | 18123 | 0.000247 | marked from wip/func_0016DC30/attempt-1.c |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.22s; configure.py: rc=0 56.16s; check_build.py: rc=0 1.44s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
