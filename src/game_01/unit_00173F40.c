#include "common.h"
#include "game_01/obj50.h"

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00173F40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174150);

s32 func_001741B0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;

    p = &arg0->pos;
    v = &arg0->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->unk_A0;
    arg0->unk_9C = arg0->unk_9C + t;

    if (!(arg0->unk_A0 <= 0.0f) && !(arg0->unk_9C <= 1.0f)) {
        arg0->unk_9C = 1.0f;
        arg0->unk_A0 = 0.0f;
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174270);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174620);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174860);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001748D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174A40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174B30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174DD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174EF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00174FB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00175010);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001750C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001753F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_00175490);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00173F40", func_001754F0);
