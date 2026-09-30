#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012DF10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E190);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E500);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E6D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E820);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E850);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E870);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E8A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E8E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E920);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E950);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E970);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E9A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E9C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E9E0);

void func_0012EA00(register Vec *a, register Vec *b, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyz vf1, vf1, vf3x
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EA20(register Vec *v, register f32 m, register f32 inv)
{
    asm {
        mfc1 v0, inv
        lqc2 vf1, 0(v)
        qmtc2.ni v0, vf2
        vmulx.xyz vf3, vf1, vf2x
        vftoi0.xyz vf3, vf3
        mfc1 v0, m
        vitof0.xyz vf3, vf3
        qmtc2.ni v0, vf2
        vmulx.xyz vf3, vf3, vf2x
        vsub.xyz vf1, vf1, vf3
        sqc2 vf1, 0(v)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012EA50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012EA80);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012EBF0);
