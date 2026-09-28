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
    u8 unk_64[0x16C];
    u8 unk_1D0;
    u8 unk_1D1[0x5F];
    u128 unk_230;
    u128 unk_240;
    u8 unk_250[0x40];
    u8 unk_290[0x10];
} Obj;

void func_00159E20(Obj1F0 *arg0, Owner1F0 *arg1);

extern s32 func_00131B30(Obj *arg0, void *arg1, s32 *arg2, Actor *arg3, void *arg4);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00158C80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00158FD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_001591C0);

void *func_00159330(char *p) {
    return p + 0x1E0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159370);

void func_00159400(Obj1F0 *arg0, Owner1F0 *arg1)
{
    switch (arg1->unk_C0) {
    case 0:
        func_00159E20(arg0, arg1);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159430);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159650);

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

s32 func_00159860(Obj *arg0, Actor *arg1)
{
    s32 tmp;

    arg0->unk_230 = arg0->unk_10;
    arg0->unk_240 = arg0->unk_30;
    if (func_00131B30(arg0, arg0->unk_290, &tmp, arg1, arg1->unk_80) != 0) {
        if (arg0->unk_1D0 != 0) {
            arg0->unk_60 |= 0x80000;
        } else if (arg1->unk_C4->unk_54 == 4) {
            arg0->unk_60 |= 0x80000;
        }
        arg0->unk_10 = arg0->unk_230;
        arg0->unk_30 = arg0->unk_240;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159920);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159B10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159BF0);

void func_00159E20(Obj1F0 *arg0, Owner1F0 *arg1) {
    if (arg0->unk_1D0 != 0) {
        arg0->unk_60 |= 0x80000;
    } else if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    arg0->unk_10 = arg0->unk_230;
    arg0->unk_30 = arg0->unk_240;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159E80);
