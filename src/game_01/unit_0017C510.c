#include "common.h"

typedef struct Obj_0017C7A0 {
    /* 0x000 */ s32 *unk_0;
    /* 0x004 */ u8 pad_4[0x168];
    /* 0x16C */ f32 unk_16C;
} Obj_0017C7A0;

extern s32 D_0069D320;

void func_0017B170();

void func_0017B7A0();

void __dl__FPv(void *);

extern s32 D_0069D390;

void func_00172E80();

extern s32 D_0069D3C0;

extern s32 D_0069D3F0;

extern s32 D_0069D420;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C660);

Obj_0017C7A0 *func_0017C7A0(Obj_0017C7A0 *arg0)
{
    func_0017B170(arg0);
    arg0->unk_0 = &D_0069D320;
    arg0->unk_16C = 61.0f;
    return arg0;
}

s32 **func_0017C7E0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D320;
        func_0017B7A0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C840);

s32 **func_0017CA50(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D390;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CAB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CBC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CCE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CE00);

s32 **func_0017D040(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D3C0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D190);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D320);

s32 **func_0017D560(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D3F0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D6B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D950);

s32 **func_0017DB90(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D420;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
