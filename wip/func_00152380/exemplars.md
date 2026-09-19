# Exemplars for func_00152380 — the 3 matched functions nearest by address

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

## func_001522E0 @ 0x001522E0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

void func_001522E0(char *arg0, char *arg1) {
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = *(f32 *)(arg0 + 0x410) * *(f32 *)(arg0 + 0x410);
}

```

## func_001525D0 @ 0x001525D0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
#include "common.h"

/* The 48 bytes copied in one go: three quads loaded before the first store. */
typedef struct Quad3 {
    u128 unk_00;
    u128 unk_10;
    u128 unk_20;
} Quad3;

typedef struct Obj3A0 {
    u8 unk_00[0x314];
    u8 unk_314;
    u8 unk_315[0x8B];
    Quad3 unk_3A0;
} Obj3A0;

typedef struct Obj80 {
    u8 unk_00[0x80];
    Quad3 unk_80;
} Obj80;

void func_001525D0(Obj3A0 *d, Obj80 *s)
{
    d->unk_314 = 1;
    d->unk_3A0 = s->unk_80;
}

```
