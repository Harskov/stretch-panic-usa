#include "common.h"
#include "game_01/obj168.h"

s32 func_00172A80(s32 arg0);

void func_0016DC40(Obj168 *arg0, s32 arg1) {
    arg0->unk_164 = arg1;
    arg0->unk_168 = func_00172A80(arg1);
    arg0->flags |= 0x04000000;
}
