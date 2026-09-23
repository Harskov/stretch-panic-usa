#include "common.h"

/* The 16 bytes at +0x20 of the destination are copied whole and then negated
   lane by lane, so the field is a union. */
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
