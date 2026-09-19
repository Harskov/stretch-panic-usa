# Exemplars for func_001525D0 — the 3 matched functions nearest by address

## func_00152600 @ 0x00152600 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Src {
    u8 pad0[0x80];
    Vec a;
    Vec b;
    Vec c;
} Src;

void func_00152600(char *arg0, Src *arg1) {
    *(u8 *)(arg0 + 0x414) = 1;
    asm {
        lq $a3, 0x80($a1)
        lq $a2, 0x90($a1)
        lq $v1, 0xA0($a1)
        sq $a3, 0x4A0($a0)
        sq $a2, 0x4B0($a0)
        sq $v1, 0x4C0($a0)
    }
}

```

## func_00152630 @ 0x00152630 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0012E9E0();

void func_00152630(char *arg0) {
    char *p = arg0 + 0x70;
    func_0012E9E0(p, p, p);
}

```

## func_00152300 @ 0x00152300 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "common.h"

/* The 16 bytes at +0x20 of the destination are copied whole and then negated
   lane by lane, so the field is a union (K1 §8, include/game_01/obj430.h). */
typedef union Quad {
    u128 q;
    Vec v;
} Quad;

typedef struct Src {
    u8 unk_00[0x250];
    u128 unk_250;
    u128 unk_260;
    u128 unk_270;
    u8 unk_280[0x94];
    u8 unk_314;
    u8 unk_315[0x5B];
    Vec unk_370;
    s32 unk_380;
    f32 unk_384;
} Src;

typedef struct Dst {
    u128 unk_00;
    u128 unk_10;
    Quad unk_20;
    u8 unk_30[0x20];
    Vec unk_50;
    s32 unk_60;
    f32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
} Dst;

void func_00152300(Src *s, Dst *d)
{
    s->unk_314 = 0;
    d->unk_50 = s->unk_370;
    d->unk_00 = s->unk_250;
    d->unk_10 = s->unk_260;
    d->unk_20.q = s->unk_270;
    d->unk_20.v.x = -d->unk_20.v.x;
    d->unk_20.v.y = -d->unk_20.v.y;
    d->unk_20.v.z = -d->unk_20.v.z;
    d->unk_60 = s->unk_380;
    d->unk_64 = s->unk_384;
    d->unk_68 = 0;
    d->unk_6C = 0;
    d->unk_70 = 0;
}

```
