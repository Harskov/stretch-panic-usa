#include "common.h"
#include "game_01/obj1F0.h"
#include "game_01/actorC4.h"

typedef struct Obj {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 unk_20[0x10];
    u128 unk_30;
    u8 unk_40[0x20];
    u32 unk_60;
    u8 unk_64[0x174];
    /* 0x1D8 */ u32 flags;
    u8 unk_1DC[0x14];
    u128 unk_1F0;
    u128 unk_200;
    u8 unk_210[0x40];
    u8 unk_250[0x10];
} Obj;

extern s32 func_00131B30(Obj *arg0, void *arg1, f32 *arg2, ObjC8 *arg3, void *arg4);


void func_0015BA00(Obj1F0 *arg0, ObjCC *arg1);

void *func_00159F10(Obj1F0 *o) {
    return &o->unk_10;
}

float func_00159F20(void) {
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_00159F30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015A3C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015A4A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015A780);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015AAC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015AC70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015ACA0);

void func_0015AD30(Obj1F0 *arg0, ObjCC *arg1)
{
    switch (arg1->unk_C0) {
    case 0:
        func_0015BA00(arg0, arg1);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015AD60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015AFB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015B2C0);

void func_0015B500(Obj1F0 *arg0, Vec *arg1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    arg0->unk_1F0 = arg0->unk_10;
    arg0->unk_200 = arg0->unk_30;
    f3 = arg0->unk_250;
    f2 = arg0->unk_254;
    f1 = arg0->unk_258;
    f0 = arg0->unk_25C;
    arg1->x = f3;
    arg1->y = f2;
    arg1->z = f1;
    arg1->w = f0;
    (void)f0;
    (void)f1;
    (void)f2;
    (void)f3;
}

// registers: out = the f32 func_00131B30 writes through its third argument, compared with zero
s32 func_0015B540(Obj *arg0, ObjC8 *arg1)
{
    f32 out;
    f32 zero;

    arg0->unk_1F0 = arg0->unk_10;
    arg0->unk_200 = arg0->unk_30;
    if (func_00131B30(arg0, arg0->unk_250, &out, arg1, arg1->unk_80) != 0) {
        arg0->unk_10 = arg0->unk_1F0;
        arg0->unk_30 = arg0->unk_200;
        if (arg1->unk_C4->unk_54 == 4) {
            arg0->unk_60 |= 0x80000;
        }
        zero = 0.0f;
        if (out != zero || (arg0->flags & 2)) {
            arg0->unk_60 |= 0x80000;
        }
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015B620);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015B800);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015B8E0);

void func_0015BA00(Obj1F0 *arg0, ObjCC *arg1) {
    f32 zero;

    arg0->unk_10 = arg0->unk_1F0;
    arg0->unk_30 = arg0->unk_200;
    if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    zero = 0.0f;
    if ((arg1->unk_80 != zero) || (arg0->flags & 2)) {
        arg0->unk_60 |= 0x80000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015BA80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015BBB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00159F10", func_0015BD00);
