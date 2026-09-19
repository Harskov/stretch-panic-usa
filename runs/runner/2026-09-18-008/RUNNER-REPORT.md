# RUNNER-REPORT — 2026-09-18-008 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `e23a92141f1b`
- **Started / finished:** 2026-09-18T22:43:40Z / 2026-09-18T22:46:07Z
- **Functions:** 12 attempted · 6 matched · 6 parked · 0 error
- **Cost:** $0.0374 · 2,795,376 tokens · $0.0062 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 49 | 97.8 | 987275 | 0.013551 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00166D90 | 80 | parked | 51 | 99.9 | 1066599 | 0.014082 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016BEB0 | 24 | parked | 8 | 80.0 | 149092 | 0.001223 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016D6B0 | 48 | parked | 8 | 56.5 | 155508 | 0.001971 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016DC80 | 80 | matched | 2 | 100.0 | 38271 | 0.000597 | marked from wip/func_0016DC80/attempt-2.c |
| func_0016DCD0 | 20 | matched | 1 | 100.0 | 18385 | 0.000289 | marked from wip/func_0016DCD0/attempt-1.c |
| func_0016D9F0 | 44 | parked | 10 | 71.7 | 198268 | 0.002377 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_0016E390 | 12 | matched | 1 | 100.0 | 18313 | 0.000265 | marked from wip/func_0016E390/attempt-1.c |
| func_0016E740 | 20 | matched | 1 | 100.0 | 18424 | 0.000304 | marked from wip/func_0016E740/attempt-1.c |
| func_0016E760 | 20 | matched | 1 | 100.0 | 18381 | 0.000297 | marked from wip/func_0016E760/attempt-1.c |
| func_0016E780 | 8 | matched | 1 | 100.0 | 18162 | 0.000227 | marked from wip/func_0016E780/attempt-1.c |
| func_0016E9A0 | 156 | parked | 5 | 61.2 | 108698 | 0.002230 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |

## Batches

- batch 1: 6 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.22s; configure.py: rc=0 55.1s; check_build.py: rc=0 1.47s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
