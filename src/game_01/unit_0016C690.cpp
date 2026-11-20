#include "common.h"
#include "globals.h"

class Obj_0016C690 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Node_006B3700 : public Obj_0016C690 {
    unsigned char unk_04[0x38];
    Node_006B3700 *next;
};

extern "C" void func_0016C690(void)
{
    s32 i;
    Node_006B3700 *p;

    for (i = 0; i < 0x5F; i++) {
        for (p = D_006B3700[i]; p != 0; p = p->next) {
            p->m3();
        }
    }
}
