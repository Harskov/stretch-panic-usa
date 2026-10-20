#include "common.h"

typedef struct Obj_00123F70 {
    /* 0x00 */ f32 unk_0;
    /* 0x04 */ f32 unk_4;
    /* 0x08 */ char *unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ struct Obj_00123F70 *unk_10;
} Obj_00123F70;

void *__nw__FUi(u32 size);

void *func_001006F0(s32 size);

s32 sprintf(char *s, const char *fmt, ...);

extern char D_0069B3D8[];

extern Obj_00123F70 *D_006A6738;

typedef struct Obj_001238B0 {
    u8 unk_0[4];
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
} Obj_001238B0;

typedef struct Obj_00124360 {
    u8 pad_0[0x350];
    /* 0x350 */ s32 unk_350;
    u8 pad_354[0x34];
    /* 0x388 */ f32 unk_388;
    u8 pad_38C[0xC];
    /* 0x398 */ f32 unk_398;
} Obj_00124360;

typedef struct Obj_00123850 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x1C];
    /* 0x20 */ void *unk_20;
} Obj_00123850;

extern s32 D_0069C270;

void __dl__FPv(void *p);

void __dla__FPv(void *p);

typedef struct Obj_00124080 {
    u8 pad_0[0x364];
    /* 0x364 */ s32 unk_364;
    /* 0x368 */ u64 unk_368[2];
} Obj_00124080;

extern volatile u64 D_0019F4A0;

extern volatile u64 D_0019F4A8;

typedef struct Blk_001243D0 {
    /* 0x00 */ u128 unk_0;
    /* 0x10 */ u128 unk_10;
    /* 0x20 */ u128 unk_20;
    /* 0x30 */ u128 unk_30;
    /* 0x40 */ u128 unk_40;
} Blk_001243D0;

typedef struct Obj_001243D0 {
    u8 pad_0[0x500];
    /* 0x500 */ Blk_001243D0 *unk_500;
    /* 0x504 */ Blk_001243D0 *unk_504;
    /* 0x508 */ Blk_001243D0 *unk_508;
    /* 0x50C */ Blk_001243D0 *unk_50C;
} Obj_001243D0;

typedef struct Obj_00125260 {
    u8 pad_0[0x35C];
    /* 0x35C */ u32 unk_35C;
    u8 pad_360[0x1D00];
    /* 0x2060 */ u32 unk_2060;
    u8 pad_2064[0xC];
    /* 0x2070 */ u8 unk_2070;
} Obj_00125260;

void func_00125530();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123520);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123620);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123700);

Obj_00123850 *func_00123850(Obj_00123850 *arg0, s16 arg1)
{
    if (arg0 != 0) {
        arg0->unk_0 = &D_0069C270;
        __dla__FPv(arg0->unk_20);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

s32 func_001238B0(Obj_001238B0 *o)
{
    return o->unk_4 != o->unk_8;
}

/* Empties the list func_00123F70 pushes nodes on; the nodes are not freed here. */
void func_001238D0(void)
{
    D_006A6738 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001238E0);

/* Stores the four float arguments into the vector arg0 points to. */
void func_00123F50(Vec *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    arg0->x = arg1;
    arg0->y = arg2;
    arg0->z = arg3;
    arg0->w = arg4;
}

/* Allocates a node, formats arg2 into a fresh 16-byte buffer and pushes the
   node on the D_006A6738 list. */
void func_00123F70(f32 arg0, f32 arg1, f32 arg2)
{
    Obj_00123F70 *o = __nw__FUi(0x14);

    o->unk_0 = arg0;
    o->unk_4 = arg1;
    o->unk_8 = func_001006F0(0x10);
    o->unk_C = 1;
    o->unk_10 = D_006A6738;
    sprintf(o->unk_8, D_0069B3D8, arg2);
    D_006A6738 = o;
}

void func_00124010(char *arg0, f32 arg1, f32 arg2)
{
    Obj_00123F70 *o = __nw__FUi(0x14);

    o->unk_0 = arg1;
    o->unk_4 = arg2;
    o->unk_8 = arg0;
    o->unk_C = 0;
    o->unk_10 = D_006A6738;
    D_006A6738 = o;
}

/* Flips between two frame buffers: 0x12000070 and 0x12000090 are the GS's DISPFB1 and
   DISPFB2 registers, whose low nine bits (FBP) give the displayed buffer's base. */
void func_00124080(Obj_00124080 *arg0)
{
    arg0->unk_364 = (u8)((arg0->unk_364 != 0) ^ 1);
    D_0019F4A0 = arg0->unk_368[arg0->unk_364] | (D_0019F4A0 & ~0x1FF);
    D_0019F4A8 = arg0->unk_368[arg0->unk_364] | (D_0019F4A8 & ~0x1FF);
    *(volatile u64 *)0x12000070 = D_0019F4A0;
    *(volatile u64 *)0x12000090 = D_0019F4A8;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124110);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001241A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001242D0);

void func_00124360(Obj_00124360 *arg0, f32 arg1, f32 arg2)
{
    f32 v = -0.5f * (arg2 + arg1);

    arg0->unk_388 = v;
    arg0->unk_398 = -v;
    arg0->unk_350 |= 0x1000;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124390);

void func_001243D0(Obj_001243D0 *arg0)
{
    arg0->unk_500[1] = arg0->unk_500[0];
    arg0->unk_504[1] = arg0->unk_504[0];
    arg0->unk_508[1] = arg0->unk_508[0];
    arg0->unk_50C[1] = arg0->unk_50C[0];
    arg0->unk_500 += 1;
    arg0->unk_504 += 1;
    arg0->unk_508 += 1;
    arg0->unk_50C += 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001244C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124500);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001247B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001249B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124A50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124AE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124BC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124CD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124E10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124EC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001250F0);

void func_00125260(Obj_00125260 *arg0)
{
    switch (arg0->unk_35C & 7) {
    case 0:
        if (arg0->unk_2060 == 0) {
            return;
        }
        break;
    case 1:
        arg0->unk_2060 = arg0->unk_2060 & ~1;
    case 2:
        if (arg0->unk_2060 < 2) {
            return;
        }
        break;
    case 3:
        arg0->unk_2060 = arg0->unk_2060 - arg0->unk_2060 % 3;
    case 4:
    case 5:
        if (arg0->unk_2060 < 3) {
            return;
        }
        break;
    case 6:
        arg0->unk_2060 = arg0->unk_2060 & ~1;
        if (arg0->unk_2060 < 2) {
            return;
        }
        break;
    }
    func_00125530(arg0, arg0->unk_2060, &arg0->unk_2070);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00125350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00125530);
