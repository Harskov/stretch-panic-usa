#include "common.h"
#include "types.h"

extern s32 D_006A6730;

void func_00127BA0();

extern s32 D_0069D020;

void func_00172DA0();

void func_00176530(s32 **, s32, f32);

extern s32 D_0069CFC0;

void func_00175970(s32 **, s32, s32, f32);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175650);

s32 **func_001757E0(s32 ** volatile arg0, s32 arg1, s32 arg2, f32 arg3) {
    func_00172DA0(arg0, 0x5B, 0);
    *arg0 = &D_0069CFC0;
    func_00175970(arg0, arg1, arg2, arg3);
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00175650", func_00175860);

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
