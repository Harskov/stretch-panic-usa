#include "common.h"

typedef struct Obj_00131800 {
    unsigned char unk_00[0x10];
    u8 unk_10;
} Obj_00131800;

typedef struct Obj_00131810 {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 pad_20[0x10];
    u128 *unk_30;
} Obj_00131810;

extern s32 D_0069C330;

extern s32 D_0069C4E0;

extern void __dl__FPv(void *);

typedef struct Obj_001318C0 Obj_001318C0;

struct Obj_001318C0 {
    s32 *unk_00;
    u8 pad_04[0x50];
    s32 unk_54;
    s32 unk_58;
    u8 pad_5C[4];
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    Obj_001318C0 *unk_6C;
    Obj_001318C0 *unk_70;
    Obj_001318C0 *unk_74;
    Obj_001318C0 *unk_78;
    Obj_001318C0 *unk_7C;
    Obj_001318C0 *unk_80;
    Obj_001318C0 *unk_84;
    Obj_001318C0 *unk_88;
};

extern s32 D_0069C4B0;

extern s32 D_006A6C00;

extern Obj_001318C0 *D_006A6C08;

extern Obj_001318C0 *D_006A6C10[];

extern Obj_001318C0 *D_006A6CB0;

/* A slot of the function-pointer table D_0069C480. Only the member's address is
   taken, so its type is not known. */
void *func_00131800(Obj_00131800 *o) {
    return &o->unk_10;
}

void func_00131810(Obj_00131810 *o) {
    o->unk_10 = *o->unk_30;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00131820);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00131870);

Obj_001318C0 *func_001318C0(Obj_001318C0 *o, s32 arg1, Obj_001318C0 *arg2) {
    o->unk_00 = &D_0069C4B0;
    o->unk_54 = arg1;
    o->unk_58 = D_006A6C00;
    o->unk_60 = 0;
    o->unk_64 = 0;
    o->unk_68 = 0;
    D_006A6C00 += 1;
    o->unk_6C = D_006A6C08;
    o->unk_70 = 0;
    D_006A6C08 = o;
    if (o->unk_6C != 0) {
        o->unk_6C->unk_70 = o;
    }
    o->unk_74 = D_006A6C10[o->unk_54];
    o->unk_78 = 0;
    D_006A6C10[o->unk_54] = o;
    if (o->unk_74 != 0) {
        o->unk_74->unk_78 = o;
    }
    o->unk_7C = arg2;
    o->unk_80 = 0;
    if (o->unk_7C == 0) {
        o->unk_84 = D_006A6CB0;
        o->unk_88 = 0;
        D_006A6CB0 = o;
    } else {
        o->unk_84 = o->unk_7C->unk_80;
        o->unk_88 = 0;
        o->unk_7C->unk_80 = o;
    }
    if (o->unk_84 != 0) {
        o->unk_84->unk_88 = o;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_001319D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00131B30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00132220);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00132240);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_001322B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00132330);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_001323B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00132440);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_001324F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00131800", func_00132580);

s32 **func_00132630(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C4E0;
        if (arg0 != 0) {
            *arg0 = &D_0069C330;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
