# Run 2026-09-17-007-match-batch — match-batch

- Target: stretch-panic-usa
- Step: match-batch (S6) — proposed by next_step.py
- Started: 2026-09-17T14:04:06Z · Finished: 2026-09-17T14:17:44Z
- Commit: the commit whose message starts `run 2026-09-17-007-match-batch:` (git log --grep)

## What changed

- Ledger: matched 4 → 13 (+9), wip 2 → 5 (+3), asm 1349 → 1337 (-12).
- Nine of twelve matched, all plain C with lint clean. The decisive shape of the batch is the Pool/slots form: a 0x70-byte header followed by eight 0x40-byte slots, indexed without a local element pointer (p->slots[i].pos_x += p->slots[i].vel_x) — it closes the one addu operand-order row that the element-pointer form left on func_001578C0 and func_001580D0, and it also produced func_00157E60 (same slot layout, the flag test as the loop exit). func_001653D0 needed the return value initialised before the compare (int alive = 1). Of the three parked: func_00163B60 reached 95.3 once the return type was unsigned char (the daddiu v0,zero,1 row); its remaining four rows and func_00165800's are one shape — the target converts the int before materialising 1.0f — which no source spelling tried reproduces (F-3). func_00165800 (85.3) and func_001636C0 (9.9) both carry a VU0 macro-mode vector add (lqc2/vadd.xyz/sqc2) for which the project defines no C form and mwccps2 2.3.3 refuses an asm block with C operands (F-2, major); until that is settled every function of this family parks, so a K1/lint decision on VU0 ops is the better next step before more game_01 batches.

## Build check

`check.json`: ok = **True**, checked 2026-09-17T14:17:25Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

# Batch table — 2026-09-17-007-match-batch

| # | function | addr | size | attempts (score) | best | status |
|---|---|---|---|---|---|---|
| 1 | func_001578C0 | 0x001578C0 | 84 | 99.5, 94.5, 99.5, 89.8, 99.5, 100.0, 100.0 | 100.0 | matched |
| 2 | func_001653D0 | 0x001653D0 | 80 | 86.8, 100.0, 100.0 | 100.0 | matched |
| 3 | func_00157E60 | 0x00157E60 | 52 | 95.4, 100.0, 100.0 | 100.0 | matched |
| 4 | func_00156E30 | 0x00156E30 | 8 | 100.0, 100.0 | 100.0 | matched |
| 5 | func_00156E20 | 0x00156E20 | 8 | 100.0, 100.0 | 100.0 | matched |
| 6 | func_00165800 | 0x00165800 | 376 | 85.3 | 85.3 | wip |
| 7 | func_001580D0 | 0x001580D0 | 84 | 99.5, 100.0, 100.0 | 100.0 | matched |
| 8 | func_00158670 | 0x00158670 | 20 | 100.0, 100.0 | 100.0 | matched |
| 9 | func_00163B60 | 0x00163B60 | 348 | 76.4, 76.4, 76.4, 71.7, 76.4, 91.7, 89.7, 59.8, 90.6, 91.7, 95.3 | 95.3 | wip |
| 10 | func_001636C0 | 0x001636C0 | 80 | err, 9.9 | 9.9 | wip |
| 11 | func_00163480 | 0x00163480 | 8 | 100.0, 100.0 | 100.0 | matched |
| 12 | func_00163470 | 0x00163470 | 8 | 100.0, 100.0 | 100.0 | matched |

## Proposed next step

S6 match-batch — 1342 game function(s) still asm/wip; batch size 12

## Friction filed

3 entries (major 1, minor 2); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [minor/tool-bug] m2c has no reading for VU0 macro-mode instructions
- F-2 [major/doc-gap] no C form defined for VU0 macro-mode vector ops (lqc2/vadd.xyz/sqc2)
- F-3 [minor/doc-gap] 1.0f/(float)n compiles with the cvt.s.w after the constant; target converts first
