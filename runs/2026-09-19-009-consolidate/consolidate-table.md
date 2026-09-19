# Consolidate table — run 2026-09-19-009-consolidate

Every function whose source changed this run. Each was re-compiled with the pinned
compiler and re-marked; every object is byte-identical to the one the ledger held
before the rewrite, so the rewrites changed the source only.

| function | change | header | objdiff |
|---|---|---|---|
| func_00159820 | 2 byte-offset casts → members of the shared Obj1F0 | include/game_01/obj1F0.h (extended with +0x290 quad) | 100 |
| func_00172410 | 10 byte-offset casts → members of a typed global object | local (single reacher) | 100 |
| func_0016D240 | `(char *)p + 0xA0` → `&o->unk_A0` | local (single reacher) | 100 |
| func_001733C0 | local struct → shared header; fields renamed unk_XX | include/game_01/obj50.h (new) | 100 |
| func_00173C00 | local struct → shared header | include/game_01/obj50.h (new) | 100 |
| func_001741B0 | local struct → shared header | include/game_01/obj50.h (new) | 100 |
| func_001636C0 | local Vec + typedef block → include/common.h | include/common.h (Vec added) | 100 |
| func_0016BDF0 | local struct → shared header | include/game_01/rec10.h (new) | 100 |
| func_0016BE80 | local struct → shared header | include/game_01/rec10.h (new) | 100 |
| func_0016BEA0 | local struct → shared header; +0x0C typed u8 from `lbu` | include/game_01/rec10.h (new) | 100 |
| func_0016E740 | local struct → shared header | include/game_01/obj2F8.h (new) | 100 |
| func_0016E760 | local struct → shared header | include/game_01/obj2F8.h (new) | 100 |
| func_0016DC80 | local struct → shared header | include/game_01/obj168.h (new) | 100 |
| func_0016DCD0 | local struct → shared header | include/game_01/obj168.h (new) | 100 |

## Headers

| header | struct | functions agreeing | agreement evidence |
|---|---|---|---|
| include/common.h | Vec | 4 | the 16-byte operand of every VU0 `lqc2`/`sqc2` block |
| include/game_01/obj1F0.h | Obj1F0 | 4 (was 3) | func_00159820 writes the +0x230/+0x240 pair func_00159E20 restores from |
| include/game_01/obj50.h | Obj50 | 3 | same +0x50/+0x60 VU0 pair, same +0x70/+0x74/+0x78 head, same +0x9C counter and return convention |
| include/game_01/rec10.h | Rec10 | 3 | same four fields at +0x00/+0x04/+0x08/+0x0C |
| include/game_01/obj2F8.h | Obj2F8 | 2 | save and restore halves of the +0x64/+0x68 ↔ +0x2F8/+0x2FC pair |
| include/game_01/obj168.h | Obj168 | 2 | same counter pair at +0x164/+0x168 |

## Not merged

| layout | functions | why kept apart |
|---|---|---|
| an int flag word at +0x60 | func_00168630, func_0016C260, func_0016D690, func_0016DC80, and Obj1F0's own +0x60 | one shared offset is a weak claim on its own; the five disagree on everything else they reach, and no function reaches two of the layouts |
| Obj10 (+0x10/+0x20 vectors) vs Obj50 (+0x50/+0x60) | func_001636C0 vs the Obj50 three | same operation, different offsets — a different object |
| Obj2F8's backup pair vs Obj1F0's | func_0016E740/760 vs func_00159820/func_00159E20 | same idea, no overlapping offset and no function in common |
