#include "common.h"
#include "game_01/obj80.h"

/* The 16 bytes at +0x20 of the destination are copied whole and then negated
   lane by lane, so the field is a union. */
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

typedef struct Src_00152380 {
    u8 unk_00[0x140];
    u128 unk_140;
    u8 unk_150[0x100];
    u128 unk_250;
    u128 unk_260;
    u128 unk_270;
    u8 unk_280[0x190];
    f32 unk_410;
    u8 unk_414;
    u8 unk_415[0x5B];
    Vec unk_470;
    s32 unk_480;
} Src_00152380;

typedef struct Dst_00152380 {
    u128 unk_00;
    u128 unk_10;
    Quad unk_20;
    u128 unk_30;
    u8 unk_40[0x10];
    Vec unk_50;
    s32 unk_60;
} Dst_00152380;

typedef struct Obj3A0 {
    u8 unk_00[0x314];
    u8 unk_314;
    u8 unk_315[0x8B];
    Quad3 unk_3A0;
} Obj3A0;

typedef struct Obj4A0 {
    u8 unk_00[0x414];
    u8 unk_414;
    u8 unk_415[0x8B];
    Quad3 unk_4A0;
} Obj4A0;

typedef struct Obj {
    u8 unk_00[0x2C0];
    Vec unk_2C0;
    u8 unk_2D0[0xD0];
    Vec unk_3A0;
} Obj;

void func_0012E9E0();

extern Vec D_006AF4B0;

extern void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152160);

void func_001522E0(Src_00152380 *s, Dst_00152380 *d)
{
    d->unk_00 = s->unk_140;
    d->unk_10 = s->unk_270;
    d->unk_20.v.x = s->unk_410 * s->unk_410;
}

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

void func_00152380(Src_00152380 *s, Dst_00152380 *d)
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

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152400);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152500);

void func_001525D0(Obj3A0 *d, Obj80 *s)
{
    d->unk_314 = 1;
    d->unk_3A0 = s->unk_80;
}

void func_00152600(Obj4A0 *d, Obj80 *s)
{
    d->unk_414 = 1;
    d->unk_4A0 = s->unk_80;
}

void func_00152630(char *arg0) {
    char *p = arg0 + 0x70;
    func_0012E9E0(p, p, p);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152640);

Vec *func_001526C0(Obj *o)
{
    func_0012E9A0(&o->unk_3A0, &o->unk_2C0, &D_006AF4B0, 0.75f);
    return &D_006AF4B0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152700);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152960);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152B20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00152040", func_00152BC0);
