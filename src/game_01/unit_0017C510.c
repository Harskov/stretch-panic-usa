#include "common.h"

typedef struct Obj_0017C7A0 {
    /* 0x000 */ s32 *unk_0;
    /* 0x004 */ u8 pad_4[0x168];
    /* 0x16C */ f32 unk_16C;
} Obj_0017C7A0;

extern s32 D_0069D320;

void func_0017B170();

void func_0017B7A0();

void __dl__FPv(void *);

extern s32 D_0069D390;

void func_00172E80();

extern s32 D_0069D3C0;

extern s32 D_0069D3F0;

extern s32 D_0069D420;

typedef struct Obj_00174DD0 {
    u8 unk_0[0x16A0];
    /* 0x16A0 */ Vec unk_16A0;
    /* 0x16B0 */ f32 unk_16B0;
    /* 0x16B4 */ f32 unk_16B4;
} Obj_00174DD0;

extern Obj_00174DD0 *D_006A6730;

void func_00125350();

typedef struct Elem_0017CAB0 {
    /* 0x00 */ Vec unk_0;
    /* 0x10 */ Vec unk_10;
    /* 0x20 */ u8 pad_20[0xC];
    /* 0x2C */ f32 unk_2C;
} Elem_0017CAB0;

typedef struct Obj_0017CAB0 {
    /* 0x0000 */ u8 pad_0[0x50];
    /* 0x0050 */ s32 unk_50;
    /* 0x0054 */ u8 pad_54[0xC];
    /* 0x0060 */ Elem_0017CAB0 unk_60[256];
    /* 0x3060 */ f32 unk_3060;
    /* 0x3064 */ s32 unk_3064;
    /* 0x3068 */ f32 unk_3068;
    /* 0x306C */ f32 unk_306C;
    /* 0x3070 */ f32 unk_3070;
    /* 0x3074 */ u8 pad_3074[0xC];
    /* 0x3080 */ f32 unk_3080;
    /* 0x3084 */ f32 unk_3084;
    /* 0x3088 */ f32 unk_3088;
    /* 0x308C */ u8 pad_308C[0x4];
    /* 0x3090 */ s32 unk_3090;
} Obj_0017CAB0;

void func_0012E9A0(Vec *arg0, void *arg1, Vec *arg2, f32 arg3);

void func_0012D5E0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C660);

Obj_0017C7A0 *func_0017C7A0(Obj_0017C7A0 *arg0)
{
    func_0017B170(arg0);
    arg0->unk_0 = &D_0069D320;
    arg0->unk_16C = 61.0f;
    return arg0;
}

s32 **func_0017C7E0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D320;
        func_0017B7A0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C840);

s32 **func_0017CA50(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D390;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

/* steps the first unk_50 elements: unk_10 through func_0012E9A0 with the scratchpad block at 0x70000BB0,
   scaled by the word at 0x3064 and added into unk_0; then unk_3068 decays by 0.96, and the result is 0
   once unk_306C, grown by unk_3070, no longer exceeds unk_3070 */
s32 func_0017CAB0(Obj_0017CAB0 *arg0) {
    s32 n;
    register Elem_0017CAB0 *e;
    Obj_0017CAB0 *p;
    register s32 k;
    register Vec *v;

    p = arg0;
    n = p->unk_50;
    e = p->unk_60;
    while (n--) {
        func_0012E9A0(&e->unk_10, (void *)0x70000BB0, &e->unk_10, p->unk_3060);
        v = &e->unk_10;
        k = p->unk_3064;
        asm {
            nop
            lqc2      vf1, 0(v)
            qmtc2.ni  k, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2      vf1, 0(v)
            lqc2      vf1, 0(e)
            lqc2      vf2, 0(v)
            vadd.xyz  vf1, vf1, vf2
            sqc2      vf1, 0(e)
        }
        e->unk_2C += p->unk_3070;
        e++;
    }
    func_0012D5E0(&p->unk_3090, p->unk_3068, p->unk_3080, p->unk_3084, p->unk_3088);
    p->unk_3068 *= 0.96f;
    p->unk_306C += p->unk_3070;
    if (p->unk_306C <= p->unk_3070)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CBC0);

/* two passes through func_00125350: the point arg1 + (arg2 + arg3) with the pair at +0x16B0 set (0, 1),
   then arg1 - (arg2 + arg3) with the pair set (1, 0) */
void func_0017CCE0(void *arg0, Vec *arg1, Vec *arg2, Vec *arg3) {
    Obj_00174DD0 *p;
    f32 z;
    f32 y;
    f32 x;

    p = D_006A6730;
    p->unk_16B0 = 0.0f;
    p->unk_16B4 = 1.0f;
    z = arg1->z + (arg2->z + arg3->z);
    y = arg1->y + (arg2->y + arg3->y);
    x = arg1->x + (arg2->x + arg3->x);
    p = D_006A6730;
    p->unk_16A0.x = x;
    p->unk_16A0.y = y;
    p->unk_16A0.z = z;
    p->unk_16A0.w = 1.0f;
    func_00125350(p);

    p = D_006A6730;
    p->unk_16B0 = 1.0f;
    p->unk_16B4 = 0.0f;
    z = arg1->z + (-arg2->z - arg3->z);
    y = arg1->y + (-arg2->y - arg3->y);
    x = arg1->x + (-arg2->x - arg3->x);
    p = D_006A6730;
    p->unk_16A0.x = x;
    p->unk_16A0.y = y;
    p->unk_16A0.z = z;
    p->unk_16A0.w = 1.0f;
    func_00125350(p);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CE00);

s32 **func_0017D040(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D3C0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D190);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D320);

s32 **func_0017D560(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D3F0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D6B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D950);

s32 **func_0017DB90(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D420;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
