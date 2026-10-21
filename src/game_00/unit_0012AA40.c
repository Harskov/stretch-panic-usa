#include "common.h"
#include "game_00/obj90.h"

extern s32 D_0069C300;

void __dl__FPv(void *);

typedef struct Obj_0012B1F0 {
    u8 unk_00[0xB0];
    s32 *unk_B0;
    s32 unk_B4;
    u8 unk_B8[0x1C];
    s32 unk_D4;
    s32 unk_D8;
} Obj_0012B1F0;

void func_0012B6D0();

extern s32 D_0069C270;

typedef struct Src_0012AF20 {
    s32 unk_0;
    u32 unk_4;
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Src_0012AF20;

typedef struct Obj_0012AF20 {
    s32 *unk_0;
    s32 unk_4;
    u32 unk_8;
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
} Obj_0012AF20;

s32 func_001006F0(s32 size);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012AA40);

s32 **func_0012AE80(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C300;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012AED0);

Obj_0012AF20 *func_0012AF20(Obj_0012AF20 *o, Src_0012AF20 *src)
{
    o->unk_0 = &D_0069C270;
    o->unk_4 = src->unk_0;
    o->unk_8 = src->unk_4;
    o->unk_C = src->unk_8;
    o->unk_10 = src->unk_C;
    o->unk_14 = src->unk_10;
    o->unk_18 = src->unk_14;
    o->unk_1C = src->unk_18;
    o->unk_20 = func_001006F0((s32)((u64)o->unk_8 * 4));
    o->unk_24 = 0;
    o->unk_25 = 0;
    o->unk_26 = 0;
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012AFB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B0F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B160);

void func_0012B1F0(Obj_0012B1F0 *o)
{
    s32 i;

    o->unk_D4 = o->unk_D8;
    for (i = o->unk_B4; i > 0; i--) {
        func_0012B6D0(o, o->unk_B0[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B260);

/* Copies the object's word at 0xE4 out through arg1. */
void func_0012B2D0(Obj90 *o, s32 *arg1)
{
    *arg1 = o->unk_E4;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B2E0);

void func_0012B490(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B4A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B5E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B6D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B800);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012AA40", func_0012B930);

void *func_0012BA70(Obj90 *o) {
    return &o->unk_90;
}
