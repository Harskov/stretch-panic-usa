#include "common.h"

void func_0012C810(register Vec *src, register Vec *dst)
{
    asm {
        lqc2 vf1, 0(src)
        lqc2 vf2, 0x10(src)
        lqc2 vf3, 0x20(src)
        lqc2 vf4, 0x30(src)
        sqc2 vf1, 0(dst)
        sqc2 vf2, 0x10(dst)
        sqc2 vf3, 0x20(dst)
        sqc2 vf4, 0x30(dst)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C840);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C8C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C8F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C950);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012C9C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CA30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CA60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CA90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012CB10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D430);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D450);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D4E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D560);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D5E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012D9E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DAC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DBA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DD20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DDB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012C810", func_0012DE80);
