# RUNNER-REPORT — 2026-09-18-005 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-18T21:49:29Z / 2026-09-18T21:52:14Z
- **Functions:** 12 attempted · 8 matched · 4 parked · 0 error
- **Cost:** $0.0365 · 2,524,253 tokens · $0.0046 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 35 | 97.8 | 698356 | 0.009670 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00159820 | 52 | matched | 31 | 100.0 | 638231 | 0.009528 | marked from wip/func_00159820/attempt-31.c |
| func_00166D90 | 80 | parked | 30 | 99.9 | 617280 | 0.008350 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00169A60 | 8 | matched | 1 | 100.0 | 17963 | 0.000197 | marked from wip/func_00169A60/attempt-1.c |
| func_0015D550 | 164 | parked | 10 | 53.9 | 215285 | 0.005039 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00169A70 | 8 | matched | 2 | 100.0 | 36070 | 0.000287 | marked from wip/func_00169A70/attempt-2.c |
| func_00169A80 | 8 | matched | 1 | 100.0 | 17968 | 0.000198 | marked from wip/func_00169A80/attempt-1.c |
| func_0016B680 | 8 | matched | 1 | 100.0 | 17968 | 0.000198 | marked from wip/func_0016B680/attempt-1.c |
| func_0016B690 | 8 | matched | 1 | 100.0 | 17983 | 0.000203 | marked from wip/func_0016B690/attempt-1.c |
| func_0016B6A0 | 8 | matched | 1 | 100.0 | 18004 | 0.000204 | marked from wip/func_0016B6A0/attempt-1.c |
| func_0016BDF0 | 24 | matched | 1 | 100.0 | 18250 | 0.000276 | marked from wip/func_0016BDF0/attempt-1.c |
| func_0016BE10 | 108 | parked | 10 | 93.5 | 210895 | 0.002331 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 93.5 at wip/func_0016BE10/attempt-2.c |

## Batches

- batch 1: 8 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.23s; configure.py: rc=0 58.19s; check_build.py: rc=0 1.37s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
