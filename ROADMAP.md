# Roadmap — Stretch Panic

The project serves four purposes — preservation, recompilation, porting and learning — and orders its milestones by what helps other people soonest. Each milestone's exit is a file or a record, not a judgment. Generated from `config/milestones.json` and the match records; never edited by hand.

| # | Milestone | Status | Exit judged on |
|---|---|---|---|
| M1 | Contributable | done | public-build.json ok=True; matched outside their unit: 0 |
| M2 | Identified | current | name pass closed: True; unlabelled game functions: 0; review pending: 62 |
| M3 | Platform boundary | later | 58/293 platform functions matched; PLATFORM.md present |
| M4 | Core | later | 15/51 core functions matched; FORMATS.md missing |
| M5 | Gameplay | later | 437/1007 gameplay functions matched |
| M6 | Complete | later | 510/1351 game functions matched; check ok=True |
| M7 | Documented | later | docs.py check ok=None (never run) |
| M8 | Behaviour-verified | not required | last behaviour compare ok=None at never |
| M9 | Reverse-engineered | done | names without checked evidence: 0; matches since the last name pass: 0; named types with two layouts: 0 |

Readability debt: 7 function(s) carry a `// !FAKE:` body and 0 carry a lint finding (see CONTRIBUTING.md); a pull request that replaces one with plain source that still matches is welcome.

Reverse-engineering debt: 0 name(s) wait for a fact a script can check (M9); [docs/NAMES.md](docs/NAMES.md) lists every name with its evidence.
