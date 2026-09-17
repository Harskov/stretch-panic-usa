# Run 2026-09-17-003-calibrate — calibrate

- Target: stretch-panic-usa
- Step: calibrate (S2) — proposed by next_step.py
- Started: 2026-09-17T03:16:40Z · Finished: 2026-09-17T03:28:26Z
- Commit: the commit whose message starts `run 2026-09-17-003-calibrate:` (git log --grep)

## What changed

- Ledger: functions 0 → 8 (+8), matched 0 → 4 (+4), wip 0 → 4 (+4).
- config/compiler.json: `mwcps2-2.3.3-000906` flags `-O3,p -sdatathreshold 0`, calibrated: True, 4 of 8 candidate functions byte-matched.
- Decisive: mwcps2-2.3.3-000906 at -O3,p. It is the only build whose cells are byte-identical on four of the eight candidates (func_00131740, func_00145A10, func_00157650, func_00164E80) AND scores highest on the best non-matching cell (func_00120340 at 90.1 vs 78.1 for 2.4-001213); mwcps2-3.0-011126 is byte-identical on none and peaks at 86.2, so the 3.0 line is excluded. Two independent fingerprints agree with the 2.3 line: the ELF .comment reads MW MIPS C Compiler (2.3.1.01), and config/fingerprint.json counts 1368 paddub register moves — K1 records paddub moves as the 2.3.3/2.4 idiom and daddu moves as the 3.0 idiom (Fate/Unlimited Codes, a 3.0 target, has 0 paddub moves). 2.3.3 and 2.4 were separated only by func_00120340; every other cell is equal between them, so that one cell carries the choice, and the .comment version number (2.3.1.01, nearer 2.3.3 than 2.4) is the corroborating reason to prefer it. Optimisation level is undetermined by this table: -O3,p and -O4,p produce identical objects for all eight candidates, as do the preset variants adding -sdatathreshold 0, -str readonly, -inline auto|deferred, -enum min and -fp single (none of the eight leaf functions references a global, a string, a float or a call, which is what those flags govern). -O3,p was taken as the level of the nearest real 2.3.3 preset (Resident Evil: Code Veronica X, -O3,p -sdatathreshold 0 -sym on). -sdatathreshold 0 rests on separate evidence, not on the table: a scan of the 0x59F800-byte LOAD segment for instructions with $gp as base register found 8 lw, 21 sw, 6 lbu and 5 addiu — effectively no small-data accesses in 5.6 MB, where the mwcc default threshold of 8 would place every scalar global in .sdata and produce thousands. That scan is heuristic (the segment contains data disassembled as code; the 4587 sd hits with rs=28 are certainly data words), so -sdatathreshold is the flag most likely to need a later calibrate step if S6 functions that touch globals mismatch systematically. Not decisive but worth recording: -O0,p scores 0.0 on four candidates and under 11 on the rest across all three builds, so the target is definitely optimised; the four non-matching candidates all park high enough to be ordinary S6 work rather than evidence against the pin — func_00120340 at 90.1 (a struct-copy loop whose PadState field types are guesswork), func_00172A40 at 62.7, func_00103628 at 54.1, and func_001185E8 at 9.9, the last being the only candidate with a stack frame and the one whose C (a mbtowc-shaped function with an unused first argument) is most likely wrong rather than mis-flagged. Four of the eight candidates were written using __int128, after a probe compile established that a plain 16-byte struct copy compiles to lwc1/swc1 and only __int128 produces lq/sq (F-2); all four of those are byte-identical, so the modelling is confirmed for this compiler.

## Build check

n/a — this step precedes the first build (split-baseline)

## Step table

# Calibration table — every (compiler, flags) x function cell, every score (2026-09-17T03:28:12Z)

Cell = objdiff match % (B = .text bytes identical to the target; err = compile error). Judgment is a separate paragraph in the run report, never a filter on this table.

| compiler | flags | func_00103628 | func_001185E8 | func_00120340 | func_00131740 | func_00145A10 | func_00157650 | func_00164E80 | func_00172A40 | byte-identical | score 100 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| mwcps2-2.3.3-000906 | `-O3,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -enum min` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O3,p -str readonly -inline deferred` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -fp single` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -inline auto` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-O4,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.3.3-000906 | `-sdatathreshold 0 -O3,p` | 54.1 | 9.9 | 90.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -enum min` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -inline auto` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |
| mwcps2-2.4-001213 | `-O3,p -str readonly -inline deferred` | 54.1 | 10.5 | 78.1 | 100.0 B | 100.0 B | 100.0 B | 100.0 B | 62.7 | 4/8 | 4/8 |

(first 25 lines; every row is in `calibration-table.md`)

## Proposed next step

S3 split-baseline — build/check.json missing

## Friction filed

5 entries (major 2, minor 2, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [papercut/environment] git_sync.sh pull skipped: working tree dirty
- F-2 [minor/doc-gap] K1 cheat sheet: lq/sq is not produced by a 16-byte struct copy
- F-3 [major/tool-bug] calibrate: target.s includes macro.inc, which only S3 writes
- F-4 [major/tool-bug] calibrate: failed target assembly leaves a 0-byte target.o that the resume then trusts
- F-5 [minor/tool-bug] calibrate --rescore runs before targets are assembled and does not recompute bytes_equal
