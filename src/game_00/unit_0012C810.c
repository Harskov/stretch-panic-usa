#include "common.h"

typedef struct Obj_0012D430 {
    u8 unk_0[0x40];
    s32 unk_40;
} Obj_0012D430;

extern s32 D_006A6BC0;

extern Vec *D_006A6BB0;

extern Vec *D_006A6BD0;

void func_0012C810();

void func_0012C840();

f32 cosf(f32);

f32 sinf(f32);

extern Vec *D_006A6BC8;

extern Vec *D_006A6BD8;

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

// v = m * v in place, m as four rows: the MMI transpose turns them into the columns the VU0 multiply takes
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

// out = m * v, m as four rows: the MMI transpose turns them into the columns the VU0 multiply takes
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

void func_0012D430(Obj_0012D430 *arg0)
{
    arg0->unk_40 = -1;
    func_0012C810((Vec *)D_006A6BC0, (Vec *)arg0);
}

void func_0012D450(Vec *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BC8[3].x = arg1;
    D_006A6BC8[3].y = arg2;
    D_006A6BC8[3].z = arg3;
    func_0012C840(D_006A6BC8, D_006A6BB0, arg0);
}

void func_0012D4E0(Vec *arg0, f32 arg1)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BC8[3].x = 0.0f;
    D_006A6BC8[3].y = arg1;
    D_006A6BC8[3].z = 0.0f;
    func_0012C840(D_006A6BC8, D_006A6BB0, arg0);
}

void func_0012D560(Vec *arg0, f32 arg1)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BC8[3].x = 0.0f;
    D_006A6BC8[3].y = 0.0f;
    D_006A6BC8[3].z = arg1;
    func_0012C840(D_006A6BC8, D_006A6BB0, arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D5E0);

/* Probably a rotation about the x axis: the rows of D_006A6BD0 take the sine and
   cosine of arg1 the way func_0012DBA0 fills them, then the result goes back to arg0. */
void func_0012D900(Vec *arg0, f32 arg1)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BD0[0].z = 0.0f;
    D_006A6BD0[1].z = sinf(arg1);
    D_006A6BD0[2].z = cosf(arg1);
    D_006A6BD0[0].y = 0.0f;
    D_006A6BD0[1].y = D_006A6BD0[2].z;
    D_006A6BD0[2].y = -D_006A6BD0[1].z;
    D_006A6BD0[0].x = 1.0f;
    D_006A6BD0[1].x = 0.0f;
    D_006A6BD0[2].x = 0.0f;
    func_0012C840(D_006A6BD0, D_006A6BB0, arg0);
}

/* Probably a rotation about the y axis: the rows of D_006A6BD0 take the cosine and
   sine of arg1 the way func_0012D900 fills them for x, then the result goes back to arg0. */
void func_0012D9E0(Vec *arg0, f32 arg1)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BD0[0].x = cosf(arg1);
    D_006A6BD0[1].x = 0.0f;
    D_006A6BD0[2].x = sinf(arg1);
    D_006A6BD0[0].y = 0.0f;
    D_006A6BD0[1].y = 1.0f;
    D_006A6BD0[2].y = 0.0f;
    D_006A6BD0[0].z = -D_006A6BD0[2].x;
    D_006A6BD0[1].z = 0.0f;
    D_006A6BD0[2].z = D_006A6BD0[0].x;
    func_0012C840(D_006A6BD0, D_006A6BB0, arg0);
}

/* Probably a rotation about the z axis: the rows of D_006A6BD0 take the sine and
   cosine of arg1 the way func_0012D900 fills them, then the result goes back to arg0. */
void func_0012DAC0(Vec *arg0, f32 arg1)
{
    func_0012C810(arg0, D_006A6BB0);
    D_006A6BD0[0].z = 0.0f;
    D_006A6BD0[1].z = 0.0f;
    D_006A6BD0[2].z = 1.0f;
    D_006A6BD0[0].y = sinf(arg1);
    D_006A6BD0[1].y = cosf(arg1);
    D_006A6BD0[2].y = 0.0f;
    D_006A6BD0[0].x = D_006A6BD0[1].y;
    D_006A6BD0[1].x = -D_006A6BD0[0].y;
    D_006A6BD0[2].x = 0.0f;
    func_0012C840(D_006A6BD0, D_006A6BB0, arg0);
}

void func_0012DBA0(Vec *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    f32 cx;
    f32 cy;
    f32 cz;
    f32 sx;
    f32 sy;
    f32 sz;

    func_0012C810(arg0, D_006A6BB0);
    cx = cosf(arg1);
    cy = cosf(arg2);
    cz = cosf(arg3);
    sx = sinf(arg1);
    sy = sinf(arg2);
    sz = sinf(arg3);
    D_006A6BD0[0].x = cy * cz + sz * (sx * sy);
    D_006A6BD0[1].x = -cy * sz + sy * (cz * sx);
    D_006A6BD0[2].x = cx * sy;
    D_006A6BD0[0].y = cx * sz;
    D_006A6BD0[1].y = cx * cz;
    D_006A6BD0[2].y = -sx;
    D_006A6BD0[0].z = -cz * sy + cy * (sx * sz);
    D_006A6BD0[1].z = sy * sz + sx * (cy * cz);
    D_006A6BD0[2].z = cx * cy;
    func_0012C840(D_006A6BD0, D_006A6BB0, arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DD20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DDB0);

/* Probably a scale along the y axis: unless arg1 is 1, the diagonal of D_006A6BD8 takes
   1, arg1, 1 and the product goes back to arg0, whose word at +0x40 is cleared first. */
void func_0012DE80(Obj_0012D430 *arg0, f32 arg1)
{
    if (arg1 != 1.0f) {
        arg0->unk_40 = 0;
        func_0012C810((Vec *)arg0, D_006A6BB0);
        D_006A6BD8[0].x = 1.0f;
        D_006A6BD8[1].y = arg1;
        D_006A6BD8[2].z = 1.0f;
        func_0012C840(D_006A6BD8, D_006A6BB0, (Vec *)arg0);
    }
}
