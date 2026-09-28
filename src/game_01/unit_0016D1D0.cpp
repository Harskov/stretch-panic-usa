#include "common.h"

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Obj {
    unsigned char unk_00[0xD8];
    u32 unk_D8;
    Base **unk_DC;
};

extern "C" void func_0016D1D0(Obj *arg0);

void func_0016D1D0(Obj *arg0)
{
    u32 i;
    u32 n;
    Base **list;

    n = arg0->unk_D8;
    list = arg0->unk_DC;
    for (i = 0; i < n; i++) {
        if (list[i] != 0) {
            list[i]->m2();
        }
    }
}
