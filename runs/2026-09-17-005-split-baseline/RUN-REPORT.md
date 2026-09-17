# Run 2026-09-17-005-split-baseline — split-baseline

- Target: stretch-panic-usa
- Step: split-baseline (S3) — proposed by next_step.py
- Started: 2026-09-17T05:54:51Z · Finished: 2026-09-17T06:01:43Z
- Commit: the commit whose message starts `run 2026-09-17-005-split-baseline:` (git log --grep)

## What changed

- Ledger: no status changes.
- Baseline: link regime `full`; splat YAML and symbol_addrs.txt written.
- The image assembles once the asset region is typed as data: code ends at 0x0017EF00 (func_0017ED50 + nop pad) and fingerprint.json classes everything from 0x180000 to 0x69F800 as data, so one data subsegment (main_data, rom 0x7F280) replaces the filler that spimdisasm had decoded as lld/sdc1 (run 004 F-2). Zero-C check green on the first link with no undefined symbols added. A6 settled: func_00131740 linked as a MW object with 0 differing bytes, link_regime full. Restoring the baseline by hand-copying the saved YAML rather than gen_splat_yaml.py --initial --force, which cannot express the data subsegment (F-1, tool-gap). The real code/data boundary and the sdk/game split inside 0x100000-0x17EF00 (fingerprint: gcc 0x100000-0x120000, mw 0x120000-0x130000, mixed to 0x180000) are S4 work.

## Build check

`check.json`: ok = **True**, checked 2026-09-17T06:01:30Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: main ok.

## Step table

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

## Proposed next step

S4 segment-map — ledger/segments.json missing or provisional

## Friction filed

2 entries (major 1, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [major/tool-gap] gen_splat_yaml.py --initial cannot express a data subsegment, so the S3 restore-the-baseline step would drop the split that makes this target assemble
- F-2 [papercut/tool-gap] string_encoding SHIFT-JIS hardcoded for a US target with language_hint C
