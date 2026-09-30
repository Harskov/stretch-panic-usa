# Contributing

Contributions are welcome: matched functions, names and types backed by evidence, header
clean-ups and fixes.

## Compiler

Pinned: compiler `mwcps2-2.3.3-000906` with flags `-O3,p -sdatathreshold 0`. Every function is compiled with exactly these; they change
only when the calibration is redone, and this line is updated with them.

## Where to start

The current milestone selects from 261 functions labelled platform (labels platform (ledger)). The smallest 40, which are the easiest place to start:

| Function | Address | Size | Segment |
|---|---|---|---|
| `func_0016D9F0` | 0x0016D9F0 | 44 | game_01 |
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
| `func_0016E2D0` | 0x0016E2D0 | 108 | game_01 |
| `func_0017C430` | 0x0017C430 | 108 | game_01 |
| `func_00121A60` | 0x00121A60 | 112 | game_00 |
| `func_00123400` | 0x00123400 | 116 | game_00 |
| `func_0012CA90` | 0x0012CA90 | 116 | game_00 |
| `func_00146D00` | 0x00146D00 | 120 | game_memcard |
| `func_0015D9C0` | 0x0015D9C0 | 120 | game_01 |
| `func_00152640` | 0x00152640 | 124 | game_01 |
| `func_0016B1D0` | 0x0016B1D0 | 124 | game_01 |
| `func_0013BF30` | 0x0013BF30 | 128 | game_00 |
| `func_0016DB10` | 0x0016DB10 | 132 | game_01 |
| `func_0016DBA0` | 0x0016DBA0 | 132 | game_01 |
| `func_0016DF60` | 0x0016DF60 | 132 | game_01 |
| `func_0013C250` | 0x0013C250 | 136 | game_00 |
| `func_00123370` | 0x00123370 | 140 | game_00 |
| `func_00124080` | 0x00124080 | 140 | game_00 |
| `func_00164A80` | 0x00164A80 | 140 | game_01 |
| `func_0012DD20` | 0x0012DD20 | 144 | game_00 |
| `func_0017AFC0` | 0x0017AFC0 | 144 | game_01 |
| `func_00146C60` | 0x00146C60 | 148 | game_memcard |
| `func_0014F280` | 0x0014F280 | 148 | game_01 |
| `func_00130E10` | 0x00130E10 | 156 | game_00 |
| `func_0016E9A0` | 0x0016E9A0 | 156 | game_01 |
| `entry` | 0x00100008 | 160 | crt0 |
| `func_00178020` | 0x00178020 | 160 | game_01 |

Build the repository first (README, "Building"); objdiff then shows each file's diff
against the original.

## A matched function

- The object compiled from your C has `.text` byte-identical to the original function
  (objdiff score 100). A 99 % is work in progress: open an issue or a draft pull request
  with the score and a decomp.me link instead.
- Put the C in place of the function's `INCLUDE_ASM(...)` line when a translation unit under
  `src/<segment>/` holds it (`unit_<ADDR>.c`, or `.cpp` for C++); a function no unit file
  holds yet goes in a new `src/<segment>/<function>.c`, and the maintainer's next run moves it
  into its unit. Use the shared types in `include/` (`common.h`, `types.h`) instead of
  re-declaring them.
- Write it the way a person would have: no second struct laid over an element address, no
  byte arithmetic to reach a field, no `*(int *)&x`, no inline asm, no `do { } while (0)`,
  no permuter output left as it came out, no comments about how the match was found.
  `python3 tools/lint_c.py --repo . <file>` exits 0 on it. The exceptions are the four
  instruction forms the compiler has no other source form for: a VU0 macro-mode block
  (`asm { }` of `lqc2`/`v*`/`sqc2` over `register` locals, with the `mfc1`/`qmtc2` pair
  that moves a float into it, and a `nop` or `.set noreorder`/`.set reorder` where the
  original has no hazard nop); a VU0 function that returns a float, written whole as a
  CodeWarrior asm function (`asm f32 f(...) { ... qmfc2 a0, vf2 / jr ra / mtc1 a0, f0 }`,
  because a block's `mtc1` never reaches the return's delay slot); an inline float-to-int
  conversion (`asm { cvt.w.s f, f / mfc1 i, f }`); and the SDK's
  `ExitHandler()`/`EI()`/`DI()` (`asm { sync / ei }`). The lint reports them as advisory,
  and a comment above the block names the operation.
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
