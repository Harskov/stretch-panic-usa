#include "common.h"

typedef struct Obj0013BD20 {
    u8 pad0[0x10];
    /* 0x10 */ Vec unk_10;
    /* 0x20 */ Vec unk_20;
    /* 0x30 */ Vec unk_30[3];
} Obj0013BD20;

extern s32 D_006A6D00;

void *__nw__FUi(u32 size);

void func_00138F80(void *obj, s32 a, s32 b, f32 x, f32 y);

typedef struct Obj_0013BC80 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x5C];
    /* 0x60 */ void *unk_60;
    u8 pad_64[0x4];
    /* 0x68 */ struct Obj_0013BC80 *link_68;
    /* 0x6C */ struct Obj_0013BC80 *link_6C;
} Obj_0013BC80;

extern s32 D_0069C718;

extern s32 D_006A6D08;

void __dla__FPv(void *p);

void __dl__FPv(void *p);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B1F0);

void *func_0013B220(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x50)) != 0) {
        func_00138F80(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x120, 240.0f, -136.0f);
    }
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B280);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B2B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B320);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B720);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B7A0);

void func_0013BAE0(void) {
}

void func_0013BAF0(void) {
}

int func_0013BB00(void) {
    return 0;
}

void func_0013BB10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013BB20);

/* Probably a destructor in the compiler's shape: the word at +0x0 is reset, the array at
   +0x60 freed with delete[], the object unlinked from a two-way list whose head is
   D_006A6D08, and the storage freed when the flag argument is positive. */
Obj_0013BC80 *func_0013BC80(Obj_0013BC80 *o, s16 arg1)
{
    if (o != 0) {
        o->unk_0 = &D_0069C718;
        __dla__FPv(o->unk_60);
        if (o->link_6C != 0)
            o->link_6C->link_68 = o->link_68;
        if (o->link_68 != 0)
            o->link_68->link_6C = o->link_6C;
        else
            D_006A6D08 = (s32)o->link_6C;
        if (arg1 > 0)
            __dl__FPv(o);
    }
    return o;
}

void func_0013BD20(Obj0013BD20 *o, register Vec *m)
{
    register Vec *p;

    p = &o->unk_10;
    asm {
        lqc2 vf1, 0x30(m)
        lqc2 vf2, 0(p)
        vsub.xyz vf2, vf1, vf2
        lqc2 vf3, 0(m)
        lqc2 vf4, 0x10(m)
        lqc2 vf5, 0x20(m)
        sqc2 vf1, 0(p)
        sqc2 vf2, 0x10(p)
        sqc2 vf3, 0x20(p)
        sqc2 vf4, 0x30(p)
        sqc2 vf5, 0x40(p)
    }
}
