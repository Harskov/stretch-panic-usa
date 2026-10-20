#include "common.h"

typedef struct Obj_00132690_2 {
    u128 q0;
    u128 q1;
    u128 q2;
    u128 q3;
} Obj_00132690_2;

typedef struct Obj_00132690_3 {
    /* 0x00 */ Obj_00132690_2 unk_0;
    /* 0x40 */ u128 unk_40;
} Obj_00132690_3;

typedef struct Slot {
    /* 0x00 */ Obj_00132690_2 unk_0;
    /* 0x40 */ u128 unk_40;
    /* 0x50 */ Vec unk_50;
    /* 0x60 */ f32 unk_60;
} Slot;

typedef struct Obj_00134880 {
    u8 pad_0[0x24];
    /* 0x24 */ u8 unk_24;
    u8 pad_25[3];
    /* 0x28 */ Slot *unk_28;
} Obj_00134880;

typedef struct Obj_00132690 {
    u8 pad_0[8];
    /* 0x08 */ s32 *unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    u8 pad_14[4];
    /* 0x18 */ u8 unk_18;
    u8 pad_19[0x1F];
    /* 0x38 */ s32 unk_38;
} Obj_00132690;

void func_00132B50();

void func_00132690(Obj_00132690 *o, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 i;

    o->unk_C = arg1;
    o->unk_10 = arg3;
    o->unk_38 = arg2;
    o->unk_18 = arg4;
    for (i = o->unk_8[0]; i != 0; i--) {
        func_00132B50(o, o->unk_8[i]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132700);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132780);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132880);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132970);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132A60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132B50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00132E10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_001330F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00133350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00133640);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00133A30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00133CE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_001340F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00134520);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00134660);

void func_00134880(Obj_00134880 *arg0, Obj_00132690_3 *arg1, Vec *arg2, f32 arg3)
{
    Slot *dst;

    arg0->unk_24 = 1;
    dst = arg0->unk_28;
    dst->unk_0 = arg1->unk_0;
    dst->unk_40 = arg1->unk_40;
    arg0->unk_28->unk_50 = *arg2;
    arg0->unk_28->unk_60 = arg3;
    arg0->unk_28 = arg0->unk_28 + 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_001348F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00134AC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00134CF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00132690", func_00134E20);
