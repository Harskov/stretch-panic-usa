#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    int limit;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001666F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001667C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001668D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001669A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166C20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166D30);

int func_00166D90(Obj *o) {
    int old;

    o->unk_E0 += o->unk_A8;
    o->unk_E4 += o->unk_E8;
    if (o->unk_E4 < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    old = o->unk_EC;
    o->unk_EC = old + 1;
    return old < o->limit;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00166DE0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167180);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001672B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_001673C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167760);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167810);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167BB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001666F0", func_00167E20);
