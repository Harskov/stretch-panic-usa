#include "common.h"

extern s32 D_001A0970[];

extern s32 D_006A6980;

extern s32 D_006A6990;

extern s32 D_006A6998;

s32 mwLoadOverlay(s32, s32);

extern s32 D_0069C290;

void __dl__FPv(void *);

extern u8 D_006A6A00[];

void func_0012A8C0();

extern u8 D_001A0850[];

extern u8 D_001A0851[];

s32 rand();

// loads overlay D_006A6990 (an index into the table at D_001A0970) only when it is not the one D_006A6998
// records as loaded; a failed load is repeated until it succeeds
void func_00128C40(void)
{
    if (D_006A6990 ^ D_006A6998) {
        D_006A6998 = D_006A6990;
        while (mwLoadOverlay(D_001A0970[D_006A6990], D_006A6980) == 0) {
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_00128CB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_00129010);

/* Selects the overlay func_00128C40 loads next. */
void func_00129050(s32 arg0)
{
    D_006A6990 = arg0;
}

/* Returns the overlay index D_006A6990 (func_00128C40 loads that overlay). */
s32 func_00129060(void)
{
    return D_006A6990;
}

void func_00129070(s32 arg0)
{
    D_001A0850[arg0 * 4] = (rand() >> 3) % 9;
    D_001A0851[arg0 * 4] = (rand() >> 3) % 3;
}

s32 **func_001290E0(s32 **arg0)
{
    s32 i;
    u8 *p;

    *arg0 = &D_0069C290;
    func_0012A8C0(arg0 + 1);
    p = D_006A6A00;
    for (i = 0; i < 8; i++) {
        *p = 0;
        p++;
    }
    return arg0;
}

s32 **func_00129140(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C290;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_00129190);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_00129240);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_001292C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_001296C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_0012A0B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_0012A8C0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_0012A910);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00128C40", func_0012AA10);
