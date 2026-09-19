# RUNNER-REPORT — 2026-09-19-005 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-19T03:13:56Z / 2026-09-19T03:16:21Z
- **Functions:** 12 attempted · 3 matched · 9 parked · 0 error
- **Cost:** $0.0718 · 5,485,266 tokens · $0.0239 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00172F60 | 264 | parked | 8 | 97.6 | 180584 | 0.003727 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00162900 | 36 | parked | 75 | 97.8 | 1516433 | 0.020482 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_001733C0 | 128 | matched | 10 | 100.0 | 216315 | 0.004030 | marked from wip/func_001733C0/attempt-10.c |
| func_00166D90 | 80 | parked | 77 | 99.9 | 1598365 | 0.020889 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 20 | 80.0 | 371218 | 0.002768 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016FA50 | 40 | parked | 20 | - | 385814 | 0.002776 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016FA80 | 48 | parked | 23 | - | 446810 | 0.003525 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00172CC0 | 68 | parked | 6 | 54.4 | 118011 | 0.001738 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016F790 | 184 | parked | 22 | - | 479119 | 0.008092 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00173C00 | 180 | matched | 1 | 100.0 | 20640 | 0.000802 | marked from wip/func_00173C00/attempt-1.c |
| func_001741B0 | 180 | matched | 1 | 100.0 | 20942 | 0.000847 | marked from wip/func_001741B0/attempt-1.c |
| func_00176BB0 | 96 | parked | 6 | 86.5 | 131015 | 0.002090 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |

## Batches

- batch 1: 3 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.24s; configure.py: rc=0 57.84s; check_build.py: rc=0 1.66s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
