#include "common.h"
#include "game_memcard/unit_001463F0.h"

typedef struct Obj14 {
    /* 0x00 */ char unk_0[0x14];
} Obj14;

extern Obj14 D_0069BE20;

extern char D_0069BE38[];

extern char D_0069BE40[];

char *strcat(char *dst, const char *src);

void func_00147B80(s32 arg0);


extern char D_0069BE50[];

extern Obj14 D_0069BEC0;

extern char D_0069BED8[];

extern s32 D_006AEF78;

extern Obj14 D_006AEFE0;

s32 func_00146500(char *path);

extern s32 D_006AEF08;

extern s32 D_006AEED8;

extern s32 D_006AEEC8;

extern s32 D_006AEED0;

void func_001469B0();

extern s32 D_006AEEF8;

extern s32 D_006AEF10;

extern s32 D_006AEF20;

extern s32 D_006AEEA0;

extern s32 D_006AEEB0;

extern s32 D_006AEEB8;

extern s32 D_006AEEC0;

s32 func_00146A90();

s32 func_001468E0();

extern s32 D_006AEEA8;

s32 func_00146060(s32 arg0, s32 arg1, s32 arg2);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00146FD0);

void func_00147070(void)
{
    func_00147B80(4);
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147080);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147120);

/* Calls func_00146060 with the three words at D_006AEEB0..C0 after func_00147B80(5);
   its -1 and -2 both come back as -1, any other non-zero result is kept in
   D_006AEEA8 and reported as -3. */
s32 func_001471C0(void)
{
    s32 ret;

    func_00147B80(5);
    ret = func_00146060(D_006AEEB0, D_006AEEB8, D_006AEEC0);
    switch (ret) {
    case 0:
        return 0;
    case -1:
    case -2:
        return -1;
    default:
        D_006AEEA8 = ret;
        return -3;
    }
}

void func_00147250(void)
{
    func_00147B80(6);
}

/* Builds the memory-card path "/BASLUS-20182SPANIC" "/" "s_panic.ico" and hands
   it to func_00146B90; its -1 and -2 both come back as -1. */
// registers: path = the buffer the three strings are joined in
s32 func_00147260(void)
{
    s32 r;
    union {
        Obj14 unk_0;
        char path[0x40];
    } u;

    // !FAKE: probably strcpy(path, "/BASLUS-20182SPANIC") into a char path[0x40]; only a 20-byte struct assignment reproduces the inline copy
    u.unk_0 = D_0069BE20;
    strcat(u.path, D_0069BE38);
    strcat(u.path, D_0069BE50);
    func_00147B80(5);
    r = func_00146B90(u.path);
    switch (r) {
    case -1:
    case -2:
        return -1;
    }
    return 0;
}

/* Builds the memory-card path "/BASLUS-20182SPANIC" "/" "icon.sys" and hands it
   to func_00146B90; its -1 and -2 both come back as -1. */
// registers: path = the buffer the three strings are joined in
s32 func_001472F0(void)
{
    s32 r;
    union {
        Obj14 unk_0;
        char path[0x40];
    } u;

    // !FAKE: probably strcpy(path, "/BASLUS-20182SPANIC") into a char path[0x40]; only a 20-byte struct assignment reproduces the inline copy
    u.unk_0 = D_0069BE20;
    strcat(u.path, D_0069BE38);
    strcat(u.path, D_0069BE40);
    func_00147B80(5);
    r = func_00146B90(u.path);
    switch (r) {
    case -1:
    case -2:
        return -1;
    }
    return 0;
}

// registers: path = the buffer the copied string lives in
s32 func_00147380(void)
{
    s32 r;
    union {
        Obj14 unk_0;
        char path[0x40];
    } u;

    // !FAKE: probably strcpy(path, ...) into a char path[0x40]; only a 20-byte struct assignment reproduces the inline copy
    u.unk_0 = D_0069BE20;
    func_00147B80(5);
    r = func_00146B90(u.path);
    switch (r) {
    case -1:
    case -2:
        return -1;
    }
    return 0;
}

void func_001473F0(void)
{
    s32 n;

    switch (D_006AEEA8) {
    case 11:
        n = 7;
        break;
    case 13:
        n = 8;
        break;
    case 8:
        n = 9;
        break;
    default:
        n = 10;
        break;
    }
    func_00147B80(n);
}

void func_00147430(void)
{
    func_00147B80(11);
}

void func_00147440(void)
{
    func_00147B80(12);
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147450);

void func_00147500(void)
{
    func_00147B80(14);
}

void func_00147510(void)
{
    func_00147B80(15);
}

s32 func_00147520(s32 arg0, s32 arg1, s32 arg2)
{
    D_006AEEB0 = arg0;
    D_006AEEB8 = arg1;
    D_006AEEC0 = arg2;
    D_006AEEA0 = 0;
    D_006AEEC8 = 2;
    D_006AEED0 = -1;
    D_006AEED8 = 14;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147570);

s32 func_00147B20(void)
{
    return D_006AEEC8;
}

s32 func_00147B30(void)
{
    return D_006AEED0;
}

void func_00147B40(s32 arg0)
{
    D_006AEED8 = arg0;
}

s32 func_00147B50(void)
{
    return D_006AEEC8;
}

s32 func_00147B60(void)
{
    return D_006AEED0;
}

void func_00147B70(s32 arg0)
{
    D_006AEED8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B80);

void func_00147BA0(void)
{
    D_006AEF10 = 0;
    D_006AEF20 = 0;
    D_006AEEF8 = 0;
}

s32 func_00147BC0(s32 arg0)
{
    return (arg0 + 0x3FF) >> 10;
}

/* Sets the card state word D_006AEF08; func_00147BE0 clears the same word. */
void func_00147BD0(void)
{
    D_006AEF08 = 1;
}

/* Clears the card state word D_006AEF08; the memory-card start-up, func_00145F00, calls it. */
void func_00147BE0(void)
{
    D_006AEF08 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147BF0);

/* Builds "/BASLUS-20182SPANIC" "/" arg0 in D_006AEFE0 and hands it to
   func_00146500; on 0 the result also depends on D_006AEF78 matching arg1. */
s32 func_00147C90(char *arg0, s32 arg1)
{
    s32 r;

    // !FAKE: probably strcpy(D_006AEFE0, "/BASLUS-20182SPANIC") into a char array; only a 20-byte struct assignment reproduces the inline copy
    D_006AEFE0 = D_0069BEC0;
    strcat((char *)&D_006AEFE0, D_0069BED8);
    strcat((char *)&D_006AEFE0, arg0);
    r = func_00146500((char *)&D_006AEFE0);
    switch (r) {
    case 0:
        if (D_006AEF78 == arg1)
            return 0;
        return -3;
    case -1:
        return -1;
    }
    return r;
}

void func_00147D50(void)
{
    func_001469B0(&D_006AEFE0);
}

s32 func_00147D60(void)
{
    s32 r;

    r = func_00146A90();
    if (r >= 0)
        r = 0;
    return r;
}

s32 func_00147D90(void)
{
    s32 r;

    r = func_001468E0();
    if (r == 0 || r == -3)
        return r;
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147DC0);
