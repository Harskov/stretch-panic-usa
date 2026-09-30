#include "common.h"

typedef struct Obj0013BD20 {
    u8 pad0[0x10];
    Vec pos;
    Vec delta;
    Vec rot[3];
} Obj0013BD20;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B1F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B220);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B280);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B2B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B320);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B350);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B720);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B7A0);

void func_0013BAE0(void) {
}

void func_0013BAF0(void) {
}

int func_0013BB00(void) {
    return 0;
}

void func_0013BB10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013BB20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013BC80);

void func_0013BD20(Obj0013BD20 *o, register Vec *m)
{
    register Vec *p;

    p = &o->pos;
    asm {
        lqc2 vf1, 0x30(m)
        lqc2 vf2, 0(p)
        vsub.xyz vf2, vf1, vf2
        lqc2 vf3, 0(m)
        lqc2 vf4, 0x10(m)
        lqc2 vf5, 0x20(m)
        sqc2 vf1, 0(p)
        sqc2 vf2, 0x10(p)
        sqc2 vf3, 0x20(p)
        sqc2 vf4, 0x30(p)
        sqc2 vf5, 0x40(p)
    }
}
