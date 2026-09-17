# stretch-panic-usa — matching decompilation

Target repository of the Decompilation Assistant (PS2) project. One step of the
decompilation is performed per run; the state lives in this tree
(`config/`, `ledger/`, `state/`, `runs/`). The disc, the ELF and generated
assembly are not committed; `bootstrap.sh` and `extract_elf.py` recreate
them from the user's disc.

## Progress

<!-- progress-table:start -->
| Segment | Kind | Functions | Matched | Wip | Asm | Library | Bytes matched |
|---|---|---|---|---|---|---|---|
| (no ledger yet — functions appear after segment-map) | | | | | | | |
| image | unclassified | 0 | 0 | 0 | 0 | 0 | 0 |

Steps run: 1; last run: 2026-09-17-001-bootstrap; build check: not yet run; compiler: not calibrated; regenerated 2026-09-17T02:37:53Z.
<!-- progress-table:end -->

## Building and verifying

Nothing from the game is in this repository: no disc, no executable, no
extracted assets, no disassembly, no compiled objects. To build you need your
own copy of the disc; the toolchain (Metrowerks CodeWarrior for PS2, run under
wibo, plus splat and objdiff) is fetched by the project's bootstrap and pinned
in `tools/manifest.json`. The pinned compiler and flags are in
`config/compiler.json`; any function's C can be verified independently by
compiling it with that compiler and diffing the object against the original.

How progress is measured: a function counts as matched only when its compiled
`.text` is byte-identical to the original (objdiff score 100); the record in
`ledger/functions.jsonl` carries the object's sha256, the C's sha256, the
compiler id and the flags. After every step the full ELF is rebuilt and its
loaded memory image compared with the original (`build/check.json`).

Disclosure: this decompilation is AI-assisted. C is proposed by language models
and accepted only when it compiles byte-identical; every run's report and
friction log are committed under `runs/`. See `CONTRIBUTING.md` to contribute.

## License

The C source, headers, configuration and records in this repository are under
the MIT License (`LICENSE`). The game is not: it remains the property of its
rightsholders and is not distributed here.

## Layout

| Path | Holds |
|---|---|
| `config/` | `target.json` (extracted facts), `compiler.json` (pinned compiler + flags), `policy.json` (step budgets), `<slug>.yaml` (splat) |
| `tools/` | toolchain (gitignored except `manifest.json`) |
| `disc/` | boot ELF and extracted disc files (gitignored) |
| `asm/` | splat output (gitignored) |
| `src/`, `include/` | matched C and headers |
| `ledger/` | `functions.jsonl`, `segments.json` |
| `state/` | `steps.jsonl` |
| `runs/` | one folder per run: `RUN-STATE.json`, `RUN-REPORT.md`, `FRICTION-REPORT.md`, step tables |
| `wip/` | per-function work folders (`target.s` gitignored) |
| `reference/` | hints (Ghidra exports), never source |
| `build/` | build outputs and `check.json` (gitignored) |
