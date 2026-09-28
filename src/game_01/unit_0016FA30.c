#include "common.h"

extern s32 D_00601A50;

void func_0016FA30(void) {
}

void func_0016FA40(void) {
}

s32 func_0016FA50(void)
{
    D_00601A50 = D_00601A50 * 5 + 1;
    return D_00601A50;
}

s32 func_0016FA80(s32 mask)
{
    D_00601A50 = D_00601A50 * 5 + 1;
    return (D_00601A50 >> 8) & mask;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_0016FAB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_0016FBE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_0016FCC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_0016FDE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_0016FE90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170100);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_001702A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170540);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_001705E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170AB0);
