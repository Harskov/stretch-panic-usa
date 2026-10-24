#include "common.h"

#include "game_01/obj50.h"

extern s32 D_00601BD0[];

extern s32 D_006B3580[];

/* List heads: func_0016C690 walks the 0x5F lists of D_006B3700 and func_0016C720 the
   list at D_006B3880, each through its own unit's object class; here they are only
   cleared, so the element type stays incomplete. */
typedef struct Node Node;

extern Node *D_006B3700[];

extern Node *D_006B3880;

extern s32 D_006B3888;

extern s32 D_006A6D18;

void func_0013BD20();

void func_0013BFB0();

typedef struct Obj_006A6730 {
    u8 unk_0[0x504];
    s32 unk_504;
} Obj_006A6730;

extern Obj_006A6730 *D_006A6730;

extern s32 D_006B3890;

extern s32 D_006B38A0;

void func_0012C9C0();

extern s32 D_0069CEA0;

void func_00172E80();

void __dl__FPv(void *);

extern s32 D_0069CED0;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00172CC0);

void func_00172D10(s32 arg0)
{
    func_0013BD20();
    func_0013BFB0(D_006A6D18, arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00172D50);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00172DA0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00172E80);

void func_00172F60(void)
{
    s32 i;

    for (i = 0; i < 0x5F; i++) {
        D_006B3700[i] = 0;
    }

    D_006B3880 = 0;
    D_006B3888 = 0;

    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x1C] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x38] = D_00601BD0[i];
    }
    for (i = 0; i != 0xB; i++) {
        D_006B3580[i + 0x54] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00173070);

/* 0x70000B80 and 0x70000BA0 are addresses in the EE's scratchpad RAM. */
void func_00173120(void)
{
    func_0012C9C0(D_006A6730->unk_504, 0x70000B80, &D_006B3890);
    func_0012C9C0(D_006A6730->unk_504, 0x70000BA0, &D_006B38A0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00173180);

s32 **func_00173360(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CEA0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_001733C0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;
    arg0->unk_7C = arg0->unk_7C * arg0->unk_80;
    t = arg0->unk_8C;
    arg0->unk_9C = arg0->unk_9C + t;

    p = &arg0->unk_50;
    v = &arg0->unk_60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00173440);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00173990);

s32 **func_00173BA0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CED0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_00173C00(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;

    p = &arg0->unk_50;
    v = &arg0->unk_60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->unk_A0;
    arg0->unk_9C = arg0->unk_9C + t;

    if (!(arg0->unk_A0 <= 0.0f) && !(arg0->unk_9C <= 1.0f)) {
        arg0->unk_9C = 1.0f;
        arg0->unk_A0 = 0.0f;
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172CC0", func_00173CC0);
