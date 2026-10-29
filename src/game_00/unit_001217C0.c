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

typedef struct Obj_001217C0_2 {
    u8 unk_0[0x10];
    f32 unk_10;
    s32 unk_14;
} Obj_001217C0_2;

typedef struct Obj_00121B10 {
    s32 unk_0;
    f32 unk_4;
    /* 0x08 */ Obj_001217C0_2 *cursor;
    Obj_001217C0_2 *unk_C;
    Obj_001217C0_2 *unk_10;
} Obj_00121B10;

s32 func_001217C0(s32 value, s32 align);

s32 func_001179D8(s32 a, s32 b);

typedef struct Obj_001221F0 {
    s32 *unk_0;
    u8 unk_4[12];
    void *unk_10;
} Obj_001221F0;

extern s32 D_0069C1C0;

void func_00122260();

void __destroy_new_array(void *, void (*)());

void __dl__FPv(void *);

typedef struct Sub_00121C10 {
    s32 unk_0;
    s32 unk_4;
    f32 unk_8;
    f32 unk_C;
    s32 unk_10;
    f32 unk_14;
} Sub_00121C10;

typedef struct Obj_00121C10 {
    s32 unk_0;
    f32 unk_4;
    Sub_00121C10 *unk_8;
} Obj_00121C10;

extern s32 D_006A6700;

extern s32 D_006A6704;

extern f32 D_006A6708;

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

void func_00121B10(Obj_00121B10 *o, f32 arg1)
{
    o->unk_4 += arg1;
    while (o->unk_4 < 0.0f || o->unk_4 >= o->cursor->unk_10) {
        if (o->unk_4 < 0.0f) {
            if (o->cursor != o->unk_C) {
                o->cursor--;
                o->unk_4 += o->cursor->unk_10;
            } else {
                o->cursor = o->unk_10;
                o->unk_4 += o->cursor->unk_10;
            }
        } else {
            if (o->cursor != o->unk_10) {
                o->unk_4 -= o->cursor->unk_10;
                o->cursor++;
            } else {
                o->unk_4 -= o->cursor->unk_10;
                o->cursor = o->unk_C;
            }
        }
    }
}

s32 *func_00121C10(Obj_00121C10 *o)
{
    f32 t;
    f32 c;
    f32 b;
    f32 a;

    D_006A6700 = o->unk_8->unk_0;
    D_006A6704 = o->unk_8->unk_4;
    t = o->unk_4;
    c = o->unk_8->unk_14;
    b = o->unk_8->unk_C;
    a = o->unk_8->unk_8;
    D_006A6708 = a + b * (t * c);
    return &D_006A6700;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121C70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121D60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121E50);

void func_00121F20(Obj_001217C0 *o, f32 v)
{
    o->unk_34 = v;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121F30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121FE0);

Obj_001221F0 *func_001221F0(Obj_001221F0 *arg0, s16 arg1)
{
    if (arg0 != 0) {
        arg0->unk_0 = &D_0069C1C0;
        __destroy_new_array(arg0->unk_10, func_00122260);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
