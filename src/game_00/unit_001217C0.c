#include "common.h"

typedef struct Pair_001217C0 {
    Quad *unk_0;
    s32 unk_4;
} Pair_001217C0;

typedef struct Obj_001217C0 {
    u8 unk_0[0x10];
    Quad unk_10;
    Vec unk_20;
    s32 unk_30;
    /* 0x34 */ f32 unk_34;
    Vec *unk_38;
    Quad *unk_3C;
    s32 unk_40;
    s32 unk_44;
} Obj_001217C0;

typedef struct Obj_00121AD0 {
    s32 unk_0;
    s32 unk_4;
    Vec *unk_8;
    Quad *unk_C;
    s32 unk_10;
    s32 unk_14;
} Obj_00121AD0;

typedef struct Seg_00121B10 {
    u8 unk_0[0x10];
    f32 unk_10;
    s32 unk_14;
} Seg_00121B10;

typedef struct Obj_00121B10 {
    s32 unk_0;
    f32 unk_4;
    Seg_00121B10 *unk_8;
    Seg_00121B10 *unk_C;
    Seg_00121B10 *unk_10;
} Obj_00121B10;

s32 func_001217C0(s32 value, s32 align);

s32 func_001179D8(s32 a, s32 b);

/* rounds value up to the next multiple of align */
s32 func_001217C0(s32 value, s32 align)
{
    return align * ((value + (align - 1)) / align);
}

void func_001217E0(s32 value, s32 align)
{
    if (func_001179D8(align, func_001217C0(value, align)) == 0) {
        while (1) {
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121820);

void func_00121880(Obj_001217C0 *o, Pair_001217C0 *s)
{
    register Vec *b;
    register Vec *a;
    register Vec *d;
    register Vec *c;

    a = &o->unk_10.vec0;
    b = &o->unk_20;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(b)
    }
    if (s->unk_0 != 0) {
        o->unk_3C = s->unk_0;
        o->unk_40 = s->unk_4;
    } else {
        o->unk_3C = (Quad *)o->unk_44;
        o->unk_40 = o->unk_44;
    }
    o->unk_30 = 0;
    o->unk_38 = &o->unk_3C->vec0;
    o->unk_10.unk_0 = o->unk_3C->unk_0;
    c = &o->unk_20;
    d = &o->unk_10.vec0;
    asm {
        lqc2 vf1, 0(c)
        lqc2 vf2, 0(d)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(c)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121930);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121A60);

void func_00121AD0(Obj_00121AD0 *o, Pair_001217C0 *s)
{
    if (s->unk_0 != 0) {
        o->unk_C = s->unk_0;
        o->unk_10 = s->unk_4;
    } else {
        o->unk_C = (Quad *)o->unk_14;
        o->unk_10 = o->unk_14;
    }
    o->unk_4 = 0;
    o->unk_8 = &o->unk_C->vec0;
}

void func_00121B10(Obj_00121B10 *o, f32 dt)
{
    o->unk_4 += dt;
    while (o->unk_4 < 0.0f || o->unk_4 >= o->unk_8->unk_10) {
        if (o->unk_4 < 0.0f) {
            if (o->unk_8 != o->unk_C) {
                o->unk_8--;
                o->unk_4 += o->unk_8->unk_10;
            } else {
                o->unk_8 = o->unk_10;
                o->unk_4 += o->unk_8->unk_10;
            }
        } else {
            if (o->unk_8 != o->unk_10) {
                o->unk_4 -= o->unk_8->unk_10;
                o->unk_8++;
            } else {
                o->unk_4 -= o->unk_8->unk_10;
                o->unk_8 = o->unk_C;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121C10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121C70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121D60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121E50);

void func_00121F20(Obj_001217C0 *o, f32 v)
{
    o->unk_34 = v;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121F30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121FE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_001221F0);
