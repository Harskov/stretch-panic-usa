#include "common.h"

typedef struct Obj_00122460 {
    u8 unk_0[0x10];
    /* 0x10 */ u8 unk_10;
    u8 unk_11[0xF];
    /* 0x20 */ Vec unk_20;
} Obj_00122460;

void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122260);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122310);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122360);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122380);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_001223D0);

f32 func_001223F0(Obj_00122460 *o)
{
    return o->unk_20.x;
}

f32 func_00122400(Obj_00122460 *o)
{
    return o->unk_20.y;
}

f32 func_00122410(Obj_00122460 *o)
{
    return o->unk_20.z;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122420);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122430);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122440);

/* Applies func_0012E9A0 to the vector at 0x20 in place, with b and t passed through. */
void func_00122450(Obj_00122460 *o, Vec *b, f32 t)
{
    func_0012E9A0(&o->unk_20, b, &o->unk_20, t);
}

void func_00122460(Obj_00122460 *o, register Vec *d)
{
    register Vec *p;

    p = &o->unk_20;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(d)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
}

/* func_00122460, func_00122480 and func_00122490 are slots of one function-pointer
   table (D_0069C200), so all three are called on the same object. Only the address
   of +0x10 is taken, so its type is not known. */
void *func_00122480(Obj_00122460 *o) {
    return &o->unk_10;
}

Vec *func_00122490(Obj_00122460 *o) {
    return &o->unk_20;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_001224A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00122260", func_00122510);
