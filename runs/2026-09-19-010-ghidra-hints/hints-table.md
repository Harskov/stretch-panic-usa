# S5 ghidra-hints — export table (stretch-panic-usa)

Run 2026-09-19-010-ghidra-hints. Ghidra 12.1.3 PUBLIC + ghidra-emotionengine-reloaded v2.1.37, language `r5900:LE:32:default`.

## Exports

| Export | Count | Size | Published |
|---|---|---|---|
| `functions.json` | 1669 | 0.2 MB | gitignored |
| `xrefs.json` | 25992 | 3.2 MB | gitignored |
| `strings.json` | 494 | 0.1 MB | gitignored |
| `decomp/<addr>.c` | 1666 | 2.5 MB | gitignored |
| `MANIFEST.json` | — | — | committed |

## Coverage against the ledger

| Measure | Count |
|---|---|
| ledger functions | 2027 |
| ledger entry addresses Ghidra also calls a function start | 1660 |
| ledger functions with a decompiler C file | 1657 |
| Ghidra function starts with no ledger entry | 9 |
| matched (77) with a Ghidra hint | 25 |
| defined strings | 494 |
| distinct functions referencing a string | 366 |

## Highest call-xref density among still-unmatched functions (S6 batch candidates)

| Function | Address | Incoming calls | Status | Decompiler C |
|---|---|---|---|---|
| func_0012E9A0 | 0x0012E9A0 | 342 | asm | yes |
| func_00125350 | 0x00125350 | 256 | asm | yes |
| func_0012E950 | 0x0012E950 | 165 | asm | yes |
| func_0012E9E0 | 0x0012E9E0 | 124 | asm | yes |
| func_0012D430 | 0x0012D430 | 98 | asm | yes |
| func_0012D450 | 0x0012D450 | 97 | asm | yes |
| func_00127BA0 | 0x00127BA0 | 92 | asm | yes |
| func_00127930 | 0x00127930 | 92 | asm | yes |
| func_0012E8A0 | 0x0012E8A0 | 77 | asm | yes |
| func_0013DF50 | 0x0013DF50 | 76 | asm | yes |
| func_00125260 | 0x00125260 | 65 | asm | yes |
| func_001250F0 | 0x001250F0 | 65 | asm | yes |
| func_0012CA30 | 0x0012CA30 | 59 | asm | yes |
| func_0016B6B0 | 0x0016B6B0 | 55 | asm | yes |
| func_0012CA60 | 0x0012CA60 | 55 | asm | yes |

Ledger status counts: asm 1243, library 672, matched 77, wip 35.

No decoded game string is reproduced here; the exports themselves stay out of git (see MANIFEST.json `publication`).
