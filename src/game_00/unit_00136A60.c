#include "common.h"

typedef struct Obj_001392C0 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0xC];
    /* 0x10 */ s32 *unk_10;
    u8 pad_14[0x30];
    /* 0x44 */ f32 unk_44;
    u8 pad_48[0xC];
    /* 0x54 */ u32 unk_54;
    u8 pad_58[0x8];
    /* 0x60 */ s32 *unk_60;
    u8 pad_64[0x30];
    /* 0x94 */ f32 unk_94;
    u8 pad_98[0xC];
    /* 0xA4 */ u32 unk_A4;
    u8 pad_A8[0x8];
    /* 0xB0 */ s32 *unk_B0;
    u8 pad_B4[0x30];
    /* 0xE4 */ f32 unk_E4;
    u8 pad_E8[0xC];
    /* 0xF4 */ u32 unk_F4;
    u8 pad_F8[0x8];
    /* 0x100 */ s32 *unk_100;
    u8 pad_104[0x10];
    /* 0x114 */ u32 unk_114;
} Obj_001392C0;

extern s32 D_0069C1E0;

extern s32 D_0069C1F0;

extern s32 D_0069C200;

extern s32 D_0069C610;

void func_001355E0();

void __dl__FPv(void *);

typedef struct Obj_001386B0 {
    u8 pad_0[0x20];
    /* 0x20 */ struct Obj_001386B0 *link_20;
    /* 0x24 */ struct Obj_001386B0 *link_24;
    /* 0x28 */ struct Obj_001386B0 **unk_28;
} Obj_001386B0;

typedef struct Obj_00139740 {
    /* 0x00 */ s32 *unk_0;
    /* 0x04 */ f32 unk_4;
    /* 0x08 */ f32 unk_8;
    u8 pad_C[0x18];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s8 counter_34;
    /* 0x35 */ s8 counter_35;
} Obj_00139740;

void func_00135570();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00136A60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00136CA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_001370A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_001371C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00137500);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_001384E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_001385A0);

Obj_001386B0 *func_001386B0(Obj_001386B0 *self, s16 flags) {
    Obj_001386B0 *link;

    if (self != 0) {
        link = self->link_24;
        if (link != 0) {
            link->link_20 = self->link_20;
        }
        link = self->link_20;
        if (link != 0) {
            link->link_24 = self->link_24;
        } else {
            *self->unk_28 = self->link_24;
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00138730);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00138890);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00138F80);

/* The 0x7000xxxx words are addresses in the EE's scratchpad RAM (0x70000000-0x70003FFF). */
Obj_001392C0 *func_001392C0(Obj_001392C0 *arg0)
{
    arg0->unk_0 = &D_0069C1F0;
    arg0->unk_10 = &D_0069C200;
    arg0->unk_54 = 0x70003B80;
    arg0->unk_44 = 0.0625f;
    arg0->unk_60 = &D_0069C200;
    arg0->unk_A4 = 0x70003B80;
    arg0->unk_94 = 0.0625f;
    arg0->unk_B0 = &D_0069C200;
    arg0->unk_F4 = 0x70003BA0;
    arg0->unk_E4 = 0.0625f;
    arg0->unk_100 = &D_0069C1E0;
    arg0->unk_114 = 0x70003BC0;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00139340);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00139430);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_001394F0);

Obj_00139740 *func_00139740(Obj_00139740 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5)
{
    func_00135570(arg0, arg2, arg3);
    arg0->unk_0 = &D_0069C610;
    arg0->unk_4 = arg4;
    arg0->unk_8 = arg5;
    arg0->unk_24 = arg1;
    arg0->unk_28 = arg1;
    arg0->counter_34 = 0;
    arg0->counter_35 = 0;
    arg0->unk_2C = 24.0f;
    arg0->unk_30 = 0;
    while (arg1 >= 10) {
        arg1 -= 10;
        arg0->counter_34++;
    }
    while (arg1 > 0) {
        arg1 -= 1;
        arg0->counter_35++;
    }
    return arg0;
}

s32 **func_00139810(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C610;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00139870);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00139A00);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_00139ED0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00136A60", func_0013A080);
