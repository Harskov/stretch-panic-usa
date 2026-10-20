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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012F810);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012F9C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_0012FB30);

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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130600);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001306D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_00130980);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012F810", func_001309E0);
