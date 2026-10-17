#include "common.h"

class Sub_0015E000 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(Vec *a, Vec *b, Vec *c);
};

typedef struct Obj_0015E000 {
    /* 0x00 */ u8 unk_0[0x30];
    /* 0x30 */ Vec unk_30;
    /* 0x40 */ u8 unk_40[0x2C];
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ Vec unk_70;
} Obj_0015E000;

typedef struct Obj4 {
    /* 0x00 */ Sub_0015E000 *unk_0;
} Obj4;

extern "C" s32 func_0015E000(Obj_0015E000 *o, Obj4 *p);

s32 func_0015E000(Obj_0015E000 *o, Obj4 *p)
{
    Vec v;
    Vec out;
    register Vec *d;
    register Vec *r;
    register f32 s;

    s = -o->unk_6C;
    d = &o->unk_30;
    r = &v;
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(d)
        qmtc2.ni v0, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(r)
    }
    if (p->unk_0->m5(&o->unk_70, &v, &out)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015E000", func_0015E070);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015E000", func_0015E160);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015E000", func_0015E340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015E000", func_0015E520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015E000", func_0015E9B0);
