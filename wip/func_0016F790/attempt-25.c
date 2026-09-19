#include "common.h"

extern Vec D_006AEE40;
extern u8 D_006AEE58;
extern u8 D_006AEE60;

typedef struct Obj {
    unsigned char unk_00[0x10];
    Vec v10;
} Obj;

s32 func_0016F790(Obj *o, Vec *b, s32 *state)
{
    register Vec *a;
    register Vec *d;

    switch (*state) {
    case 0:
        a = &D_006AEE40;
        d = &o->v10;
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(b)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(d)
        }
        if (D_006AEE58 | D_006AEE60) {
            *state = *state + 1;
        }
        return 0;
    case 1:
        a = &D_006AEE40;
        d = &o->v10;
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(b)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(d)
        }
        if (D_006AEE60) {
            *state = *state + 1;
        }
        return 0;
    case 2:
        return 1;
    }
}
