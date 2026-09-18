# RUNNER-REPORT — 2026-09-18-001 (dsstep 0.1.0)

- **Model:** deepseek:deepseek-flash · prompt ds-v1 `bdbe8fe7c46f`
- **Started / finished:** 2026-09-18T16:18:53Z / 2026-09-18T16:20:13Z
- **Functions:** 3 attempted · 1 matched · 2 parked · 0 error
- **Cost:** $0.0100 · 514,260 tokens · $0.0100 per match
- **Final check_build:** ok=True check: OK — rebuilt image equals the original's loaded segment(s) 0x00100000-0x0069F800 (5896192 bytes); regime full

## Functions

| function | size | state | attempts | best | tokens | usd | note |
|---|---|---|---|---|---|---|---|
| func_001636C0 | 80 | matched | 2 | 100.0 | 37174 | 0.000763 | marked from wip/func_001636C0/attempt-4.c |
| func_00165800 | 376 | parked | 10 | 90.3 | 257653 | 0.006096 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 90.3 at wip/func_00165800/attempt-6.c |
| func_00162900 | 36 | parked | 11 | 97.8 | 219433 | 0.003091 | dsstep 0.1.0: attempt cap 10 reached; best objdiff 97.8 at wip/func_00162900/attempt-8.c |

## Batches

- batch 1: 1 matched / 3 · check True · gen_splat_yaml.py: rc=0 0.22s; configure.py: rc=0 53.66s; check_build.py: rc=0 1.14s

For the Claude Project's RESUME: `state/runner-steps.jsonl` holds one `match-batch-external` record per batch; re-run `check_build.py` before proposing the next step.
