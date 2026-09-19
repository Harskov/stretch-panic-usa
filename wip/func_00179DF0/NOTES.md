# func_00179DF0 @ 0x00179DF0 — 48 bytes, segment game_01

Compiler: mwcps2-2.3.3-000906 `-O3,p -sdatathreshold 0`; m2c seed: ok; externs: 0 data, 1 functions.

Write attempt-1.c (function named exactly as above; include "ctx.c" declarations you need by copying them, not the file), then:

    python3 skills/dps2-toolkit/scripts/match.py --repo targets/<slug> try func_00179DF0 wip/func_00179DF0/attempt-1.c

On 100:  python3 skills/dps2-toolkit/scripts/ledger.py --repo targets/<slug> mark func_00179DF0 --from wip/func_00179DF0/attempt-N.c
Stuck after 3 substantive attempts:  match.py permute func_00179DF0  then  ledger.py set-status func_00179DF0 wip
