#include "common.h"

typedef struct Sub_00123370 {
    /* 0x00 */ u32 pad_0 : 6;
    /* 0x00 */ u32 unk_0 : 1;
} Sub_00123370;

typedef struct Elem_00123370 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u64 *unk_4;
} Elem_00123370;

typedef struct Obj_00123370 {
    /* 0x00 */ Sub_00123370 *unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ Elem_00123370 *unk_8;
    /* 0x0C */ Elem_00123370 unk_C[2];
} Obj_00123370;

Sub_00123370 *sceDmaGetChan(s32 id);

void *func_001006F0(s32 size);

typedef struct Obj_00122870 {
    /* 0x00 */ u8 pad_0[0x25];
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ u8 unk_26;
} Obj_00122870;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_001227B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122800);

void func_00122870(Obj_00122870 *o)
{
    o->unk_25 = 0;
    o->unk_26 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122880);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_001228C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122AE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122C30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122CF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122DE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00122FE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00123080);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00123150);

/* Takes DMA channel 1, sets bit 6 of its control word, and allocates two 0x80000-byte buffers,
   each entry's second pointer starting at its first. */
Obj_00123370 *func_00123370(Obj_00123370 *o)
{
    o->unk_0 = sceDmaGetChan(1);
    o->unk_0->unk_0 = 1;
    o->unk_4 = 0;
    o->unk_8 = &o->unk_C[o->unk_4];
    o->unk_C[0].unk_0 = func_001006F0(0x80000);
    o->unk_C[1].unk_0 = func_001006F0(0x80000);
    o->unk_C[0].unk_4 = o->unk_C[0].unk_0;
    o->unk_C[1].unk_4 = o->unk_C[1].unk_0;
    return o;
}

/* Appends one quadword to the current buffer: a tag word built from the three arguments
   (bits 28-29 set) and a second word carrying arg2 in its upper half. */
void func_00123400(Obj_00123370 *o, s32 arg1, u32 arg2, u32 arg3)
{
    o->unk_8->unk_4[0] = ((u64)arg3 << 32) | ((u64)arg2 | ((s64)arg1 << 16) | 0x30000000);
    o->unk_8->unk_4[1] = ((u64)arg2 << 32) | 0x5100000011000000;
    o->unk_8->unk_4 += 2;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_00123480);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001227B0", func_001234E0);
