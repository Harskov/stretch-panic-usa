# Baseline table — split-baseline (S3), run 2026-09-17-005

| subsegment | file offset | vram | type | evidence |
|---|---|---|---|---|
| main | 0x00000380 | 0x00100000 | asm | code from the entry point |
| main_data | 0x0007F280 | 0x0017EF00 | data | last function `func_0017ED50` ends in a nop pad at 0x0017EF00 (asm/main.s line 146584: `dlabel D_0017EF00`); `config/fingerprint.json` classes 0x00180000–0x0069F800 as `data` (82/82 windows); run 004 F-2: the assembler refused 656 `lld`/`sdc1` words decoded from filler at 0x0054A8EC–0x0054F29C |
| main_bss | 0x0059FB80 | 0x0069F800 | bss | LOAD memsz − filesz = 0x14100; stub written by `configure.py write_missing_bss_stubs()` (run 004 fix) |

splat 73.2 s; build 11.8 s (ninja, 3 asm objects, 0 C); undefined address-named symbols added to `config/undefined_syms.txt`: 0 (splat's own `undefined_syms_auto.txt`: 272, `undefined_funcs_auto.txt`: 12).
check.json (zero-C baseline): ok=True, image 0x00100000–0x0069F800, 5896192 bytes, 0 differing bytes.

## A6 link-regime probe

`func_00131740` (calibration match, 96 bytes) as `[0x00031AC0, c, probe/func_00131740]` + `[0x00031B20, asm, main_1]`, compiled with `mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0`, linked: check ok=True, 0 differing bytes (`a6-link-probe-check.json`). `link_regime: full` recorded in `config/compiler.json`. Probe C moved to `_delete/2026-09-17-005-split-baseline/src-probe/`; the saved `baseline.yaml` restored (F-1: `--initial --force` would have dropped `main_data`).
