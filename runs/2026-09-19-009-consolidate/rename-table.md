# Rename table — run 2026-09-19-009-consolidate

| old | new | evidence |
|---|---|---|
| — | — | n/a — no function clears the evidence bar |

`xrefs.py --naming-census` (reference/naming-census.json): **0 of 77** matched functions
have machine-checkable naming evidence.

| source | matched functions reached |
|---|---|
| referenced string | 0 |
| named caller | 0 |
| named callee | 0 |
| Ghidra hint | 0 |

Candidates examined by hand and rejected:

| function | what was available | why no name |
|---|---|---|
| func_0016D240 | 6 function-pointer tables hold its address (D_0069CE00, D_0069D0E0, D_0069D1B0, D_0069D2B0, D_0069D320, D_0069D4B0) | an unnamed vtable slot names neither the class nor the member at +0xA0 |
| func_0016E740 / func_0016E760 | save/restore pair on +0x64/+0x68 ↔ +0x2F8/+0x2FC | the operation is clear, the object is not; no string or named caller reaches either |
| func_0016BDF0 / func_0016BE80 / func_0016BEA0 | constructor, initialiser and getter on one 0x10-byte record | no referenced string and no named caller; the record's purpose is unestablished |
| func_001733C0 / func_00173C00 / func_001741B0 | per-frame integrate-and-expire on a pos/vel pair | the shape suggests a particle or effect, which is a guess, not evidence |
| func_00172410 | global pointer D_006A6B90, two float triples integrated | the global is unnamed; no string reaches it |

No vtable in `reference/xrefs-index.json` holds two matched functions, so no name can be
carried from one matched function to another this run either.
