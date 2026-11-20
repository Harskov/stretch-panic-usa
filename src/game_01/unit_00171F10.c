#include "common.h"
#include "globals.h"
#include "types.h"

extern s32 D_006A6730;

void func_00127BA0();

void func_00172410(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5, f32 x6, f32 x7);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00171F10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00171FB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172060);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172170);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172280);

void func_00172410(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5, f32 x6, f32 x7) {
    Obj6A6B90 *q;

    D_006A6B90->unk_1C = x6;
    D_006A6B90->unk_2C = x6;
    D_006A6B90->unk_3C = x7;
    D_006A6B90->unk_4C = x7;
    q = D_006A6B90;
    q->unk_30 = q->unk_30 + x0;
    q->unk_34 = q->unk_34 + x1;
    q->unk_38 = q->unk_38 + x2;
    q = D_006A6B90;
    q->unk_40 = q->unk_40 + x3;
    q->unk_44 = q->unk_44 + x4;
    q->unk_48 = q->unk_48 + x5;
}

void func_001724A0(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5) {
    func_00172410(x0, x1, x2, x3, x4, x5, 0.4f, 0.065f);
}

void func_001724D0(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5) {
    func_00172410(x0, x1, x2, x3, x4, x5, 0.5f, 0.05f);
}

void func_001724F0(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5) {
    func_00172410(x0, x1, x2, x3, x4, x5, 0.6f, 0.035f);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172740);

void func_00172860(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172890);

// registers: count = the value *arg1 holds, stepped down by one while it is nonzero
s32 func_00172A40(s32 *arg0, s32 *arg1) {
    s32 count;

    count = *arg1;
    if (count != 0) {
        *arg1 = count - 1;
        if (*arg1 == 0) {
            *arg0 = 0;
        }
        return 1;
    }
    return 0;
}

s32 func_00172A80(s32 arg0) {
    s32 *p = &D_00601BB0;
    return p[arg0];
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00171F10", func_00172AA0);

void func_00172BC0(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

void func_00172BF0(void) {
}
