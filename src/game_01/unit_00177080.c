#include "common.h"

typedef struct Obj_00177FF0 {
    u8 pad_0[0x4E9];
    u8 unk_4E9;
} Obj_00177FF0;

void func_0017A5B0();

typedef struct Obj_00177170 {
    u8 pad_0[0x70];
    Quad unk_70;
    u8 pad_80[0x30];
    Quad unk_B0;
    f32 unk_C0;
    f32 unk_C4;
} Obj_00177170;

extern Quad D_00677D60;

void func_0016FDE0(s32 a0, s32 a1, s32 a2, Quad *a3, Quad *t0, Quad *t1, f32 f12, f32 f13);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00177080);

void func_00177170(Obj_00177170 *arg0)
{
    Quad local;

    local = D_00677D60;
    func_0016FDE0(4, 4, 0, &arg0->unk_70, &arg0->unk_B0, &local, arg0->unk_C0, arg0->unk_C4);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_001771C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_001774A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00177540);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00177A30);

void func_00177CF0(void)
{
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00177D00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00177F90);

void func_00177FF0(Obj_00177FF0 *arg0)
{
    func_0017A5B0();
    arg0->unk_4E9 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00178020);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_001780C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00178320);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00178380);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00177080", func_00178460);
