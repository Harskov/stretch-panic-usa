#include "common.h"

extern s32 D_0069C870;

void func_00172E80();

void __dl__FPv(void *);

extern s32 D_006A6730;

void func_00127BA0();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00141210);

f32 func_00141B10(s32 arg0)
{
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00141B20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00142250);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_001426A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00142920);

void func_00142A70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00142A80);

void func_00142E30(void) {
}

int func_00142E40(void) {
    return 0;
}

void func_00142E50(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00142E60);

s32 **func_00142FA0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C870;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00143000);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00143050);

void func_001431E0(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00141210", func_00143220);
