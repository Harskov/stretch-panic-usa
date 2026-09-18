# Run 2026-09-18-008-consolidate — consolidate

- Target: stretch-panic-usa
- Step: consolidate (S8) — proposed by next_step.py
- Started: 2026-09-18T20:51:38Z · Finished: 2026-09-18T21:00:12Z
- Commit: the commit whose message starts `run 2026-09-18-008-consolidate:` (git log --grep)

## What changed

- Ledger: no status changes.
- The step's decisive result is negative on naming and positive on types. None of the five admitted naming sources reaches any of the 33 matched functions: no matched function references a string, none calls anything at all, no symbol anywhere in the target carries a non-systematic name, the dossier records no address-bearing fact for game_01, and S5 has never run — so the rename table is n/a and every systematic name stays. What the run did establish is structural: the rodata at 0x0069C870-0x0069D4B0 is a family of 12-word vtables 0x30 apart, and 20 of the 33 matched functions are reached only from them. That is what made the two headers defensible rather than speculative: func_00157650, func_001578C0, func_001580D0 and func_00157E60 carried four private views of one 8-entry pool, one of them (func_00157650's s->unk_00[0x70] on a 0x40-byte struct) an index outside the type it was declared in; func_00159E20, func_0015B500 and func_0015BA00 carried three views of one base object, disagreeing on the type of the flag word at +0x60. All seven were rewritten onto include/game_01/pool70.h and include/game_01/obj1F0.h and re-marked: every one returned objdiff 100 with byte-identical .text, so the objects are unchanged and only the C sha256 moved. func_00157650's first rewrite, a typed pointer walk, scored 92.2 and was discarded; the indexed form that matched turned out to be character-identical to func_00157E60's, which is the run's other finding: they are the same function duplicated per class. The blocking friction is F-1: xrefs.py reads asm/ and wip/*/target.s, and a matched, linked function has neither, so the evidence S8 exists to consume disappears at the moment a function is matched - 4 of 33 could not be checked at all this run, and that fraction grows with every match.

## Build check

`check.json`: ok = **True**, checked 2026-09-18T21:00:06Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

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

(first 25 lines; every row is in `rename-table.md`)

## Proposed next step

S6 match-batch — 1322 game function(s) still asm/wip; batch size 12
- note: external lane: 4 runner batch(es), 20 matched, $0.09 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

2 entries (major 1, minor 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [major/tool-gap] xrefs.py cannot report a matched, linked function — the evidence S8 needs disappears at the moment a function is matched
- F-2 [minor/evidence-gap] no admitted naming evidence exists anywhere in this target yet
