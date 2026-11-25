#include "common.h"
#include "types.h"

extern s32 D_006A6730;

void func_00127BA0();

extern s32 D_0069D020;

void func_00172DA0();

void func_00176530(s32 **, s32, f32);

extern s32 D_0069CFC0;

void func_00175970(s32 **, s32, s32, f32);

typedef struct Elem_001758D8 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Elem_001758D8;

typedef struct Sub_001758CC {
    /* 0x00 */ u8 pad_0[0x10];
    /* 0x10 */ Elem_001758D8 **unk_10;
} Sub_001758CC;

typedef struct Obj_00175860 {
    /* 0x00 */ s32 *unk_0;
    /* 0x04 */ u8 pad_4[0x4C];
    /* 0x50 */ Sub_001758CC *unk_50;
    /* 0x54 */ u8 pad_54[0x7C];
    /* 0xD0 */ Elem_001758D8 *unk_D0;
    /* 0xD4 */ u8 pad_D4[0xC];
    /* 0xE0 */ Elem_001758D8 unk_E0;
} Obj_00175860;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175650);

s32 **func_001757E0(s32 **volatile arg0, s32 arg1, s32 arg2, f32 arg3)
{
    // !FAKE: probably a C++ constructor whose `this` lives in a stack slot and is returned; the volatile parameter forces that spill in C
    func_00172DA0(arg0, 0x5B, 0);
    *arg0 = &D_0069CFC0;
    func_00175970(arg0, arg1, arg2, arg3);
    return arg0;
}

/* probably a constructor: the base part and its table, then a private copy of the
   block the object at +0x50 points through, which is redirected to that copy */
Obj_00175860 *func_00175860(Obj_00175860 *volatile arg0, s32 arg1, s32 arg2, f32 arg3, u128 *arg4, u128 *arg5)
{
    Obj_00175860 *p;

    // !FAKE: probably a C++ constructor keeping `this` in a stack slot and returning it; the volatile parameter forces that spill in C, and the copy into p reads it once per statement as the constructor's `this` is reloaded
    func_00172DA0(arg0, 0x5B, 0);
    arg0->unk_0 = &D_0069CFC0;
    func_00175970((s32 **)arg0, arg1, arg2, arg3);
    p = arg0;
    p->unk_E0 = **p->unk_50->unk_10;
    p = arg0;
    p->unk_D0 = &p->unk_E0;
    p = arg0;
    p->unk_50->unk_10 = &p->unk_D0;
    p = arg0;
    p->unk_E0.unk_0 = *arg4;
    p = arg0;
    p->unk_E0.unk_10 = *arg4;
    p = arg0;
    p->unk_E0.unk_30 = *arg5;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175970);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175B60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175C00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175C90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175DA0);

void func_00175EF0(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175F20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00176050);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_001760D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00176200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_001763A0);

s32 **func_001764C0(s32 **arg0, s32 arg1, f32 arg2) {
    // !FAKE: the original is probably a C++ constructor whose `this` lives in a stack slot and is returned; volatile forces that spill in C
    s32 **volatile self = arg0;

    func_00172DA0(self, 0x5E, 0);
    *self = &D_0069D020;
    func_00176530(self, arg1, arg2);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00176530);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00176690);
