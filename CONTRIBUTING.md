# Contributing

Contributions are welcome: matched functions, names and types backed by evidence, header
clean-ups and fixes.

## Compiler

Pinned: compiler `mwcps2-2.3.3-000906` with flags `-O3,p -sdatathreshold 0`. Every function is compiled with exactly these; they change
only when the calibration is redone, and this line is updated with them.

## Where to start

The current milestone selects from 26 functions labelled platform (no labels yet: game functions within 1 call(s) of 480 SDK/library anchor(s)). The smallest 26, which are the easiest place to start:

| Function | Address | Size | Segment |
|---|---|---|---|
| `func_00123520` | 0x00123520 | 100 | game_00 |
| `func_001211E0` | 0x001211E0 | 108 | game_00 |
| `func_00146D00` | 0x00146D00 | 120 | game_memcard |
| `func_0013C250` | 0x0013C250 | 136 | game_00 |
| `func_00123370` | 0x00123370 | 140 | game_00 |
| `func_00146C60` | 0x00146C60 | 148 | game_memcard |
| `func_00100008` | 0x00100008 | 160 | crt0 |
| `func_00145F00` | 0x00145F00 | 180 | game_memcard |
| `func_001468E0` | 0x001468E0 | 200 | game_memcard |
| `func_00146B90` | 0x00146B90 | 208 | game_memcard |
| `func_001463F0` | 0x001463F0 | 220 | game_memcard |
| `func_00146700` | 0x00146700 | 220 | game_memcard |
| `func_001469B0` | 0x001469B0 | 220 | game_memcard |
| `func_001216E0` | 0x001216E0 | 224 | game_00 |
| `func_0013DBF0` | 0x0013DBF0 | 224 | game_00 |
| `func_00146600` | 0x00146600 | 244 | game_memcard |
| `func_001467E0` | 0x001467E0 | 244 | game_memcard |
| `func_00146A90` | 0x00146A90 | 244 | game_memcard |
| `func_00146500` | 0x00146500 | 248 | game_memcard |
| `func_0013C2E0` | 0x0013C2E0 | 312 | game_00 |
| `func_00120A70` | 0x00120A70 | 392 | game_00 |
| `func_00121250` | 0x00121250 | 408 | game_00 |
| `func_00120E70` | 0x00120E70 | 648 | game_00 |
| `func_0011FA50` | 0x0011FA50 | 1016 | game_00 |
| `func_0011F5E0` | 0x0011F5E0 | 1044 | game_00 |
| `func_00127FD0` | 0x00127FD0 | 2908 | game_00 |

Build the repository first (README, "Building"); objdiff then shows each file's diff
against the original.

## A matched function

- The object compiled from your C has `.text` byte-identical to the original function
  (objdiff score 100). A 99 % is work in progress: open an issue or a draft pull request
  with the score and a decomp.me link instead.
- Put the C with the segment's other functions under `src/<segment>/` and use the shared
  types in `include/` (`common.h`, `types.h`) instead of re-declaring them.
- Write it the way a person would have: no second struct laid over an element address, no
  byte arithmetic to reach a field, no `*(int *)&x`, no inline asm, no `do { } while (0)`,
  no permuter output left as it came out, no comments about how the match was found.
  `python3 tools/lint_c.py --repo . <file>` exits 0 on it. The exceptions are the two
  instruction forms the compiler has no other source form for: a VU0 macro-mode block
  (`asm { }` of `lqc2`/`v*`/`sqc2` over `register` locals, with the `mfc1`/`qmtc2` pair
  that moves a float into it) and an inline float-to-int conversion (`asm { cvt.w.s f, f
  / mfc1 i, f }`). The lint reports both as advisory, and a comment above the block
  names the operation.
- Format with the repository's `.clang-format`.

## Names and types

A name or a struct field is added only with evidence: a referenced string, an SDK call
pattern, a cross-reference from a named caller. Say what the evidence is in the pull
request and in a short comment above the function. Without evidence the systematic name
(`func_00123456`, `D_0052ABCD`, `unk_XX`) stays; a placeholder is better than a wrong name.

## How a pull request is handled

`ninja` runs the whole-executable check on your machine before you open the pull request.
The maintainer's pipeline then rebuilds every function in the pull request with the pinned
compiler, records the result, and rebuilds and compares the whole executable. A pull
request is merged as a match when both are byte-identical. `README.md`, `CONTRIBUTING.md`,
`ROADMAP.md`, `PLATFORM.md`, `symbols/` and `progress/report.json` are generated from the
pipeline's records, so please do not edit them by hand; open an issue if something in them
is wrong.

## AI-assisted contributions

This repository is itself produced with language models (see the README). Contributions
made with AI assistance are welcome on the same terms as any other: say so in the pull
request, name the tool, and make sure you can explain every change. The byte match is the
gate; readable C and evidence-backed names are what make it done.

## Never commit

The disc, the executable, extracted files, disassembly, compiled objects or build
output. The `.gitignore` refuses most of it; please do not force it in.
