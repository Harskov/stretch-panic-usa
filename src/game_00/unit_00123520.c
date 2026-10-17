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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123520);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123620);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123700);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123850);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001238B0);

/* Empties the list func_00123F70 pushes nodes on; the nodes are not freed here. */
void func_001238D0(void)
{
    D_006A6738 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001238E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00123F50);

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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124010);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124080);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124110);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001241A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001242D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124360);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00124390);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_001243D0);

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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00125260);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00125350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00123520", func_00125530);
