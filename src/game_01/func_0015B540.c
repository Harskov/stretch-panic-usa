#include "common.h"

typedef struct Info {
    u8 unk_00[0x54];
    s32 unk_54;
} Info;

typedef struct Actor {
    u8 unk_00[0x80];
    u8 unk_80[0x44];
    Info *unk_C4;
} Actor;

typedef struct Obj {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 unk_20[0x10];
    u128 unk_30;
    u8 unk_40[0x20];
    u32 unk_60;
    u8 unk_64[0x174];
    u32 unk_1D8;
    u8 unk_1DC[0x14];
    u128 unk_1F0;
    u128 unk_200;
    u8 unk_210[0x40];
    u8 unk_250[0x10];
} Obj;

extern s32 func_00131B30(Obj *arg0, void *arg1, f32 *arg2, Actor *arg3, void *arg4);

s32 func_0015B540(Obj *arg0, Actor *arg1)
{
    f32 tmp;
    f32 zero;

    arg0->unk_1F0 = arg0->unk_10;
    arg0->unk_200 = arg0->unk_30;
    if (func_00131B30(arg0, arg0->unk_250, &tmp, arg1, arg1->unk_80) != 0) {
        arg0->unk_10 = arg0->unk_1F0;
        arg0->unk_30 = arg0->unk_200;
        if (arg1->unk_C4->unk_54 == 4) {
            arg0->unk_60 |= 0x80000;
        }
        zero = 0.0f;
        if (tmp != zero || (arg0->unk_1D8 & 2)) {
            arg0->unk_60 |= 0x80000;
        }
        return 1;
    }
    return 0;
}
