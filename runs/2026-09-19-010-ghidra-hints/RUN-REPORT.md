# Run 2026-09-19-010-ghidra-hints — ghidra-hints

- Target: stretch-panic-usa
- Step: ghidra-hints (S5) — **override**: named in chat
- Started: 2026-09-19T04:42:32Z · Finished: 2026-09-19T04:46:42Z
- Commit: the commit whose message starts `run 2026-09-19-010-ghidra-hints:` (git log --grep)

## What changed

- Ledger: no status changes.

## Build check

`check.json`: ok = **True**, checked 2026-09-19T04:46:34Z, regime `full`; image 0x00100000–0x0069F800, rebuilt 5896192 of 5896192 bytes; first diff None, 0 differing byte(s). Segments: crt0 ok; mw_runtime ok; sdk_libgraph ok; sdk_libdma ok; sdk_libkernel ok; sdk_libpad ok; sdk_libcdvd ok; sdk_libmc ok.

## Step table

n/a

## Proposed next step

S6 match-batch — 1278 game function(s) still asm/wip; batch size 12
- note: external lane: 15 runner batch(es), 64 matched, $0.71 in state/runner-steps.jsonl (never a step of a run)

## Friction filed

4 entries (minor 3, papercut 1); stages attested: E, R, S, V, X; export: FRICTION-REPORT.md
- F-1 [papercut/tool-bug] git checkout -- .gitignore through git_mount.sh did not restore the file
- F-2 [minor/evidence-gap] Ghidra's auto-analysis misses the tiny leaf functions S6 matches first: only 25 of 77 matched functions got a hint
- F-3 [minor/operator-drift] the operator's name was written into the run report's judgment paragraph
- F-4 [minor/tool-gap] friction_log.py amend cannot redact a scrub token: the original field stays verbatim in the committed jsonl
