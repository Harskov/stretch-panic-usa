#include "common.h"

typedef struct PadBuf {
    unsigned short b[9];
} PadBuf;

typedef struct PadState {
    unsigned char unk_00[0x18];
    unsigned short now;
    unsigned short pressed;
    unsigned short changed;
    unsigned short released;
    PadBuf old;
    PadBuf cur;
} PadState;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011F5E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FA00);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FA50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FE50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FEA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120100);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120160);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001201D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120230);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120270);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001202B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001202F0);

void func_00120340(PadState *p) {
    u16 cur;
    cur = p->cur.b[0];
    p->changed = p->old.b[0] ^ cur;
    p->pressed = p->changed & cur;
    p->released = p->changed ^ p->pressed;
    p->now = cur;
    p->old = p->cur;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001203A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001207D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001208A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120970);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001209F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120A50);
