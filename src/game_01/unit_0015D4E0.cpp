#include "common.h"

class Sub {
public:
    virtual void m0(int);
};

struct Obj_0015D4E0 {
    unsigned char pad[0x114];
    Sub *unk_114;
};

extern "C" void func_0015D4E0(Obj_0015D4E0 *arg0);

// registers: sub = the object held at unk_114, called through its vtable
void func_0015D4E0(Obj_0015D4E0 *arg0)
{
    Sub *sub = arg0->unk_114;
    if (sub != 0) {
        sub->m0(1);
    }
}
