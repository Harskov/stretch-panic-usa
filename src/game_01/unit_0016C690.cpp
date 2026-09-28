#include "common.h"

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

class Node : public Base {
public:
    unsigned char unk_04[0x38];
    Node *next;
};

extern Node *D_006B3700[];

extern "C" void func_0016C690(void)
{
    s32 i;
    Node *p;

    for (i = 0; i < 0x5F; i++) {
        for (p = D_006B3700[i]; p != 0; p = p->next) {
            p->m3();
        }
    }
}
