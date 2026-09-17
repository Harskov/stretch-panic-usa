# Run 2026-09-17-002-extract — extract

- Target: stretch-panic-usa
- Step: extract (S1) — proposed by next_step.py
- Started: 2026-09-17T02:35:55Z · Finished: 2026-09-17T02:38:08Z
- Commit: the commit whose message starts `run 2026-09-17-002-extract:` (git log --grep)

## What changed

- Ledger: no status changes.
- config/target.json: `SLUS_201.82` 5898360 bytes sha1 `0a330e76424b7254e4096d8809b2a927603d3581`, .comment `MW MIPS C Compiler (2.3.1.01)`, 6 IRX modules; DOSSIER.md written.
- Extracted SLUS_201.82 (5898360 B, sha1 0a330e76424b7254e4096d8809b2a927603d3581, LBA 28) from the MODE2/2352 CD rip; config/target.json, DOSSIER.md and config/fingerprint.json written. The disc is a raw .bin+.cue, which extract_elf.py could not read (F-2, major): its Iso class assumed 2048-byte sectors and found no CD001 at LBA 16. Fixed in the script that owns the defect — the sector mode is now detected at LBA 16 (2048 / 2352 mode 2 / 2352 mode 1) and recorded as iso.sector_mode in target.json; the pre-fix reader is the failing check. Two facts for S2 calibrate: .comment reads 'MW MIPS C Compiler (2.3.1.01)', a narrower hint than Fate's misleading string but still to be proved by the calibration table, not assumed; and fingerprint.py classifies only 0x00100000-0x00180000 as code (gcc-ish at 0x100000-0x120000, mw at 0x120000-0x130000, mixed to 0x180000) with 82 of 90 windows data, so S2 candidates should be drawn from below 0x180000. The 22 zero-filesz LOAD segments at vaddr 0x006B3900 with differing memsz look like overlay/bss declarations and are S4's problem.

## Build check

n/a — this step precedes the first build (split-baseline)

## Step table

n/a

## Proposed next step

S2 calibrate — config/compiler.json missing

## Friction filed

3 entries (major 1, minor 1, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [papercut/tool-gap] targets.py resolve does not match the game name for stretch-panic-usa
- F-2 [major/tool-gap] extract_elf.py could not read the disc: Stretch Panic ships as a raw 2352-byte-sector .bin+.cue, not a 2048-byte .iso
- F-3 [minor/doctrine-gap] a toolkit fix made during a run has no commit record: the project root is not a git repository
