#include "game_01/obj1F0.h"

void func_00159E20(Obj1F0 *arg0, Owner1F0 *arg1) {
    if (arg0->unk_1D0 != 0) {
        arg0->unk_60 |= 0x80000;
    } else if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    arg0->unk_10 = arg0->unk_230;
    arg0->unk_30 = arg0->unk_240;
}
