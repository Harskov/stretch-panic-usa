#include "common.h"
#include "game_01/obj50.h"

extern s32 D_0069CF90;

void func_00172DA0();

typedef struct Obj_001753F0 {
    void *unk_0;
    u8 unk_4[0xC];
    u128 unk_10;
    u8 unk_20[0x30];
    s32 unk_50;
    f32 unk_54;
    f32 unk_58;
    s32 unk_5C;
    u128 unk_60;
    u128 unk_70;
} Obj_001753F0;

extern s32 D_0069CF60;

typedef struct Obj_00174EF0 {
    void *unk_0;
    u8 unk_4[0xC];
    u128 unk_10;
    u8 unk_20[0x30];
    s32 unk_50;
    f32 unk_54;
    f32 unk_58;
    s32 unk_5C;
    f32 unk_60;
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[4];
    u128 unk_70;
    u128 unk_80;
} Obj_00174EF0;

extern s32 D_0069CF00;

void func_00172E80();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00173F40);

s32 **func_00174150(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CF00;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_001741B0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;

    p = &arg0->unk_50;
    v = &arg0->unk_60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->unk_A0;
    arg0->unk_9C = arg0->unk_9C + t;

    if (!(arg0->unk_A0 <= 0.0f) && !(arg0->unk_9C <= 1.0f)) {
        arg0->unk_9C = 1.0f;
        arg0->unk_A0 = 0.0f;
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174270);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174620);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174860);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001748D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174A40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174B30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174DD0);

Obj_00174EF0 *func_00174EF0(Obj_00174EF0 *arg0, void *arg1, u128 *arg2, f32 arg6, u128 *arg3, u128 *arg4, f32 arg7, s32 arg5) {
    func_00172DA0(arg0, arg1, 0);
    arg0->unk_0 = &D_0069CF60;
    arg0->unk_10 = *arg2;
    arg0->unk_50 = 0;
    arg0->unk_54 = arg7;
    arg0->unk_58 = arg7;
    arg0->unk_5C = 0;
    arg0->unk_60 = arg6;
    arg0->unk_64 = arg5;
    arg0->unk_68 = 0x3E800000;
    arg0->unk_70 = *arg3;
    arg0->unk_80 = *arg4;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174FB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00175010);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001750C0);

Obj_001753F0 *func_001753F0(Obj_001753F0 *arg0, void *arg1, u128 *arg2, u128 *arg3, u128 *arg4, f32 arg5, s32 arg6) {
    func_00172DA0(arg0, arg1, 0);
    arg0->unk_0 = &D_0069CF90;
    arg0->unk_10 = *arg2;
    arg0->unk_50 = 0;
    arg0->unk_54 = arg5;
    arg0->unk_58 = arg5;
    arg0->unk_5C = arg6;
    arg0->unk_60 = *arg3;
    arg0->unk_70 = *arg4;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00175490);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001754F0);
