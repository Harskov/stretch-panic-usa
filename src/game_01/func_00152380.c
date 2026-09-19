#include "common.h"

/* The 16 bytes at +0x20 of the destination are copied whole and then negated
   lane by lane, so the field is a union (K1 §8, include/game_01/obj430.h). */
typedef union Quad {
    u128 q;
    Vec v;
} Quad;

typedef struct Src {
    u8 unk_00[0x140];
    u128 unk_140;
    u8 unk_150[0x100];
    u128 unk_250;
    u128 unk_260;
    u128 unk_270;
    u8 unk_280[0x194];
    u8 unk_414;
    u8 unk_415[0x5B];
    Vec unk_470;
    s32 unk_480;
} Src;

typedef struct Dst {
    u128 unk_00;
    u128 unk_10;
    Quad unk_20;
    u128 unk_30;
    u8 unk_40[0x10];
    Vec unk_50;
    s32 unk_60;
} Dst;

void func_00152380(Src *s, Dst *d)
{
    s->unk_414 = 0;
    d->unk_50 = s->unk_470;
    d->unk_60 = s->unk_480;
    d->unk_30 = s->unk_140;
    d->unk_00 = s->unk_250;
    d->unk_10 = s->unk_260;
    d->unk_20.q = s->unk_270;
    d->unk_20.v.x = -d->unk_20.v.x;
    d->unk_20.v.y = -d->unk_20.v.y;
    d->unk_20.v.z = -d->unk_20.v.z;
}
