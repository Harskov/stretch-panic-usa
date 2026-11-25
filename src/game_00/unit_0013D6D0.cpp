#include "common.h"

class Sub_0013D8C0 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Obj_0013D8C0 {
    /* 0x000 */ u8 unk_0[0x1F4];
    /* 0x1F4 */ Sub_0013D8C0 *unk_1F4;
    /* 0x1F8 */ u8 unk_1F8[8];
    /* 0x200 */ Sub_0013D8C0 *unk_200[5];
};

extern "C" void func_0013D8C0(Obj_0013D8C0 *arg0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013D6D0", func_0013D6D0);

void func_0013D8C0(Obj_0013D8C0 *arg0)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (arg0->unk_200[i] != 0) {
            arg0->unk_200[i]->m2();
        }
    }
    arg0->unk_1F4->m2();
}
