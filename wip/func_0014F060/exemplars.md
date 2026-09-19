# Exemplars for func_0014F060 — the 3 matched functions nearest by address

## func_00151060 @ 0x00151060 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0014FFD0();

void func_00151060(void) {
    func_0014FFD0();
}

```

## func_00151460 @ 0x00151460 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj430.h"

void func_00151460(Obj430 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 0;
    arg0->unk_420.w.unk_00 = 0;
    arg0->unk_420.w.unk_04 = 0;
    arg0->unk_420.w.unk_08 = 0;
    arg0->unk_420.w.unk_0C = 1.0f;
}

```

## func_001514A0 @ 0x001514A0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj430.h"

void func_001514A0(Obj430 *arg0, s32 arg1, const Quad420 *arg2, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 1;
    arg0->unk_420.q = arg2->q;
}

```
