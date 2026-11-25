#include "common.h"

class Sub_0013FCB0 {
public:
    virtual void m0(int);
    virtual void m1(int);
    virtual void m2(int);
    virtual void m3(int);
    virtual void m4(int);
    virtual void m5(int, f32);
};

struct Obj_0013FCB0 {
    /* 0x000 */ u8 unk_0[0x154];
    /* 0x154 */ Sub_0013FCB0 *unk_154;
    /* 0x158 */ u8 unk_158[8];
    /* 0x160 */ Sub_0013FCB0 *unk_160;
    /* 0x164 */ u8 unk_164[0x4C];
    /* 0x1B0 */ Vec unk_1B0;
    /* 0x1C0 */ Vec unk_1C0;
    /* 0x1D0 */ u8 unk_1D0[0x28];
    /* 0x1F8 */ f32 unk_1F8;
};

extern "C" void func_0013FCB0(Obj_0013FCB0 *arg0);

void func_0013FCB0(Obj_0013FCB0 *arg0)
{
    register Vec *src;
    register Vec *dst;
    dst = &arg0->unk_1B0;
    src = &arg0->unk_1C0;
    asm {
        lqc2 vf1, 0(dst)
        lqc2 vf2, 0(src)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(dst)
    }
    arg0->unk_154->m5(0, arg0->unk_1F8);
    arg0->unk_160->m5(0, arg0->unk_1F8);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013FCB0", func_0013FD20);
