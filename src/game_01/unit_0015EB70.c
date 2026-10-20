#include "common.h"

typedef struct Obj_0015ED00 {
    u8 unk_0[0x10];
    /* 0x10 */ Quad unk_10;
    /* 0x20 */ Quad unk_20;
    /* 0x30 */ Quad unk_30;
    u8 pad_40[0x20];
    /* 0x60 */ Vec unk_60;
    /* 0x70 */ Vec unk_70;
} Obj_0015ED00;

void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015EB70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015ECA0);

void func_0015ED00(Obj_0015ED00 *o)
{
    Quad mid;
    Quad a;
    Quad b;
    Quad c;

    a = o->unk_30;
    b = o->unk_10;
    c = o->unk_20;
    func_0012E9A0(&a.vec0, &b.vec0, &o->unk_70, 0.75f);
    func_0012E9A0(&a.vec0, &b.vec0, &mid.vec0, 0.5f);
    func_0012E9A0(&mid.vec0, &c.vec0, &o->unk_60, -3.0f);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015ED90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015EF70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015F260);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015F420);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015F650);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015F7C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015F900);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015FAF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015FCD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_0015FEF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_00160200);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_001602F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_001603F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_00160460);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015EB70", func_00160640);
