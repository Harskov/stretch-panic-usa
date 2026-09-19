#include "common.h"

/* A different object from Obj50: its vector pair sits at +0x10/+0x20, not +0x50/+0x60,
   and its counter at +0x54. Only the Vec type is shared. */
typedef struct Obj10 {
    unsigned char unk_00[0x10];
    Vec pos;
    Vec vel;
    unsigned char unk_30[0x24];
    f32 unk_54;
    f32 unk_58;
} Obj10;

s32 func_001636C0(Obj10 *o) {
    register Vec *v;
    register Vec *p;
    f32 a;
    f32 b;

    p = &o->pos;
    v = &o->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    b = o->unk_58;
    a = o->unk_54;
    a = a - b;
    o->unk_54 = a;
    if (a <= 0.0f) {
        return 0;
    }
    return 1;
}
