#include "common.h"
#include "globals.h"

class Obj_0016C720 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int);
};

struct Node_006B3880 : public Obj_0016C720 {
    unsigned char pad_4[0x44];
    Node_006B3880 *next;
};

extern "C" int func_0016C720(int arg0, int arg1);

int func_0016C720(int arg0, int arg1)
{
    Node_006B3880 *p;

    for (p = D_006B3880; p != 0; p = p->next) {
        p->m4(arg1);
    }
    return 0;
}
