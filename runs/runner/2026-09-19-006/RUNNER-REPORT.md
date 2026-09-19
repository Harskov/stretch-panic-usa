# RUNNER-REPORT — 2026-09-19-006 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-19T03:20:15Z / 2026-09-19T03:22:51Z
- **Functions:** 12 attempted · 3 matched · 9 parked · 0 error
- **Cost:** $0.0743 · 5,920,070 tokens · $0.0248 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 77 | 97.8 | 1554328 | 0.020950 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00172F60 | 264 | parked | 10 | 97.6 | 223904 | 0.004483 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 87 | 99.9 | 1815833 | 0.023458 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 22 | 80.0 | 408239 | 0.003026 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016FA50 | 40 | parked | 22 | - | 422660 | 0.003001 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016FA80 | 48 | parked | 25 | - | 483842 | 0.003779 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00172CC0 | 68 | parked | 16 | 54.4 | 331261 | 0.004293 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 54.4 at wip/func_00172CC0/attempt-2.c |
| func_0016F790 | 184 | parked | 24 | - | 520692 | 0.008738 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_00176C10 | 76 | parked | 4 | 85.1 | 84182 | 0.001445 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00176F30 | 8 | matched | 1 | 100.0 | 19292 | 0.000397 | marked from wip/func_00176F30/attempt-1.c |
| func_00176F40 | 8 | matched | 1 | 100.0 | 18865 | 0.000333 | marked from wip/func_00176F40/attempt-1.c |
| func_00176F50 | 8 | matched | 2 | 100.0 | 36972 | 0.000366 | marked from wip/func_00176F50/attempt-2.c |

## Batches

- batch 1: 3 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.24s; configure.py: rc=0 59.13s; check_build.py: rc=0 1.69s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
