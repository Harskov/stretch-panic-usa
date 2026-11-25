#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    /* 0xAC */ int unk_AC;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

typedef struct Obj_00167180 Obj_00167180;

struct Obj_00167180 {
    /* 0x00 */ s32 *unk_0;
    u8 unk_04[0x9C];
    /* 0xA0 */ Obj_00167180 *link_A0;
    /* 0xA4 */ Obj_00167180 *link_A4;
    /* 0xA8 */ Obj_00167180 *link_A8;
    /* 0xAC */ Obj_00167180 *link_AC;
};

extern s32 D_0069CCD0;

void func_00135450();

extern s32 D_0069CCA0;

void func_00172E80();

void __dl__FPv(void *);

typedef struct Sub_005C1370 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Sub_005C1370;

typedef struct Obj_006A6730 {
    u8 pad_0[0x350];
    /* 0x350 */ u32 unk_350;
    u8 pad_354[0x378 - 0x354];
    /* 0x378 */ s32 unk_378;
    u8 pad_37C[0x500 - 0x37C];
    /* 0x500 */ Sub_005C1370 *cursor[1];
    u8 pad_504[0x16C0 - 0x504];
    /* 0x16C0 */ Sub_005C1370 unk_16C0;
} Obj_006A6730;

extern Sub_005C1370 D_005C1370;

extern Obj_006A6730 *D_006A6730;

extern s32 D_005A5660;

void func_00125D20(Obj_006A6730 *, s32, s32 *);

void func_00167810(s32, s32, s32);

typedef struct Sub_001666F0 {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Sub_001666F0;

typedef struct Obj_001666F0 {
    u8 pad_0[0x50];
    /* 0x50 */ Sub_005C1370 unk_50;
    u8 pad_A0[0x4];
    /* 0xA4 */ f32 unk_A4;
    u8 pad_A8[0x8];
    /* 0xB0 */ f32 unk_B0;
    u8 pad_B4[0xC];
    /* 0xC0 */ f32 unk_C0;
    u8 pad_C4[0x2C];
    /* 0xF0 */ f32 unk_F0;
    u8 pad_F4[0x8];
    /* 0xFC */ f32 unk_FC;
    /* 0x100 */ Sub_001666F0 unk_100[32];
} Obj_001666F0;

void func_001668D0(Obj_001666F0 *o);

f32 func_001152E0(f32 x);

void func_0012D9E0(f32 a, Sub_005C1370 *m);

void func_001669A0(Obj_001666F0 *o);

/* Steps the 32 entries: each third value is func_001152E0 of minus the first squared,
   offset and scaled by the object; the first advances by the second times +0xB0 and
   wraps back to -2 once past 2. */
int func_001666F0(Obj_001666F0 *o)
{
    int i;

    func_001668D0(o);
    for (i = 0; i < 32; i++) {
        o->unk_100[i].z = o->unk_FC * (o->unk_F0 + func_001152E0(-1.0f * (o->unk_100[i].x * o->unk_100[i].x)));
        o->unk_100[i].x = o->unk_100[i].x + o->unk_100[i].y * o->unk_B0;
        if (o->unk_100[i].x > 2.0f) {
            o->unk_100[i].x = -2.0f;
        }
    }
    o->unk_A4 += o->unk_C0;
    return 1;
}

/* Probably a push/pop around func_001669A0: the object's 0x50-byte block is copied above
   the entry D_006A6730 indexes by +0x378, that entry advanced, passed with +0xA4 to
   func_0012D9E0, then stepped back; each change sets the index's bit (0x100 << i) in +0x350. */
void func_001667C0(Obj_001666F0 *o)
{
    Obj_006A6730 *g;

    g = D_006A6730;
    g->cursor[g->unk_378][1] = o->unk_50;
    g->cursor[g->unk_378]++;
    g->unk_350 |= 0x100 << g->unk_378;

    g = D_006A6730;
    func_0012D9E0(o->unk_A4, g->cursor[g->unk_378]);
    g->unk_350 |= 0x100 << g->unk_378;

    func_001669A0(o);

    g = D_006A6730;
    g->cursor[g->unk_378]--;
    g->unk_350 |= 0x100 << g->unk_378;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001668D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001669A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166C20);

s32 **func_00166D30(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CCA0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

int func_00166D90(Obj *o) {
    int old;

    o->unk_E0 += o->unk_A8;
    o->unk_E4 += o->unk_E8;
    if (o->unk_E4 < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    old = o->unk_EC;
    o->unk_EC = old + 1;
    return old < o->unk_AC;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166DE0);

Obj_00167180 *func_00167180(Obj_00167180 *arg0, s32 arg1, Obj_00167180 *arg2)
{
    func_00135450(arg0, arg1, arg2);
    arg0->unk_0 = &D_0069CCD0;
    arg0->link_A8 = arg2;
    if (arg0->link_A8 != 0) {
        arg0->link_A0 = arg0->link_A8->link_AC;
        arg0->link_A8->link_AC = arg0;
        if (arg0->link_A0 != 0) {
            arg0->link_A0->link_A4 = arg0;
        }
    } else {
        arg0->link_A0 = 0;
    }
    arg0->link_A4 = 0;
    arg0->link_AC = 0;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001672B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001673C0);

/* copies the five-quad block at D_005C1370 into the object, sets bit 0x4000 of its word at +0x350,
   then hands the object to func_00125D20 before passing the arguments on to func_00167810 */
void func_00167760(s32 arg0, s32 arg1, s32 arg2)
{
    Obj_006A6730 *obj;

    obj = D_006A6730;
    obj->unk_16C0 = D_005C1370;
    obj->unk_350 |= 0x4000;
    func_00125D20(D_006A6730, 0, &D_005A5660);
    func_00167810(arg0, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167810);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167BB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167E20);
