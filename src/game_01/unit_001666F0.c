#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    /* 0xAC */ int unk_AC;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

typedef struct Obj_00167180 Obj_00167180;

struct Obj_00167180 {
    /* 0x00 */ s32 *unk_0;
    u8 unk_04[0x9C];
    /* 0xA0 */ Obj_00167180 *link_A0;
    /* 0xA4 */ Obj_00167180 *link_A4;
    /* 0xA8 */ Obj_00167180 *link_A8;
    /* 0xAC */ Obj_00167180 *link_AC;
};

extern s32 D_0069CCD0;

void func_00135450();

extern s32 D_0069CCA0;

void func_00172E80();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001666F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001667C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001668D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001669A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166C20);

s32 **func_00166D30(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CCA0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

int func_00166D90(Obj *o) {
    int old;

    o->unk_E0 += o->unk_A8;
    o->unk_E4 += o->unk_E8;
    if (o->unk_E4 < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    old = o->unk_EC;
    o->unk_EC = old + 1;
    return old < o->unk_AC;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166DE0);

Obj_00167180 *func_00167180(Obj_00167180 *arg0, s32 arg1, Obj_00167180 *arg2)
{
    func_00135450();
    arg0->unk_0 = &D_0069CCD0;
    arg0->link_A8 = arg2;
    if (arg0->link_A8 != 0) {
        arg0->link_A0 = arg0->link_A8->link_AC;
        arg0->link_A8->link_AC = arg0;
        if (arg0->link_A0 != 0) {
            arg0->link_A0->link_A4 = arg0;
        }
    } else {
        arg0->link_A0 = 0;
    }
    arg0->link_A4 = 0;
    arg0->link_AC = 0;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001672B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001673C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167760);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167810);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167BB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167E20);
