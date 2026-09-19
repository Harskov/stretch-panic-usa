# Exemplars for func_00159EE0 — the 3 matched functions nearest by address

## func_00159F10 @ 0x00159F10 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void *func_00159F10(char *p) {
    return p + 0x10;
}

```

## func_00159F20 @ 0x00159F20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
float func_00159F20(void) {
    return 0.0f;
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
