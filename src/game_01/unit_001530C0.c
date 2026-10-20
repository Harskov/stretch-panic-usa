#include "common.h"

typedef struct Obj_001530C0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ u8 pad_10[8];
    /* 0x18 */ f32 unk_18;
} Obj_001530C0;

typedef struct Obj_001530C0_2 {
    /* 0x00 */ u8 pad_0[0x60];
    /* 0x60 */ Obj_001530C0 *unk_60;
} Obj_001530C0_2;

typedef struct Obj_001530C0_3 {
    /* 0x000 */ u8 pad_0[0x504];
    /* 0x504 */ Obj_001530C0_2 *unk_504;
} Obj_001530C0_3;

extern s32 D_006A6D10;

s32 func_0013DF50();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001530C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001535C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001537D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001541C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00154AC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00154C70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00154EF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001552F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001556C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001558A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00155CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00155F90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001561B0);

void func_001562A0(Obj_001530C0_3 *arg0) {
    Obj_001530C0_2 *mid;
    Obj_001530C0 *in;

    arg0->unk_504->unk_60->unk_18 = 1.0f;
    mid = arg0->unk_504;
    in = mid->unk_60;
    mid->unk_60->unk_0 = func_0013DF50(in->unk_0, ((s32 *)D_006A6D10)[1], 0xB, in->unk_4, in->unk_C, in->unk_8);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00156300);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001563D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00156460);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_00156620);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001530C0", func_001568E0);
