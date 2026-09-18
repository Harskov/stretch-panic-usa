# RUNNER-REPORT — 2026-09-18-002 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `bdbe8fe7c46f`
- **Started / finished:** 2026-09-18T16:43:15Z / 2026-09-18T16:46:45Z
- **Functions:** 12 attempted · 5 matched · 7 parked · 0 error
- **Cost:** $0.0234 · 1,447,833 tokens · $0.0047 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_00162900 | 36 | parked | 21 | 97.8 | 420682 | 0.005674 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.8 at wip/func_00162900/attempt-8.c |
| func_00162870 | 136 | parked | 4 | 75.9 | 82506 | 0.002258 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00159330 | 8 | matched | 1 | 100.0 | 17437 | 0.000256 | marked from wip/func_00159330/attempt-1.c |
| func_001627B0 | 192 | parked | 8 | 37.0 | 186317 | 0.004627 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00162790 | 28 | matched | 1 | 100.0 | 17785 | 0.000388 | marked from wip/func_00162790/attempt-1.c |
| func_00159820 | 52 | parked | 8 | 98.2 | 162955 | 0.002583 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_001668D0 | 196 | parked | 8 | 70.1 | 171148 | 0.002668 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00159E20 | 88 | matched | 1 | 100.0 | 18466 | 0.000539 | marked from wip/func_00159E20/attempt-1.c |
| func_00159F10 | 8 | matched | 1 | 100.0 | 17475 | 0.000261 | marked from wip/func_00159F10/attempt-1.c |
| func_00159F20 | 12 | matched | 2 | 100.0 | 35061 | 0.000348 | marked from wip/func_00159F20/attempt-2.c |
| func_00166D90 | 80 | parked | 6 | 99.0 | 119109 | 0.001757 | dsstep 0.1.0: 2 byte-identical resubmissions in a row; the model is repeating itself; best |
| func_00161980 | 92 | parked | 10 | 88.3 | 198892 | 0.002077 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 88.3 at wip/func_00161980/attempt-4.c |

## Batches

- batch 1: 5 matched / 12 · check True · gen_splat_yaml.py: rc=0 0.21s; configure.py: rc=0 51.33s; check_build.py: rc=0 1.14s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
