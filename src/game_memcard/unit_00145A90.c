#include "common.h"

void func_00147B80(s32 arg0);

extern s32 D_006AEE70;

extern s32 D_006AEEA0;

extern s32 D_006AEEF0;

extern s32 D_006AEEF8;

extern s32 D_006AEF00;

extern s32 D_006AEF10;

extern s32 D_006AEF18;

extern s32 D_006AEF20;

extern s32 D_006AEF28;

extern s32 D_006AEF38;

extern s32 D_006AEF40;

extern s32 D_006AEF48;

extern s32 D_006AEF50;

extern s32 D_006AEF58;

extern s32 D_006AEF78;

extern s32 D_006AEF80;

extern s32 D_006AEF88;

extern s32 D_006AEFD0;

s32 sceMcInit(void);

void func_00147BE0(void);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145A90);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145AB0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145AD0);

void func_00145B80(void)
{
    func_00147B80(2);
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145B90);

void func_00145C20(void)
{
    func_00147B80(4);
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145C30);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145C90);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145CE0);

/* Memory-card start-up: initialises the libmc client, then clears the card state
   words (D_006AEF40 alone starts at 1) around a call to func_00147BE0. */
void func_00145F00(void)
{
    sceMcInit();
    D_006AEEF0 = 0;
    D_006AEEF8 = 0;
    D_006AEF10 = 0;
    D_006AEF18 = 0;
    D_006AEF20 = 0;
    D_006AEF28 = 0;
    D_006AEF38 = 0;
    D_006AEF48 = 0;
    D_006AEF50 = 0;
    D_006AEF58 = 0;
    D_006AEF78 = 0;
    D_006AEF88 = 0;
    D_006AEFD0 = 0;
    D_006AEE70 = 0;
    D_006AEEA0 = 0;
    D_006AEF40 = 1;
    func_00147BE0();
    D_006AEF00 = 0;
    D_006AEF80 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00145FC0);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00146060);

INCLUDE_ASM("asm/nonmatchings/game_memcard/unit_00145A90", func_00146230);

s32 func_001463A0(void)
{
    return D_006AEF38;
}

s32 func_001463B0(void)
{
    return D_006AEF48;
}

s32 func_001463C0(void)
{
    return D_006AEF50;
}

s32 func_001463D0(void)
{
    return D_006AEF80;
}

s32 func_001463E0(void)
{
    return D_006AEF40;
}
