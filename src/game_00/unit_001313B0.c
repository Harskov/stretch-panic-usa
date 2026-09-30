#include "common.h"

typedef struct E64 {
    __int128 q[4];
} E64;

typedef struct Src {
    unsigned char unk_00[4];
    E64 *arr;
} Src;

typedef struct Ctx {
    unsigned char unk_00[8];
    Src *src;
    int count;
    E64 *dst;
} Ctx;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001313B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131410);

void func_00131420(void) {
}

void func_00131430(void) {
}

void func_00131440(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131450);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001314B0);

void func_001314C0(void) {
}

void func_001314D0(void) {
}

void func_001314E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001314F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131550);

void func_00131560(void) {
}

void func_00131570(void) {
}

void func_00131580(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131590);

void *func_00131620(char *p) {
    return p + 0xC;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131630);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001316B0);

void *func_00131730(char *p) {
    return p + 0xC;
}

void func_00131740(Ctx *c) {
    int i;

    for (i = 0; i < c->count; i++) {
        c->dst[i] = c->src->arr[i];
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001317A0);
