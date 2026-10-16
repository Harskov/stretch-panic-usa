#include "common.h"

typedef struct E64 {
    __int128 q[4];
} E64;

typedef struct Src {
    unsigned char unk_00[4];
    /* 0x04 */ E64 *unk_4;
} Src;

typedef struct Ctx {
    unsigned char unk_00[8];
    /* 0x08 */ Src *unk_8;
    int count;
    /* 0x10 */ E64 *unk_10;
} Ctx;

typedef struct Obj_00131620 {
    unsigned char unk_00[0xC];
    u8 unk_C;
} Obj_00131620;

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

/* A slot of the function-pointer table D_0069C420. Only the member's address is
   taken, so its type is not known. */
void *func_00131620(Obj_00131620 *o) {
    return &o->unk_C;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131630);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001316B0);

/* Shares the function-pointer table D_0069C450 with func_00131740, so both are
   called on the same object. */
int *func_00131730(Ctx *c) {
    return &c->count;
}

void func_00131740(Ctx *c) {
    int i;

    for (i = 0; i < c->count; i++) {
        c->unk_10[i] = c->unk_8->unk_4[i];
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_001317A0);
