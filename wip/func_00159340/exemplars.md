# Exemplars for func_00159340 — the 3 matched functions nearest by address

## func_00159330 @ 0x00159330 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void *func_00159330(char *p) {
    return p + 0x1E0;
}

```

## func_00159820 @ 0x00159820 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj1F0.h"

void func_00159820(Obj1F0 *a0, f32 *a1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    a0->unk_230 = a0->unk_10;
    a0->unk_240 = a0->unk_30;
    f3 = a0->unk_290;
    f2 = a0->unk_294;
    f1 = a0->unk_298;
    f0 = a0->unk_29C;
    a1[0] = f3;
    a1[1] = f2;
    a1[2] = f1;
    a1[3] = f0;
    (void)f0;
    (void)f1;
    (void)f2;
    (void)f3;
}

```

## func_00159E20 @ 0x00159E20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj1F0.h"

void func_00159E20(Obj1F0 *arg0, Owner1F0 *arg1) {
    if (arg0->unk_1D0 != 0) {
        arg0->unk_60 |= 0x80000;
    } else if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    arg0->unk_10 = arg0->unk_230;
    arg0->unk_30 = arg0->unk_240;
}

```
