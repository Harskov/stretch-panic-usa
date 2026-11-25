#include "common.h"
#include "types.h"

extern s32 D_006A6730;

void func_00127BA0();

typedef struct Obj_0017DF40 {
    s32 *unk_0;
    u8 unk_4[0x12C];
    s32 unk_130;
} Obj_0017DF40;

extern s32 D_0069D450;

void func_00172DA0(Obj_0017DF40 *, s32, s32);

void func_0013BB20(s32 *, s32);

void func_0017DFC0(Obj_0017DF40 *, s32, f32);

extern s32 D_0069D4B0;

void func_00172E80();

void __dl__FPv(void *);

typedef struct Obj_006A6B88 {
    u8 pad_0[0x140];
    /* 0x140 */ Quad unk_140;
} Obj_006A6B88;

typedef struct Elem_0017DBF0 {
    u8 pad_0[0x4];
    /* 0x04 */ f32 counter_4;
    u8 pad_8[0xC];
    /* 0x14 */ f32 counter_14;
    u8 pad_18[0x8];
} Elem_0017DBF0;

typedef struct Obj_0017DBF0 {
    u8 pad_0[0x54];
    /* 0x0054 */ f32 unk_54;
    /* 0x0058 */ s32 counter;
    /* 0x005C */ s32 unk_5C;
    /* 0x0060 */ Elem_0017DBF0 unk_60[0x400];
    /* 0x8060 */ Quad unk_8060;
    u8 pad_8070[0xC];
    /* 0x807C */ f32 unk_807C;
} Obj_0017DBF0;

extern Obj_006A6B88 *D_006A6B88;

void func_0017DE30(Obj_0017DBF0 *, Elem_0017DBF0 *);

void func_0013E050(s32);

void func_00127930(s32, s32);

void func_001277C0(s32, s32);

typedef struct Obj_00178990 {
    u8 unk_0[0x70];
    /* 0x070 */ u64 unk_70;
    u8 unk_78[0x18];
    /* 0x090 */ u8 unk_90;
    u8 unk_91[0x2BF];
    /* 0x350 */ u32 unk_350;
    u8 unk_354[0xC];
    /* 0x360 */ u32 unk_360;
} Obj_00178990;

// stores a new word at +0x360: bits 12 and 13 are mirrored into bits 0 and 14 of the
// 64-bit word at +0x70 (the byte at +0x90 set before each), and the low four bits that
// changed are recorded, shifted up by four, in the word at +0x350
static inline void Obj_00178990_SetUnk360(Obj_00178990 *o, u32 v)
{
    o->unk_90 = 1;
    o->unk_70 = (u64)((v & 0x1000) >> 12) | (o->unk_70 & ~1);
    o->unk_90 = 1;
    o->unk_70 = (u64)(((v & 0x2000) >> 13) << 14) | (o->unk_70 & ~0x4000);
    o->unk_350 |= ((v ^ o->unk_360) & 0xF) << 4;
    o->unk_360 = v;
}

/* Moves all 0x400 entries down by 4.0 (the field depends on bit 0x1 of unk_58), then counts
   unk_58 down; once it runs out, unk_807C falls by 1/128 a call and at zero func_0013E050 is
   called and 0 returned. Probably a per-frame update; 1 means keep going. */
s32 func_0017DBF0(Obj_0017DBF0 *arg0)
{
    Elem_0017DBF0 *e;
    s32 i;
    f32 f;

    arg0->unk_8060 = D_006A6B88->unk_140;
    e = arg0->unk_60;
    if (!(arg0->counter & 1)) {
        for (i = 0; i != 0x400; i++) {
            if (e->counter_4 <= arg0->unk_54) {
                func_0017DE30(arg0, e);
            }
            e->counter_4 -= 4.0f;
            e++;
        }
    } else {
        for (i = 0; i != 0x400; i++) {
            e->counter_14 -= 4.0f;
            e++;
        }
    }

    arg0->counter--;
    if (arg0->counter <= 0) {
        f = arg0->unk_807C - 0.0078125f;
        arg0->unk_807C = f;
        if (f <= 0.0f) {
            func_0013E050(arg0->unk_5C);
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DD30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DE30);

Obj_0017DF40 *func_0017DF40(Obj_0017DF40 *arg0, s32 arg1, f32 arg2)
{
    // !FAKE: the reference keeps the object pointer in a stack slot and reloads it before every use; a volatile local forces that
    Obj_0017DF40 *volatile self = arg0;

    func_00172DA0(self, 0x5D, 0);
    self->unk_0 = &D_0069D450;
    func_0013BB20(&self->unk_130, 1);
    func_0017DFC0(self, arg1, arg2);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017DFC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E150);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E270);

// probably a mode switch on the global object: two calls with 0 and 5, bit 0x400 set,
// then bits 0x900 cleared, then the closing call
void func_0017E3A0(void)
{
    func_00127930(D_006A6730, 0);
    func_00127930(D_006A6730, 5);
    Obj_00178990_SetUnk360((Obj_00178990 *)D_006A6730, ((Obj_00178990 *)D_006A6730)->unk_360 | 0x400);
    Obj_00178990_SetUnk360((Obj_00178990 *)D_006A6730, ((Obj_00178990 *)D_006A6730)->unk_360 & ~0x900);
    func_001277C0(D_006A6730, 1);
}

void func_0017E4F0(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E640);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E6C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017E890);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EA30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EB50);

s32 **func_0017EC20(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D4B0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017EC80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017DBF0", func_0017ED50);
