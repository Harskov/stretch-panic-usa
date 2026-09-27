#include "common.h"

/* +0x230, +0x240 and +0x250 are copied whole from +0x190..+0x1B0 and then have their
   fourth lane set to 1.0, and +0x270 is cleared lane by lane and then copied whole to
   +0x280, so those four fields are reached at two widths: unions. */
typedef union Quad {
    u128 q;
    Vec v;
} Quad;

typedef struct Obj {
    u8 unk_00[0x190];
    u128 unk_190;
    u128 unk_1A0;
    u128 unk_1B0;
    u8 unk_1C0[0x70];
    Quad unk_230;
    Quad unk_240;
    Quad unk_250;
    u8 unk_260[0x10];
    Quad unk_270;
    u128 unk_280;
    u8 unk_290[0x64];
    u8 unk_2F4;
} Obj;

extern void func_0016D9F0(Obj *o);

void func_0016D830(Obj *o)
{
    func_0016D9F0(o);
    o->unk_2F4 = 0;
    o->unk_270.v.x = 0.0f;
    o->unk_270.v.y = 0.0f;
    o->unk_270.v.z = 0.0f;
    o->unk_270.v.w = 0.0f;
    o->unk_280 = o->unk_270.q;
    o->unk_230.q = o->unk_190;
    o->unk_240.q = o->unk_1A0;
    o->unk_250.q = o->unk_1B0;
    o->unk_230.v.w = 1.0f;
    o->unk_240.v.w = 1.0f;
    o->unk_250.v.w = 1.0f;
}
