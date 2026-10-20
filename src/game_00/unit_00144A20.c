#include "common.h"
#include "types.h"

typedef struct M128 {
    __int128 q[8];
} M128;

typedef struct Obj {
    unsigned char unk_00[0x90];
    /* 0x90 */ M128 unk_90;
    unsigned char unk_110[0x3C];
    /* 0x14C */ unsigned char unk_14C;
} Obj;

extern s32 D_006A6730;

void func_00125260();

void func_00127BA0();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144A20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144C20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144C80);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144E00);

void func_00144FA0(void) {
    func_00125260(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144FD0);

void func_00145140(void) {
}

void func_00145150(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145160);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_001454D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_001455F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145790);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145800);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_001459B0);

void func_00145A10(Obj *o, M128 *dst) {
    *dst = o->unk_90;
    o->unk_14C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145A40);

void func_00145A70(void) {
}

int func_00145A80(void) {
    return 0;
}
