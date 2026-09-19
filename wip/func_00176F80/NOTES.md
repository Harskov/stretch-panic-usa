# func_00176F80 @ 0x00176F80 — 148 bytes, segment game_01

Compiler: mwcps2-2.3.3-000906 `-O3,p -sdatathreshold 0`; m2c seed: ok; externs: 1 data, 2 functions.

Write attempt-1.c (function named exactly as above; include "ctx.c" declarations you need by copying them, not the file), then:

    python3 skills/dps2-toolkit/scripts/match.py --repo targets/<slug> try func_00176F80 wip/func_00176F80/attempt-1.c

On 100:  python3 skills/dps2-toolkit/scripts/ledger.py --repo targets/<slug> mark func_00176F80 --from wip/func_00176F80/attempt-N.c
Stuck after 3 substantive attempts:  match.py permute func_00176F80  then  ledger.py set-status func_00176F80 wip
