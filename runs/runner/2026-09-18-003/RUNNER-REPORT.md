# RUNNER-REPORT — 2026-09-18-003 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `bdbe8fe7c46f`
- **Started / finished:** 2026-09-18T17:28:31Z / 2026-09-18T17:31:49Z
- **Functions:** 12 attempted · 6 matched · 6 parked · 0 error
- **Cost:** $0.0296 · 1,902,061 tokens · $0.0049 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 31 | 97.8 | 624278 | 0.008535 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.8 at wip/func_00162900/attempt-8.c |
| func_00159820 | 52 | parked | 14 | 98.2 | 282635 | 0.004428 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 12 | 99.0 | 239656 | 0.003387 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00162870 | 136 | parked | 10 | 75.9 | 211449 | 0.005170 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0015B500 | 52 | matched | 6 | 100.0 | 119122 | 0.002066 | marked from wip/func_0015B500/attempt-6.c |
| func_0015BA00 | 120 | matched | 2 | 100.0 | 38176 | 0.000913 | marked from wip/func_0015BA00/attempt-2.c |
| func_00160940 | 132 | parked | 6 | 90.3 | 119406 | 0.001819 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_001683E0 | 8 | matched | 1 | 100.0 | 17629 | 0.000279 | marked from wip/func_001683E0/attempt-1.c |
| func_00168630 | 76 | parked | 9 | 98.7 | 179038 | 0.002095 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0015D510 | 8 | matched | 1 | 100.0 | 17809 | 0.000306 | marked from wip/func_0015D510/attempt-1.c |
| func_0015D520 | 8 | matched | 1 | 100.0 | 17805 | 0.000305 | marked from wip/func_0015D520/attempt-1.c |
| func_0015D530 | 8 | matched | 2 | 100.0 | 35058 | 0.000342 | marked from wip/func_0015D530/attempt-2.c |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.21s; configure.py: rc=0 51.23s; check_build.py: rc=0 1.2s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
