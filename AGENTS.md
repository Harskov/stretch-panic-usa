# Project profile: the code rules as this project applies them

This file is the project's profile for the decompilation code rules (R1-R37): the compiler's dialect, the
annotation and naming forms, the commands, and every rule the project tightens or relaxes, with the reason.
[CONTRIBUTING.md](CONTRIBUTING.md) says how to send a change; this file says what the source must look like
before a function counts.

## Two counts

A function is **matched** when the pinned compiler rebuilds it to the original's bytes (`ninja`, `check: OK`).
It is **matched under the rules** when it is matched *and* passes every [match] rule: R1 and R2 (one declaration
per type and per global), R4 (no offset casts), R13 (real vtables), R17 (no fake code) and R18 (no assembly
bodies). Matched but failing one is `MATCH-PENDING`: reported, not counted. `python3 tools/lint_rules.py`
computes both counts and lists every finding; its docstring has the exact test behind each rule.

The bytes win. A change made for a rule must leave every object as it was; when a rule and the bytes disagree,
keep the bytes and write `// RULE-EXCEPTION: <rule>, <reason the bytes give>` at the code. An exception bends
a style rule. It never licenses fake code.

## Compiler and dialect

Metrowerks CodeWarrior for PS2, `mwcps2-2.3.3-000906`, with `-O3,p -sdatathreshold 0`. The file extension picks
the language: `.c` is C, `.cpp` is C++. Checked against the pinned compiler:

| | accepted | rejected |
|---|---|---|
| C | `//` comments, `inline`, a trailing comma after the last enumerator, `asm { }` blocks and `asm` functions, `register`, `unsigned __int128` | a declaration after a statement, `for (int i ...)`, designated initializers |
| C++ | `bool`, a `for`-loop variable scoped to its loop, single inheritance with virtual functions | `nullptr` and everything else from C++11 |

So C units declare locals at the top of a block. A unit is C++ only where the original function needs it (a
virtual call, a class with a base): changing a unit's language changes how its functions are named and called.

## Annotations

| form | meaning |
|---|---|
| `INCLUDE_ASM("asm/nonmatchings/<segment>/<unit>", func_<ADDR>);` | a function not written yet. The build puts the original's assembly there. This is the project's parking mechanism (exempt from R37); such a function is not matched and not counted. |
| `// !FAKE: <what the original probably wrote>` | the body below matches only through a form nobody would write. The function is `MATCH-PENDING` (R17) until the real form is found. |
| `#if VERSION_US` / `VERSION_EU` / `VERSION_JP` | lines that differ between the three releases. These are real builds (R37). |
| `/* volatile: <evidence> */` | above a member or global declared `volatile`: what in the bytes needs it. Without the note the declaration fails R17. |
| `// RULE-EXCEPTION: <rule>, <reason>` | the bytes need a form a style rule discourages. |
| `guess:` | inside a comment: the claim after it is not established. |

## Names

No symbol table, debug information or source of the game survives; only SDK and runtime library functions,
format strings and the ELF header name anything. So this project tightens R7: **a name is written only with
evidence a script has checked**, and [docs/NAMES.md](docs/NAMES.md) records every such name with its
evidence. Nobody writes an invented name, however plausible. Until then the systematic placeholder stays:

| entity | placeholder | examples |
|---|---|---|
| function | `func_<ADDR>` | `func_0012C710` |
| global | `D_<ADDR>` | `D_006A6730` |
| type of the object at an address, or first used by a function | `Obj_<ADDR>`, `Sub_<ADDR>`, `Elem_<ADDR>`, `Blk_<ADDR>`, `Node_<ADDR>` | `Obj_006A6730`, `Node_006B3700` |
| type known only by its size | `Obj<SIZE>` | `Obj3B0`, `Obj2F8` |
| member | `unk_<OFFSET>` | `unk_350` |
| bytes no code reaches | `pad_<OFFSET>` | `u8 pad_520[0x1180];` |
| virtual function | `m<SLOT>` | `m4` |
| parameter | `arg<N>` | `arg0` |

A placeholder is open naming work, not a failed match. A type name identifies one layout: two units never
give different objects the same name (the address in the name is what keeps them apart).

The original's own naming style is unknown. When evidence earns a name, it takes the C++ engine forms of the
rules' default table (the binary is C++: vtables, `operator new`, mangled runtime symbols): `PascalCase` methods,
`lowerCamel` members with no `m_` prefix, `UPPER_SNAKE` constants. SDK and library names stay exactly as the
SDK spells them. Names already recorded in docs/NAMES.md stay as recorded.

## Declarations

- **Globals** (R2): each is declared once. `include/globals.h` lists them in address order with the types of
  the objects themselves; a global whose type has its own header is declared in that header, beside the type
  (`include/game_00/obj_006A6730.h`). A unit never writes `extern` for an object.
- **Types** (R1): a type two units use lives in a header under `include/<segment>/`, named for the type. A type
  only one unit uses may stay at the top of that unit. A second struct for part of an object another struct
  already describes (a "view") is a violation even under a different name: merge it into the first.
- **Both languages**: a class that C units also reach is declared once per language in one header, under
  `#ifdef __cplusplus` / `#else`, with `struct` as the keyword on both sides; the C side shows the vtable
  pointer as a member. A C++ class only its own unit defines is an incomplete `struct` everywhere else.
- **Prototypes** (R25): the functions of a unit that other units call belong in
  `include/<segment>/unit_<ADDR>.h`, or in the header of the object they work on. Most are still declared
  inside the calling units, and 140 of those declarations have empty parentheses; this is open work that
  `tools/lint_rules.py` counts. Moving one is [checked]: a prototype changes how a C call passes `float` and
  narrow integer arguments.

## Layout

`.clang-format` at the root fixes it: 4-space indent, 120 columns, the function's brace on its own line, the
brace of a control statement on the same line, pointers bound to the name. Format in a commit of its own.

A function's header comment (R33) is a plain block comment above it, at most three lines, saying what the
function does and what is uncertain; it never narrates the code and never says how the match was found. A
function whose purpose is unknown has none. `python3 tools/lint_c.py` checks comments.

The loaded image holds no line numbers and no unit uses `__LINE__` or `assert`, so layout changes cannot
change the bytes (R23).

## Units and order

One file under `src/<segment>/` is one original object file, named `unit_<ADDR>` for its first address until
its name is known, and its functions stay in address order (R15). Segments and their ranges are in
[docs/CODE-MAP.md](docs/CODE-MAP.md). Do not split, merge or reorder units.

## Rules this project changes

| rule | change | reason |
|---|---|---|
| R7 | tightened: no invented names at all | the project publishes each name with machine-checked evidence |
| R17, padding members | relaxed: `pad_<OFFSET>` is allowed | it is this project's spelling of an offset-named range that no code reaches, and `tools/lint_c.py` rejects any code that reaches one. A `pad` not named for its offset still fails. |
| R17, fake bodies | tightened: every `// !FAKE:` body is `MATCH-PENDING` | the marker is the project's own admission that the form is not the original's |
| R18, listed helpers | three inline-assembly forms are original helpers: a VU0 macro-mode block (COP2 instructions and the moves that feed them), a float-to-int block (`cvt.w.s` and its moves), and the kernel's `EI`/`DI`/`ExitHandler` block | the pinned compiler has no C spelling for any of them and the image holds those instructions inline in compiled functions, so the original source had them as assembly too. A function that uses one is counted, and listed. |
| R18, original assembly | a whole `asm` function whose body is the VU0 form and returns a float (`jr ra` with `mtc1` in the delay slot) is `ORIGINAL-ASM` | the compiler never emits that return sequence. Listed apart, counted neither as matched nor in the total. |
| R13 | the checker tests only the names of virtuals | the binary's vtables are not in this repository; the maintainer's tooling checks slot counts when it accepts a function |
| R33 | the header comment is a plain comment of at most three lines, and optional when the purpose is unknown | see Layout |

Every other rule applies as written.

## Evidence sources

The three release executables (USA, Europe, Japan, which share most of their code), the SCE symbol
database matches for SDK and runtime functions, strings and format strings in the image, SDK prototypes, and
[PLATFORM.md](PLATFORM.md). No disassembly, decompiler output or game data is ever committed.

## Commands

| what | command |
|---|---|
| set up, split your own copy, write `build.ninja` | `python3 configure.py` |
| build everything and compare with the original (the byte gate) | `ninja` |
| one function against the original | open the folder in objdiff (`objdiff.json`) |
| the [match] rules and the two counts | `python3 tools/lint_rules.py` (`--list`, `--json`, `--strict`) |
| readability, comments, offset casts, assembly forms | `python3 tools/lint_c.py` |

A change to source is ready when `ninja` prints `check: OK`, `tools/lint_c.py` exits 0, and
`tools/lint_rules.py` reports no new `MATCH-PENDING` function.

## Generated files

`README.md`'s progress section, `ROADMAP.md`, `PLATFORM.md`, everything under `docs/`, `symbols/`, `progress/`
and `config/*/symbols-evidence.tsv` are written by the maintainer's tooling. Never edit them by hand (R24);
open an issue instead.
