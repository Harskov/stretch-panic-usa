#include "common.h"

typedef struct Obj14 {
    /* 0x00 */ char unk_0[0x14];
} Obj14;

extern Obj14 D_0069BE20;

extern char D_0069BE38[];

extern char D_0069BE40[];

char *strcat(char *dst, const char *src);

void func_00147B80(s32 arg0);

s32 func_00146B90(char *path);

extern char D_0069BE50[];

extern Obj14 D_0069BEC0;

extern char D_0069BED8[];

extern s32 D_006AEF78;

extern Obj14 D_006AEFE0;

s32 func_00146500(char *path);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00146FD0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147070);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147080);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147120);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_001471C0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147250);

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

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147380);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_001473F0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147430);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147440);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147450);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147500);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147510);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147520);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147570);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B20);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B30);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B40);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B50);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B60);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B70);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147B80);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147BA0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147BC0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147BD0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147BE0);

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

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147D50);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147D60);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147D90);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00146FD0", func_00147DC0);
