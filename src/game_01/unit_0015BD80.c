#include "common.h"

extern s32 D_0069CA70;

extern s32 D_006AF4C0;

void func_001319D0();

void func_0015D4E0();

void __dl__FPv(void *);

extern s32 D_005D99A0;

extern s32 D_005D99BC;

extern s32 D_0069C510;

void func_0012AF20();

void *__nw__FUi(u32);

typedef struct Obj3B0 {
    /* 0x000 */ s32 *unk_0;
    /* 0x004 */ u8 unk_4[0x24];
    /* 0x028 */ u8 *unk_28;
    /* 0x02C */ u8 unk_2C[0x4];
    /* 0x030 */ u8 unk_30[0x380];
} Obj3B0;

typedef struct Obj_0015BD80 {
    /* 0x00 */ u8 unk_0[0x90];
    /* 0x90 */ Obj3B0 *unk_90;
    /* 0x94 */ Obj3B0 *unk_94;
} Obj_0015BD80;

void func_001664F0();

typedef struct Sub_0015D100 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Sub_0015D100;

typedef struct Obj_0015D100 {
    /* 0x000 */ u8 unk_0[0x90];
    /* 0x090 */ Sub_0015D100 unk_90;
    /* 0x0E0 */ u8 unk_E0[0x30];
    /* 0x110 */ f32 unk_110;
} Obj_0015D100;

typedef struct Obj90 {
    /* 0x00 */ Sub_0015D100 unk_0;
    /* 0x50 */ f32 unk_50;
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ u8 unk_64[0xC];
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ f32 unk_7C;
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ f32 unk_8C;
} Obj90;

// registers: obj = the block operator new returns, then the object being built in it (obj)
/* builds the two 0x3B0-byte objects the owner keeps at +0x90 and +0x94: operator new,
   then the base constructor with its table, the vtable, and the pointer to the object's own buffer */
void func_0015BD80(Obj_0015BD80 *arg0)
{
    Obj3B0 *obj;

    if ((obj = __nw__FUi(sizeof(Obj3B0))) != 0) {
        func_0012AF20(obj, &D_005D99A0);
        obj->unk_0 = &D_0069C510;
        obj->unk_28 = obj->unk_30;
    }
    arg0->unk_90 = obj;

    if ((obj = __nw__FUi(sizeof(Obj3B0))) != 0) {
        func_0012AF20(obj, &D_005D99BC);
        obj->unk_0 = &D_0069C510;
        obj->unk_28 = obj->unk_30;
    }
    arg0->unk_94 = obj;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015BE20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015BE80);

/* destructor-shaped: restores the vtable, runs the base teardown, and deletes the object when the flag is positive */
s32 **func_0015C130(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069CA70;
        func_0015D4E0();
        D_006AF4C0 = 0;
        func_001319D0(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C1A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C300);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C480);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C8F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015CB40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015CD50);

/* builds two 0x280-byte objects from one parameter block: the five quads at +0x90 of
   the owner and its float at +0x110, with the second object's settings changed */
void func_0015D100(Obj_0015D100 *arg0)
{
    Obj90 params;
    void *p;

    params.unk_50 = 1.0f;
    params.unk_54 = 1.5f;
    params.unk_58 = 1.5f;
    params.unk_5C = 0.5f;
    params.unk_60 = 0.0f;

    params.unk_0 = arg0->unk_90;
    params.unk_54 = 2.0f;
    params.unk_58 = arg0->unk_110;
    params.unk_5C = 0.5f;
    params.unk_60 = 0.00390625f;
    params.unk_70 = 1.0f;
    params.unk_74 = 1.0f;
    params.unk_78 = 1.0f;
    params.unk_7C = 0.8f;
    params.unk_80 = 0.0f;
    params.unk_84 = 1.0f;
    params.unk_88 = 0.0f;
    params.unk_8C = 0.0f;
    if ((p = __nw__FUi(0x280)) != 0) {
        func_001664F0(p, &params);
    }

    params.unk_50 = 3.0f;
    params.unk_54 = 1.0f;
    params.unk_5C = 1.5f;
    params.unk_60 = -0.0078125f;
    params.unk_70 = 1.0f;
    params.unk_74 = 1.0f;
    params.unk_78 = 1.0f;
    params.unk_7C = 0.9f;
    params.unk_80 = 1.0f;
    params.unk_84 = 0.5f;
    params.unk_88 = 0.0f;
    params.unk_8C = 0.0f;
    if ((p = __nw__FUi(0x280)) != 0) {
        func_001664F0(p, &params);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015D2B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015D490);
