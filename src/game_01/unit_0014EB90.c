#include "common.h"

typedef struct Obj {
    u8 pad0[0x30];
    u128 unk_30;
    u8 pad40[0x14C - 0x40];
    s32 unk_14C;
    s32 unk_150;
    u8 pad154[0x2B0 - 0x154];
    u128 unk_2B0;
    u8 pad2C0[0x378 - 0x2C0];
    s32 unk_378;
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

extern f32 func_0012E8E0(Vec *in, Vec *out);

void func_0014FFD0();

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

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014ED70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014EE90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_0014EF80);

void func_0014F060(Obj *arg0, Vec *arg1) {
    arg0->unk_3A0 = arg0->unk_2B0;
    arg0->unk_3B0 = arg0->unk_30;
    if (arg0->unk_378 & 2) {
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

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150D00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150D90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00150E00);

void func_00151060(void) {
    func_0014FFD0();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014EB90", func_00151070);
