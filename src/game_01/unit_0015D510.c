#include "common.h"
#include "game_00/unit_0012DF10.h"

extern void __dl__FPv(void *p);

int func_0015E070(Vec *, Vec *, Vec *, void *, Vec *);

/* The scale at +0x60 is a float the VU0 block takes whole into vf2's x lane, so it is
   read through its word view. */
typedef union Sub_0015DF60 {
    f32 f0;
    s32 i0;
} Sub_0015DF60;

typedef struct Obj_0015DF00 {
    u8 pad_0[0x20];
    /* 0x20 */ Vec unk_20;
    u8 pad_30[0x10];
    /* 0x40 */ Vec unk_40;
    u8 pad_50[0x10];
    /* 0x60 */ Sub_0015DF60 unk_60;
    u8 pad_64[0x1C];
    /* 0x80 */ Vec unk_80;
} Obj_0015DF00;

int func_0015E340(Obj_0015DF00 *o, Vec *a, Vec *b, void *p);

void func_0015D510(void) {
}

void func_0015D520(void) {
}

int func_0015D530(void) {
    return 0;
}

void func_0015D540(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D550);

void *func_0015D600(void *p, s16 flags)
{
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D650);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D850);

int func_0015D9C0(Vec *a, void *arg1)
{
    Vec out[3];
    Vec d;
    register Vec *p = a;
    register Vec *q = a + 1;
    register Vec *r = &d;

    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(q)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(r)
    }
    if (func_0015E070(a, &d, a + 1, arg1, out) != 0) {
        func_0012E9A0(a, &out[1], a, 0.03125f + out[2].x);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015DA40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015DC70);

/* Scales the vectors at +0x40 and +0x20 by the scalar at +0x60 and passes each to
   func_0015E340 twice, once as it is and once negated; the last call's result is returned. */
u8 func_0015DF00(Obj_0015DF00 *o, void *p)
{
    Vec v;
    register s32 k;
    register Vec *d;
    register Vec *r;

    d = &o->unk_40;
    k = o->unk_60.i0;
    r = &v;
    asm {
        nop
        lqc2 vf1, 0(d)
        qmtc2.ni k, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(r)
    }
    func_0015E340(o, &o->unk_80, &v, p);
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    func_0015E340(o, &o->unk_80, &v, p);

    d = &o->unk_20;
    k = o->unk_60.i0;
    r = &v;
    asm {
        nop
        lqc2 vf1, 0(d)
        qmtc2.ni k, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(r)
    }
    func_0015E340(o, &o->unk_80, &v, p);
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    return func_0015E340(o, &o->unk_80, &v, p);
}
