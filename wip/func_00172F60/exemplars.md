# Exemplars for func_00172F60 — the 3 matched functions nearest by address

## func_00172BF0 @ 0x00172BF0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00172BF0(void) {
}

```

## func_001733C0 @ 0x001733C0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "game_01/obj50.h"

s32 func_001733C0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;
    arg0->unk_7C = arg0->unk_7C * arg0->unk_80;
    t = arg0->unk_8C;
    arg0->unk_9C = arg0->unk_9C + t;

    p = &arg0->pos;
    v = &arg0->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

```

## func_00172A80 @ 0x00172A80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

extern s32 D_00601BB0;

s32 func_00172A80(s32 arg0) {
    s32 *p = &D_00601BB0;
    return p[arg0];
}

```
