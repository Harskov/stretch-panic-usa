#include "common.h"

void func_00146600();

extern s32 D_006AEF90;

void func_00146700();

void func_00147EE0(void)
{
    func_00146700(&D_006AEF90);
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00147EE0", func_00147EF0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00147EE0", func_00147F20);

void func_00147F50(void) {
    func_00146600();
}
