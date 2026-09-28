#include "common.h"
#include "game_01/obj50.h"

extern s32 D_00601BD0[];

extern s32 D_006B3580[];

extern s32 D_006B3700[];

extern s32 D_006B3880;

extern s32 D_006B3888;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172C00);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172C60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172D10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172D50);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172DA0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00172E80);

void func_00172F60(void)
{
    s32 i;

    for (i = 0; i < 0x5F; i++) {
        D_006B3700[i] = 0;
    }

    D_006B3880 = 0;
    D_006B3888 = 0;

    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x1C] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x38] = D_00601BD0[i];
    }
    for (i = 0; i != 0xB; i++) {
        D_006B3580[i + 0x54] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173070);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173120);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173180);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173360);

s32 func_001733C0(Obj50 *arg0) {
    register Vec *v;
    register Vec *p;
    f32 t;
    s32 r;

    arg0->unk_70 = arg0->unk_70 * arg0->unk_74;
    arg0->unk_74 = arg0->unk_74 * arg0->unk_78;
    arg0->unk_7C = arg0->unk_7C * arg0->unk_80;
    t = arg0->unk_8C;
    arg0->unk_9C = arg0->unk_9C + t;

    p = &arg0->pos;
    v = &arg0->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    r = 1;
    if (arg0->unk_9C <= 0.0f) {
        r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173440);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173990);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173BA0);

s32 func_00173C00(Obj50 *arg0) {
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

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00172C00", func_00173CC0);
