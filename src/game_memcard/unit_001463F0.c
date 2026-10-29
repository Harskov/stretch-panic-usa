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

s32 sceMcOpen(s32 port, s32 slot, const char *name, s32 mode);

s32 sceMcWrite(s32 fd, const void *buff, s32 size);

extern s32 D_006AEF78;

extern s32 D_006AF040;

extern s32 D_006AF050;

s32 sceMcGetDir(s32 port, s32 slot, const char *name, u32 mode, s32 maxent, void *table);

s32 sceMcMkdir(s32 port, s32 slot, const char *name);

s32 sceMcRead(s32 fd, void *buff, s32 size);

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

/* The memory-card directory step, shaped like the format step beside it: it issues
   sceMcGetDir for one entry into D_006AF040, then waits for both state words to read
   0xD; the return codes' meaning is not yet known. */
s32 func_00146500(const char *arg0)
{
    func_00146D00();
    if (D_006AEF10 == 0xD) {
        if (D_006AEF20 == 0xD) {
            D_006AEF78 = D_006AF050;
            func_00147BA0();
            return D_006AEF28 > 0 ? 0 : 9;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcGetDir(0, 0, arg0, 0, 1, &D_006AF040) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 0xD;
    return -2;
}

/* The memory-card mkdir step, the same state machine as the format step with state
   0xB: it issues sceMcMkdir once, then reports when both state words read 0xB; a
   result of 0 or -4 counts as done. The negative returns are not yet known. */
s32 func_00146600(const char *arg0)
{
    func_00146D00();
    if (D_006AEF10 == 0xB) {
        if (D_006AEF20 == 0xB) {
            func_00147BA0();
            switch (D_006AEF28) {
            case 0:
            case -4:
                return 0;
            }
            return -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcMkdir(0, 0, arg0) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 0xB;
    return -2;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_001463F0", func_00146700);

/* The memory-card write step, beside the open, close and format steps: it issues
   sceMcWrite, sets D_006AEEF8 to 2 and D_006AEF10 to 6, and once D_006AEF20 reaches 6
   returns D_006AEF28 (probably the bytes written), or -3 when that is negative. */
s32 func_001467E0(s32 arg0, const void *arg1, s32 arg2)
{
    func_00146D00();
    if (D_006AEF10 == 6) {
        if (D_006AEF20 == 6) {
            func_00147BA0();
            return D_006AEF28 >= 0 ? D_006AEF28 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcWrite(arg0, arg1, arg2) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 6;
    return -2;
}

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

/* The memory-card open step, beside the close and delete steps: sceMcOpen on port 0, slot 0,
   mode 1; once D_006AEF20 reaches 2 it returns D_006AEF28 (probably the descriptor), or -3
   when that is negative. The other negative returns are status codes not yet known. */
s32 func_001469B0(const char *arg0)
{
    func_00146D00();
    if (D_006AEF10 == 2) {
        if (D_006AEF20 == 2) {
            func_00147BA0();
            return D_006AEF28 >= 0 ? D_006AEF28 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcOpen(0, 0, arg0, 1) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 2;
    return -2;
}

/* The memory-card read step, beside the open, write and close steps: it issues
   sceMcRead, sets D_006AEEF8 to 2 and D_006AEF10 to 5, and once D_006AEF20 reaches 5
   returns D_006AEF28 (probably the bytes read), or -3 when that is negative. */
s32 func_00146A90(s32 arg0, void *arg1, s32 arg2)
{
    func_00146D00();
    if (D_006AEF10 == 5) {
        if (D_006AEF20 == 5) {
            func_00147BA0();
            return D_006AEF28 >= 0 ? D_006AEF28 : -3;
        }
        return -2;
    }
    if (D_006AEEF8 != 0) {
        return -1;
    }
    func_00147BD0();
    if (sceMcRead(arg0, arg1, arg2) != 0) {
        return -1;
    }
    D_006AEEF8 = 2;
    D_006AEF10 = 5;
    return -2;
}

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
