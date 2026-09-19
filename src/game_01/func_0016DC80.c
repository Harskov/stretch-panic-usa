#include "game_01/obj168.h"

s32 func_0016DC80(Obj168 *arg0) {
    s32 v = arg0->unk_168;
    if (v != 0) {
        arg0->unk_168 = v - 1;
        if (arg0->unk_168 == 0) {
            arg0->flags &= 0xFBFFFFFF;
            arg0->unk_164 = 0;
        }
        return 1;
    }
    return 0;
}
