# Stretch Panic (USA) SLUS_201.82 — matching decompilation

[![Progress report](https://github.com/Harskov/stretch-panic-usa/actions/workflows/report.yml/badge.svg)](https://github.com/Harskov/stretch-panic-usa/actions/workflows/report.yml)
[![Code progress](https://decomp.dev/Harskov/stretch-panic-usa.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/Harskov/stretch-panic-usa)

Target repository of the Decompilation Assistant (PS2) project. One step of the
decompilation is performed per run; the state lives in this tree
(`config/`, `ledger/`, `state/`, `runs/`). The disc, the ELF and generated
assembly are not committed; `bootstrap.sh` and `extract_elf.py` recreate
them from the user's disc.

## Progress

<!-- progress-table:start -->
| Segment | Kind | Functions | Matched | Wip | Asm | Library | Bytes matched |
|---|---|---|---|---|---|---|---|
| crt0 | game | 4 | 0 | 0 | 4 | 0 | 0 (0.0%) |
| mw_runtime | libc | 39 | 0 | 0 | 0 | 39 | 0 (0.0%) |
| sdk_libgraph | sdk | 21 | 0 | 0 | 0 | 21 | 0 (0.0%) |
| sdk_libdma | sdk | 12 | 0 | 0 | 0 | 12 | 0 (0.0%) |
| sdk_libkernel | sdk | 339 | 0 | 0 | 0 | 339 | 0 (0.0%) |
| sdk_libpad | sdk | 34 | 0 | 0 | 0 | 34 | 0 (0.0%) |
| sdk_libcdvd | sdk | 48 | 0 | 0 | 0 | 48 | 0 (0.0%) |
| sdk_libmc | sdk | 26 | 0 | 0 | 0 | 26 | 0 (0.0%) |
| sdk_libm | sdk | 30 | 0 | 0 | 0 | 30 | 0 (0.0%) |
| sdk_libc | libc | 123 | 0 | 0 | 0 | 123 | 0 (0.0%) |
| game_00 | game | 563 | 2 | 1 | 560 | 0 | 144 (0.1%) |
| game_memcard | game | 74 | 0 | 0 | 74 | 0 | 0 (0.0%) |
| game_01 | game | 714 | 111 | 50 | 553 | 0 | 4004 (1.8%) |
| data_vu | data | 0 | 0 | 0 | 0 | 0 | 0 |
| data_sdk | data | 0 | 0 | 0 | 0 | 0 | 0 |
| data_game | data | 0 | 0 | 0 | 0 | 0 | 0 |
| rodata_00 | rodata | 0 | 0 | 0 | 0 | 0 | 0 |
| main_bss | bss | 0 | 0 | 0 | 0 | 0 | 0 |
| **total** | | 2027 | 113 | 51 | 1191 | 672 | 4148 / 510776 |

Matched functions whose C still carries a layout cast flagged by `lint_c.py` (byte-identical, not final source; rewritten at consolidate): 2 — func_0014E460, func_00152600.

Matched by the operator: 19; by the external lane (MatchRunner): 94 in 24 batch(es) (last 2026-09-19-015).

Steps run: 12; last run: 2026-09-19-012-consolidate; build check: ok; compiler: mwcps2-2.3.3-000906; regenerated 2026-09-19T12:46:52Z.
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
friction log are committed under `runs/`. Provenance is per function: the ledger
record says who wrote the C (`match.origin`: the operator session, or the
MatchRunner lane with its model and prompt hash). Byte-identical is the gate, not
the goal: C that reaches 100 through a layout cast or a permuter's text is flagged
by `tools/lint_c.py` (listed in the progress table when any exist) and rewritten
as plain C at the next consolidate step. See `CONTRIBUTING.md` to contribute.

## Progress reporting

Progress is published the way the decompilation community tracks it, through
[decomp.dev](https://decomp.dev): `tools/objdiff_report.py` writes an objdiff (v2)
report from `ledger/functions.jsonl`, and the `Progress report` workflow generates it
on every push to `main`, validates it with `objdiff-cli` and uploads it as the
`<BOOT2 file>_report` artifact decomp.dev consumes. The ledger is the evidence behind
every number: a function is recorded as matched only after the pinned compiler
rebuilt its C byte-identical on the maintainer's machine, where the disc is, so the
workflow needs nothing from the game. To regenerate the report locally:

```sh
python3 tools/objdiff_report.py --repo . --out build/report.json
```

`matched_code` counts byte-identical functions; `complete_code` counts those linked
into the rebuilt ELF whose loaded image equals the original's (`build/check.json`).
Categories: game code, SDK and libc.

## Contributing

`CONTRIBUTING.md` has the pinned compiler id and flags, how to verify a function at
[decomp.me](https://decomp.me) or locally with objdiff against your own copy of the disc,
and how a match is recorded in the ledger. Pull requests with plain, readable C are
welcome; a matched function is one whose object is byte-identical to the original.

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
