#include "common.h"

typedef struct Pair_001217C0 {
    Quad *unk_0;
    s32 unk_4;
} Pair_001217C0;

typedef struct Obj_001217C0 {
    u8 unk_0[0x10];
    Quad unk_10;
    Vec unk_20;
    s32 unk_30;
    u8 unk_34[0x4];
    Vec *unk_38;
    Quad *unk_3C;
    s32 unk_40;
    s32 unk_44;
} Obj_001217C0;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_001217C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_001217E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121820);

void func_00121880(Obj_001217C0 *o, Pair_001217C0 *s)
{
    register Vec *b;
    register Vec *a;
    register Vec *d;
    register Vec *c;

    a = &o->unk_10.v;
    b = &o->unk_20;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(b)
    }
    if (s->unk_0 != 0) {
        o->unk_3C = s->unk_0;
        o->unk_40 = s->unk_4;
    } else {
        o->unk_3C = (Quad *)o->unk_44;
        o->unk_40 = o->unk_44;
    }
    o->unk_30 = 0;
    o->unk_38 = &o->unk_3C->v;
    o->unk_10.q = o->unk_3C->q;
    c = &o->unk_20;
    d = &o->unk_10.v;
    asm {
        lqc2 vf1, 0(c)
        lqc2 vf2, 0(d)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(c)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121900);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121930);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121A60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121AD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121B10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121C10);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121C70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121D60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121E50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121F20);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121F30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_00121FE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001217C0", func_001221F0);
