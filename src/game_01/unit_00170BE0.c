#include "common.h"

extern s32 D_0062FEA0;

extern s32 D_006A6730;

void func_00125D20();

extern s32 D_00601A80;

void func_00170BE0(void) {
    func_00125D20(D_006A6730, 0, &D_0062FEA0);
}

s32 *func_00170C00(s32 arg0) {
    s32 *p = &D_00601A80;
    return p + arg0 * 4;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00170C20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00170CD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00170E00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00170F30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171070);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_001710D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_001711B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171260);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171320);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171760);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171960);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171B90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00170BE0", func_00171DF0);
