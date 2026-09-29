# Contributing

Contributions are welcome: matched functions, names and types backed by evidence, header
clean-ups and fixes.

## Compiler

Pinned: compiler `mwcps2-2.3.3-000906` with flags `-O3,p -sdatathreshold 0`. Every function is compiled with exactly these; they change
only when the calibration is redone, and this line is updated with them.

## Where to start

The current milestone selects from 288 functions labelled platform (labels platform (ledger)). The smallest 40, which are the easiest place to start:

| Function | Address | Size | Segment |
|---|---|---|---|
| `func_0012EE10` | 0x0012EE10 | 20 | game_00 |
| `func_00122460` | 0x00122460 | 24 | game_00 |
| `func_0012EDF0` | 0x0012EDF0 | 24 | game_00 |
| `func_0012E850` | 0x0012E850 | 28 | game_00 |
| `func_0012EE50` | 0x0012EE50 | 28 | game_00 |
| `func_0012E950` | 0x0012E950 | 32 | game_00 |
| `func_0012E9A0` | 0x0012E9A0 | 32 | game_00 |
| `func_0012E9C0` | 0x0012E9C0 | 32 | game_00 |
| `func_0012E9E0` | 0x0012E9E0 | 32 | game_00 |
| `func_0012EA00` | 0x0012EA00 | 32 | game_00 |
| `func_0012EE30` | 0x0012EE30 | 32 | game_00 |
| `func_0012EE70` | 0x0012EE70 | 32 | game_00 |
| `func_0012C810` | 0x0012C810 | 36 | game_00 |
| `func_0012E870` | 0x0012E870 | 36 | game_00 |
| `func_0012E970` | 0x0012E970 | 36 | game_00 |
| `func_0012EA50` | 0x0012EA50 | 36 | game_00 |
| `func_0012EE90` | 0x0012EE90 | 36 | game_00 |
| `func_0012E820` | 0x0012E820 | 40 | game_00 |
| `func_0012E920` | 0x0012E920 | 40 | game_00 |
| `func_0012CA30` | 0x0012CA30 | 44 | game_00 |
| `func_0012CA60` | 0x0012CA60 | 44 | game_00 |
| `func_0016D9F0` | 0x0016D9F0 | 44 | game_01 |
| `func_0012EA20` | 0x0012EA20 | 48 | game_00 |
| `func_0013BD20` | 0x0013BD20 | 52 | game_00 |
| `func_0012E8A0` | 0x0012E8A0 | 56 | game_00 |
| `func_0012E8E0` | 0x0012E8E0 | 56 | game_00 |
| `func_0016DFF0` | 0x0016DFF0 | 72 | game_01 |
| `func_0016E270` | 0x0016E270 | 96 | game_01 |
| `func_00123520` | 0x00123520 | 100 | game_00 |
| `func_0012C950` | 0x0012C950 | 100 | game_00 |
| `func_0012C9C0` | 0x0012C9C0 | 100 | game_00 |
| `func_0017C3C0` | 0x0017C3C0 | 100 | game_01 |
| `func_0017C4A0` | 0x0017C4A0 | 100 | game_01 |
| `func_0013FCB0` | 0x0013FCB0 | 104 | game_00 |
| `func_0015E000` | 0x0015E000 | 104 | game_01 |
| `func_0016E040` | 0x0016E040 | 104 | game_01 |
| `func_0016E0B0` | 0x0016E0B0 | 104 | game_01 |
| `func_00179D80` | 0x00179D80 | 104 | game_01 |
| `func_001211E0` | 0x001211E0 | 108 | game_00 |
| `func_00128C40` | 0x00128C40 | 108 | game_00 |

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

## Two markers you may see

A `register` local kept only so the compiler allocates the way the original did, and a
body marked `// !FAKE: <what a programmer would have written>` — C kept only because it
matches — are readability debt, not finished source. `tools/lint_c.py` reports both
(`register-pin`, `fake-body`), the maintainer's pipeline publishes their counts in
`ROADMAP.md`, and a pull request that replaces one with plain C that still matches is
welcome. A `// !FAKE:` without its reason fails the lint.

## Never commit

The disc, the executable, extracted files, disassembly, compiled objects or build
output. The `.gitignore` refuses most of it; please do not force it in.
