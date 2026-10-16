# Contributing to Stretch Panic

Pull requests are welcome on `src/`. The maintainer's tooling imports a merged pull request's source at the next run,
rebuilds it with the pinned toolchain and records a match only when the rebuilt code matches the original under the
project's criterion (the compiled code must be byte for byte the original's); a function that does not match stays as the reference line. Everything outside
`src/` (the documentation, the symbol map, shared headers) is generated from the maintainer's workbench, so a correction
there is welcome as an issue and is carried over by hand.

## The toolchain

mwccps2 mwcps2-2.3.3-000906; criterion `bytes`. `python3 configure.py` installs it from the pinned release into `tools/` and
`tools/check.py` compares the rebuilt artifact with your own original. No scratch from decomp.me or any other site is
copied here: the work is clean-room from the original file.

### PlayStation 2 specifics

- Pinned compiler: `mwcps2-2.3.3-000906` with `-O3,p -sdatathreshold 0`. Every function is compiled with exactly these; they change only when the
  calibration is redone, and this line changes with them.
- A matched function's object has `.text` byte-identical to the original function (objdiff score 100). A 99 % is work in
  progress: open an issue or a draft pull request with the score and a decomp.me link instead.
- Put the C in place of the function's `INCLUDE_ASM(...)` line in its translation unit under `src/<segment>/`
  (`unit_<ADDR>.c`, or `.cp` for C++); a function no unit file holds yet goes in a new `src/<segment>/<function>.c`, and
  the maintainer's next run moves it into its unit. Use the shared types in `include/` instead of re-declaring them.
- Where the releases differ, guard the differing lines with `#if VERSION_<ID>` / `#else` / `#endif` (the ids are in each
  `config/<SERIAL>/build.json`); `ninja` builds and checks every release present under `orig/`, so a change that matches
  one release and breaks another fails there first.
- Write it the way a person would have: no second struct laid over an element address, no byte arithmetic to reach a
  field, no `*(int *)&x`, no inline asm, no `do { } while (0)`, no permuter output left as it came out, no comments about
  how the match was found. `python3 tools/lint_c.py <file>` exits 0 on it. The exceptions are the instruction forms the
  compiler has no other source form for (a VU0 macro-mode block, a VU0 function returning a float written as a
  CodeWarrior asm function, an inline float-to-int conversion, the SDK's `ExitHandler()`/`EI()`/`DI()`): the lint
  reports them as advisory, and a comment above the block names the operation.
- Format with the repository's `.clang-format`. Never commit the disc, the executable, extracted files, disassembly,
  compiled objects or build output; the `.gitignore` refuses most of it.


## Naming

A name is written only with evidence a script can check (a string the function references, an SDK prototype a value is
passed to, a library symbol, a checked caller or callee, a member tested against a mask or bounding a loop); without it the
systematic name stays (it is better to leave it unnamed than name it wrongly). `docs/NAMES.md` lists every name with its
evidence, and the symbol map in `symbols/` carries it too. Original identifiers kept by the bytecode are names with evidence.
A pull request that names something states the facts; the maintainer's tooling checks them before the name is written.

## Readability

`python3 tools/lint_c.py <file>` (the contributor copy of the project's lint) refuses decompiler temporaries and
artifacts, pipeline comments, debug leftovers, unexplained `!FAKE` markers and placeholders. Comments say why and what is
uncertain, at most three lines per function; they never narrate the code. One definition per type.

## Pull requests

Small, one subsystem or a handful of functions each; the subject says what changed. The audit workflow refuses any
game-derived file. AI-assisted source is welcome when it meets the criterion and the lint; say so in the pull request.
