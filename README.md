# Stretch Panic (USA)

[![Progress report](https://github.com/Harskov/stretch-panic-usa/actions/workflows/report.yml/badge.svg)](https://github.com/Harskov/stretch-panic-usa/actions/workflows/report.yml)
[![Audit](https://github.com/Harskov/stretch-panic-usa/actions/workflows/audit.yml/badge.svg)](https://github.com/Harskov/stretch-panic-usa/actions/workflows/audit.yml)
[![Code](https://decomp.dev/Harskov/stretch-panic-usa.svg?mode=shield&measure=code&label=Code)](https://decomp.dev/Harskov/stretch-panic-usa)

A work-in-progress matching decompilation of *Stretch Panic* for the PlayStation 2
(NTSC-U, `SLUS_201.82`): C source that the game's original compiler, Metrowerks
CodeWarrior for PS2, turns back into the same machine code.

This repository does **not** contain any game assets or assembly whatsoever. An existing
copy of the game is required. The `Audit` workflow runs `tools/audit_public.py` on every
push and pull request and fails when a tracked file is game-derived — by its path or
extension, by its first bytes, by a SHA-1 recorded in `config/SLUS_201.82/checksum.sha1`,
or by a size no source file reaches.

## AI disclosure

This decompilation is produced with language models. Claude (Anthropic) writes the C.
For part of September 2026 a second, cheaper model also proposed matches for simpler
functions through a local tool; that lane is retired. Every commit that adds or changes C
names the model that wrote it in a credit line (`Co-Authored-By: Claude` or
`Assisted-by: <model>`). A function counts as matched only
when the pinned compiler rebuilds it byte-identical to the original, and the whole
executable is rebuilt and compared after every change. Names are given only with cited
evidence (a referenced string, an SDK call pattern, a named caller); without it the
systematic name (`func_00123456`, `D_0052ABCD`) stays, and struct fields stay `unk_XX`.

## Supported versions

| Version | Executable | SHA-1 |
|---|---|---|
| NTSC-U | `SLUS_201.82` | `0a330e76424b7254e4096d8809b2a927603d3581` |

## Progress

**8,172 of 383,756 bytes of game code are matched (2.13 %)**: 147 of 1355 game functions. 3 game functions and 450 of 672 SDK and runtime functions carry a name backed by evidence; 20 structs are typed in shared headers. SDK and runtime-library code is identified as such and not counted as game code.

| Milestone | Status | Exit judged on |
|---|---|---|
| M1 Contributable | done | public build ok (translation-unit, 2026-09-29T23:55:53Z); 0 matched function(s) still in per-function files; units map present |
| M2 Identified | done | 1 complete name-pass run(s); 1355 of 1355 game functions labelled |
| M3 Platform boundary | current | 6 of 294 function(s) labelled platform matched (912 of 145972 bytes); PLATFORM.md present |
| M4 Core | pending | 0 of 54 function(s) labelled core matched (0 of 13784 bytes); FORMATS.md missing |
| M5 Gameplay | pending | 141 of 1007 function(s) labelled gameplay matched (7260 of 224000 bytes) |
| M6 Complete | pending | 8172 of 383756 game bytes matched; check ok |

The milestones and why they come in this order: [ROADMAP.md](ROADMAP.md).

The per-function report is on [decomp.dev](https://decomp.dev/Harskov/stretch-panic-usa).

## Building

You need Linux x86-64 (WSL2 on Windows works), Python 3.8 or newer, git, and your own
copy of the game.

1. Copy `SLUS_201.82` from your disc to `orig/SLUS_201.82/SLUS_201.82`.
2. `python3 -m pip install -r requirements.txt` installs splat and ninja.
3. `python3 configure.py` checks your copy against `config/SLUS_201.82/checksum.sha1`,
   downloads the pinned tools into `tools/` (each checked against the sha256 in
   `config/SLUS_201.82/build.json`), splits the executable into `asm/` with splat, and
   writes `build.ninja` and `objdiff.json`.
4. `ninja` compiles every matched C file with the pinned compiler (compiler `mwcps2-2.3.3-000906` with flags `-O3,p -sdatathreshold 0`),
   assembles the rest, links, and checks that the rebuilt executable's loaded image
   equals the original's byte for byte.

To work on a function, open the repository folder in
[objdiff](https://github.com/encounter/objdiff): `objdiff.json` pairs every C file with
splat's disassembly of the same range. [decomp.me](https://decomp.me) has the same
compiler for trying a single function.

## Symbols and documentation

Generated from the match records at every change, never edited by hand:

- `symbols/SLUS_201.82.txt`: every function's name and address, for Ghidra's
  `ImportSymbolsScript.py`; `symbols/SLUS_201.82.sym`: the same for the PCSX2 debugger;
  `symbols/SLUS_201.82.subsystems.tsv`: each function's subsystem label.
- `config/SLUS_201.82/symbols-evidence.tsv`: the evidence behind every name.
- [PLATFORM.md](PLATFORM.md): the SDK functions, IOP modules, VU microprograms and
  hardware registers the game uses, and the functions that use them.
- [ROADMAP.md](ROADMAP.md): the milestones, why they come in this order, and where the
  project stands.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md). Pull requests with plain, readable C are welcome.

## Layout

| Path | Holds |
|---|---|
| `src/` | matched C, one folder per segment of the executable |
| `include/` | shared headers and types |
| `config/SLUS_201.82/` | splat configuration, `symbol_addrs.txt`, `checksum.sha1`, the tool pins (`build.json`), `symbols-evidence.tsv` |
| `orig/SLUS_201.82/` | where your copy of the executable goes (gitignored) |
| `configure.py`, `requirements.txt` | the build set-up |
| `tools/` | `dps2build.py` (the build graph), `download_tool.py`, `check.py`, `audit_public.py` (the game-derived-file audit the `Audit` workflow runs), and `lint_c.py`, the readability check every matched file passes; the downloaded tools land here too (gitignored) |
| `symbols/` | the symbol map for Ghidra and PCSX2, and the subsystem labels |
| `progress/report.json` | the objdiff progress report uploaded to decomp.dev |

## License

The C source, headers and configuration are under the MIT License (`LICENSE`). The game
remains the property of its rightsholders and is not distributed here.
