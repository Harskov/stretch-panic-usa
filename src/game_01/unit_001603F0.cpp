#include "common.h"

class Sub {
public:
    virtual void m0(int);
};

struct Obj {
    Sub *unk_0;
};

extern "C" void __dl__FPv(void *);

extern "C" Obj *func_001603F0(Obj *self, s16 flags);

Obj *func_001603F0(Obj *self, s16 flags)
{
    if (self != 0) {
        Sub *sub = self->unk_0;
        if (sub != 0) {
            sub->m0(1);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001603F0", func_00160460);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001603F0", func_00160640);
