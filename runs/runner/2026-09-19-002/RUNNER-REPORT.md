# RUNNER-REPORT — 2026-09-19-002 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-19T02:46:40Z / 2026-09-19T02:50:14Z
- **Functions:** 12 attempted · 2 matched · 10 parked · 0 error
- **Cost:** $0.0775 · 4,697,741 tokens · $0.0387 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00170C00 | 20 | matched | 11 | 100.0 | 209800 | 0.001966 | marked from wip/func_00170C00/attempt-11.c |
| func_00162900 | 36 | parked | 63 | 97.8 | 1275505 | 0.017330 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 63 | 99.9 | 1311014 | 0.017143 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 14 | 80.0 | 260155 | 0.001995 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016FA50 | 40 | parked | 14 | - | 275276 | 0.002101 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016FA80 | 48 | parked | 17 | - | 335718 | 0.002767 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00170AB0 | 292 | parked | 7 | 70.3 | 157350 | 0.003567 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016F790 | 184 | parked | 13 | - | 287624 | 0.005046 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00170980 | 292 | parked | 9 | 90.5 | 208618 | 0.004915 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_001705E0 | 424 | parked | 6 | 39.3 | 193476 | 0.018045 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00172410 | 140 | matched | 1 | 100.0 | 20105 | 0.000737 | marked from wip/func_00172410/attempt-1.c |
| func_001724A0 | 36 | parked | 8 | 42.2 | 163100 | 0.001847 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |

## Batches

- batch 1: 2 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 54.89s; check_build.py: rc=0 1.53s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
