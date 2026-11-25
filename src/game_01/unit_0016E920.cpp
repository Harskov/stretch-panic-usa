#include "common.h"

class Sub_0016E920 {
public:
    virtual void m0(int);
};

typedef struct Elem_0016E920 {
    u8 unk_0[0x24];
    Sub_0016E920 *unk_24;
    u8 unk_28[8];
} Elem_0016E920;

typedef struct Obj_0016E920 {
    u8 unk_0[0xE8];
    s32 unk_E8;
    Elem_0016E920 *unk_EC;
} Obj_0016E920;

extern "C" void func_0016E920(Obj_0016E920 *arg0);

void func_0016E920(Obj_0016E920 *arg0) {
    s32 i;

    for (i = 0; i != arg0->unk_E8; i++) {
        Sub_0016E920 *sub = arg0->unk_EC[i].unk_24;
        if (sub != 0) {
            sub->m0(1);
        }
    }
}
