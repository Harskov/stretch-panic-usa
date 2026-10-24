#include "common.h"

extern s32 D_0069CA70;

extern s32 D_006AF4C0;

void func_001319D0();

void func_0015D4E0();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015BD80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015BE20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015BE80);

/* destructor-shaped: restores the vtable, runs the base teardown, and deletes the object when the flag is positive */
s32 **func_0015C130(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069CA70;
        func_0015D4E0();
        D_006AF4C0 = 0;
        func_001319D0(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C1A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C300);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C480);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015C8F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015CB40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015CD50);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015D100);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015D2B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015BD80", func_0015D490);
