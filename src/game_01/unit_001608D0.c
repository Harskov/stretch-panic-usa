#include "common.h"
#include "game_01/obj80.h"

typedef struct Src {
    unsigned char unk_00[0x1B0];
    /* 0x1B0 */ u128 unk_1B0;
    unsigned char unk_1C0[0x50];
    /* 0x210 */ u128 unk_210;
} Src;

typedef struct Dst {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u32 unk_20;
    /* 0x30 */ u128 unk_30[9];
    /* 0xC0 */ s32 unk_C0;
} Dst;

typedef struct Dst_00162900 {
    u8 unk_00[0x28C];
    u8 unk_28C;
    u8 unk_28D[0x83];
    Obj30 unk_310;
} Dst_00162900;

extern s32 D_0069CAA0;

void func_001355E0();

void __dl__FPv(void *);

typedef struct Obj_001608D0 {
    s32 *unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C[0x18];
    s32 *unk_24;
    f32 unk_28;
    f32 unk_2C;
    s32 unk_30;
} Obj_001608D0;

extern s32 D_00601A00;

extern s32 D_006A6D00;

void func_00135570();

void func_00162790(Src *a0, Dst *a1);

void func_001627B0(Src *a0, Dst *a1);

void func_00162870();

void func_00162900();

typedef struct Obj_00161840 {
    u8 unk_0[0x210];
    /* 0x210 */ Vec unk_210;
    /* 0x220 */ Vec unk_220;
    /* 0x230 */ Vec unk_230;
    /* 0x240 */ Vec unk_240;
} Obj_00161840;

typedef struct Obj_006A6730 {
    u8 unk_0[0x378];
    /* 0x378 */ s32 unk_378;
    u8 unk_37C[0x184];
    /* 0x500 */ s32 unk_500[1];
} Obj_006A6730;

extern Obj_006A6730 *D_006A6730;

void func_0012CA30();

extern s32 D_006AF4D0;

extern s32 D_006AF4D4;

Obj_001608D0 *func_001608D0(Obj_001608D0 *self)
{
    func_00135570(self, D_006A6D00 + 0x100, D_006A6D00 + 0x118);
    self->unk_00 = &D_0069CAA0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_24 = &D_00601A00;
    self->unk_28 = 12.0f;
    self->unk_2C = 1.0f;
    self->unk_30 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00160940);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001609D0);

s32 **func_00160CE0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CAA0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00160D40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161160);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161250);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001615D0);

void func_001617A0(Src *a0, Dst *a1)
{
    switch (a1->unk_C0) {
    case 3:
        func_00162790(a0, a1);
        break;
    case 4:
        func_001627B0(a0, a1);
        break;
    }
}

void func_001617F0(Src *a0, Dst *a1)
{
    switch (a1->unk_C0) {
    case 3:
        func_00162870(a0, a1);
        break;
    case 4:
        func_00162900(a0, a1);
        break;
    }
}

/* Fills one vector (mode 1) or three (mode 3) with fixed values and hands each
   to func_0012CA30 with the entry of D_006A6730's table that unk_378 selects. */
void func_00161840(Obj_00161840 *o, s32 mode)
{
    switch (mode) {
    case 1:
        o->unk_210.x = 0.15f;
        o->unk_210.y = 0.0f;
        o->unk_210.z = 0.25f;
        o->unk_210.w = 1.0f;
        func_0012CA30(D_006A6730->unk_500[D_006A6730->unk_378], &o->unk_210);
        break;
    case 3:
        o->unk_220.x = 0.085f;
        o->unk_220.y = 0.0f;
        o->unk_220.z = -0.045f;
        o->unk_220.w = 1.0f;
        o->unk_230.x = -0.085f;
        o->unk_230.y = 0.0f;
        o->unk_230.z = -0.045f;
        o->unk_230.w = 1.0f;
        o->unk_240.x = 0.0f;
        o->unk_240.y = 0.3f;
        o->unk_240.z = -1.0f;
        o->unk_240.w = 1.0f;
        func_0012CA30(D_006A6730->unk_500[D_006A6730->unk_378], &o->unk_220);
        func_0012CA30(D_006A6730->unk_500[D_006A6730->unk_378], &o->unk_230);
        func_0012CA30(D_006A6730->unk_500[D_006A6730->unk_378], &o->unk_240);
        break;
    }
}

/* Combines two flag words: 1 when both are 1, 0 when either is clear, 2 otherwise. */
s32 func_00161980(void)
{
    if (D_006AF4D0 == 1 && D_006AF4D4 == 1)
        return 1;
    if (D_006AF4D0 == 0 || D_006AF4D4 == 0)
        return 0;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001619E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161A90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161CF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00162350);

void func_00162790(Src *a0, Dst *a1) {
    a1->unk_0 = a0->unk_210;
    a1->unk_10 = a0->unk_1B0;
    a1->unk_20 = 0x3E440000;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001627B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00162870);

void func_00162900(Dst_00162900 *d, Obj80 *s)
{
    d->unk_28C = 1;
    d->unk_310 = s->unk_80;
}
