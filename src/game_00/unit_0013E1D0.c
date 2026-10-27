#include "common.h"

typedef struct Obj_0013E690 {
    /* 0x000 */ u8 unk_0[0x1AC];
    /* 0x1AC */ s32 unk_1AC;
} Obj_0013E690;

typedef struct Obj_0013E350 {
    /* 0x00 */ s32 *unk_0;
} Obj_0013E350;

extern s32 D_0069C780;

void func_0013E6A0();

void func_001319D0();

void func_0013FB70();

void func_001401F0();

void func_00140D70();

void func_00140F10();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013E1D0);

// probably a destructor written out by hand: the table word is reset, the parts are torn
// down, and operator delete runs when the second argument is positive
Obj_0013E350 *func_0013E350(Obj_0013E350 *o, s16 arg1)
{
    if (o != 0) {
        o->unk_0 = &D_0069C780;
        func_0013E6A0();
        func_001401F0(o);
        func_00140F10(o);
        func_0013FB70(o);
        func_00140D70(o);
        func_001319D0(o, 0);
        if (arg1 > 0)
            __dl__FPv(o);
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013E3E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013E530);

void func_0013E620(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013E630);

void func_0013E690(Obj_0013E690 *o)
{
    o->unk_1AC = 0;
}

void func_0013E6A0(void) {
}

void func_0013E6B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013E6C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013EBD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013FB70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013FCB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013E1D0", func_0013FD20);
