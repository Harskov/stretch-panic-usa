#include "common.h"

class Sub {
public:
    virtual void m0(int);
};

struct Obj {
    unsigned char pad[0xB0];
    Sub *unk_B0;
};

extern "C" void func_00159EE0(Obj *arg0);

// registers: sub = the object held at unk_B0, called through its vtable
void func_00159EE0(Obj *arg0)
{
    Sub *sub = arg0->unk_B0;
    if (sub != 0) {
        sub->m0(1);
    }
}
