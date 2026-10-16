#include "common.h"

class Obj_00172C00 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(s32);
    f32 unk_4;
    f32 unk_8;
};

extern "C" bool func_00172C00(Obj_00172C00 *o, s32 arg1, f32 arg2)
{
    bool r = false;
    if (arg2 + o->unk_4 >= o->unk_8) {
        r = true;
        if (arg1 != 0) {
            o->m5(0);
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172C60);
