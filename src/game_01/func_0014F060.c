#include "common.h"

typedef struct Obj {
    u8 pad0[0x30];
    u128 unk_30;
    u8 pad40[0x14C - 0x40];
    s32 unk_14C;
    s32 unk_150;
    u8 pad154[0x2B0 - 0x154];
    u128 unk_2B0;
    u8 pad2C0[0x378 - 0x2C0];
    s32 unk_378;
    u8 pad37C[0x3A0 - 0x37C];
    u128 unk_3A0;
    u128 unk_3B0;
    u8 pad3C0[0x3C4 - 0x3C0];
    s32 unk_3C4;
    u8 pad3C8[0x3D0 - 0x3C8];
    s32 unk_3D0;
    u8 pad3D4[0x400 - 0x3D4];
    Vec unk_400;
} Obj;

void func_0014F060(Obj *arg0, Vec *arg1) {
    arg0->unk_3A0 = arg0->unk_2B0;
    arg0->unk_3B0 = arg0->unk_30;
    if (arg0->unk_378 & 2) {
        arg0->unk_3C4 = arg0->unk_150;
        arg0->unk_3D0 = 2;
    } else {
        arg0->unk_3C4 = arg0->unk_14C;
        arg0->unk_3D0 = 0;
    }
    *arg1 = arg0->unk_400;
}
