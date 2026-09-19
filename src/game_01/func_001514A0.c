#include "game_01/obj430.h"

void func_001514A0(Obj430 *arg0, s32 arg1, const Quad420 *arg2, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 1;
    arg0->unk_420.q = arg2->q;
}
