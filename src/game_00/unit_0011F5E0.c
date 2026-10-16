#include "common.h"

typedef struct Obj_0011F5E0 {
    /* 0x00 */ unsigned short unk_0[9];
} Obj_0011F5E0;

typedef struct Obj_0011F5E0_2 {
    unsigned char unk_00[0x18];
    /* 0x18 */ unsigned short unk_18;
    /* 0x1A */ unsigned short unk_1A;
    /* 0x1C */ unsigned short unk_1C;
    /* 0x1E */ unsigned short unk_1E;
    /* 0x20 */ Obj_0011F5E0 unk_20;
    /* 0x32 */ Obj_0011F5E0 unk_32;
} Obj_0011F5E0_2;

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

void func_00120340(Obj_0011F5E0_2 *p) {
    u16 cur;
    cur = p->unk_32.unk_0[0];
    p->unk_1C = p->unk_20.unk_0[0] ^ cur;
    p->unk_1A = p->unk_1C & cur;
    p->unk_1E = p->unk_1C ^ p->unk_1A;
    p->unk_18 = cur;
    p->unk_20 = p->unk_32;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001203A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001207D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001208A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120970);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001209F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120A50);
