#include "common.h"

class Sub {
public:
    virtual void m0(int);
};

struct Obj_001690A0 {
    void *unk_0;
    unsigned char unk_04[0xCC];
    Sub *unk_D0;
};

extern s32 D_0069CD40;

extern "C" void func_001319D0(void *, int);

extern "C" void __dl__FPv(void *);

extern "C" Obj_001690A0 *func_001690A0(Obj_001690A0 *o, s16 flags);

Obj_001690A0 *func_001690A0(Obj_001690A0 *o, s16 flags) {
    if (o != 0) {
        o->unk_0 = &D_0069CD40;
        if (o->unk_D0 != 0) {
            o->unk_D0->m0(1);
        }
        func_001319D0(o, 0);
        if (flags > 0) {
            __dl__FPv(o);
        }
    }
    return o;
}
