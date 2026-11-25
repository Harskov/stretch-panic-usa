#include "common.h"

typedef struct Sub_0012FF90 {
    u8 unk_0[0x14];
    f32 unk_14;
} Sub_0012FF90;

typedef struct Obj_0012FF90 {
    u8 unk_0[8];
    Sub_0012FF90 *unk_8;
} Obj_0012FF90;

extern f32 func_0012E870();

typedef struct Elem_0012FB30 {
    u8 unk_0[0x40];
} Elem_0012FB30;

typedef struct Sub_0012FB30 {
    /* 0x00 */ s32 count;
    Elem_0012FB30 *unk_4;
} Sub_0012FB30;

typedef struct Obj_0012FB30 {
    u8 unk_0[0xC];
    Sub_0012FF90 *unk_C;
    Sub_0012FB30 *unk_10;
} Obj_0012FB30;

extern f32 func_0012E970();

typedef struct Sub_00130600 {
    /* 0x00 */ Sub_0012FF90 *unk_0;
    /* 0x04 */ Sub_0012FB30 *unk_4;
} Sub_00130600;

typedef struct Obj_00130600 {
    u8 unk_0[8];
    /* 0x08 */ Sub_00130600 *unk_8;
} Obj_00130600;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012F810);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012F9C0);

/* 1 when b passes the test against unk_C and every one of the unk_10 elements, 0 at the first that fails */
s32 func_0012FB30(Obj_0012FB30 *a, Vec *b)
{
    s32 i;

    if (!(func_0012E870(b, a->unk_C) <= a->unk_C->unk_14)) {
        return 0;
    }
    for (i = 0; i < a->unk_10->count; i++) {
        if (!(func_0012E970(b, &a->unk_10->unk_4[i]) <= 0.0f)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012FC00);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012FEB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012FF10);

s32 func_0012FF90(Obj_0012FF90 *a, Vec *b)
{
    return func_0012E870(b, a->unk_8) <= a->unk_8->unk_14;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012FFE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130150);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001301B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130230);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001302D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130520);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130580);

/* The func_0012FF90 bound test against unk_8->unk_0, then every 0x40-byte element
   of unk_8->unk_4 must give func_0012E970 a result at or below zero; probably a
   point-inside test against a bounding volume and its list of planes. */
s32 func_00130600(Obj_00130600 *a, Vec *b)
{
    s32 i;

    if (!(func_0012E870(b, a->unk_8->unk_0) <= a->unk_8->unk_0->unk_14))
        return 0;
    for (i = 0; i < a->unk_8->unk_4->count; i++) {
        if (!(func_0012E970(b, &a->unk_8->unk_4->unk_4[i]) <= 0.0f))
            return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001306D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130980);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001309E0);
