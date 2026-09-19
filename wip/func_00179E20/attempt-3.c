#include "common.h"

typedef struct Obj {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 unk_20[0x100];
    u128 unk_120;
    u8 unk_130[0x1B4];
    f32 unk_2E4;
    u8 unk_2E8[0x8];
    f32 unk_2F0;
} Obj;

extern void func_00179E80(Obj *);

void func_00179E20(Obj *o)
{
    if (0.0f != o->unk_2F0 && 0.7f < o->unk_2E4) {
        o->unk_120 = o->unk_10;
        func_00179E80(o);
    }
}
