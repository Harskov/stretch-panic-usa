#include "common.h"

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    void f0() {
        unk_24 = 0;
        unk_28 = unk_30;
    }
    unsigned char unk_04[0x20];
    u8 unk_24;
    unsigned char unk_25[3];
    unsigned char *unk_28;
    unsigned char unk_2C[4];
    unsigned char unk_30[4];
};

struct Obj {
    unsigned char unk_00[0xD8];
    u32 unk_D8;
    Base **unk_DC;
};

extern "C" void func_0016D770(Obj *arg0)
{
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
    {
        u32 i;
        u32 n;
        Base **list;

        n = arg0->unk_D8;
        list = arg0->unk_DC;
        for (i = 0; i < n; i++) {
            if (list[i] != 0) {
                list[i]->f0();
            }
        }
    }
}
