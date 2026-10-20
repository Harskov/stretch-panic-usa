#include "common.h"
#include "game_00/unit_0012DF10.h"
#include "game_01/obj2F8.h"

void func_0016FBE0();


void func_0012D430(Vec *);

void func_0012D450(Vec *, f32, f32, f32);

void func_0012C8F0(Vec *, Vec *);

typedef struct Obj_0016DE30 {
    u128 q[5];
} Obj_0016DE30;

typedef struct Obj_0016DE30_2 {
    u8 unk_0[0x350];
    s32 unk_350;
    u8 unk_354[0x24];
    s32 unk_378;
    u8 unk_37C[0x184];
    Obj_0016DE30 *unk_500[4];
} Obj_0016DE30_2;

extern Obj_0016DE30_2 *D_006A6730;

void func_0016E5A0();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016DE30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016DF60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016DFF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E0B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E120);

void func_0016E270(Obj2F8 *arg0, f32 scale, f32 arg2)
{
    {
        register Vec *a = (Vec *)&arg0->unk_184[0xEC];
        register f32 s = scale;

        asm {
            mfc1 v0, s
            lqc2 vf1, 0(a)
            qmtc2.ni v0, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(a)
        }
    }
    func_0012E9A0((Vec *)&arg0->unk_184[0xEC], (Vec *)&arg0->unk_20[0x10], (Vec *)&arg0->unk_20[0x10], arg2);
    {
        register Vec *e;
        register Vec *d;

        d = (Vec *)&arg0->unk_10;
        e = (Vec *)&arg0->unk_20[0x10];
        asm {
            lqc2 vf1, 0(d)
            lqc2 vf2, 0(e)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(d)
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E2D0);

void func_0016E340(Obj2F8 *arg0)
{
    func_0012D430((Vec *)&arg0->unk_184[0xC]);
    func_0012D450((Vec *)&arg0->unk_184[0xC], ((Vec *)&arg0->unk_10)->x, ((Vec *)&arg0->unk_10)->y, ((Vec *)&arg0->unk_10)->z);
    func_0012C8F0((Vec *)&arg0->unk_184[0xC], (Vec *)&arg0->unk_184[0x5C]);
}

void func_0016E390(int arg0, int arg1, int arg2) {
    func_0016FBE0(arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E3A0);

void func_0016E4D0(s32 arg0, Obj_0016DE30 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    Obj_0016DE30_2 *s = D_006A6730;
    Obj_0016DE30_2 *s2;

    s->unk_500[s->unk_378][1] = *arg1;
    s->unk_500[s->unk_378] += 1;
    s->unk_350 |= 0x100 << s->unk_378;
    func_0016E5A0(arg0, arg2, arg3, arg4);
    s2 = D_006A6730;
    s2->unk_500[s2->unk_378] -= 1;
    s2->unk_350 |= 0x100 << s2->unk_378;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E5A0);

void func_0016E740(Obj2F8 *arg0) {
    arg0->unk_2F8 = arg0->unk_64;
    arg0->unk_2FC = arg0->unk_68;
}

void func_0016E760(Obj2F8 *arg0) {
    arg0->unk_64 = arg0->unk_2F8;
    arg0->unk_68 = arg0->unk_2FC;
}

void func_0016E780(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016DE30", func_0016E920);
