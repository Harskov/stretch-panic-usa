# Run 2026-09-19-014-match-batch — match-batch

- Target: stretch-panic-usa
- Step: match-batch (S6) — proposed by next_step.py
- Started: 2026-09-19T12:56:29Z · Finished: 2026-09-19T13:24:05Z
- Commit: the commit whose message starts `run 2026-09-19-014-match-batch:` (git log --grep)

## What changed

- Ledger: matched 113 → 121 (+8), wip 51 → 47 (-4), asm 1191 → 1187 (-4).
- Eight of the twelve batch functions reached 100 byte-identical and four parked; the batch table lists every one. The decisive results are the three that were not source problems. Three functions are a two-load vtable dispatch and stop with only the call register differing (t9 in the target, v0 compiled) across seven spellings and a 328-iteration permuter run; an image census of all 460 jalr sites shows 449 of the 460 t9 sites are the two-load shape and 37 of the 38 v0 sites are the one-load shape, so the shipping build's own split is by chain depth and the C is already right (F-4). func_0014E490 parks for the same kind of reason: (s32)f compiles to jal fptosi under the pinned build on every spelling and every flag set probed, while all 31 conversion sites in the image are inline cvt.w.s and the image carries no fptosi symbol (F-6). Both point at the pinned mwcps2-2.3.3-000906 not being the shipping build, and both would be settled by one calibrate step whose candidates include a vtable dispatch and a float-to-int conversion; that is the better next step than another match-batch, and 449 dispatch sites plus 36 conversion functions are capped below 100 until it is taken. The three that closed on a spelling are worth reading: a quad copied whole and then negated lane by lane is a union { u128 q; Vec v; } (the external lane spent 80 attempts on it at 99.3), consecutive quads whose loads are all hoisted above the first store are one struct assignment rather than N u128 fields (62 and 116 external attempts at 98.7), and a float constant compared inline takes the higher FPU register while the same constant as a named local takes the lower one. All four of the external lane's parked functions in this batch closed or were explained on the operator's first attempt, which is what F-1, F-2 and F-5 propose feeding back into the primer and the runner prompt. No toolkit script was changed; match.py permute could not preprocess an attempt that includes a project header and was worked around by copying include/common.h and include/types.h into the run's permuter directory (F-3).

## Build check

`check.json`: ok = **True**, checked 2026-09-19T13:23:03Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

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

## Proposed next step

S6 match-batch — 1234 game function(s) still asm/wip; batch size 12
- note: external lane: 24 runner batch(es), 93 matched, $4.11 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

6 entries (major 3, minor 3); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [minor/doc-gap] quad copied whole then read lane by lane: the union spelling is not in K1 §6
- F-2 [minor/doc-gap] consecutive quads loaded before the first store are one struct assignment, not N u128 assignments
- F-3 [major/tool-gap] match.py permute cannot preprocess an attempt that includes a project header
- F-4 [major/toolchain-drift] two-load vtable dispatch: the shipping build calls through $t9, the pinned build through $v0, on every spelling
- F-5 [minor/doc-gap] a float constant compared inline takes $f1; as a named local it takes $f0
- F-6 [major/toolchain-drift] float-to-int: the shipping build inlines cvt.w.s, the pinned build always calls the fptosi helper
