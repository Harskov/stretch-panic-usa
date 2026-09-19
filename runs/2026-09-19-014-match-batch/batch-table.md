# Batch table — run 2026-09-19-014-match-batch

Target `stretch-panic-usa`, compiler `mwcps2-2.3.3-000906`, flags `-O3,p -sdatathreshold 0`.
Batch of 12 from segment `game_01`, in `select_batch.py` order. Every function and every final status;
the judgment is in the run report. Attempts is the ledger total and includes the external lane's
attempts made before this run.

| # | Function | Addr | Size | Status | Score | Attempts | Best C | What closed or blocked it |
|---|---|---|---|---|---|---|---|---|
| 1 | `func_00152300` | 0x00152300 | 128 | matched | 100.0 | 69 | `src/game_01/func_00152300.c` | union { u128 q; Vec v; } for the quad negated lane by lane |
| 2 | `func_001525D0` | 0x001525D0 | 36 | matched | 100.0 | 64 | `src/game_01/func_001525D0.c` | the 48 bytes as one struct assignment |
| 3 | `func_00152380` | 0x00152380 | 116 | matched | 100.0 | 67 | `src/game_01/func_00152380.c` | union quad, Vec and quad copies |
| 4 | `func_00162900` | 0x00162900 | 36 | matched | 100.0 | 118 | `src/game_01/func_00162900.c` | the 48 bytes as one struct assignment |
| 5 | `func_00172F60` | 0x00172F60 | 264 | matched | 100.0 | 75 | `src/game_01/func_00172F60.c` | five array loops, plain indexing |
| 6 | `func_0016C720` | 0x0016C720 | 88 | wip | 99.09091 | 24 | `wip/func_0016C720/attempt-100.c` | parked: vtable dispatch register, t9 vs v0 (F-4) |
| 7 | `func_00159EE0` | 0x00159EE0 | 48 | wip | 98.333336 | 13 | `wip/func_00159EE0/attempt-1.c` | parked: vtable dispatch register, t9 vs v0 (F-4) |
| 8 | `func_0015D4E0` | 0x0015D4E0 | 48 | wip | 98.333336 | 9 | `wip/func_0015D4E0/attempt-1.c` | parked: vtable dispatch register, t9 vs v0 (F-4) |
| 9 | `func_00179E20` | 0x00179E20 | 92 | matched | 100.0 | 6 | `src/game_01/func_00179E20.c` | 0.0f as a named local, not an inline literal (F-5) |
| 10 | `func_0016BED0` | 0x0016BED0 | 368 | matched | 100.0 | 7 | `src/game_01/func_0016BED0.c` | if/else bool, switch in reverse case order, sel before code |
| 11 | `func_0014E490` | 0x0014E490 | 440 | wip | 74.472725 | 2 | `wip/func_0014E490/attempt-1.c` | parked: (s32)f is jal fptosi, the target inlines cvt.w.s (F-6) |
| 12 | `func_001683A0` | 0x001683A0 | 56 | matched | 100.0 | 3 | `src/game_01/func_001683A0.c` | a single-case switch, not an if |
