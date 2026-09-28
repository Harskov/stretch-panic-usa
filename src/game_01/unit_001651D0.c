#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0x50];
    float speed;
    float drag;
    unsigned char unk_58[4];
    float fall;
    unsigned char unk_60[0x30];
    float pos;
    float height;
} Obj;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_001651D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165300);

int func_001653D0(Obj *o) {
    int alive = 1;

    o->speed = o->speed - o->speed * o->drag;
    o->pos += o->speed;
    o->height -= o->fall;
    if (o->height <= 0.0f) {
        alive = 0;
    }
    return alive;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165420);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_001656D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165800);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165980);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165DC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165E20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00165FF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00166060);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00166210);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_001664F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001651D0", func_00166690);
