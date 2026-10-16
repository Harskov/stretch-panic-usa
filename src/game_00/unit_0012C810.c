#include "common.h"

void func_0012C810(register Vec *src, register Vec *dst)
{
    asm {
        lqc2 vf1, 0(src)
        lqc2 vf2, 0x10(src)
        lqc2 vf3, 0x20(src)
        lqc2 vf4, 0x30(src)
        sqc2 vf1, 0(dst)
        sqc2 vf2, 0x10(dst)
        sqc2 vf3, 0x20(dst)
        sqc2 vf4, 0x30(dst)
    }
}

void func_0012C840(register Vec *a, register Vec *b, register Vec *out)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0x10(a)
        lqc2 vf3, 0x20(a)
        lqc2 vf4, 0x30(a)
        lqc2 vf5, 0(b)
        lqc2 vf6, 0x10(b)
        lqc2 vf7, 0x20(b)
        lqc2 vf8, 0x30(b)
        vmulax.xyzw ACC, vf5, vf1x
        vmadday.xyzw ACC, vf6, vf1y
        vmaddaz.xyzw ACC, vf7, vf1z
        vmaddw.xyzw vf9, vf8, vf1w
        vmulax.xyzw ACC, vf5, vf2x
        vmadday.xyzw ACC, vf6, vf2y
        vmaddaz.xyzw ACC, vf7, vf2z
        vmaddw.xyzw vf10, vf8, vf2w
        vmulax.xyzw ACC, vf5, vf3x
        vmadday.xyzw ACC, vf6, vf3y
        vmaddaz.xyzw ACC, vf7, vf3z
        vmaddw.xyzw vf11, vf8, vf3w
        vmulax.xyzw ACC, vf5, vf4x
        vmadday.xyzw ACC, vf6, vf4y
        vmaddaz.xyzw ACC, vf7, vf4z
        vmaddw.xyzw vf12, vf8, vf4w
        sqc2 vf9, 0(out)
        sqc2 vf10, 0x10(out)
        sqc2 vf11, 0x20(out)
        sqc2 vf12, 0x30(out)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C8C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C8F0);

// m = 4x4 matrix rows, v = input/output vector
void func_0012C950(register Vec *m, register Vec *v)
{
    asm {
        lq t0, 0(m)
        lq t1, 0x10(m)
        lq t2, 0x20(m)
        lq t3, 0x30(m)
        pextlw t4, t1, t0
        pextuw t5, t1, t0
        pextlw t6, t3, t2
        pextuw t7, t3, t2
        pcpyld t0, t6, t4
        pcpyud t1, t4, t6
        pcpyld t2, t7, t5
        pcpyud t3, t5, t7
        qmtc2.ni t0, vf1
        qmtc2.ni t1, vf2
        qmtc2.ni t2, vf3
        qmtc2.ni t3, vf4
        lqc2 vf31, 0(v)
        vmulax.xyzw ACC, vf1, vf31x
        vmadday.xyzw ACC, vf2, vf31y
        vmaddaz.xyzw ACC, vf3, vf31z
        vmaddw.xyzw vf5, vf4, vf31w
        vnop
        vnop
        sqc2 vf5, 0(v)
    }
}

/* Apply the 4x4 matrix at m to vector v, storing the result in out.
   The MMI row-to-column transpose and VU0 multiply have no C spelling,
   so the sequence is written as one asm block. */
void func_0012C9C0(register Vec *m, register Vec *v, register Vec *out)
{
    asm {
        lq t0, 0(m)
        lq t1, 0x10(m)
        lq t2, 0x20(m)
        lq t3, 0x30(m)
        pextlw t4, t1, t0
        pextuw t5, t1, t0
        pextlw t6, t3, t2
        pextuw t7, t3, t2
        pcpyld t0, t6, t4
        pcpyud t1, t4, t6
        pcpyld t2, t7, t5
        pcpyud t3, t5, t7
        qmtc2.ni t0, vf1
        qmtc2.ni t1, vf2
        qmtc2.ni t2, vf3
        qmtc2.ni t3, vf4
        lqc2 vf31, 0(v)
        vmulax.xyzw ACC, vf1, vf31x
        vmadday.xyzw ACC, vf2, vf31y
        vmaddaz.xyzw ACC, vf3, vf31z
        vmaddw.xyzw vf5, vf4, vf31w
        vnop
        vnop
        sqc2 vf5, 0(out)
    }
}

void func_0012CA30(register Vec *m, register Vec *v)
{
    asm {
        lqc2 vf1, 0(v)
        lqc2 vf2, 0(m)
        lqc2 vf3, 0x10(m)
        lqc2 vf4, 0x20(m)
        lqc2 vf5, 0x30(m)
        vmulax.xyzw ACC, vf2, vf1x
        vmadday.xyzw ACC, vf3, vf1y
        vmaddaz.xyzw ACC, vf4, vf1z
        vmaddw.xyzw vf6, vf5, vf1w
        sqc2 vf6, 0(v)
    }
}

void func_0012CA60(register Vec *m, register Vec *v, register Vec *out)
{
    asm {
        lqc2 vf1, 0(v)
        lqc2 vf2, 0(m)
        lqc2 vf3, 0x10(m)
        lqc2 vf4, 0x20(m)
        lqc2 vf5, 0x30(m)
        vmulax.xyzw ACC, vf2, vf1x
        vmadday.xyzw ACC, vf3, vf1y
        vmaddaz.xyzw ACC, vf4, vf1z
        vmaddw.xyzw vf6, vf5, vf1w
        sqc2 vf6, 0(out)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CA90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CB10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D430);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D450);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D4E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D560);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D5E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D9E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DAC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DBA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DD20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DDB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DE80);
