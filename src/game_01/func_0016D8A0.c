#include "common.h"

typedef struct Quad {
    u128 q;
} Quad;

#define SPR_QUAD ((Quad *)0x70000BE0)

typedef struct Obj {
    u8 unk_00[0x10];
    Quad unk_10;
    u8 unk_20[0x10];
    Quad unk_30;
    u8 unk_40[0xE0];
    Quad unk_120;
    f32 unk_130;
} Obj;

extern f32 func_0012E850(Quad *arg0);

void func_0016D8A0(Obj *arg0)
{
    if (func_0012E850(&arg0->unk_10) >= arg0->unk_130) {
        arg0->unk_10 = arg0->unk_120;
        arg0->unk_30 = *SPR_QUAD;
    }
}
