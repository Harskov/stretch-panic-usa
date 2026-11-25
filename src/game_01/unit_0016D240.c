#include "common.h"
#include "game_01/scratchpad.h"
#include "types.h"

/* A vtable accessor: six function-pointer tables (D_0069CE00, D_0069D0E0, D_0069D1B0,
   D_0069D2B0, D_0069D320, D_0069D4B0) hold its address, and it returns the address of
   whatever sits at +0xA0 in the object it is called on. No function written so far
   reaches that member, so only its existence is asserted here. */
typedef struct ObjA0 {
    unsigned char unk_00[0xA0];
    u8 unk_A0;
} ObjA0;

typedef struct {
    unsigned char unk_00[0x60];
    u32 unk_60;
    unsigned char unk_64[0x108];
    int unk_16C;
} Obj;

extern Quad D_00601A40;

extern void func_0016EFC0(void *arg0, Quad *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);

typedef struct Obj_0016D360 {
    unsigned char unk_00[0x10];
    unsigned char unk_10[0x124];
    s32 unk_134;
    f32 unk_138;
    unsigned char unk_13C[0x4];
    unsigned char unk_140[0x120];
    unsigned char unk_260[0x4];
} Obj_0016D360;

typedef struct Src_0016D360 {
    unsigned char unk_00[0x80];
    f32 unk_80;
    unsigned char unk_84[0x3C];
    s32 unk_C0;
} Src_0016D360;

extern void func_0012E9A0(void *arg0, void *arg1, void *arg2, f32 arg3);

typedef struct Obj_0016D6B0 {
    unsigned char unk_00[0x134];
    s32 unk_134;
    f32 unk_138;
    s32 unk_13C;
    Quad unk_140;
    Quad unk_150;
} Obj_0016D6B0;

typedef struct Src_0016D250 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
} Src_0016D250;

typedef struct Obj_0016D250 {
    unsigned char unk_00[0xF8];
    Src_0016D250 *unk_F8;
} Obj_0016D250;

typedef struct Dst_0016D250 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    unsigned char unk_10[0xB0];
    s32 unk_C0;
} Dst_0016D250;

/* Stores 2 at +0x134 and 1.0f at +0x138 and passes +0x10, +0x260 and +0x140 on, as
   Obj_0016D360's do; whether the two are one object is still open. */
typedef struct Obj_0016D560 {
    unsigned char unk_00[0x10];
    /* 0x010 */ Quad unk_10;
    unsigned char unk_20[0xD8];
    /* 0x0F8 */ void *unk_F8;
    unsigned char unk_FC[0x38];
    /* 0x134 */ s32 unk_134;
    /* 0x138 */ f32 unk_138;
    unsigned char unk_13C[0x4];
    /* 0x140 */ Quad unk_140;
    unsigned char unk_150[0x10];
    /* 0x160 */ f32 unk_160;
    unsigned char unk_164[0xFC];
    /* 0x260 */ unsigned char unk_260[0x4];
} Obj_0016D560;

typedef struct Sub_0016D560 {
    unsigned char unk_00[0x54];
    /* 0x54 */ s32 unk_54;
} Sub_0016D560;

typedef struct Src_0016D560 {
    unsigned char unk_00[0x80];
    /* 0x80 */ f32 unk_80;
    unsigned char unk_84[0x40];
    /* 0xC4 */ Sub_0016D560 *unk_C4;
} Src_0016D560;

extern s32 func_00131B30(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);

typedef struct Obj_0016D430 {
    unsigned char unk_00[0x58];
    /* 0x058 */ s32 unk_58;
    unsigned char unk_5C[0x4];
    /* 0x060 */ u32 unk_60;
    unsigned char unk_64[0x6C];
    /* 0x0D0 */ s32 unk_D0;
    /* 0x0D4 */ s32 unk_D4;
    unsigned char unk_D8[0x4];
    /* 0x0DC */ s32 unk_DC;
    unsigned char unk_E0[0x4];
    /* 0x0E4 */ s32 unk_E4;
    unsigned char unk_E8[0x24];
    /* 0x10C */ s32 unk_10C;
    unsigned char unk_110[0x24];
    /* 0x134 */ s32 unk_134;
    /* 0x138 */ f32 unk_138;
    unsigned char unk_13C[0x4];
    /* 0x140 */ Quad unk_140;
    /* 0x150 */ Quad unk_150;
    unsigned char unk_160[0x4];
    /* 0x164 */ s32 unk_164;
    unsigned char unk_168[0x28];
    /* 0x190 */ Quad unk_190;
} Obj_0016D430;

typedef struct Src_0016D430 {
    unsigned char unk_00[0x60];
    /* 0x60 */ s32 unk_60;
    unsigned char unk_64[0x4];
    /* 0x68 */ s32 flags;
    /* 0x6C */ s32 unk_6C;
    /* 0x70 */ f32 unk_70;
    unsigned char unk_74[0xC];
    /* 0x80 */ Quad unk_80;
    unsigned char unk_90[0x10];
    /* 0xA0 */ Quad unk_A0;
} Src_0016D430;

extern void func_00132970(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, void *arg5, void *arg6);

extern void func_0016BED0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);

void *func_0016D240(ObjA0 *o) {
    return &o->unk_A0;
}

void func_0016D250(Obj_0016D250 *arg0, Dst_0016D250 *arg1)
{
    switch (arg1->unk_C0) {
    case 0:
        arg1->unk_0 = arg0->unk_F8->unk_0;
        arg1->unk_4 = arg0->unk_F8->unk_4;
        arg1->unk_8 = arg0->unk_F8->unk_8;
        arg1->unk_C = arg0->unk_F8->unk_C;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D2A0);

void func_0016D360(Obj_0016D360 *arg0, Src_0016D360 *arg1)
{
    f32 zero = 0.0f;

    switch (arg1->unk_C0) {
    case 0:
        if (arg1->unk_80 != zero) {
            arg0->unk_134 = 2;
            arg0->unk_138 = 1.0f;
            func_0012E9A0(arg0->unk_10, arg0->unk_260, arg0->unk_140, 0.75f);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D3D0);

/* When the source's +0x60 matches this object's +0x58: passes both on, copies the source's
   state when its bit 0x2 is set (with the difference of its two vectors), sets bit 0x800000
   at +0x60 and returns 1; otherwise returns 0. */
s32 func_0016D430(Obj_0016D430 *arg0, Src_0016D430 *arg1)
{
    if (arg1->unk_60 == arg0->unk_58) {
        func_00132970(arg0->unk_D0, arg0->unk_DC, &arg0->unk_190, arg0->unk_D4, arg0->unk_E4,
                      arg1, &arg1->unk_80);
        if (arg1->flags & 2) {
            register Quad *out;
            register Quad *rhs;
            register Quad *lhs;

            lhs = &arg1->unk_A0;
            rhs = &arg1->unk_80;
            out = &arg0->unk_150;
            arg0->unk_134 = arg1->unk_6C;
            arg0->unk_138 = arg1->unk_70;
            arg0->unk_140 = arg1->unk_80;
            asm {
                lqc2 vf1, 0x0(lhs)
                lqc2 vf2, 0x0(rhs)
                vsub.xyz vf1, vf1, vf2
                sqc2 vf1, 0x0(out)
            }
            if (arg0->unk_164 != 0) {
                func_0016BED0(0, arg0->unk_60, arg0->unk_10C, 2, arg1->unk_70);
            }
        }
        arg0->unk_60 |= 0x800000;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D510);

s32 func_0016D560(Obj_0016D560 *arg0, Src_0016D560 *arg1)
{
    f32 zero = 0.0f;

    if (func_00131B30(arg0, arg0->unk_F8, &arg0->unk_160, arg1, &arg1->unk_80) != 0) {
        if (arg0->unk_160 != zero) {
            arg0->unk_134 = 2;
            arg0->unk_138 = 1.0f;
            if (arg1->unk_C4->unk_54 == 4) {
                func_0012E9A0(&arg0->unk_10, arg0->unk_260, &arg0->unk_140, 0.75f);
            } else {
                arg0->unk_140 = arg0->unk_10;
            }
        }
        return 1;
    }
    return 0;
}

// registers: copy = the local copy of D_00601A40 whose address is passed on
void func_0016D620(void *arg0, s32 arg1)
{
    Quad copy;

    copy = D_00601A40;
    func_0016EFC0(arg0, &copy, arg1, 0, 0.75f, 0.0f);
}

void func_0016D660(void) {
}

void func_0016D670(void) {
}

void func_0016D680(void) {
}

void func_0016D690(Obj *arg0) {
    arg0->unk_16C = 0;
    arg0->unk_60 |= 0x10000;
}

/* 0x70000BA0, like SPR_QUAD, is a quadword of the EE's scratchpad RAM */
void func_0016D6B0(Obj_0016D6B0 *arg0) {
    arg0->unk_134 = 0;
    arg0->unk_138 = 1.0f;
    arg0->unk_13C = 0;
    arg0->unk_140 = *SPR_QUAD;
    arg0->unk_150 = *(Quad *)0x70000BA0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D6E0);
