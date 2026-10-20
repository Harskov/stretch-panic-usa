#include "common.h"

/* A different object from Obj50: its vector pair sits at +0x10/+0x20, not +0x50/+0x60,
   and its counter at +0x54. Only the Vec type is shared. */
typedef struct Obj10 {
    unsigned char unk_00[0x10];
    /* 0x10 */ Vec unk_10;
    /* 0x20 */ Vec unk_20;
    unsigned char unk_30[0x24];
    f32 unk_54;
    f32 unk_58;
} Obj10;

extern s32 D_0069CAF0;

void func_00172E80();

void __dl__FPv(void *);

extern s32 D_0069CB20;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00162930);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00162AF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00162B90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00162D20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00162D90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163150);

void func_00163470(void) {
}

int func_00163480(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163490);

s32 func_001636C0(Obj10 *o) {
    register Vec *v;
    register Vec *p;
    f32 a;
    f32 b;

    p = &o->unk_10;
    v = &o->unk_20;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    b = o->unk_58;
    a = o->unk_54;
    a = a - b;
    o->unk_54 = a;
    if (a <= 0.0f) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163710);

s32 **func_00163A30(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CAF0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163A90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163B60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00162930", func_00163CC0);

s32 **func_00163FE0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CB20;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
