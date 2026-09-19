# Run 2026-09-19-012-consolidate — consolidate

- Target: stretch-panic-usa
- Step: consolidate (S8) — proposed by next_step.py
- Started: 2026-09-19T08:48:32Z · Finished: 2026-09-19T08:55:28Z
- Commit: the commit whose message starts `run 2026-09-19-012-consolidate:` (git log --grep)

## What changed

- Ledger: no status changes.
- Two pieces of work, one evidence source each. The naming pass: the census found 0 of 104 matched functions with machine-checkable evidence - the matched set is still leaves that reference nothing named - but the Ghidra ee-reloaded export carried 47 recovered names on ledger functions, all SDK stubs in sdk_libkernel, none blocked by a duplicate. 46 were applied in one rename-batch pass; func_00100008 -> entry was left systematic because Ghidra labels the ELF entry point that way by default, so the name says only what config/target.json already records. With renameable now 0 the export is exhausted as a naming source here, and the next naming evidence has to come from matched game code rather than from another S5. The structure pass: lint_c reported three byte-offset errors. func_00151460 and func_001514A0 agree on a layout at +0x60, +0x410, +0x414 and a discriminator byte at +0x418, so they now share one header, Obj430; their disagreement at +0x420 - four separate words in one, a single 16-byte lq/sq copy in the other - is recorded as a union in that struct rather than resolved by laying a second view over the first. func_00179E80's byte-offset read at +0x10 became a 128-bit field of its own struct. func_0016F790 names a 16-byte field at the same +0x10 on its object and func_001522E0 reads +0x410 as an f32 where Obj430 stores an s32; neither shares a caller with the functions above, so no objects were merged on one shared offset. All three rewrites recompiled byte-identical before being re-marked, so the ledger C shas changed and the objects did not; lint_c now exits 0 with six advisories left, all VU0 macro-mode blocks that already carry their vector-op notes. No function changed status this run: the renames are on library stubs and the rewrites are on functions already matched. The one friction entry is a bridge outage during SHIP, not a defect of any script.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T08:55:20Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

# Rename table — run 2026-09-19-012-consolidate (S8 consolidate)

46 renames, all from one evidence source: the Ghidra ee-reloaded export read through
`reference/naming-census.json` (`ghidra_rename_candidates`), applied in one pass with
`ledger.py rename-batch --from runs/2026-09-19-012-consolidate/renames.jsonl`.

| old | new | addr | evidence |
|---|---|---|---|
| `func_00104E60` | `SetGsCrt` | 0x00104E60 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104E80` | `_Exit` | 0x00104E80 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104F60` | `RemoveIntcHandler` | 0x00104F60 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104F70` | `AddDmacHandler` | 0x00104F70 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104F90` | `RemoveDmacHandler` | 0x00104F90 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104FA0` | `_EnableIntc` | 0x00104FA0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104FB0` | `_DisableIntc` | 0x00104FB0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104FC0` | `_EnableDmac` | 0x00104FC0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00104FD0` | `_DisableDmac` | 0x00104FD0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105000` | `_iEnableIntc` | 0x00105000 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105010` | `_iDisableIntc` | 0x00105010 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105020` | `_iEnableDmac` | 0x00105020 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105030` | `_iDisableDmac` | 0x00105030 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105060` | `CreateThread` | 0x00105060 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105080` | `_StartThread` | 0x00105080 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001050A0` | `ExitDeleteThread` | 0x001050A0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001050F0` | `ChangeThreadPriority` | 0x001050F0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |

(first 25 lines; every row is in `rename-table.md`)

## Proposed next step

S6 match-batch — 1251 game function(s) still asm/wip; batch size 12
- note: external lane: 19 runner batch(es), 85 matched, $1.60 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

1 entry (minor 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [minor/environment] run_report.py exceeded the device_bash time cap; the bridge then dropped
