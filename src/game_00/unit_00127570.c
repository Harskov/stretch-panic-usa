#include "common.h"
#include "globals.h"

extern void __dl__FPv(void *p);

typedef struct Obj_00127810 {
    u8 pad_0[0x40];
    u64 unk_40;
    u8 pad_48[0x28];
    u64 unk_70;
    u8 pad_78[0x18];
    u8 unk_90;
} Obj_00127810;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127570);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127650);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_001276F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127750);

void func_001277C0(Obj_00127810 *arg0, s32 arg1)
{
    arg0->unk_90 = 1;
    arg0->unk_40 = (((u64)(u32)arg1 & 1) << 32) | (arg0->unk_40 & ~0x100000000ULL);
}

void func_00127810(Obj_00127810 *arg0, s32 arg1)
{
    arg0->unk_90 = 1;
    arg0->unk_70 = (arg1 << 17) | (arg0->unk_70 & ~0x60000);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127840);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_001278A0);

void func_00127900(Obj_00127810 *arg0, s32 arg1)
{
    arg0->unk_90 = 1;
    arg0->unk_70 = (arg1 << 15) | (arg0->unk_70 & ~0x8000);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127930);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127BA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00127570", func_00127FD0);

/* Returns its argument; func_00127FD0 hands its address on as a callback
   beside func_00128B40. */
void *func_00128B30(void *p)
{
    return p;
}

void *func_00128B40(void *p, s16 flags)
{
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

void func_00128B90(void)
{
    D_001A0840.unk_0 = 0;
    D_006A69F0 = 0;
    D_006A69D0 = 0;
    D_006A69E8 = 0;
    D_006A69A0 = 0;
    D_006A6990 = 0x10;
    D_006A6998 = -0x11;
    D_006A69D8 = 1;
    D_006A69E0 = 1;
    D_006A69A8 = 1;
    D_006A6980 = D_0069F794;
}

void func_00128C00(void)
{
    s32 i;

    D_006A69F0 = 0;
    D_006AF098 = 0;
    for (i = 0; i < 12; i++) {
        D_001A0840.unk_10[i].unk_2 = 0;
        D_001A0840.unk_10[i].unk_3 = 0;
    }
}
