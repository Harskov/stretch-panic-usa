#include "common.h"
#include "game_01/actorC4.h"

typedef struct Obj {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 unk_20[0x10];
    u128 unk_30;
    u8 unk_40[0x20];
    u32 unk_60;
    u8 unk_64[0x16C];
    u8 unk_1D0;
    u8 unk_1D1[0x5F];
    u128 unk_230;
    u128 unk_240;
    u8 unk_250[0x40];
    u8 unk_290[0x10];
} Obj;

extern s32 func_00131B30(Obj *arg0, void *arg1, s32 *arg2, Actor *arg3, void *arg4);

s32 func_00159860(Obj *arg0, Actor *arg1)
{
    s32 tmp;

    arg0->unk_230 = arg0->unk_10;
    arg0->unk_240 = arg0->unk_30;
    if (func_00131B30(arg0, arg0->unk_290, &tmp, arg1, arg1->unk_80) != 0) {
        if (arg0->unk_1D0 != 0) {
            arg0->unk_60 |= 0x80000;
        } else if (arg1->unk_C4->unk_54 == 4) {
            arg0->unk_60 |= 0x80000;
        }
        arg0->unk_10 = arg0->unk_230;
        arg0->unk_30 = arg0->unk_240;
        return 1;
    }
    return 0;
}
