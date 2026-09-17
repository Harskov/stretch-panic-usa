# Baseline table — split-baseline (S3) — PARTIAL

The run was closed at Jordan's request before the baseline linked. The table records
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
