#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012DF10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E190);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E500);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012E6D0);

asm f32 func_0012E820(Vec *a)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    vmul.xyz vf2, vf1, vf1
    vaddy.x vf2, vf2, vf2y
    vaddz.x vf2, vf2, vf2z
    vsqrt Q, vf2x
    vwaitq
    vaddq.x vf1, vf0, Q
    qmfc2.ni a0, vf1
    jr ra
    mtc1 a0, f0
}

asm f32 func_0012E850(Vec *a)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    vmul.xyz vf2, vf1, vf1
    vaddy.x vf2, vf2, vf2y
    vaddz.x vf2, vf2, vf2z
    qmfc2.ni a0, vf2
    jr ra
    mtc1 a0, f0
}

asm f32 func_0012E870(Vec *a, Vec *b)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    lqc2 vf2, 0(a1)
    vsub.xyz vf1, vf1, vf2
    vmul.xyz vf2, vf1, vf1
    vaddy.x vf2, vf2, vf2y
    vaddz.x vf2, vf2, vf2z
    qmfc2.ni a0, vf2
    jr ra
    mtc1 a0, f0
}

f32 func_0012E8A0(register Vec *a)
{
    register f32 r;

    asm {
        lqc2 vf1, 0(a)
        vmul.xyz vf2, vf1, vf1
        vaddy.x vf2, vf2, vf2y
        vaddz.x vf2, vf2, vf2z
        vsqrt Q, vf2x
        vwaitq
        vaddq.x vf2, vf0, Q
        vdiv Q, vf0w, vf2x
        vwaitq
        qmfc2.ni t0, vf2
        mtc1 t0, r
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(a)
    }
    return r;
}

f32 func_0012E8E0(register Vec *a, register Vec *out)
{
    register f32 r;

    asm {
        lqc2 vf1, 0(a)
        vmul.xyz vf2, vf1, vf1
        vaddy.x vf2, vf2, vf2y
        vaddz.x vf2, vf2, vf2z
        vsqrt Q, vf2x
        vwaitq
        vaddq.x vf2, vf0, Q
        vdiv Q, vf0w, vf2x
        vwaitq
        qmfc2.ni t0, vf2
        mtc1 t0, r
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0(out)
    }
    return r;
}

asm f32 func_0012E920(Vec *a)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    vmul.xyz vf2, vf1, vf1
    vaddy.x vf2, vf2, vf2y
    vaddz.x vf2, vf2, vf2z
    vrsqrt Q, vf0w, vf2x
    vwaitq
    vaddq.x vf1, vf0, Q
    qmfc2.ni a0, vf1
    jr ra
    mtc1 a0, f0
}

asm f32 func_0012E950(Vec *a, Vec *b)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    lqc2 vf2, 0(a1)
    vmul.xyz vf2, vf1, vf2
    vaddy.x vf2, vf2, vf2y
    vaddz.x vf2, vf2, vf2z
    qmfc2.ni a0, vf2
    jr ra
    mtc1 a0, f0
}

asm f32 func_0012E970(Vec *a, Vec *b)
{
    .set noreorder
    lqc2 vf1, 0(a0)
    lqc2 vf2, 0(a1)
    vmul.xyzw vf2, vf1, vf2
    vaddy.x vf2, vf2, vf2y
    vaddw.z vf2, vf2, vf2w
    vaddz.x vf2, vf2, vf2z
    qmfc2.ni a0, vf2
    jr ra
    mtc1 a0, f0
}

void func_0012E9A0(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        mfc1 v0, t
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyz vf2, vf2, vf3x
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012E9C0(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        mfc1 v0, t
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyz vf1, vf1, vf3x
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012E9E0(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        mfc1 v0, t
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyz vf2, vf2, vf3x
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

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

void func_0012EA50(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyz vf4, vf2, vf1
        .set noreorder
        mfc1 v0, t
        qmtc2.ni v0, vf3
        .set reorder
        vmulx.xyz vf4, vf4, vf3x
        vadd.xyz vf1, vf1, vf4
        sqc2 vf1, 0(out)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012EA80);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012EBF0);
