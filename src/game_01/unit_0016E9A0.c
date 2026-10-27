#include "common.h"
#include "game_01/scratchpad.h"

typedef struct Obj {
    unsigned char unk_00[0x10];
    /* 0x10 */ Vec unk_10;
} Obj;

typedef struct Obj_0016E9A0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u8 unk_1C[4];
    s32 unk_20;
    u8 unk_24[0x1C];
    s32 unk_40;
    u8 unk_44[0x1C];
    s32 unk_60;
} Obj_0016E9A0;

typedef struct Obj_0016E9A0_2 {
    u8 unk_00[0x60];
    Obj_0016E9A0 *unk_60;
} Obj_0016E9A0_2;

typedef struct Obj_0016F850 {
    u8 unk_00[0x10C];
    Obj_0016E9A0_2 *unk_10C;
} Obj_0016F850;

extern Vec D_006AEE40;

extern u8 D_006AEE58;

extern u8 D_006AEE60;

extern s32 *D_006A6D10;

extern s32 func_0013DF50(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

void func_0013E050();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016E9A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016EA40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016EB20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016ED20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016EFC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F170);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F360);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F480);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F670);

s32 func_0016F790(Obj *o, Vec *src, s32 *state)
{
    register Vec *a;
    register Vec *d;
    register Vec *b;
    u8 x;

    switch (*state) {
    case 0:
        a = &D_006AEE40;
        d = &o->unk_10;
        b = src;
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(b)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(d)
        }
        x = D_006AEE60;
        if (D_006AEE58 | x) {
            *state = *state + 1;
        }
        return 0;
    case 1:
        a = &D_006AEE40;
        d = &o->unk_10;
        b = src;
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(b)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(d)
        }
        if (D_006AEE60) {
            *state = *state + 1;
        }
        return 0;
    case 2:
        return 1;
    }
}

void func_0016F850(Obj_0016F850 *o)
{
    Obj_0016E9A0_2 *m;

    o->unk_10C->unk_60->unk_10 = 12566371.0f;
    o->unk_10C->unk_60->unk_14 = 1000.0f;
    o->unk_10C->unk_60->unk_18 = 1.0f;
    m = o->unk_10C;
    m->unk_60->unk_00 = func_0013DF50(m->unk_60->unk_00, *D_006A6D10, 0x13,
                                      m->unk_60->unk_04, m->unk_60->unk_0C, m->unk_60->unk_08);
}

void func_0016F8E0(Obj_0016F850 *o)
{
    func_0013E050(o->unk_10C->unk_60->unk_00);
    func_0013E050(o->unk_10C->unk_60->unk_20);
    func_0013E050(o->unk_10C->unk_60->unk_40);
    func_0013E050(o->unk_10C->unk_60->unk_60);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016E9A0", func_0016F940);

int func_0016F9F0(void) {
    return 0;
}

float func_0016FA00(void) {
    return 0.0f;
}

int func_0016FA10(void) {
    return 0;
}

Quad *func_0016FA20(void) {
    return SPR_QUAD;
}
