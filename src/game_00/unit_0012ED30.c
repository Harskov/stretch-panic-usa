#include "common.h"

void func_0012CA30();

void func_0012CA60();

typedef struct Obj_0012EEC0 {
    u8 pad_0[0x10];
    Vec unk_10;
    u8 pad_20[0x10];
    void *unk_30;
} Obj_0012EEC0;

typedef struct Elem_0012F440 {
    u8 unk_0[0x40];
} Elem_0012F440;

typedef struct List_0012F440 {
    s32 unk_0;
    Elem_0012F440 *unk_4;
} List_0012F440;

typedef struct Obj_0012F440 {
    u8 pad_0[8];
    List_0012F440 *unk_8;
} Obj_0012F440;

f32 func_0012E970(Vec *a, Elem_0012F440 *b);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012ED30);

void func_0012EDF0(register Vec *in, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(in)
        qmtc2.ni v0, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0(out)
    }
}

void func_0012EE10(register Vec *a, register Vec *b, register Vec *out)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE30(register Vec *a, register Vec *b, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyzw vf2, vf2, vf3x
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE50(register Vec *a, register Vec *b, register Vec *out)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf1, vf1, vf2
        vnop
        vnop
        sqc2 vf1, 0(out)
    }
}

void func_0012EE70(register Vec *a, register Vec *b, register Vec *out, register f32 s)
{
    asm {
        mfc1 v0, s
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        qmtc2.ni v0, vf3
        vmulx.xyzw vf2, vf2, vf3x
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(out)
    }
}

void func_0012EE90(register Vec *a, register Vec *b, register Vec *out, register f32 t)
{
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf4, vf2, vf1
        .set noreorder
        mfc1 v0, t
        qmtc2.ni v0, vf3
        .set reorder
        vmulx.xyzw vf4, vf4, vf3x
        vadd.xyzw vf1, vf1, vf4
        sqc2 vf1, 0(out)
    }
}

void func_0012EEC0(Obj_0012EEC0 *a, Vec *b)
{
    func_0012CA60(b, a->unk_30, &a->unk_10);
}

void func_0012EEE0(Vec *a, Vec *b)
{
    func_0012CA30(b, a + 1);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EEF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012EF40);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F0B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F110);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F190);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F300);

s32 func_0012F440(Obj_0012F440 *a, Vec *b)
{
    s32 i;

    for (i = 0; i < a->unk_8->unk_0; i++) {
        if (!(func_0012E970(b, &a->unk_8->unk_4[i]) <= 0.0f)) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F4E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F730);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012ED30", func_0012F790);
