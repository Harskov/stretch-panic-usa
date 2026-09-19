# func_0016F790 @ 0x0016F790 — 184 bytes, segment game_01

Compiler: mwcps2-2.3.3-000906 `-O3,p -sdatathreshold 0`; m2c seed: ok; externs: 3 data, 1 functions.

VU0 macro mode: 8 COP2 instruction(s) in target.s (lqc2, sqc2, vadd.xyz). m2c prints M2C_ERROR for these (it has no reading for COP2); write the sequence as a CodeWarrior `asm { }` block over `register` pointer locals, declared in the order the target allocates them — the pinned compiler's only source form for these ops (K1 §6 item 11); lint_c.py reports the block as `vu0-asm` (advisory) and the ledger note names the vector op.

Write attempt-1.c (function named exactly as above; include "ctx.c" declarations you need by copying them, not the file), then:

    python3 skills/dps2-toolkit/scripts/match.py --repo targets/<slug> try func_0016F790 wip/func_0016F790/attempt-1.c

On 100:  python3 skills/dps2-toolkit/scripts/ledger.py --repo targets/<slug> mark func_0016F790 --from wip/func_0016F790/attempt-N.c
Stuck after 3 substantive attempts:  match.py permute func_0016F790  then  ledger.py set-status func_0016F790 wip
