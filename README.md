# Stretch Panic

[![Audit](https://github.com/Harskov/stretch-panic-usa/actions/workflows/audit.yml/badge.svg)](https://github.com/Harskov/stretch-panic-usa/actions/workflows/audit.yml)
[![Code](https://bytematch.dev/Harskov/stretch-panic-usa.svg?label=Code&measure=matched_code_percent&category=game)](https://bytematch.dev/Harskov/stretch-panic-usa)
[![Functions](https://bytematch.dev/Harskov/stretch-panic-usa.svg?label=Functions&measure=matched_functions&category=game)](https://bytematch.dev/Harskov/stretch-panic-usa)

A decompilation of Stretch Panic (PlayStation 2). It builds any of the following releases from the same source:

| Release | Region | Executable | SHA-1 | Size |
|---|---|---|---|---|
| Stretch Panic | USA | `SLUS_201.82` | `0a330e76424b7254e4096d8809b2a927603d3581` | 5898360 bytes |
| Freak Out | Europe | `SLES_503.10` | `fe80cf507bb438e5cf51cc55f7865ec962125e6a` | 5899384 bytes |
| Hippa Linda | Japan | `SLPM_621.09` | `14fb5cef008dc24b7826492cccdef7fe7d6cbdd3` | 6191480 bytes |

**This repository contains no game assets**: no original file, no extracted asset, no decompiler output and no reference
P-code or assembly. Building it needs your own copy of the game. The source was written function by function, much of it
with AI assistance, and accepted only when the pinned toolchain rebuilt it to match the original; see
[How the source was made](#how-the-source-was-made-and-the-ai-disclosure).

## Building

You need Linux x86-64 (WSL2 on Windows works), Python 3.9 or newer, git, and your own copy of the game.

1. Clone this repository.
2. Copy the executable the table names from your disc (it sits beside `SYSTEM.CNF`) to `orig/<SERIAL>/<SERIAL>`, for example `orig/SLUS_201.82/SLUS_201.82`; its SHA-1 must be the one in the table. Any listed release builds, and several can sit side by side.
3. `python3 -m pip install -r requirements.txt` installs splat and ninja.
4. `python3 configure.py` checks each copy it finds against `config/<SERIAL>/checksum.sha1`, downloads the pinned tools into `tools/` (each checked against the sha256 in `config/<SERIAL>/build.json`), splits each executable with splat, and writes `build.ninja` and `objdiff.json`.
5. `ninja` compiles every matched C file with the pinned compiler (`mwcps2-2.3.3-000906` with `-O3,p -sdatathreshold 0`), assembles the rest, links, and checks that each rebuilt executable's loaded image equals the original's byte for byte (`check: OK`).

## Progress

**448 of 1351 game functions are matched** (7,204 of 95,883 instructions, 7.51 %). 0 of the matched and 2 of all game functions carry a name whose evidence a script checked; so do 3 of 196 types, 60 of 639 members the matched code reaches, 9 of 197 globals the matched code reaches; 1351 functions carry a subsystem label. Every name and its evidence: [docs/NAMES.md](docs/NAMES.md).

| Milestone | Status | Exit judged on |
|---|---|---|
| M1 Contributable | done | public-build.json ok=True; matched outside their unit: 0 |
| M2 Identified | done | name pass closed: True; unlabelled game functions: 0; review pending: 0 |
| M3 Platform boundary | current | 54/293 platform functions matched; PLATFORM.md present |
| M4 Core | later | 11/51 core functions matched; FORMATS.md missing |
| M5 Gameplay | later | 383/1007 gameplay functions matched |
| M6 Complete | later | 448/1351 game functions matched; check ok=True |
| M7 Documented | later | docs.py check ok=None (never run) |
| M8 Behaviour-verified | not required | last behaviour compare ok=None at never |
| M9 Reverse-engineered | later | names without checked evidence: 18; matches since the last name pass: 223; named types with two layouts: 0 |

The milestones and why they come in this order: [ROADMAP.md](ROADMAP.md).

The same reports are tracked on [ByteMatch](https://bytematch.dev/Harskov/stretch-panic-usa): the report workflow uploads it on every push (`SLUS_201.82_report`).

## How the source was made, and the AI disclosure

The source here was written function by function and accepted only when the pinned toolchain rebuilt it to match the
original under the project's criterion (the compiled code must be byte for byte the original's). Much of it was drafted with AI assistance (Claude, and the
batch lane's models); every accepted function was rebuilt and compared by the tooling on the maintainer's machine, and
the commit that adds a function carries a credit line naming who wrote it (`Co-Authored-By: Claude <noreply@anthropic.com>`
for the operator's model, `Assisted-by: <model> (batch)` for the batch lane). A name — of a function, a type, a struct member
or a global — is written only after a script has checked each fact it cites against the code (a string, an SDK prototype, a
library symbol, a checked caller, what the matched code does with a member) and every word of the name against those facts;
otherwise the systematic placeholder stays. [docs/NAMES.md](docs/NAMES.md) lists every name with its evidence, so each one can
be checked again. A function marked `// !FAKE:` matches
through an implausible form and is listed as readability debt in [ROADMAP.md](ROADMAP.md).

## Platform: PlayStation 2 (Metrowerks CodeWarrior)

The game is a PS2 executable for the Emotion Engine (a MIPS R5900). The source under `src/` is C (C++ where the original
was) that the game's own compiler, Metrowerks CodeWarrior for PS2 (`mwcps2-2.3.3-000906` with `-O3,p -sdatathreshold 0`), compiles back to the same machine
code; a function not yet written stays an `INCLUDE_ASM` line that pulls in splat's disassembly of it, split from your own
copy at build time. A function is accepted when its compiled `.text` is byte for byte the original's, and the whole
executable is rebuilt and its loaded image compared after every change.

One source tree builds every listed release. The releases share most of their code; where one differs, the source says so with a preprocessor conditional on the release (`VERSION_US`, `VERSION_EU`, `VERSION_JP`) around the differing lines, and a function only one release has is guarded the same way. The USA release splits into `asm/` and builds into `build/`; every other release into `asm/<id>/` and `build/<id>/`, at its own addresses.

To work on a function, open the repository folder in [objdiff](https://github.com/encounter/objdiff): `objdiff.json`
pairs every C file with splat's disassembly of the same range. [decomp.me](https://decomp.me) has the same compiler for
trying a single function.

Generated from the match records at every change, never edited by hand: `symbols/<SERIAL>.txt` (every function's name
and address, for Ghidra's `ImportSymbolsScript.py`), `symbols/<SERIAL>.sym` (the same for the PCSX2 debugger) and
`symbols/<SERIAL>.subsystems.tsv` (each function's subsystem label), one set per release at that release's addresses;
`config/<SERIAL>/symbols-evidence.tsv` (the evidence behind every name); [PLATFORM.md](PLATFORM.md) (the SDK functions,
IOP modules, VU microprograms and hardware registers the game uses, and the functions that use them).


## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md): the layout, the toolchain, the naming rule, the readability lint and what the
maintainer's tooling does with a merged pull request.

## Layout

`src/` the source in the layout the toolchain consumes (one file per unit; a function not yet accepted is a reference
line) · `docs/` the architecture, the subsystem pages, the code map and `NAMES.md` (every name and its evidence) · `config/<SERIAL>/` each release's splat configuration, symbol map, checksums and tool pins · `include/` the shared headers and types · `orig/<SERIAL>/` where your copy of the executable goes (gitignored) · `symbols/` the symbol map with its evidence · `tools/` the contributor copies of the lint and the check ·
`progress/report.json` the progress report.

## License

The source in this repository is dedicated to the public domain under CC0 1.0 Universal (see LICENSE). The game itself is not
covered: nothing of it is here.
