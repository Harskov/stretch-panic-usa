#include "common.h"
#include "game_01/obj430.h"

extern s32 D_006AF0A0[];

extern s32 D_006AF0A4[];

extern s32 D_006AF4A0;

void func_00152040();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001510C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001512B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001513D0);

void func_00151460(Obj430 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 0;
    arg0->unk_420.w.unk_00 = 0;
    arg0->unk_420.w.unk_04 = 0;
    arg0->unk_420.w.unk_08 = 0;
    arg0->unk_420.w.unk_0C = 1.0f;
}

void func_001514A0(Obj430 *arg0, s32 arg1, const Quad420 *arg2, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 1;
    arg0->unk_420.q = arg2->q;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001514D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151530);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151600);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001517A0);

void func_00151820(s32 arg0) {
    s32 idx;

    if (arg0 > 0) {
        D_006AF0A0[((D_006AF4A0 + 0x5A) % 128) * 2] += arg0;
    }
    if (arg0 < 0) {
        D_006AF0A4[((D_006AF4A0 + 0x10) % 128) * 2] += arg0;
    }
}

void func_001518B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001518C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151A40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151AF0);

void func_00152030(void) {
    func_00152040();
}
