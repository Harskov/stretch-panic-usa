#include "common.h"
#include "game_00/unit_0012DF10.h"

typedef struct Obj {
    u8 pad0[0x30];
    u128 unk_30;
    u8 pad40[0x14C - 0x40];
    s32 unk_14C;
    s32 unk_150;
    u8 pad154[0x2B0 - 0x154];
    u128 unk_2B0;
    u8 pad2C0[0x378 - 0x2C0];
    /* 0x378 */ s32 flags;
    u8 pad37C[0x3A0 - 0x37C];
    u128 unk_3A0;
    u128 unk_3B0;
    u8 pad3C0[0x3C4 - 0x3C0];
    s32 unk_3C4;
    u8 pad3C8[0x3D0 - 0x3C8];
    s32 unk_3D0;
    u8 pad3D4[0x400 - 0x3D4];
    Vec unk_400;
} Obj;


void func_0014FFD0();

void func_0014EE90();

extern s32 D_0069C8E0;

void func_001319D0();

void func_00150660();

extern s32 D_006AF098;

extern s32 *D_006A6D10;

void func_0013DFD0();

typedef struct Obj_00150D00 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x90 - 0x4];
    /* 0x90 */ Quad unk_90;
    /* 0xA0 */ Quad unk_A0;
    /* 0xB0 */ f32 unk_B0;
} Obj_00150D00;

void func_001318C0();

void func_00150330();

extern s32 D_006AF0A0[];

extern s32 D_006AF0A4[];

extern s32 D_006AF4A0;

typedef struct Obj_0014ED70 {
    u8 pad_0[0xB8];
    /* 0xB8 */ f32 unk_B8;
    u8 pad_BC[0x570 - 0xBC];
    /* 0x570 */ s32 counter_570;
    /* 0x574 */ f32 counter_574;
    u8 pad_578[0x580 - 0x578];
    /* 0x580 */ Vec unk_580;
    /* 0x590 */ Vec unk_590;
    /* 0x5A0 */ Quad unk_5A0;
    /* 0x5B0 */ Quad unk_5B0;
    u8 pad_5C0[0x5D0 - 0x5C0];
    /* 0x5D0 */ Vec unk_5D0;
} Obj_0014ED70;

void func_0012EE90(Vec *a, Vec *b, Vec *out, f32 t);

void func_0012EDF0(Vec *a, Vec *b, f32 t);

void func_0014EB90(void *arg0, Vec *in, register Vec *out)
{
    Vec dir;
    register Vec *d;
    register f32 s;
    f32 len;

    len = func_0012E8E0(in, &dir);
    if (len < 0.083333336f) {
        s = 0.083333336f;
        d = &dir;
        asm {
            mfc1 v0, s
            lqc2 vf1, 0(d)
            qmtc2.ni v0, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(out)
        }
    } else if (len > 0.16666667f) {
        s = 0.16666667f;
        d = &dir;
        asm {
            mfc1 v0, s
            lqc2 vf1, 0(d)
            qmtc2.ni v0, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(out)
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014EC30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014ECF0);

/* A three-state ramp: state 0 waits for unk_B8 to pass 75, state 1 raises
   unk_574 by 1/16 up to 1, state 2 lowers it to 0; the value then weights the
   blend of the vectors at 0x580 and 0x590, probably a fade in and out. */
void func_0014ED70(Obj_0014ED70 *arg0)
{
    switch (arg0->counter_570) {
    case 0:
        if (arg0->unk_B8 > 75.0f)
            arg0->counter_570++;
        break;
    case 1:
        arg0->counter_574 += 0.0625f;
        if (arg0->counter_574 > 1.0f) {
            arg0->counter_574 = 1.0f;
            arg0->counter_570++;
        }
        break;
    case 2:
        arg0->counter_574 -= 0.0625f;
        if (arg0->counter_574 < 0.0f) {
            arg0->counter_574 = 0.0f;
            arg0->counter_570--;
        }
        break;
    }
    func_0012EE90(&arg0->unk_580, &arg0->unk_590, &arg0->unk_5B0.vec0, arg0->counter_574);
    arg0->unk_5A0.unk_0 = arg0->unk_5B0.unk_0;
    func_0012EDF0(&arg0->unk_5B0.vec0, &arg0->unk_5D0, 0.5f);
}

/* Adds arg1 to the counter at D_006AF098, kept within 0..99, then calls
   func_0013DFD0 with 5 for a rise or 4 for a fall. Nothing happens when the
   counter is already at its limit in the direction of the change. */
void func_0014EE90(s32 arg0, s32 arg1)
{
    if (D_006AF098 >= 99 && arg1 > 0)
        return;
    if (D_006AF098 <= 0 && arg1 < 0)
        return;

    D_006AF098 += arg1;
    if (D_006AF098 > 99)
        D_006AF098 = 99;
    if (D_006AF098 < 0)
        D_006AF098 = 0;

    if (arg1 > 0) {
        func_0013DFD0(-1, *D_006A6D10, 5, 0x3FFF, 0, 0);
    } else if (arg1 < 0) {
        func_0013DFD0(-1, *D_006A6D10, 4, 0x3FFF, 0, 0);
    }
}

void func_0014EF80(s32 arg0)
{
    s32 first;
    s32 second;

    first = D_006AF0A0[D_006AF4A0 * 2];
    if (first != 0) {
        func_0014EE90(arg0, first);
        D_006AF0A0[D_006AF4A0 * 2] = 0;
    }
    second = D_006AF0A4[D_006AF4A0 * 2];
    if (second != 0) {
        func_0014EE90(arg0, second);
        D_006AF0A4[D_006AF4A0 * 2] = 0;
    }
    D_006AF4A0 += 1;
    if (D_006AF4A0 >= 0x80) {
        D_006AF4A0 = 0;
    }
}

void func_0014F060(Obj *arg0, Vec *arg1) {
    arg0->unk_3A0 = arg0->unk_2B0;
    arg0->unk_3B0 = arg0->unk_30;
    if (arg0->flags & 2) {
        arg0->unk_3C4 = arg0->unk_150;
        arg0->unk_3D0 = 2;
    } else {
        arg0->unk_3C4 = arg0->unk_14C;
        arg0->unk_3D0 = 0;
    }
    *arg1 = arg0->unk_400;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F0D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F280);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F320);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F3D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F590);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014F6C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014FFD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_001502A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150330);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150660);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150760);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_001509A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150B90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150C30);

/* Probably a constructor: the base initialiser runs first, then the table pointer at +0x0
   is set, the two quads and the float are copied in, and the object is returned. */
// !FAKE: probably a constructor whose this the compiler keeps in a stack slot and reloads before every use; volatile on the parameter keeps those reloads in C
Obj_00150D00 *func_00150D00(Obj_00150D00 *volatile arg0, Quad *arg1, Quad *arg2, f32 arg3)
{
    func_001318C0(arg0, 4, 0);
    arg0->unk_0 = &D_0069C8E0;
    arg0->unk_90 = *arg1;
    arg0->unk_A0 = *arg2;
    arg0->unk_B0 = arg3;
    func_00150330(arg0);
    return arg0;
}

s32 **func_00150D90(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C8E0;
        func_00150660(arg0);
        func_001319D0(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150E00);

void func_00151060(void) {
    func_0014FFD0();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00151070);
