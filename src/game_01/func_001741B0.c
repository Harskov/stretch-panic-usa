#include "game_01/obj50.h"

s32 func_001741B0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;

    p = &arg0->pos;
    v = &arg0->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->unk_A0;
    arg0->unk_9C = arg0->unk_9C + t;

    if (!(arg0->unk_A0 <= 0.0f) && !(arg0->unk_9C <= 1.0f)) {
        arg0->unk_9C = 1.0f;
        arg0->unk_A0 = 0.0f;
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}
