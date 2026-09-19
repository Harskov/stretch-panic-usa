# Run 2026-09-19-015-calibrate — calibrate

- Target: stretch-panic-usa
- Step: calibrate (S2) — **override**: named in chat
- Started: 2026-09-19T14:26:17Z · Finished: 2026-09-19T14:48:06Z
- Commit: the commit whose message starts `run 2026-09-19-015-calibrate:` (git log --grep)

## What changed

- Ledger: wip 47 → 49 (+2), asm 1187 → 1185 (-2).
- config/compiler.json: `mwcps2-2.3.3-000906` flags `-O3,p -sdatathreshold 0`, calibrated: True, 4 of 12 candidate functions byte-matched.
- The step was an override: next_step.py proposed match-batch and the user named calibrate, on the strength of run 014's own report, which proposed it. Nothing about the pin changed — mwcps2-2.3.3-000906 with -O3,p -sdatathreshold 0 stands — but the two boundaries that run 014 filed as toolchain-drift are now settled, and one of them is settled decisively. The candidate pool was the reason the previous calibrate could not settle them: calibrate_compiler.py candidates selects only leaf functions with no calls, so no cell in the table could exercise a call idiom (F-1). Four non-leaf candidates were added by hand — two vtable dispatches and two float-to-int conversions — and the compiler pool was widened from 3 mwcps2 builds to all 21 that decompme publishes. The decisive result is the dispatch one. Written as a C function-pointer field, func_00159EE0 compiles to jalr $v0 under all 21 builds; written as C++ with a real virtual member and compiled by the already-pinned build at the already-pinned flags, its .text is byte-identical to the target, 12 of 12 instructions. The register was never a compiler difference — the target is C++ and the source shape was wrong, which retires run 014 F-4 and puts the 449 two-load dispatch sites within reach (F-2). They are not yet reachable in practice: the toolkit compiles .c as C, and -dialect c++ mangles the symbol objdiff and the linker match on, though it is codegen-neutral for plain C on all 8 leaf candidates, so the path is extern "C" plus a dialect flag and that is remediation work, not a step's (F-3). The conversion boundary is settled in the weaker sense that it is now known not to be a build difference: the idiom matrix shows sq $ra only in 2.3.3 and 2.4 and inline cvt.w.s only from 3.0.1b44 on, with no build producing both, while the image uses sq $ra in all 958 game functions that have a frame and inlines the conversion at all 16 sites that have one — ten of which save $ra with sq. Seven C spellings across seven flag sets all call the fptosi helper under 2.3.3, so the inline sites come from a source construct still to be identified, most likely a macro carrying an asm block for the GS 12.4 fixed-point form (F-4). Two defects surfaced. pin rewrites every candidate's ledger record: it demoted two library functions to wip and cleared linked on four matched functions that had been linked since before this run, which would have taken the SHIP build red; both were repaired in the run with set-status and relink, and check.json is green (F-6, blocker). And a hand-written probe loop twice produced a false signal — once from a stale scratch object left by a failed compile, once from grep patterns that used spaces where objdump writes tabs (F-5). The better next step is not another match-batch: a remediation round that gives the toolkit a C++ path would unblock roughly a third of the remaining game functions, and is worth more than twelve more matches.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T14:47:58Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

# Calibration table — every (compiler, flags) x function cell, every score (2026-09-19T14:44:18Z)

Cell = objdiff match % (B = .text bytes identical to the target; err = compile error). Judgment is a separate paragraph in the run report, never a filter on this table.

| compiler | flags | func_00103628 | func_001185E8 | func_00120340 | func_00125C90 | func_001278A0 | func_00131740 | func_00145A10 | func_00157650 | func_00159EE0 | func_0015D4E0 | func_00164E80 | func_00172A40 | byte-identical | score 100 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| mwcps2-2.3.3-000906 | `-O3,p` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -enum min` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O3,p -str readonly -inline deferred` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O4,p` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O4,p -fp single` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O4,p -inline auto` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-O4,p -sdatathreshold 0` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.3.3-000906 | `-sdatathreshold 0 -O3,p` | 54.1 | 9.9 | 90.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -enum min` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -fp single -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -inline auto` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -inline auto -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -sdatathreshold 0` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |
| mwcps2-2.4-001213 | `-O3,p -str readonly -inline deferred` | 54.1 | 10.5 | 78.1 | 0.0 | 0.0 | 100.0 B | 100.0 B | 100.0 B | 98.3 | 98.3 | 100.0 B | 62.7 | 4/12 | 4/12 |

(first 25 lines; every row is in `calibration-table.md`)

## Proposed next step

S6 match-batch — 1234 game function(s) still asm/wip; batch size 12
- note: external lane: 24 runner batch(es), 93 matched, $4.11 in state/runner-steps.jsonl (never a step of a run)
- note: runner batch(es) named by a wip/<fn>/runner.json but with no record in state/runner-steps.jsonl: 2026-09-19-016 — the batch died before it finalised, so its end-of-batch rebuild never ran: verify check.json and repair (S9) if red
- note: 1 function(s) at runner state=error, the runner could not work them: func_00178B30 — select_batch ranks them last; check the function has a glabel block in asm/

## Friction filed

6 entries (blocker 1, major 4, minor 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [major/tool-gap] candidates finds only leaf functions, which cannot separate compiler builds on call or conversion idioms
- F-2 [major/doctrine-gap] the target is C++: a vtable dispatch is a virtual call, and K1 has no C++ idiom section
- F-3 [major/tool-gap] no C++ path in the toolkit: prepare, try, mark, gen_splat_yaml and configure assume a .c source compiled as C
- F-4 [major/evidence-gap] float-to-int: not a build difference — no available build produces both the image's sq $ra frame and an inline cvt.w.s
- F-5 [minor/false-signal] a failed probe compile left the previous object in place and the disassembly read as a result
- F-6 [blocker/tool-bug] pin rewrites every candidate's ledger record: it demoted two library functions to wip and unlinked four linked matches
