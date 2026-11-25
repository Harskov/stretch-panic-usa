#include "common.h"

extern s32 D_00601A50;

extern s32 D_006AF500;

extern s32 D_006B1540;

void func_001705E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, f32 arg5);

void func_00170100(s32 arg0, s32 *arg1, s32 *arg2, f32 arg3, f32 arg4);

void func_00170790(s32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 *arg4);

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

void func_00170540(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7)
{
    func_001705E0(arg0, arg1, arg2, arg3, &D_006AF500, arg5);
    func_00170100(arg1 - 2, &D_006AF500, &D_006B1540, arg5, arg5);
    func_00170790(arg1, arg6, arg7, arg4, &D_006B1540);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_001705E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016FA30", func_00170AB0);
