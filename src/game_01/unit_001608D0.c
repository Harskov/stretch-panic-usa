#include "common.h"
#include "game_01/obj80.h"

typedef struct Src {
    unsigned char unk_00[0x1B0];
    u128 v1B0;
    unsigned char unk_1C0[0x50];
    u128 v210;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u32 v20;
} Dst;

typedef struct Dst_00162900 {
    u8 unk_00[0x28C];
    u8 unk_28C;
    u8 unk_28D[0x83];
    Quad3 unk_310;
} Dst_00162900;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001608D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00160940);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001609D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00160CE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00160D40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161160);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161250);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001615D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001617A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001617F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161840);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001619E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161A90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00161CF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00162350);

void func_00162790(Src *a0, Dst *a1) {
    a1->v0 = a0->v210;
    a1->v10 = a0->v1B0;
    a1->v20 = 0x3E440000;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_001627B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001608D0", func_00162870);

void func_00162900(Dst_00162900 *d, Obj80 *s)
{
    d->unk_28C = 1;
    d->unk_310 = s->unk_80;
}
