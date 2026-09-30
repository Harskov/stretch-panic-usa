#include "common.h"

typedef struct Obj_00122460 {
    u8 unk_0[0x20];
    Vec pos;
} Obj_00122460;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122260);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122310);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122360);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122380);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_001223D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_001223F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122400);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122410);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122420);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122430);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122440);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122450);

void func_00122460(Obj_00122460 *o, register Vec *d)
{
    register Vec *p;

    p = &o->pos;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(d)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
}

void *func_00122480(char *p) {
    return p + 0x10;
}

void *func_00122490(char *p) {
    return p + 0x20;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_001224A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122510);
