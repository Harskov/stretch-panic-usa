#include "common.h"

typedef struct Obj_0016D0D0 {
    u8 pad_0[0xD4];
    s32 unk_D4;
    u8 pad_D8[4];
    s32 unk_DC;
    u8 pad_E0[0xB0];
    u8 unk_190;
} Obj_0016D0D0;

void func_0016C780(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016C790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016C980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016CA40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016CE60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016CF10);

void func_0016D0D0(Obj_0016D0D0 *arg0)
{
    func_0016E4D0(arg0, &arg0->unk_190, arg0->unk_DC, arg0->unk_D4, 0);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016C780", func_0016D0F0);
