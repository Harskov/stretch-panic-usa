#include "common.h"
#include "globals.h"
#include "game_00/obj_006A6730.h"

void *__nw__FUi(u32 size);

void *func_001006F0(s32 size);

s32 sprintf(char *s, const char *fmt, ...);

typedef struct Obj_001238B0 {
    u8 unk_0[4];
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
} Obj_001238B0;

typedef struct Obj_00123850 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x1C];
    /* 0x20 */ void *unk_20;
} Obj_00123850;

void __dl__FPv(void *p);

void __dla__FPv(void *p);

void func_00125530();

void FlushCache(s32 operation);

void sceDmaSend(void *d, void *tag);

void func_00123590();

void func_001247B0();

/* Sends the current buffer when it holds anything: clears the ID bits (28-30) of the last
   tag written, flushes the data cache, and starts the transfer on the object's channel. */
void func_00123520(Obj_006A6730 *o)
{
    if (o->unk_8->unk_4 != o->unk_8->unk_0) {
        o->unk_8->unk_4[-2] &= ~0x70000000;
        FlushCache(0);
        sceDmaSend(o->unk_0, o->unk_8->unk_0);
    }
}

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
    o->next = D_006A6738;
    sprintf(o->unk_8, gFormat_69B3D8, arg2);
    D_006A6738 = o;
}

void func_00124010(char *arg0, f32 arg1, f32 arg2)
{
    Obj_00123F70 *o = __nw__FUi(0x14);

    o->unk_0 = arg1;
    o->unk_4 = arg2;
    o->unk_8 = arg0;
    o->unk_C = 0;
    o->next = D_006A6738;
    D_006A6738 = o;
}

/* Flips between two frame buffers: 0x12000070 and 0x12000090 are the GS's DISPFB1 and
   DISPFB2 registers, whose low nine bits (FBP) give the displayed buffer's base. */
void func_00124080(Obj_006A6730 *arg0)
{
    arg0->unk_364 = (u8)((arg0->unk_364 != 0) ^ 1);
    D_0019F4A0 = arg0->unk_368[arg0->unk_364] | (D_0019F4A0 & ~0x1FF);
    D_0019F4A8 = arg0->unk_368[arg0->unk_364] | (D_0019F4A8 & ~0x1FF);
    *(volatile u64 *)0x12000070 = D_0019F4A0;
    *(volatile u64 *)0x12000090 = D_0019F4A8;
}

/* Swaps to the other of the two halves at 0xC, then copies the current buffer base
   into the low nine bits of the word at 0x30, probably a DISPFB value as in
   func_00124080. */
void func_00124110(Obj_006A6730 *o)
{
    u64 v;

    func_00123520(o);
    o->unk_4 = (u8)!o->unk_4;
    o->unk_8 = &o->unk_C[o->unk_4];
    func_00123590(o);
    v = o->unk_368[o->unk_364];
    o->unk_90 = 1;
    o->unk_30 = v | (o->unk_30 & ~0x1FF);
    func_001247B0(o, v);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001241A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001242D0);

void func_00124360(Obj_006A6730 *arg0, f32 arg1, f32 arg2)
{
    f32 v = -0.5f * (arg2 + arg1);

    arg0->unk_388 = v;
    arg0->unk_398 = -v;
    arg0->unk_350 |= 0x1000;
}

void func_00124390(Obj_006A6730 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    arg0->unk_380 = 0.5f * arg3;
    arg0->unk_384 = -0.5f * arg4;
    arg0->unk_390 = arg1;
    arg0->unk_394 = arg2;
    arg0->unk_350 |= 0x1000;
}

void func_001243D0(Obj_006A6730 *arg0)
{
    arg0->cursor[0][1] = arg0->cursor[0][0];
    arg0->cursor[1][1] = arg0->cursor[1][0];
    arg0->cursor[2][1] = arg0->cursor[2][0];
    arg0->cursor[3][1] = arg0->cursor[3][0];
    arg0->cursor[0] += 1;
    arg0->cursor[1] += 1;
    arg0->cursor[2] += 1;
    arg0->cursor[3] += 1;
}

void func_001244C0(Obj_006A6730 *arg0)
{
    arg0->cursor[0] -= 1;
    arg0->cursor[1] -= 1;
    arg0->cursor[2] -= 1;
    arg0->cursor[3] -= 1;
    arg0->unk_350 |= 0xF00;
}

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

void func_00125260(Obj_006A6730 *arg0)
{
    switch (arg0->flags & 7) {
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
