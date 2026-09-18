# RUNNER-REPORT — 2026-09-18-004 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `bdbe8fe7c46f`
- **Started / finished:** 2026-09-18T19:25:00Z / 2026-09-18T19:27:31Z
- **Functions:** 12 attempted · 8 matched · 4 parked · 0 error
- **Cost:** $0.0285 · 2,050,588 tokens · $0.0036 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 33 | 97.8 | 660455 | 0.009011 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00168630 | 76 | matched | 14 | 100.0 | 272578 | 0.002973 | marked from wip/func_00168630/attempt-14.c |
| func_00159820 | 52 | parked | 23 | 98.2 | 468531 | 0.007083 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 22 | 99.9 | 446281 | 0.005855 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 99.9 at wip/func_00166D90/attempt-21.c |
| func_0015D540 | 8 | matched | 1 | 100.0 | 17110 | 0.000201 | marked from wip/func_0015D540/attempt-1.c |
| func_0015D550 | 164 | parked | 4 | 53.9 | 82493 | 0.002130 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00168E20 | 8 | matched | 1 | 100.0 | 17378 | 0.000241 | marked from wip/func_00168E20/attempt-1.c |
| func_00169590 | 8 | matched | 1 | 100.0 | 17224 | 0.000218 | marked from wip/func_00169590/attempt-1.c |
| func_001696B0 | 8 | matched | 1 | 100.0 | 17241 | 0.000221 | marked from wip/func_001696B0/attempt-1.c |
| func_001696C0 | 8 | matched | 1 | 100.0 | 17098 | 0.000199 | marked from wip/func_001696C0/attempt-1.c |
| func_00169A40 | 8 | matched | 1 | 100.0 | 17098 | 0.000199 | marked from wip/func_00169A40/attempt-1.c |
| func_00169A50 | 8 | matched | 1 | 100.0 | 17101 | 0.000200 | marked from wip/func_00169A50/attempt-1.c |

## Batches

- batch 1: 8 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.25s; configure.py: rc=0 54.54s; check_build.py: rc=0 1.26s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
