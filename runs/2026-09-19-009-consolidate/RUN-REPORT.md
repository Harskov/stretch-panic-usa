# Run 2026-09-19-009-consolidate — consolidate

- Target: stretch-panic-usa
- Step: consolidate (S8) — proposed by next_step.py
- Started: 2026-09-19T04:00:38Z · Finished: 2026-09-19T04:09:01Z
- Commit: the commit whose message starts `run 2026-09-19-009-consolidate:` (git log --grep)

## What changed

- Ledger: no status changes.
- The step found structure, not names. The naming census is 0 of 77 and no vtable in the xrefs index holds two matched functions, so nothing can be named from a string, a caller or a sibling this run and the rename table is empty with the candidates listed under it; the report proposes S5 ghidra-hints below for that reason. What the run did change is the source. All 13 lint errors are gone: func_00159820's two u128 byte-offsets and func_00172410's ten float byte-offsets became struct members, and func_0016D240's pointer arithmetic became the address of a member. Six functions had been matched against a struct laid out in their own file that another matched function already described, so the layouts were merged into shared headers under include/game_01/ and the files now include them. The decisive evidence differs per header and is quoted in each: for Obj1F0 that func_00159820 writes the +0x230/+0x240 pair func_00159E20 restores from, for Obj50 that three functions integrate the same +0x50/+0x60 vector pair with the same VU0 block and expire on the same +0x9C counter, for Rec10 that three functions reach the same four fields — and that func_0016BEA0's lbu at 0x0016BEA4, not a guess, is what makes +0x0C unsigned. The five layouts that share only an int flag word at +0x60 were deliberately not merged; one common offset is too thin, and the not-merged table records the decision so the next consolidate does not redo the reasoning. Every one of the 14 rewrites re-marked byte-identical, so the source changed and the image did not; check.json is green and the four remaining lint findings are the VU0 macro-mode blocks, which are final C and now each carry a ledger note naming the vector op.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T04:08:52Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

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

(first 25 lines; every row is in `rename-table.md`)

## Proposed next step

S6 match-batch — 1278 game function(s) still asm/wip; batch size 12
- note: external lane: 15 runner batch(es), 64 matched, $0.71 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

2 entries (minor 1, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [papercut/environment] 11 runner batches uncommitted at RESUME
- F-2 [minor/tool-gap] ledger.py note only appends; no way to condense an over-long note list
