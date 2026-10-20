#include "common.h"

typedef struct Obj_00122460 {
    u8 unk_0[0x10];
    /* 0x10 */ u8 unk_10;
    u8 unk_11[0xF];
    /* 0x20 */ Vec unk_20;
} Obj_00122460;

void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

extern s32 D_0069C1E0;

void __dl__FPv();

typedef struct Obj_001223D0 {
    u8 unk_0[0x3C];
    /* 0x3C */ s32 unk_3C;
    u8 unk_40[4];
    /* 0x44 */ s32 unk_44;
} Obj_001223D0;

extern s32 D_0069C200;

typedef struct Obj_001224A0 {
    u8 unk_0[8];
    /* 0x08 */ s32 *unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 unk_18;
} Obj_001224A0;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122260);

s32 **func_00122310(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C1E0;
        if (arg1 > 0) {
            // !FAKE: the original is a C++ destructor calling operator delete(this); the argument register still holds this, so the call passes nothing
            __dl__FPv();
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122360);

s32 **func_00122380(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C200;
        if (arg1 > 0) {
            // !FAKE: the original is a C++ destructor calling operator delete(this); the argument register still holds this, so the call passes nothing
            __dl__FPv();
        }
    }
    return arg0;
}

s32 func_001223D0(Obj_001223D0 *o)
{
    return o->unk_3C != o->unk_44;
}

f32 func_001223F0(Obj_00122460 *o)
{
    return o->unk_20.x;
}

f32 func_00122400(Obj_00122460 *o)
{
    return o->unk_20.y;
}

f32 func_00122410(Obj_00122460 *o)
{
    return o->unk_20.z;
}

void func_00122420(Obj_00122460 *o, f32 dx)
{
    o->unk_20.x += dx;
}

void func_00122430(Obj_00122460 *o, f32 dy)
{
    o->unk_20.y += dy;
}

void func_00122440(Obj_00122460 *o, f32 dz)
{
    o->unk_20.z += dz;
}

/* Applies func_0012E9A0 to the vector at 0x20 in place, with b and t passed through. */
void func_00122450(Obj_00122460 *o, Vec *b, f32 t)
{
    func_0012E9A0(&o->unk_20, b, &o->unk_20, t);
}

void func_00122460(Obj_00122460 *o, register Vec *d)
{
    register Vec *p;

    p = &o->unk_20;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(d)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
}

/* func_00122460, func_00122480 and func_00122490 are slots of one function-pointer
   table (D_0069C200), so all three are called on the same object. Only the address
   of +0x10 is taken, so its type is not known. */
void *func_00122480(Obj_00122460 *o) {
    return &o->unk_10;
}

Vec *func_00122490(Obj_00122460 *o) {
    return &o->unk_20;
}

void func_001224A0(Obj_001224A0 *o, s32 a1, s32 a2, s32 a3, u8 a4)
{
    s32 i;

    o->unk_C = a1;
    o->unk_14 = a2;
    o->unk_10 = a3;
    o->unk_18 = a4;
    for (i = *o->unk_8; i != 0; i--) {
        func_00122510(o, o->unk_8[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122510);
