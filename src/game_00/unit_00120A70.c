#include "common.h"

typedef struct Obj_001211E0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ u8  unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} Obj_001211E0;

extern s32 D_006A66F8;

s32 scePadInit(s32);

void func_00121250(Obj_001211E0 *o);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120A70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120C00);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120CE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120D90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120E30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120E70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121100);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001211C0);

// set up the object: register it globally, initialize the pad library, clear fields and continue setup
Obj_001211E0 *func_001211E0(Obj_001211E0 *o)
{
    D_006A66F8 = (s32)o;
    if (scePadInit(0) == 0) {
        while (1) {}
    }
    o->unk_18 = 0;
    o->unk_0  = 0;
    o->unk_4  = 0;
    o->unk_8  = 0;
    o->unk_C  = 0;
    o->unk_10 = 0;
    o->unk_14 = 0;
    o->unk_1C = 0;
    func_00121250(o);
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121250);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001213F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001214F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001215A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001215E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121640);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121690);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001216E0);
