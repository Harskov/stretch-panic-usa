#include "common.h"

extern s32 D_0069C6D0;

void func_001355E0();

void __dl__FPv(void *);

extern s32 D_0069C6F0;

typedef struct Obj_00135570 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u8 pad_4[8];
    /* 0x0C */ struct Obj_00135570 *link_C;
    /* 0x10 */ struct Obj_00135570 *link_10;
    /* 0x14 */ struct Obj_00135570 **unk_14;
    /* 0x18 */ struct Obj_00135570 *link_18;
    /* 0x1C */ struct Obj_00135570 *link_1C;
    /* 0x20 */ struct Obj_00135570 **unk_20;
} Obj_00135570;

extern s32 D_0069C6B0;

extern s32 D_0069C690;

extern s32 D_0069C670;

extern s32 D_0069C540;

typedef struct Obj_00135450 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u8 pad_4[0x8C];
    /* 0x90 */ struct Obj_00135450 *link_90;
    /* 0x94 */ struct Obj_00135450 *link_94;
} Obj_00135450;

extern Obj_00135450 *D_006A6CF0;

void func_001318C0();

typedef struct Obj_00135770 {
    /* 0x00 */ u8 pad_0[0x28];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ u8 pad_40[4];
    /* 0x44 */ f32 unk_44;
} Obj_00135770;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00134FD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135190);

Obj_00135450 *func_00135450(Obj_00135450 *o)
{
    func_001318C0(o);
    o->unk_0 = &D_0069C540;
    o->link_90 = D_006A6CF0;
    o->link_94 = 0;
    D_006A6CF0 = o;
    if (o->link_90 != 0) {
        o->link_90->link_94 = o;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001354B0);

Obj_00135570 *func_00135570(Obj_00135570 *o, Obj_00135570 **head_a, Obj_00135570 **head_b)
{
    o->unk_0 = &D_0069C6F0;
    o->unk_14 = head_a;
    o->unk_20 = head_b;
    o->link_C = *o->unk_14;
    o->link_10 = 0;
    *o->unk_14 = o;
    if (o->link_C != 0) {
        o->link_C->link_10 = o;
    }
    o->link_18 = *o->unk_20;
    o->link_1C = 0;
    *o->unk_20 = o;
    if (o->link_18 != 0) {
        o->link_18->link_1C = o;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001355E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001356A0);

s32 **func_00135710(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C6D0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

/* moves the three floats at +0x34 toward the three at +0x28 by the fraction at +0x44 */
s32 func_00135770(Obj_00135770 *o)
{
    o->unk_34 += o->unk_44 * (o->unk_28 - o->unk_34);
    o->unk_38 += o->unk_44 * (o->unk_2C - o->unk_38);
    o->unk_3C += o->unk_44 * (o->unk_30 - o->unk_3C);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001357D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135C70);

s32 **func_00135CC0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C6B0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_00135D20(void)
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135D30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00136440);

s32 **func_00136490(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C690;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001364F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001365F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001368A0);

s32 **func_001368F0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C670;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00136950);
