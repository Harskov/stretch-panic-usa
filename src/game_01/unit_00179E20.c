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
    /* 0x16C */ s32 unk_16C;
} Obj16C;

void func_00179E80();

void func_0016E760(Obj2F8 *arg0);

void func_0017AFC0();

void func_0016E760(Obj2F8 *);

typedef struct Obj4E8 {
    u8 pad0[0x4E8];
    u8 unk_4E8;
} Obj4E8;

s32 func_0016CF10();

typedef struct Obj_0017C370 {
    u8 unk_0[0x260];
    u8 unk_260[0x28C];
    f32 unk_4EC;
} Obj_0017C370;

f32 func_0012E850();

void func_0012E9A0(void *, void *, void *, f32);

void func_0017A220(Obj2F8 *arg0);

typedef struct Obj_0017C4A0 {
    u8 unk_0[0x10];
    u128 unk_10;
    u8 unk_20[0x100];
    u128 unk_120;
    u8 unk_130[0x3C4];
    f32 unk_4F4;
} Obj_0017C4A0;

typedef struct Sub_0017BBA0 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Sub_0017BBA0;

typedef struct Obj_0017BBA0 {
    u8 unk_0[0xD0];
    /* 0x0D0 */ s32 unk_D0;
    /* 0x0D4 */ s32 unk_D4;
    u8 unk_D8[0x4];
    /* 0x0DC */ s32 unk_DC;
    u8 unk_E0[0xB0];
    /* 0x190 */ Sub_0017BBA0 unk_190;
} Obj_0017BBA0;

typedef struct Obj_006A6730 {
    u8 unk_0[0x350];
    /* 0x350 */ s32 unk_350;
    u8 unk_354[0x24];
    /* 0x378 */ s32 unk_378;
    u8 unk_37C[0x184];
    /* 0x500 */ Sub_0017BBA0 *cursor[8];
} Obj_006A6730;

extern Obj_006A6730 *D_006A6730;

void func_00132690();

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

void func_0017A220(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 3;
    arg0->unk_178 = 0;
    arg0->unk_180 = 0x3F400000;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    func_0016E760(arg0);
    arg0->unk_504 = 0;
}

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

void func_0017A5E0(Obj2F8 *arg0)
{
    func_0012E9A0(&arg0->unk_270, &arg0->unk_250, &arg0->unk_270, 0.015f);
    arg0->unk_2B8 = arg0->unk_2B8 + 1;
    if (arg0->unk_2B8 >= 0x3C) {
        func_0017A220(arg0);
    }
}

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

s32 func_0017B930(Obj4E8 *arg0)
{
    if (arg0->unk_4E8 == 0) {
        return 1;
    }
    return func_0016CF10();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017B960);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BA40);

/* Copies the object's five-quad block one slot past the current list entry, advances the
   entry over it for the call, then steps it back; both changes set the entry's bit at 0x100. */
void func_0017BBA0(Obj_0017BBA0 *arg0)
{
    Obj_006A6730 *obj = D_006A6730;

    obj->cursor[obj->unk_378][1] = arg0->unk_190;
    obj->cursor[obj->unk_378]++;
    obj->unk_350 |= 0x100 << obj->unk_378;
    func_00132690(arg0->unk_D0, D_006A6730, arg0->unk_DC, arg0->unk_D4, 0);
    obj = D_006A6730;
    obj->cursor[obj->unk_378]--;
    obj->unk_350 |= 0x100 << obj->unk_378;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BC80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BD40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BE20);

void func_0017BEE0(Obj16C *arg0)
{
    arg0->unk_16C = 0;
    func_0017AFC0();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BEF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C1B0);

s32 func_0017C370(Obj_0017C370 *arg0)
{
    f32 radius = arg0->unk_4EC;

    if (func_0012E850(arg0->unk_260) < radius * radius) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C3C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017C430);

s32 func_0017C4A0(Obj_0017C4A0 *arg0)
{
    Vec d;
    f32 f;
    f32 f2;
    register Vec *out;
    register u128 *b;
    register u128 *a;

    a = &arg0->unk_10;
    b = &arg0->unk_120;
    out = &d;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
    f = arg0->unk_4F4;
    f2 = f * f;
    if (func_0012E850(&d) > f2) {
        return 1;
    }
    return 0;
}
