#include "common.h"

class Obj_001784A0 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Obj {
    unsigned char unk_00[0x50];
    Obj_001784A0 *field_50;
    unsigned char unk_54[0x495];
    unsigned char unk_4E9;
};

extern "C" s32 D_006A6730;

extern "C" void func_00127BA0(s32);

extern "C" s32 func_0016FA80(s32);

extern "C" void func_0017A640(Obj *p);

extern "C" s32 D_0069D1B0;

extern "C" void func_0017B7A0(s32 **, s32);

extern "C" void __dl__FPv(void *);

extern "C" s32 D_0069D220;

extern "C" void func_00172E80(s32 **, s32);

extern "C" s32 D_0069D180;

extern "C" void func_00172DA0(s32 **, s32, s32);

extern "C" void func_00178630(s32 **, s32, s32, f32);

typedef struct Obj50 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Obj50;

struct Sub_00178B30 {
    unsigned char unk_0[0x10];
    /* 0x10 */ Obj50 **unk_10;
};

struct Obj_00178B30 {
    /* 0x000 */ s32 *unk_0;
    unsigned char unk_4[0x350];
    /* 0x354 */ Sub_00178B30 *unk_354[11];
    unsigned char unk_380[0x16C];
    /* 0x4EC */ f32 unk_4EC;
    /* 0x4F0 */ f32 unk_4F0;
    /* 0x4F4 */ f32 unk_4F4;
    /* 0x4F8 */ f32 unk_4F8;
    /* 0x4FC */ f32 unk_4FC;
    /* 0x500 */ f32 unk_500;
    unsigned char unk_504[0xBC];
    /* 0x5C0 */ Obj50 unk_5C0;
    /* 0x610 */ Obj50 unk_610;
    /* 0x660 */ Obj50 unk_660;
    /* 0x6B0 */ Obj50 unk_6B0;
    /* 0x700 */ Obj50 *unk_700[16];
};

extern "C" Obj50 D_00698D60;

extern "C" Obj50 D_00698DB0;

extern "C" Obj50 D_00698E00;

extern "C" Obj50 D_00698E50;

extern "C" void func_0017B170(Obj_00178B30 *p, f32 arg1, f32 arg2, f32 arg3);

extern "C" Obj_00178B30 *func_00178B30(Obj_00178B30 *self, f32 arg1, f32 arg2, f32 arg3);

struct Obj_00178520 {
    /* 0x00 */ s32 *unk_0;
    unsigned char unk_4[0x4C];
    /* 0x50 */ Sub_00178B30 *unk_50;
    unsigned char unk_54[0x7C];
    /* 0xD0 */ Obj50 *unk_D0;
    unsigned char unk_D4[0xC];
    /* 0xE0 */ Obj50 unk_E0;
};

extern "C" void func_00127930(s32, s32);

extern "C" void func_001277C0(s32, s32);

struct Obj_00178990 {
    unsigned char unk_0[0x70];
    /* 0x070 */ u64 unk_70;
    unsigned char unk_78[0x18];
    /* 0x090 */ u8 unk_90;
    unsigned char unk_91[0x2BF];
    /* 0x350 */ u32 unk_350;
    unsigned char unk_354[0xC];
    /* 0x360 */ u32 unk_360;
};

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

extern "C" s32 **func_001784A0(s32 **volatile arg0, s32 arg1, s32 arg2, f32 arg3)
{
    // !FAKE: probably a C++ constructor whose `this` is kept in a stack slot and returned; the volatile parameter forces that spill in C
    func_00172DA0(arg0, 0x5C, 0);
    *arg0 = &D_0069D180;
    func_00178630(arg0, arg1, arg2, arg3);
    return arg0;
}

/* probably a constructor: the base part and its table, then a private copy of the
   block the object at +0x50 points through, which is redirected to that copy */
extern "C" Obj_00178520 *func_00178520(Obj_00178520 *volatile arg0, s32 arg1, s32 arg2, f32 arg3, u128 *arg4, u128 *arg5)
{
    Obj_00178520 *p;

    // !FAKE: probably a C++ constructor keeping `this` in a stack slot and returning it; the volatile parameter forces that spill, and the copy into p reads it once per statement as the constructor's `this` is reloaded
    func_00172DA0((s32 **)arg0, 0x5C, 0);
    arg0->unk_0 = &D_0069D180;
    func_00178630((s32 **)arg0, arg1, arg2, arg3);
    p = arg0;
    p->unk_E0 = **p->unk_50->unk_10;
    p = arg0;
    p->unk_D0 = &p->unk_E0;
    p = arg0;
    p->unk_50->unk_10 = &p->unk_D0;
    p = arg0;
    p->unk_E0.unk_0 = *arg4;
    p = arg0;
    p->unk_E0.unk_10 = *arg4;
    p = arg0;
    p->unk_E0.unk_30 = *arg5;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178630);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178770);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178810);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178880);

// probably a mode switch on the global object: two calls with 0 and 5, bit 0x400 set,
// then bits 0x900 cleared, then the closing call
extern "C" void func_00178990(void)
{
    func_00127930(D_006A6730, 0);
    func_00127930(D_006A6730, 5);
    Obj_00178990_SetUnk360((Obj_00178990 *)D_006A6730, ((Obj_00178990 *)D_006A6730)->unk_360 | 0x400);
    Obj_00178990_SetUnk360((Obj_00178990 *)D_006A6730, ((Obj_00178990 *)D_006A6730)->unk_360 & ~0x900);
    func_001277C0(D_006A6730, 1);
}

extern "C" void func_00178AE0(void)
{
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

extern "C" void func_00178B10(Obj *p)
{
    p->field_50->m2();
}

// probably a constructor: the base part first, then this class's vtable (the one the
// destructor func_00178DC0 restores), four 0x50-byte blocks copied from tables, and the
// table of block pointers each of the eleven sub-objects at +0x354 is linked to
Obj_00178B30 *func_00178B30(Obj_00178B30 *self, f32 arg1, f32 arg2, f32 arg3)
{
    func_0017B170(self, arg1, arg2, arg3);
    self->unk_0 = &D_0069D1B0;
    /* 10.240001f: the stored bits are 0x4123D70B, one step above 10.24f */
    self->unk_4F8 = 10.240001f;
    self->unk_4FC = 0.0005f;
    self->unk_500 = 0.001f;
    if (arg1 == 0.0f) {
        self->unk_4EC = 3.0f;
    }
    if (arg2 == 0.0f) {
        self->unk_4F0 = 4.0f;
    }
    if (arg3 == 0.0f) {
        self->unk_4F4 = 6.0f;
    }
    self->unk_5C0 = D_00698D60;
    self->unk_610 = D_00698DB0;
    self->unk_660 = D_00698E00;
    self->unk_6B0 = D_00698E50;
    self->unk_700[0] = &self->unk_5C0;
    self->unk_700[1] = &self->unk_5C0;
    self->unk_700[2] = &self->unk_610;
    self->unk_700[3] = &self->unk_610;
    self->unk_700[4] = &self->unk_610;
    self->unk_700[5] = &self->unk_660;
    self->unk_700[6] = &self->unk_610;
    self->unk_700[7] = &self->unk_6B0;
    self->unk_700[8] = &self->unk_610;
    self->unk_700[9] = &self->unk_610;
    self->unk_700[10] = &self->unk_610;
    self->unk_700[11] = &self->unk_5C0;
    self->unk_700[12] = &self->unk_610;
    self->unk_700[13] = &self->unk_5C0;
    self->unk_700[14] = &self->unk_660;
    self->unk_700[15] = &self->unk_660;
    self->unk_354[0]->unk_10 = &self->unk_700[0];
    self->unk_354[1]->unk_10 = &self->unk_700[1];
    self->unk_354[2]->unk_10 = &self->unk_700[5];
    self->unk_354[3]->unk_10 = &self->unk_700[14];
    self->unk_354[4]->unk_10 = &self->unk_700[15];
    self->unk_354[5]->unk_10 = &self->unk_700[8];
    self->unk_354[6]->unk_10 = &self->unk_700[9];
    self->unk_354[7]->unk_10 = &self->unk_700[10];
    self->unk_354[8]->unk_10 = &self->unk_700[12];
    self->unk_354[9]->unk_10 = &self->unk_700[3];
    self->unk_354[10]->unk_10 = &self->unk_700[4];
    return self;
}

extern "C" s32 **func_00178DC0(s32 **self, s16 flags)
{
    if (self != 0) {
        *self = &D_0069D1B0;
        func_0017B7A0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void func_00178E20(Obj *p)
{
    if (func_0016FA80(0xFF) == 0) {
        func_0017A640(p);
    }
    p->unk_4E9 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178E60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178EF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178FC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_001790E0);

extern "C" s32 **func_00179360(s32 **self, s16 flags)
{
    if (self != 0) {
        *self = &D_0069D220;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
