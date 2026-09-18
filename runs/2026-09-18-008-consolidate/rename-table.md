# Rename table — run 2026-09-18-008-consolidate

| old | new | evidence |
|---|---|---|
| — | — | n/a — no function clears the evidence bar |

No name was written this run. `ledger/renames.jsonl` is unchanged.

## Evidence sources checked

All five sources the naming rule admits were checked against the 33 matched functions:

| source | result |
|---|---|
| a referenced string | `xrefs.py` reported `references (0): none` for all 29 matched functions it could read, and for 7 of their 8 callers. The eighth, `func_00167ED0`, references `D_006A6B80`, which has no `dlabel` in `asm/` and decodes to no text. |
| an SDK call pattern | `callees (0): none` for every matched function; no matched function calls anything at all. |
| an xref from a named caller | `config/symbol_addrs.txt` holds 0 non-systematic names and the ledger holds 0 named library functions, so every caller is an unnamed `func_*`. |
| a TCRF fact | `DOSSIER.md` records no address-bearing fact for `game_01`. |
| a Ghidra hint | `reference/ghidra/` does not exist — S5 has not been run on this target. |

Four matched functions (`func_00131740`, `func_00145A10`, `func_00157650`,
`func_00164E80`) could not be checked at all: `xrefs.py` reads `asm/` and
`wip/*/target.s`, and a linked function has neither. Filed as F-1 (tool-gap, major).

## What was established instead

The rodata at `0x0069C870`–`0x0069D4B0` is a family of vtables: 12 words each,
0x30 apart, two zero words (offset-to-top and RTTI, both absent) then virtual
slots. 20 of the 33 matched functions are reached only from these tables, never
from a call site. The slot layout is stable across the family:

| slot | content |
|---|---|
| +0x00, +0x04 | always 0 |
| +0x08, +0x0C, +0x10 | per-class: construct, step, and a third override |
| +0x14, +0x18 | `func_00145140`, `func_00145150` in all 32 tables |
| +0x1C, +0x20 | `func_00156E20`, `func_00156E30` in all 32 tables — empty base-class virtuals |
| +0x24..+0x2C | 0, or a second base's methods (`func_0012BA90/AA0/AB0`) |

A slot index is not one of the five admitted sources, so no name follows from it;
it is recorded in the ledger notes of each function above, and it is what makes the
two shared headers below defensible.

`func_00157650` and `func_00157E60` are the same function duplicated per class:
both 52 bytes, and after this run's rewrite both compile to objdiff 100 from
character-identical C.

## Headers written

| header | agreed by | content |
|---|---|---|
| `include/game_01/pool70.h` (new) | `func_00157650`, `func_001578C0`, `func_001580D0`, `func_00157E60` | `Slot40` (the in-use byte at +0x0, the interleaved position/velocity floats at +0x20..+0x37) and `Pool70` (that slot array at +0x70 of its owner, 8 entries) |
| `include/game_01/obj1F0.h` (new) | `func_00159E20`, `func_0015B500`, `func_0015BA00` | `Obj1F0`, the base layout reached from two vtables: the quadword pair at +0x10/+0x30, its backups at +0x1F0/+0x200 and +0x230/+0x240, the flag word at +0x60 and the float quad at +0x250; plus `Owner1F0` and `Sub54`, the argument types `func_00159E20` and `func_0015BA00` agree on |

Seven sources were rewritten onto these two headers and re-marked; every one
returned objdiff 100 with byte-identical `.text`, so the objects are unchanged and
only the C sha256 moved. The four `Pool70` functions previously carried four
private, mutually inconsistent views of one object — `func_00157650`'s reached the
in-use byte as `s->unk_00[0x70]` on a 0x40-byte struct, an index outside the type
it was declared in. That view is gone.
