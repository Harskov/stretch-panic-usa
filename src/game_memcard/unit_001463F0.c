#include "common.h"

extern char D_0069BDF8[];

extern char D_0069BE08[];

extern s32 D_006AEEF8;

extern s32 D_006AEF10;

extern s32 D_006AEF20;

extern s32 D_006AEF28;

void func_00146D00(void);

void func_00147BA0(void);

void func_00147BD0(void);

s32 sceMcFormat(s32 port, s32 slot);

s32 printf(const char *fmt, ...);

void func_00147B80(s32 arg0);

/* The memory-card format step (it prints "[FORMAT]" when it issues sceMcFormat
   and "[FORMAT END]" once both state words read 0x10); the negative returns are
   status codes whose meaning is not yet known. */
s32 func_001463F0(void)
{
    func_00146D00();
    if (D_006AEF10 == 0x10) {
        if (D_006AEF20 == 0x10) {
            func_00147BA0();
            printf(D_0069BDF8);
            return D_006AEF28 == 0 ? 0 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcFormat(0, 0) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 0x10;
    printf(D_0069BE08);
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001464D0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146500);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146600);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146700);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001467E0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001468E0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001469B0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146A90);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146B90);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146C60);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146D00);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146D80);

void func_00146E90(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146EA0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146EC0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146EE0);

void func_00146FC0(void)
{
    func_00147B80(2);
}
