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

typedef struct Obj_0017C3C0 {
    u8 unk_0[0x10];
    u128 unk_10;
    u8 unk_20[0x100];
    u128 unk_120;
    u8 unk_130[0x3BC];
    f32 unk_4EC;
} Obj_0017C3C0;

typedef struct Obj_0017BEF0 {
    u8 unk_0[0x10];
    /* 0x010 */ Vec unk_10;
    u8 unk_20[0x430];
    /* 0x450 */ Vec unk_450;
    /* 0x460 */ Vec unk_460;
    u8 unk_470[0xB0];
    /* 0x520 */ u128 unk_520;
    /* 0x530 */ u128 unk_530;
    /* 0x540 */ u128 unk_540;
    /* 0x550 */ u128 unk_550;
    u8 unk_560[0x20];
    /* 0x580 */ Vec unk_580;
    /* 0x590 */ Vec unk_590;
    /* 0x5A0 */ Vec unk_5A0;
    /* 0x5B0 */ Vec unk_5B0;
} Obj_0017BEF0;

extern Quad D_00699240;

extern Quad D_00699250;

void func_0012CA60(Sub_0017BBA0 *, Vec *, Vec *);

typedef struct Obj_0017BC80 {
    u8 unk_0[0x30];
    /* 0x030 */ Vec unk_30;
    u8 unk_40[0xF4];
    /* 0x134 */ s32 unk_134;
    u8 unk_138[0x2C];
    /* 0x164 */ s32 unk_164;
    u8 unk_168[0x148];
    /* 0x2B0 */ s32 unk_2B0;
    u8 unk_2B4[0x3C];
    /* 0x2F0 */ s32 unk_2F0;
    u8 unk_2F4[0x26C];
    /* 0x560 */ Vec unk_560;
    /* 0x570 */ Vec unk_570;
} Obj_0017BC80;

void func_0017ABC0(Obj2F8 *arg0);

s32 func_0017C4A0(Obj_0017C4A0 *arg0);

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

/* Hands the object to func_0017ABC0 when func_0017C4A0 agrees and the word at +0x2B0 is not 9;
   when +0x134 is 3 and +0x164 is not, passes it to func_0017A3D0 and raises +0x34 by 0.15;
   then resets the two vectors at +0x560 and +0x570. */
void func_0017BC80(Obj_0017BC80 *arg0)
{
    if (func_0017C4A0((Obj_0017C4A0 *)arg0) != 0 && arg0->unk_2B0 != 9) {
        func_0017ABC0((Obj2F8 *)arg0);
    }
    if (arg0->unk_134 == 3 && arg0->unk_164 != 3) {
        func_0017A3D0((Obj2F8 *)arg0);
        arg0->unk_2F0 = 0;
        arg0->unk_30.y += 0.15f;
    }
    arg0->unk_570.x = 0.5f;
    arg0->unk_570.y = 0.0f;
    arg0->unk_570.z = 0.4f;
    arg0->unk_570.w = 1.0f;
    arg0->unk_560.x = -0.5f;
    arg0->unk_560.y = 0.0f;
    arg0->unk_560.z = 0.4f;
    arg0->unk_560.w = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BD40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00179E20", func_0017BE20);

void func_0017BEE0(Obj16C *arg0)
{
    arg0->unk_16C = 0;
    func_0017AFC0();
}

/* Per message number: copies the current list entry's quads into the object, or passes a
   vector through func_0012CA60 with the entry, storing the result or its xyz difference
   from the vector at +0x10. */
void func_0017BEF0(Obj_0017BEF0 *arg0, s32 arg1)
{
    Sub_0017BBA0 *entry;
    Quad in0;
    Vec out0;
    Quad in1;
    Vec out1;
    register Vec *dst;
    register Vec *base;
    register Vec *src;

    switch (arg1) {
    case 3:
        arg0->unk_520 = D_006A6730->cursor[D_006A6730->unk_378]->unk_30;
        entry = D_006A6730->cursor[D_006A6730->unk_378];
        arg0->unk_530 = entry->unk_0;
        arg0->unk_540 = entry->unk_10;
        arg0->unk_550 = entry->unk_20;
        break;
    case 9:
        func_0012CA60(D_006A6730->cursor[D_006A6730->unk_378], &arg0->unk_590, &arg0->unk_460);
        break;
    case 10:
        func_0012CA60(D_006A6730->cursor[D_006A6730->unk_378], &arg0->unk_580, &arg0->unk_450);
        break;
    case 12:
        in0 = D_00699240;
        func_0012CA60(D_006A6730->cursor[D_006A6730->unk_378], &in0.vec0, &out0);
        src = &out0;
        base = &arg0->unk_10;
        dst = &arg0->unk_5A0;
        asm {
            lqc2 vf1, 0(src)
            lqc2 vf2, 0(base)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(dst)
        }
        break;
    case 11:
        in1 = D_00699250;
        func_0012CA60(D_006A6730->cursor[D_006A6730->unk_378], &in1.vec0, &out1);
        src = &out1;
        base = &arg0->unk_10;
        dst = &arg0->unk_5B0;
        asm {
            lqc2 vf1, 0(src)
            lqc2 vf2, 0(base)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(dst)
        }
        break;
    }
}

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

s32 func_0017C3C0(Obj_0017C3C0 *arg0)
{
    Vec diff;
    register Vec *out;
    register u128 *to;
    register u128 *from;
    f32 radius;
    f32 radiusSq;

    from = &arg0->unk_10;
    to = &arg0->unk_120;
    out = &diff;
    asm {
        lqc2 vf1, 0(from)
        lqc2 vf2, 0(to)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
    radius = arg0->unk_4EC;
    radiusSq = radius * radius;
    if (func_0012E850(&diff) > radiusSq) {
        return 1;
    }
    return 0;
}

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
