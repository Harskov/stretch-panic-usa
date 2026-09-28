#include "common.h"
#include "game_01/obj2F8.h"

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

typedef struct Obj16C {
    u8 pad0[0x16C];
    s32 i16C;
} Obj16C;

void func_00179E80();

void func_0016E760(Obj2F8 *arg0);

void func_0017AFC0();

void func_00179E20(Obj *o)
{
    f32 zero;

    zero = 0.0f;
    if (o->unk_2F0 != zero && o->unk_2E4 > 0.7f) {
        o->unk_120 = o->unk_10;
        func_00179E80(o);
    }
}

void func_00179E80(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 1;
    arg0->unk_178 = 0;
    arg0->unk_180 = 0x3F000000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    arg0->unk_64 = 0;
    arg0->unk_68 = 0;
    arg0->unk_4E9 = 0;
    arg0->unk_510 = arg0->unk_10;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_00179EC0);

void func_00179F40(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 2;
    arg0->unk_178 = 0;
    arg0->unk_180 = 0x3F400000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
    arg0->unk_504 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_00179F90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A220);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A270);

void func_0017A3D0(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 4;
    arg0->unk_178 = 8;
    arg0->unk_180 = 0x3F800000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A400);

void func_0017A5B0(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 5;
    arg0->unk_178 = 0;
    arg0->unk_180 = 0x40000000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A5E0);

void func_0017A640(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 6;
    arg0->unk_178 = 7;
    arg0->unk_180 = 0x3F800000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A670);

void func_0017A950(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 7;
    arg0->unk_178 = 5;
    arg0->unk_180 = 0x3F800000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017A980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017ABC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017AC80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017AFC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B050);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B170);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B530);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B7A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B930);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B960);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BA40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BBA0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BC80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BD40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BE20);

void func_0017BEE0(Obj16C *arg0)
{
    arg0->i16C = 0;
    func_0017AFC0();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BEF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C1B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C370);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C3C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C430);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C4A0);
