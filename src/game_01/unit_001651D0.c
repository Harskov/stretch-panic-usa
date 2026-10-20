#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0x50];
    /* 0x50 */ float unk_50;
    /* 0x54 */ float unk_54;
    unsigned char unk_58[4];
    /* 0x5C */ float unk_5C;
    unsigned char unk_60[0x30];
    /* 0x90 */ float unk_90;
    /* 0x94 */ float unk_94;
} Obj;

extern s32 D_0069CBE0;

void func_00172E80();

void __dl__FPv(void *);

extern s32 D_0069CC70;

typedef struct Sub_00165730 {
    u128 unk_0[4];
} Sub_00165730;

typedef struct Obj_00165730 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_04[0x4C];
    /* 0x50 */ Sub_00165730 unk_50;
    /* 0x90 */ u128 unk_90;
    /* 0xA0 */ u128 unk_A0;
    /* 0xB0 */ u128 unk_B0;
    /* 0xC0 */ Vec unk_C0;
    /* 0xD0 */ u128 unk_D0;
    /* 0xE0 */ u128 unk_E0;
    u8 pad_F0[8];
    /* 0xF8 */ s32 unk_F8;
    /* 0xFC */ s32 unk_FC;
    /* 0x100 */ s32 unk_100;
    /* 0x104 */ s32 unk_104;
} Obj_00165730;

typedef struct Src_00165730 {
    /* 0x00 */ Sub_00165730 unk_0;
    /* 0x40 */ u128 unk_40;
    /* 0x50 */ u128 unk_50;
    /* 0x60 */ u128 unk_60;
    /* 0x70 */ Vec unk_70;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 unk_88;
    u8 pad_8C[4];
    /* 0x90 */ u128 unk_90;
    /* 0xA0 */ u128 unk_A0;
} Src_00165730;

extern s32 D_0069CC10;

void func_00172DA0();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_001651D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165300);

int func_001653D0(Obj *o) {
    int alive = 1;

    o->unk_50 = o->unk_50 - o->unk_50 * o->unk_54;
    o->unk_90 += o->unk_50;
    o->unk_94 -= o->unk_5C;
    if (o->unk_94 <= 0.0f) {
        alive = 0;
    }
    return alive;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165420);

s32 **func_001656D0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CBE0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

Obj_00165730 *func_00165730(Obj_00165730 *self, Src_00165730 *src) {
    func_00172DA0(self, 0x38, 0);
    self->unk_0 = &D_0069CC10;
    self->unk_50 = src->unk_0;
    self->unk_90 = src->unk_40;
    self->unk_A0 = src->unk_50;
    self->unk_B0 = src->unk_60;
    self->unk_C0.x = src->unk_70.x;
    self->unk_C0.y = src->unk_70.y;
    self->unk_C0.z = src->unk_70.z;
    self->unk_C0.w = src->unk_70.w;
    self->unk_D0 = src->unk_90;
    self->unk_E0 = src->unk_A0;
    self->unk_F8 = 0;
    self->unk_FC = src->unk_80;
    self->unk_100 = src->unk_84;
    self->unk_104 = src->unk_88;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165800);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165DC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165E20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165FF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00166060);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00166210);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_001664F0);

s32 **func_00166690(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CC70;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
