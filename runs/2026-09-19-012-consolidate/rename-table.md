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
| `func_00105110` | `RotateThreadReadyQueue` | 0x00105110 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105150` | `GetThreadId` | 0x00105150 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105160` | `ReferThreadStatus` | 0x00105160 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105180` | `SleepThread` | 0x00105180 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105190` | `WakeupThread` | 0x00105190 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001051A0` | `_iWakeupThread` | 0x001051A0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001051D0` | `SuspendThread` | 0x001051D0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001051E0` | `_iSuspendThread` | 0x001051E0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105240` | `EndOfHeap` | 0x00105240 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105260` | `CreateSema` | 0x00105260 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105270` | `DeleteSema` | 0x00105270 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105280` | `SignalSema` | 0x00105280 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105290` | `iSignalSema` | 0x00105290 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001052A0` | `WaitSema` | 0x001052A0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001052B0` | `PollSema` | 0x001052B0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001054E0` | `FlushCache` | 0x001054E0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105530` | `sceSifStopDma` | 0x00105530 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001055A0` | `GsPutIMR` | 0x001055A0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_001055D0` | `SetVSyncFlag` | 0x001055D0 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105600` | `sceSifDmaStat` | 0x00105600 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105620` | `sceSifSetDma` | 0x00105620 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105630` | `isceSifSetDma` | 0x00105630 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105640` | `sceSifSetDChain` | 0x00105640 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105650` | `isceSifSetDChain` | 0x00105650 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105660` | `sceSifSetReg` | 0x00105660 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105670` | `sceSifGetReg` | 0x00105670 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105690` | `Deci2Call` | 0x00105690 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105EA8` | `RFU116_SetSyscall` | 0x00105EA8 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |
| `func_00105F00` | `RFU091` | 0x00105F00 | Ghidra ee-reloaded export, recovered name unique in the export, on the ledger function in segment sdk_libkernel; SDK syscall-stub pass |

## Examined and not renamed

| function | Ghidra name | why not |
|---|---|---|
| `func_00100008` | `entry` | Ghidra labels the ELF entry point `entry` by default, so the name carries nothing beyond `e_entry`, which `config/target.json` already records. A placeholder, not a recovered symbol; the systematic name stays. |

The census reports 0 of 104 matched functions with machine-checkable naming evidence
(string 0, named_caller 0, named_callee 0, ghidra 0): the matched set is still leaves that
reference nothing named. Every name in this table is on a `library`-status SDK stub, not on
a matched function, so the matched count is unchanged by the pass. With `renameable` now 0,
the Ghidra export is exhausted as a naming source for this target.
