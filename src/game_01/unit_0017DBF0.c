#include "common.h"
#include "types.h"

extern s32 D_006A6730;

void func_00127BA0();

typedef struct Obj_0017DF40 {
    s32 *unk_0;
    u8 unk_4[0x12C];
    s32 unk_130;
} Obj_0017DF40;

extern s32 D_0069D450;

void func_00172DA0(Obj_0017DF40 *, s32, s32);

void func_0013BB20(s32 *, s32);

void func_0017DFC0(Obj_0017DF40 *, s32, f32);

extern s32 D_0069D4B0;

void func_00172E80();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DBF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DD30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DE30);

Obj_0017DF40 *func_0017DF40(Obj_0017DF40 *arg0, s32 arg1, f32 arg2)
{
    // !FAKE: the reference keeps the object pointer in a stack slot and reloads it before every use; a volatile local forces that
    Obj_0017DF40 *volatile self = arg0;

    func_00172DA0(self, 0x5D, 0);
    self->unk_0 = &D_0069D450;
    func_0013BB20(&self->unk_130, 1);
    func_0017DFC0(self, arg1, arg2);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DFC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E150);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E270);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E3A0);

void func_0017E4F0(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E640);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E6C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E890);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EA30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EB50);

s32 **func_0017EC20(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D4B0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EC80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017ED50);
