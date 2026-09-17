# Run 2026-09-17-001-bootstrap — bootstrap

- Target: stretch-panic-usa
- Step: bootstrap (S0) — proposed by next_step.py
- Started: 2026-09-17T01:52:54Z · Finished: 2026-09-17T01:55:55Z
- Commit: the commit whose message starts `run 2026-09-17-001-bootstrap:` (git log --grep)

## What changed

- Ledger: no status changes.
- tools/manifest.json: 7 tools, 4 compilers, assembler decision `debian-deb`, smoke tests 11/11 ok.
- New target repository for Stretch Panic (USA). The BOOT2 name in the title is quoted from the disc image itself (LC_ALL=C grep -a on Stretch Panic (USA).bin returns BOOT2 = cdrom0:\\SLUS_201.82;1); everything else about the game is still unknown until S1. Two environment findings shape the next runs: the VM session disk holding $HOME is 100% full and not freeable from here, so every bootstrap.sh call ran with HOME=/tmp/dps2-home, and the disc is a CD image (Stretch Panic (USA).bin/.cue, MODE2/2352 raw sectors) rather than the 2048-byte ISO extract_elf.py --iso reads for the first target.

## Build check

n/a — this step precedes the first build (split-baseline)

## Step table

n/a

## Proposed next step

S1 extract — config/target.json missing

## Friction filed

2 entries (blocker 1, major 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [blocker/environment] device VM session disk 100% full; $HOME unusable for scratch
- F-2 [major/tool-gap] bootstrap.sh hardcodes $HOME for the clone scratch with no override
