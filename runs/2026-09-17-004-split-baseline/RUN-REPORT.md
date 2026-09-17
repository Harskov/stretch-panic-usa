# Run 2026-09-17-004-split-baseline — split-baseline

- Target: stretch-panic-usa
- Step: split-baseline (S3) — proposed by next_step.py
- Started: 2026-09-17T05:42:28Z · Finished: 2026-09-17T05:51:25Z
- Commit: the commit whose message starts `run 2026-09-17-004-split-baseline:` (git log --grep)

## What changed

- Ledger: no status changes.
- Baseline: link regime `undecided`; splat YAML and symbol_addrs.txt written.
- Partial: closed at the user's request before the baseline linked. Two blockers, both new to this target. F-1 — splat 0.50.0 lists build/asm/data/main_bss.bss.s.o in the NOLOAD .bss output section but writes no .s for a bss subsegment, so the first link cannot start; fixed in the toolkit this run (configure.py gained write_missing_bss_stubs(), which writes '.section .bss' + '.space <bss_size>' when the file splat references is absent; pre-fix copy in _backup/run-fixes/2026-09-17-004-split-baseline-configure.py). The Fate target only ever built because an equivalent stub was created before its S3 run and has survived since. F-2 — the S3 one-asm-subsegment YAML does not assemble here: 656 R5900-invalid opcodes (654 lld, 2 sdc1) from filler data at 0x0054A8EC-0x0054F29C that spimdisasm decoded as instructions. The judgment: this is a doctrine gap, not a tool bug. spimdisasm is doing what an asm subsegment asks of it, and the S3 procedure has no sanctioned move for typing the minimum data needed to assemble before the segment map. The next S3 run should bound that blob from asm/main.s (0xCBD3CBD3 filler above 0x0054E868, 0x9A9A9AFF/0xFDFBA3F6 runs at the two sdc1 sites), add one narrow data subsegment, and leave the real boundaries to S4. The link regime (A6) is still undecided.

## Build check

`check.json`: ok = **False**, checked 2026-09-17T05:51:03Z, regime `undecided`; image None–None, rebuilt None of None bytes; first diff None, None differing byte(s).

## Step table

# Baseline table — split-baseline (S3) — PARTIAL

The run was closed at the user's request before the baseline linked. The table records
the state reached, not a finished baseline.

| subsegment | file offset | vram | type | result |
|---|---|---|---|---|
| main | 0x00000380 | 0x00100000 | asm | split (86,972,686 bytes of asm/main.s); 656 assembler errors |
| main_bss | 0x0059FB80 | 0x0069F800 | bss | no .s emitted by splat; stub written by configure.py (`.space 0x14100`) |

splat 0.50.0 / spimdisasm 1.42.4: rc=0 in 63.9 s, "Split 5 MB (99.96%) in defined
segments — asm: 5 MB (99.96%) 1 split". ld script written; SUBALIGN rewritten to 4
(2 directives). ninja: 2 asm objects, 0 C objects.

Assembler (`mipsel-linux-gnu-as -EL -march=r5900 -mabi=eabi -no-pad-sections -G0`):
rc=1, 656 errors, all "opcode not supported on this processor: r5900 (mips3)".

| opcode | errors | line runs in asm/main.s | vram |
|---|---|---|---|
| sdc1 | 2 | 1143889; 1145009 | 0x0054A8EC; 0x0054B81C |
| lld | 654 | 1148413-1148442, 1148449-1148550, 1148557-1148778, 1148785-1148790, 1148797-1148868, 1148875-1149096 | 0x0054E868-0x0054F29C |

check.json: `ok: false` — "built ELF missing — the link did not produce it".
Link regime (ASSUMPTION A6): not settled; `config/compiler.json` still
`link_regime: undecided`.

## Proposed next step

S3 split-baseline — check.json red (first diff None) with zero C

## Friction filed

2 entries (blocker 2); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [blocker/tool-bug] splat 0.50.0 emits the .main_bss ld entry but writes no asm/data/main_bss.bss.s, so the first link cannot start
- F-2 [blocker/doctrine-gap] S3's one-asm-subsegment baseline does not assemble for this target: 656 R5900-invalid opcodes from data decoded as code, and the step procedure has no minimal data-typing move
