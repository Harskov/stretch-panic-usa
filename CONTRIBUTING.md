# Contributing

Contributions are welcome. This repository is maintained with an automated
step machine, so a few rules keep human and automated work from colliding.

## What a contribution looks like

- **A matched function**: the C for one or more functions, byte-identical to
  the original when compiled with the compiler and flags pinned in
  `config/compiler.json` (`compiler_id`, `flags`). Put the source where the
  segment's other functions live under `src/`, and state the objdiff score
  (100) in the pull request. A function is only "matched" when its compiled
  `.text` is byte-identical; a 99 % is a work-in-progress and can go in
  `wip/<function>/` as `attempt-N.c` with the score in the PR.
- **A name or a type**: only with evidence — a referenced string, an SDK call
  pattern, a cross-reference from a named caller. Say what the evidence is in
  the PR and in a comment above the function. Without evidence the systematic
  name (`func_00123456`, `D_0052ABCD`) stays.
- **A fix to a header or a build issue**: as usual.

## What not to touch by hand

`ledger/functions.jsonl`, `ledger/renames.jsonl`, `state/*.jsonl`,
`progress.json` and the README progress table are written by scripts from the
compiled evidence. Do not edit them in a pull request: the maintainer's next run
records your match in the ledger after rebuilding it with the pinned compiler
and checking the whole ELF (`build/check.json`). If the rebuild disagrees with
the PR, the PR is not merged as a match.

## Pull request checklist

- Compiler id and flags used (must equal `config/compiler.json`).
- Objdiff score per function.
- Evidence for every name or struct field you introduce.
- No compiled objects, no disassembly, no disc content, no ELF — the
  `.gitignore` refuses most of it; please do not force it in.

## Disclosure

Matching in this repository is done partly with AI assistance (LLM-proposed C,
verified by compiling and diffing). Contributions made the same way are fine;
please say so in the PR. What matters is the byte-identical object, not who or
what wrote the C.
