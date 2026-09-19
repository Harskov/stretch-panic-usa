#include "game_01/obj430.h"

void func_00151460(Obj430 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 0;
    arg0->unk_420.w.unk_00 = 0;
    arg0->unk_420.w.unk_04 = 0;
    arg0->unk_420.w.unk_08 = 0;
    arg0->unk_420.w.unk_0C = 1.0f;
}
