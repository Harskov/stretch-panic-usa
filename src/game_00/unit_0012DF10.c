#include "common.h"
#include "game_00/unit_0012DF10.h"

void func_0012C710(f32 *);

typedef struct Obj_0012E350 {
    /* 0x00 */ Vec unk_0[4];
    /* 0x40 */ s32 unk_40;
} Obj_0012E350;

extern Vec *D_006A6BB0;

extern Vec *D_006A6BB8;

void func_0012C810(Vec *a, Vec *b);

void func_0012C840(Vec *a, Vec *b, Vec *out);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012DF10", func_0012DF10);

/* Probably a perspective (frustum) projection: the matrix at D_006A6BB8 takes 2*arg5/(arg2-arg1),
   2*arg5/(arg4-arg3) on its diagonal, the centres in its third row with -1 in its w, and the
   depth terms from arg5 and arg6, then goes through func_0012C840 into arg0. */
// locals: the reciprocals of the three extents (inv_x, inv_y, inv_z)
void func_0012E190(Obj_0012E350 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    f32 inv_x;
    f32 inv_y;
    f32 inv_z;

    arg0->unk_40 = 0;
    func_0012C810(arg0->unk_0, D_006A6BB0);

    inv_x = 1.0f / (arg2 - arg1);
    inv_y = 1.0f / (arg4 - arg3);
    inv_z = 1.0f / (arg6 - arg5);

    D_006A6BB8[0].x = 2.0f * arg5 * inv_x;
    D_006A6BB8[1].x = 0.0f;
    D_006A6BB8[2].x = inv_x * (arg2 + arg1);
    D_006A6BB8[3].x = 0.0f;

    D_006A6BB8[0].y = 0.0f;
    D_006A6BB8[1].y = 2.0f * arg5 * inv_y;
    D_006A6BB8[2].y = inv_y * (arg4 + arg3);
    D_006A6BB8[3].y = 0.0f;

    D_006A6BB8[0].z = 0.0f;
    D_006A6BB8[1].z = 0.0f;
    D_006A6BB8[2].z = -inv_z * (arg6 + arg5);
    D_006A6BB8[3].z = inv_z * (-2.0f * arg6 * arg5);

    D_006A6BB8[0].w = 0.0f;
    D_006A6BB8[1].w = 0.0f;
    D_006A6BB8[2].w = -1.0f;
    D_006A6BB8[3].w = 0.0f;

    func_0012C840(D_006A6BB8, D_006A6BB0, arg0->unk_0);
}

/* Probably an orthographic projection: the matrix at D_006A6BB8 takes 2/(arg2-arg1),
   2/(arg4-arg3), -2/(arg6-arg5) on its diagonal and the negated centres in its last row,
   then goes through func_0012C840 into arg0, whose word at +0x40 is cleared first. */
// locals: the reciprocals of the three extents (inv_x, inv_y, inv_z)
void func_0012E350(Obj_0012E350 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    f32 inv_x;
    f32 inv_y;
    f32 inv_z;

    arg0->unk_40 = 0;
    func_0012C810(arg0->unk_0, D_006A6BB0);

    inv_x = 1.0f / (arg2 - arg1);
    inv_y = 1.0f / (arg4 - arg3);
    inv_z = 1.0f / (arg6 - arg5);

    D_006A6BB8[0].x = 2.0f * inv_x;
    D_006A6BB8[1].x = 0.0f;
    D_006A6BB8[2].x = 0.0f;
    D_006A6BB8[3].x = -inv_x * (arg2 + arg1);

    D_006A6BB8[0].y = 0.0f;
    D_006A6BB8[1].y = 2.0f * inv_y;
    D_006A6BB8[2].y = 0.0f;
    D_006A6BB8[3].y = -inv_y * (arg4 + arg3);

    D_006A6BB8[0].z = 0.0f;
    D_006A6BB8[1].z = 0.0f;
    D_006A6BB8[2].z = -2.0f * inv_z;
    D_006A6BB8[3].z = -inv_z * (arg6 + arg5);

    D_006A6BB8[0].w = 0.0f;
    D_006A6BB8[1].w = 0.0f;
    D_006A6BB8[2].w = 0.0f;
    D_006A6BB8[3].w = 1.0f;

    func_0012C840(D_006A6BB8, D_006A6BB0, arg0->unk_0);
}

/* Probably a planar projection (shadow) matrix: with d the dot of arg1..arg3 and arg5..arg7,
   the matrix at D_006A6BB8 holds d on its diagonal less arg5..arg8 times arg1..arg4, the
   other entries their negated products; it then goes through func_0012C840 into arg0. */
// locals: the dot product of the first three of each four arguments (dot)
void func_0012E500(Obj_0012E350 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8)
{
    f32 dot;

    arg0->unk_40 = 0;
    func_0012C810(arg0->unk_0, D_006A6BB0);

    dot = arg1 * arg5 + arg2 * arg6 + arg3 * arg7;

    D_006A6BB8[0].x = dot - arg5 * arg1;
    D_006A6BB8[1].x = -arg6 * arg1;
    D_006A6BB8[2].x = -arg7 * arg1;
    D_006A6BB8[3].x = -arg8 * arg1;

    D_006A6BB8[0].y = -arg5 * arg2;
    D_006A6BB8[1].y = dot - arg6 * arg2;
    D_006A6BB8[2].y = -arg7 * arg2;
    D_006A6BB8[3].y = -arg8 * arg2;

    D_006A6BB8[0].z = -arg5 * arg3;
    D_006A6BB8[1].z = -arg6 * arg3;
    D_006A6BB8[2].z = dot - arg7 * arg3;
    D_006A6BB8[3].z = -arg8 * arg3;

    D_006A6BB8[0].w = -arg5 * arg4;
    D_006A6BB8[1].w = -arg6 * arg4;
    D_006A6BB8[2].w = -arg7 * arg4;
    D_006A6BB8[3].w = dot - arg8 * arg4;

    func_0012C840(D_006A6BB8, D_006A6BB0, arg0->unk_0);
}

/* After func_0012C710 on the argument, fills a table of vectors in the scratchpad: the six
   unit axes +x -x +y -y +z -z as points (w = 1), the point (0, 0, 0, 1), then a zero vector
   and a vector of ones. What reads the table is not yet known. */
void func_0012E6D0(void *arg0)
{
    func_0012C710(arg0);

    ((Vec *)0x70000B80)[0].x = 1.0f;
    ((Vec *)0x70000B80)[0].y = 0.0f;
    ((Vec *)0x70000B80)[0].z = 0.0f;
    ((Vec *)0x70000B80)[0].w = 1.0f;

    ((Vec *)0x70000B80)[1].x = -1.0f;
    ((Vec *)0x70000B80)[1].y = 0.0f;
    ((Vec *)0x70000B80)[1].z = 0.0f;
    ((Vec *)0x70000B80)[1].w = 1.0f;

    ((Vec *)0x70000B80)[2].x = 0.0f;
    ((Vec *)0x70000B80)[2].y = 1.0f;
    ((Vec *)0x70000B80)[2].z = 0.0f;
    ((Vec *)0x70000B80)[2].w = 1.0f;

    ((Vec *)0x70000B80)[3].x = 0.0f;
    ((Vec *)0x70000B80)[3].y = -1.0f;
    ((Vec *)0x70000B80)[3].z = 0.0f;
    ((Vec *)0x70000B80)[3].w = 1.0f;

    ((Vec *)0x70000B80)[4].x = 0.0f;
    ((Vec *)0x70000B80)[4].y = 0.0f;
    ((Vec *)0x70000B80)[4].z = 1.0f;
    ((Vec *)0x70000B80)[4].w = 1.0f;

    ((Vec *)0x70000B80)[5].x = 0.0f;
    ((Vec *)0x70000B80)[5].y = 0.0f;
    ((Vec *)0x70000B80)[5].z = -1.0f;
    ((Vec *)0x70000B80)[5].w = 1.0f;

    ((Vec *)0x70000B80)[6].x = 0.0f;
    ((Vec *)0x70000B80)[6].y = 0.0f;
    ((Vec *)0x70000B80)[6].z = 0.0f;
    ((Vec *)0x70000B80)[6].w = 1.0f;

    ((Vec *)0x70000B80)[8].x = 0.0f;
    ((Vec *)0x70000B80)[8].y = 0.0f;
    ((Vec *)0x70000B80)[8].z = 0.0f;
    ((Vec *)0x70000B80)[8].w = 0.0f;

    ((Vec *)0x70000B80)[7].x = 1.0f;
    ((Vec *)0x70000B80)[7].y = 1.0f;
    ((Vec *)0x70000B80)[7].z = 1.0f;
    ((Vec *)0x70000B80)[7].w = 1.0f;
}

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
