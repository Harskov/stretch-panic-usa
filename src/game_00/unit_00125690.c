#include "common.h"

void func_00122C30(s32 arg0, s32 arg1);

typedef struct Obj_00125CF0 {
    u8 pad_0[0xF0];
    u64 unk_F0;
    u8 pad_F8[0x18];
    u8 unk_110;
} Obj_00125CF0;

typedef struct Obj_00126900 {
    u8 pad_0[0x350];
    u32 unk_350;
    u8 pad_354[0x156C];
    s32 unk_18C0[4];
    u128 unk_18D0[4];
    u128 unk_1910[4];
} Obj_00126900;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125690);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_001256B0);

void func_00125730(s32 arg0, s32 arg1)
{
    func_00122C30(arg1, 1);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125740);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125820);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125B50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125C30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125C90);

void func_00125CF0(Obj_00125CF0 *arg0, s32 arg1)
{
    arg0->unk_110 = 1;
    arg0->unk_F0 = (arg1 << 15) | (arg0->unk_F0 & ~0x8000);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125D20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00125EA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00126140);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00126320);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_001265C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00126880);

void func_00126900(Obj_00126900 *arg0, s32 arg1, s32 arg2, u128 *arg3)
{
    arg0->unk_350 |= 0x2000;
    arg0->unk_18C0[arg1] = arg2;
    switch (arg1) {
    case 0:
        arg0->unk_18D0[0] = *arg3;
        arg0->unk_1910[0] = *arg3;
        break;
    case 1:
        arg0->unk_18D0[1] = *arg3;
        arg0->unk_1910[1] = *arg3;
        break;
    case 2:
        arg0->unk_18D0[2] = *arg3;
        arg0->unk_1910[2] = *arg3;
        break;
    case 3:
        arg0->unk_18D0[3] = *arg3;
        arg0->unk_1910[3] = *arg3;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_001269A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00125690", func_00127040);
