#include "common.h"

typedef struct Obj_0017C7A0 {
    /* 0x000 */ s32 *unk_0;
    /* 0x004 */ u8 pad_4[0x168];
    /* 0x16C */ s32 unk_16C;
} Obj_0017C7A0;

extern s32 D_0069D320;

void func_0017B170();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C660);

Obj_0017C7A0 *func_0017C7A0(Obj_0017C7A0 *arg0)
{
    func_0017B170(arg0);
    arg0->unk_0 = &D_0069D320;
    arg0->unk_16C = 0x42740000;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C7E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017C840);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CA50);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CAB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CBC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CCE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017CE00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D190);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D320);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D560);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D5C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D6B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017D950);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0017C510", func_0017DB90);
