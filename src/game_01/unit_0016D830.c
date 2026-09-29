#include "common.h"
#include "game_01/obj168.h"

/* +0x230, +0x240 and +0x250 are copied whole from +0x190..+0x1B0 and then have their
   fourth lane set to 1.0, and +0x270 is cleared lane by lane and then copied whole to
   +0x280, so those four fields are reached at two widths: unions. */
typedef struct Obj2F4 {
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
} Obj2F4;

#define SPR_QUAD ((Quad *)0x70000BE0)

typedef struct Obj130 {
    u8 unk_00[0x10];
    Quad unk_10;
    u8 unk_20[0x10];
    Quad unk_30;
    u8 unk_40[0xE0];
    Quad unk_120;
    f32 unk_130;
} Obj130;

extern void func_0016D9F0(Obj2F4 *o);

extern f32 func_0012E850(Quad *arg0);

s32 func_00172A80(s32 arg0);

void func_0016D830(Obj2F4 *o)
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

void func_0016D8A0(Obj130 *arg0)
{
    if (func_0012E850(&arg0->unk_10) >= arg0->unk_130) {
        arg0->unk_10 = arg0->unk_120;
        arg0->unk_30 = *SPR_QUAD;
    }
}

int func_0016D900(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016D910);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016D9F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DA20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DAA0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DB10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DBA0);

void func_0016DC30(Obj168 *arg0) {
    func_0016DC40(arg0, arg0->unk_134);
}

void func_0016DC40(Obj168 *arg0, s32 arg1) {
    arg0->unk_164 = arg1;
    arg0->unk_168 = func_00172A80(arg1);
    arg0->flags |= 0x04000000;
}

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

void func_0016DCD0(Obj168 *arg0, Obj168 *arg1) {
    arg0->unk_164 = arg1->unk_164;
    arg0->unk_168 = arg1->unk_168;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DCF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DD60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D830", func_0016DDD0);
