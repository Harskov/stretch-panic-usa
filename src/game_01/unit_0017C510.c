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

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CAB0);

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
