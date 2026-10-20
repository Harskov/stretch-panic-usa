#include "common.h"
#include "game_memcard/unit_001463F0.h"

extern char gFormat_69BDF8[];

extern char gFormat_69BE08[];

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

s32 sceMcClose(s32 fd);

s32 sceMcDelete(s32 port, s32 slot, const char *name);

extern s32 D_006AEEA0;

extern s32 D_006AEE98;

extern s32 D_006AEED8;

extern s32 D_006AEF50;

/* The memory-card format step (it prints "[FORMAT]" when it issues sceMcFormat
   and "[FORMAT END]" once both state words read 0x10); the negative returns are
   status codes whose meaning is not yet known. */
s32 func_001463F0(void)
{
    func_00146D00();
    if (D_006AEF10 == 0x10) {
        if (D_006AEF20 == 0x10) {
            func_00147BA0();
            printf(gFormat_69BDF8);
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
    printf(gFormat_69BE08);
    return -2;
}

s32 func_001464D0(void)
{
    if (D_006AEF50 >= 0x64) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146500);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146600);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146700);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001467E0);

/* The memory-card close step, parallel to the format step beside it: it issues
   sceMcClose, sets D_006AEEF8 to 2 and D_006AEF10 to 3, and returns 0 or -3 once
   D_006AEF20 has reached 3 as well; the negative returns are status codes whose
   meaning is not yet known. */
s32 func_001468E0(s32 arg0)
{
    func_00146D00();
    if (D_006AEF10 == 3) {
        if (D_006AEF20 == 3) {
            func_00147BA0();
            return D_006AEF28 == 0 ? 0 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcClose(arg0) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 3;
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_001469B0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146A90);

s32 func_00146B90(const char *arg0)
{
    func_00146D00();
    if (D_006AEF10 == 0xF) {
        if (D_006AEF20 == 0xF) {
            func_00147BA0();
            return D_006AEF28 == 0 ? 0 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcDelete(0, 0, arg0) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 0xF;
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146C60);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146D00);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146D80);

void func_00146E90(void) {
}

void func_00146EA0(s32 arg0)
{
    D_006AEEA0 = arg0;
    D_006AEE98 = 0;
    D_006AEED8 = 0xE;
}

s32 func_00146EC0(void)
{
    func_00147B80(0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146EE0);

void func_00146FC0(void)
{
    func_00147B80(2);
}
