# RUNNER-REPORT — 2026-09-19-003 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-19T02:53:28Z / 2026-09-19T02:56:09Z
- **Functions:** 12 attempted · 3 matched · 9 parked · 0 error
- **Cost:** $0.0759 · 4,757,023 tokens · $0.0253 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 65 | 97.8 | 1313475 | 0.017833 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 66 | 99.9 | 1371017 | 0.017952 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 16 | 80.0 | 297176 | 0.002253 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016FA50 | 40 | parked | 16 | - | 312122 | 0.002326 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_0016FA80 | 48 | parked | 19 | - | 372748 | 0.003019 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_001724D0 | 32 | parked | 8 | 35.0 | 162457 | 0.001826 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_001724F0 | 36 | parked | 10 | 50.7 | 207239 | 0.002133 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 50.7 at wip/func_001724F0/attempt-7.c |
| func_0016F790 | 184 | parked | 17 | - | 373586 | 0.006406 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself |
| func_001705E0 | 424 | parked | 9 | 63.7 | 270600 | 0.020807 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00172A40 | 60 | matched | 2 | 100.0 | 38974 | 0.000660 | marked from wip/func_00172A40/attempt-2.c |
| func_00172A80 | 24 | matched | 1 | 100.0 | 18945 | 0.000387 | marked from wip/func_00172A80/attempt-1.c |
| func_00172BF0 | 8 | matched | 1 | 100.0 | 18684 | 0.000305 | marked from wip/func_00172BF0/attempt-1.c |

## Batches

- batch 1: 3 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 56.43s; check_build.py: rc=0 1.56s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
