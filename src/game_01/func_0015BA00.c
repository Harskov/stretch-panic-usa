#include "game_01/obj1F0.h"

void func_0015BA00(Obj1F0 *arg0, Owner1F0 *arg1) {
    f32 zero;

    arg0->unk_10 = arg0->unk_1F0;
    arg0->unk_30 = arg0->unk_200;
    if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    zero = 0.0f;
    if ((arg1->unk_80 != zero) || (arg0->unk_1D8 & 2)) {
        arg0->unk_60 |= 0x80000;
    }
}
