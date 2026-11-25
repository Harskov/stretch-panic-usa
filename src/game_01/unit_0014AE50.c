#include "common.h"

typedef struct Obj_0014DDF0 {
    /* 0x000 */ u8 pad_0[0x10];
    /* 0x010 */ u8 unk_10[0x50];
    /* 0x060 */ s32 flags;
    /* 0x064 */ u8 pad_64[0x54];
    /* 0x0B8 */ f32 unk_B8;
    /* 0x0BC */ u8 pad_BC[0x2A8];
    /* 0x364 */ s32 unk_364;
    /* 0x368 */ u8 pad_368[0xA8];
    /* 0x410 */ s32 unk_410;
    /* 0x414 */ f32 unk_414;
    /* 0x418 */ u8 pad_418[0x140];
    /* 0x558 */ s32 unk_558;
    /* 0x55C */ s32 unk_55C;
} Obj_0014DDF0;

extern f32 D_001A0920[];

s32 func_0016BEB0(s32);

f32 func_00132220(f32, f32, f32);

void func_001384E0(s32, void *, s32, f32, f32);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014AE50);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014B020);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014B330);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014B640);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014B7A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014BF60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014C2C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014C560);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014C660);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014CA60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014D510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014D930);

/* Advances unk_B8 by a step scaled from the table entry for unk_410, passes the step on,
   then sets unk_364 from unk_410 (1, 2, 3 give 7, 8, 9). */
void func_0014DDF0(Obj_0014DDF0 *arg0)
{
    f32 r;

    if ((arg0->flags & 0x4000000) && func_0016BEB0(arg0->unk_558) != 0) {
        r = func_00132220(D_001A0920[arg0->unk_410], 1.0f,
                          arg0->unk_414 * D_001A0920[arg0->unk_410]);
        arg0->unk_B8 += r;
        func_001384E0(arg0->unk_55C, arg0->unk_10, arg0->unk_410, arg0->unk_414, r);
        switch (arg0->unk_410) {
        case 1:
            arg0->unk_364 = 7;
            break;
        case 2:
            arg0->unk_364 = 8;
            break;
        case 3:
            arg0->unk_364 = 9;
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014AE50", func_0014DEE0);
