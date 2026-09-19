# Run 2026-09-19-010-ghidra-hints — ghidra-hints

- Target: stretch-panic-usa
- Step: ghidra-hints (S5) — **override**: named in chat
- Started: 2026-09-19T04:42:32Z · Finished: 2026-09-19T04:46:42Z
- Commit: the commit whose message starts `run 2026-09-19-010-ghidra-hints:` (git log --grep)

## What changed

- Ledger: no status changes.
- The second S5 of the session, run against the toolchain the fate run had already installed in the cloud sandbox: no downloads, one analyzeHeadless pass (26 s of auto-analysis, language r5900:LE:32:default, zero decompile failures), and an 11 MB export that travelled back as a 666 KB tarball. The exports are gitignored under the same rule the fate run introduced (reference/ghidra/* with !reference/ghidra/MANIFEST.json, committed here as 407e404 before the run so the tree was clean for the pull); MANIFEST.json carries the Ghidra and extension versions, both archive sha256s, the ELF sha1 (0a330e76..., matching config/target.json) and the counts. The result worth judging is the coverage, which is not what the fate run saw: 1660 of 2027 ledger entries are function starts to Ghidra too, but only 25 of the 77 matched functions are, against 93 of 94 on fate. The 52 uncovered ones are all in game_01 and game_00 between 0x00131740 and 0x00176F50, none of them falls inside a Ghidra function body, and 37 are eight bytes long - Ghidra's auto-analyzer never created a function there, because nothing calls them by a plain reference. That is exactly the population S6 matches first, so the naming evidence this step was run for is thinnest where this target is furthest along, and the fix is cheap: a pre-script that calls createFunction at every config/symbol_addrs.txt address before the export (F-2). The hint set is still worth having for the dense end - func_0012E9A0 (342 incoming calls), func_00125350 (256) and func_0012E950 (165) are the S6 batch candidates K3 §8 names, and all three have decompiler C. The proposal stays S6 match-batch; S8 consolidate would now have machine-checkable naming evidence for the 25 covered matches, which is Jordan's call.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T04:46:34Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

n/a

## Proposed next step

S6 match-batch — 1278 game function(s) still asm/wip; batch size 12
- note: external lane: 15 runner batch(es), 64 matched, $0.71 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

2 entries (minor 1, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [papercut/tool-bug] git checkout -- .gitignore through git_mount.sh did not restore the file
- F-2 [minor/evidence-gap] Ghidra's auto-analysis misses the tiny leaf functions S6 matches first: only 25 of 77 matched functions got a hint
