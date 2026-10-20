#include "common.h"

typedef struct Obj_00130A60 {
    Vec unk_0;
    f32 unk_10;
    f32 unk_14;
} Obj_00130A60;

f32 func_0012E870();

int func_00130A60(Obj_00130A60 *arg0, Obj_00130A60 *arg1) {
    f32 limit;

    limit = arg1->unk_14 + (arg0->unk_14 + 2.0f * arg0->unk_10 * arg1->unk_10);
    return func_0012E870(arg1, arg0) < limit;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130AD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130D80);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130E10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130EB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00131240);

int func_001312F0(void) {
    return 0;
}

int func_00131300(void) {
    return 0;
}

int func_00131310(void) {
    return 0;
}

int func_00131320(void) {
    return 0;
}

int func_00131330(void) {
    return 0;
}

int func_00131340(void) {
    return 0;
}

int func_00131350(void) {
    return 0;
}

int func_00131360(void) {
    return 0;
}

int func_00131370(void) {
    return 0;
}

int func_00131380(void) {
    return 0;
}

int func_00131390(void) {
    return 0;
}

int func_001313A0(void) {
    return 0;
}
