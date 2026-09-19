# Idiom matrix — run 2026-09-19-015-calibrate

Target `stretch-panic-usa`. Two idioms that separate compiler builds, probed over every
mwcps2 build in `tools/manifest.json` at the pinned flags `-O3,p -sdatathreshold 0`.
Complete: every build, every cell. The judgment is in the run report.

- **dispatch** — the register a two-load vtable dispatch calls through, from a C++ source with a real `virtual` member (`/tmp` probe `vcall.cp`). The image uses `$t9` at 449 of its 460 `jalr` sites (run 014 F-4 census).
- **ra_save** — how a non-leaf frame saves `$ra`. The image uses `sq` in every game segment and `sd` in every sdk segment.
- **conversion** — `(s32)(128.0f * f)`: inline `cvt.w.s` (`0x46000024`) or a call to the `fptosi` helper. The image inlines it at all 16 sites that have one.

| Compiler build | dispatch | ra_save | conversion |
|---|---|---|---|
| `mwcps2-2.3.3-000906` | `$t9` | `sq` | `fptosi` helper |
| `mwcps2-2.4-001213` | `$t9` | `sq` | `fptosi` helper |
| `mwcps2-3.0-011126` | `$t9` | `sd` | `fptosi` helper |
| `mwcps2-3.0.1-020123` | `$t9` | `sd` | `fptosi` helper |
| `mwcps2-3.0.1b103-040528` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b119-040914` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b145-050209` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b151-050317` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b198-051011` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b205-051227` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b210-060308` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b44-030325` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b51-030512` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b74-030811` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b75-030916` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b87-031208` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.1b95-040309` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0.3-020716` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0b38-030307` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0b50-030527` | `$t9` | `sd` | inline `cvt.w.s` |
| `mwcps2-3.0b52-030722` | `$t9` | `sd` | inline `cvt.w.s` |

## Image census (`asm/`, every function)

| | game segments | sdk segments |
|---|---|---|
| `sq $ra` | 958 (+30 in `mw_runtime`) | 1 |
| `sd $ra` | 0 | 348 |
| inline `cvt.w.s` | 16 functions | 0 |

Every function that contains an inline `cvt.w.s` is in a game segment, and each of the ten
that has a frame saves `$ra` with `sq` — so one build produced both idioms.
