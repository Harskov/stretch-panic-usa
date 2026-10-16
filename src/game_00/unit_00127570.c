#include "common.h"

extern void __dl__FPv(void *p);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127570);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127650);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_001276F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127750);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_001277C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127810);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127840);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_001278A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127930);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127BA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127FD0);

/* Returns its argument; func_00127FD0 hands its address on as a callback
   beside func_00128B40. */
void *func_00128B30(void *p)
{
    return p;
}

void *func_00128B40(void *p, s16 flags)
{
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00128B90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00128C00);
