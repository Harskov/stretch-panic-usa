#include "common.h"

extern char D_0069B800[];

extern char D_0069B820[];

extern s32 D_006AEE20;

extern s32 D_006AEE28;

extern s32 D_006AEE30;

extern s32 D_006AEE38;

s32 sceSifInitRpc(s32 mode);

s32 func_0010C610(char *path, s32 arg1, s32 arg2);

s32 func_0013C250(void);

void func_0013C420(s32 arg0, s32 arg1, s32 arg2);

void func_0013DE10(s32 *args);

typedef struct Obj_0013D940 {
    /* 0x000 */ u8 pad_0[0x240];
    /* 0x240 */ s32 unk_240;
} Obj_0013D940;

extern s32 gFormat_69B870;

void printf();

extern s32 gFormat_69B840;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013D6D0", func_0013D6D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013D6D0", func_0013D8C0);

void func_0013D940(Obj_0013D940 *o, s32 *arg1)
{
    *arg1 = o->unk_240;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013D6D0", func_0013D950);

void func_0013DBE0(void) {
}

/* Sound start-up, probably: loads LIBSD.IRX and SMSPS2.IRX from the disc,
   retrying each until the call succeeds, then sends two parameter pairs. */
s32 func_0013DBF0(void)
{
    s32 args[2];

    sceSifInitRpc(0);
    while (func_0010C610(D_0069B800, 0, 0) < 0)
        ;
    while (func_0010C610(D_0069B820, 0, 0) < 0)
        ;
    if (func_0013C250() < 0)
        return -1;
    func_0013C420(0, 0, 0);
    D_006AEE20 = 0;
    D_006AEE28 = 0;
    D_006AEE30 = 0;
    D_006AEE38 = 0;
    args[0] = 0;
    args[1] = 0x3FFF3FFF;
    func_0013DE10(args);
    args[0] = 1;
    args[1] = 0x3FFF3FFF;
    func_0013DE10(args);
    return 0;
}

/* evidence: debug string D_0069B840 begins with this name and only this function references it */
void smsBufferPush(void)
{
    if (D_006AEE38 >= 4) {
        printf(&gFormat_69B840);
        return;
    }
    func_0013C420(6, (s32)&D_006AEE38, 4);
    D_006AEE38 += 1;
}

/* evidence: debug string D_0069B870 begins with this name and only this function references it */
void smsBufferPop(void)
{
    if (D_006AEE38 <= 0) {
        printf(&gFormat_69B870);
        return;
    }
    D_006AEE38 -= 1;
    func_0013C420(7, (s32)&D_006AEE38, 4);
}

s32 func_0013DDA0(s32 *args)
{
    *args = D_006AEE20;
    func_0013C420(3, (s32)args, 0x14);
    return D_006AEE20++;
}

void func_0013DDF0(s32 *args)
{
    func_0013C420(5, (s32)args, 0x48);
}

void func_0013DE00(s32 *args)
{
    func_0013C420(0xC, (s32)args, 0x48);
}

void func_0013DE10(s32 *args)
{
    func_0013C420(9, (s32)args, 8);
}

s32 func_0013DE20(s32 *args)
{
    *args = D_006AEE28;
    func_0013C420(0xD, (s32)args, 0x14);
    return D_006AEE28++;
}
