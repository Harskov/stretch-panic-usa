#include "common.h"

typedef struct Ent {
    /* 0x00 */ unsigned char unk_0;
    unsigned char unk_01[0x2F];
} Ent;

typedef struct Obj {
    unsigned char unk_00[0x50];
    int count;
    unsigned char unk_54[0x14];
    /* 0x68 */ Ent *unk_68;
} Obj;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164100);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164580);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164690);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164700);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_001647D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164930);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164A80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164B10);

Ent *func_00164E80(Obj *o) {
    int i;

    for (i = 0; i < o->count; i++) {
        if (o->unk_68[i].unk_0 == 0) {
            return &o->unk_68[i];
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164EE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164F20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00165090);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00165100);
