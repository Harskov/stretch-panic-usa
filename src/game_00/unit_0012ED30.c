#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012ED30);

void func_0012EDF0(register Vec *in, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(in)
        qmtc2.ni v0, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0(out)
    }
}

void func_0012EE10(register Vec *a, register Vec *b, register Vec *out)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE30(register Vec *a, register Vec *b, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyzw vf2, vf2, vf3x
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE50(register Vec *a, register Vec *b, register Vec *out)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf1, vf1, vf2
        vnop
        vnop
        sqc2 vf1, 0(out)
    }
}

void func_0012EE70(register Vec *a, register Vec *b, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyzw vf2, vf2, vf3x
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE90(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf4, vf2, vf1
        .set noreorder
        mfc1 v0, t
        qmtc2.ni v0, vf3
        .set reorder
        vmulx.xyzw vf4, vf4, vf3x
        vadd.xyzw vf1, vf1, vf4
        sqc2 vf1, 0(out)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EEC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EEE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EEF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EF40);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F0B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F110);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F190);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F300);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F440);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F4E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F730);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F790);
