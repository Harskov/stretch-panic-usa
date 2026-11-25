#include "common.h"

typedef struct Obj_0015BD00 {
    u8 unk_0[0xA4];
    s32 unk_A4;
} Obj_0015BD00;

struct Sub_0015BD00 {
    u8 unk_0[0x10];
    u128 unk_10;
};

class Node_0015BD00 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual Sub_0015BD00 *m10();
    u8 unk_4[0x54];
    s32 unk_58;
    u8 unk_5C[0x34];
    Node_0015BD00 *unk_90;
};

extern Node_0015BD00 *D_006A6CF0;

extern "C" s32 func_0015BD00(Obj_0015BD00 *arg0, u128 *arg1);

/* walks the list at D_006A6CF0 for the node whose word at +0x58 equals the object's word at +0xA4,
   and copies the quadword at +0x10 of what that node's virtual returns; 1 when found, else 0 */
s32 func_0015BD00(Obj_0015BD00 *arg0, u128 *arg1)
{
    Node_0015BD00 *node;

    for (node = D_006A6CF0; node != 0; node = node->unk_90) {
        if (arg0->unk_A4 == node->unk_58) {
            *arg1 = node->m10()->unk_10;
            return 1;
        }
    }
    return 0;
}
