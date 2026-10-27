#include "common.h"

extern s32 D_006AEE30;

void func_0013C420();

void func_0013DF00(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);

typedef struct Obj_0013DF50 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
} Obj_0013DF50;

typedef struct Obj_0013E160 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s16 unk_4;
    /* 0x06 */ s16 unk_6;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
} Obj_0013E160;

void func_0013DE70(s32 arg0)
{
    func_0013C420(0xB, (s32)&arg0, 4);
}

void func_0013DEA0(s32 arg0)
{
    func_0013C420(0xA, (s32)&arg0, 4);
}

void func_0013DED0(s32 arg0, s32 arg1)
{
    s32 args[2];

    args[0] = arg0;
    args[1] = arg1;
    func_0013C420(0xF, args, 8);
}

void func_0013DF00(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3)
{
    if (arg1 >= 0) {
        *arg2 = arg0;
    } else {
        *arg2 = (arg0 * (arg1 + 0x7FFF + 1)) >> 15;
    }
    if (arg1 <= 0) {
        *arg3 = arg0;
    } else {
        *arg3 = (arg0 * (0x8000 - arg1)) >> 15;
    }
}

/* builds a 0x18-byte block (with the running count from D_006AEE30), sends it as
   command 0x10 through func_0013C420, then steps the count and returns the one sent */
s32 func_0013DF50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    Obj_0013DF50 args;
    s32 val0;
    s32 val1;

    args.unk_0 = arg0;
    args.unk_4 = D_006AEE30;
    args.unk_8 = arg1;
    args.unk_C = arg2;
    args.unk_10 = arg5;
    func_0013DF00(arg3, arg4, &val0, &val1);
    args.unk_14 = val0;
    args.unk_16 = val1;
    func_0013C420(0x10, (s32)&args, 0x18);
    return D_006AEE30++;
}

/* same block as the command 0x10 sender next to it, sent as command 0x11 */
s32 func_0013DFD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    Obj_0013DF50 args;
    s32 val0;
    s32 val1;

    args.unk_0 = arg0;
    args.unk_4 = D_006AEE30;
    args.unk_8 = arg1;
    args.unk_C = arg2;
    args.unk_10 = arg5;
    func_0013DF00(arg3, arg4, &val0, &val1);
    args.unk_14 = val0;
    args.unk_16 = val1;
    func_0013C420(0x11, (s32)&args, 0x18);
    return D_006AEE30++;
}

void func_0013E050(s32 arg0)
{
    func_0013C420(0x12, (s32)&arg0, 4);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013DE70", func_0013E080);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013DE70", func_0013E0E0);

void func_0013E140(void)
{
    func_0013C420(0x16, 0, 0);
}

void func_0013E150(void)
{
    func_0013C420(0x17, 0, 0);
}

void func_0013E160(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    Obj_0013E160 args;

    args.unk_0 = arg0;
    args.unk_4 = arg1;
    args.unk_6 = arg2;
    args.unk_8 = arg3;
    args.unk_C = arg4;
    args.unk_10 = arg5;
    args.unk_12 = arg6;
    func_0013C420(0x18, (s32)&args, 0x14);
}

void func_0013E1A0(s32 arg0)
{
    func_0013C420(0x19, (s32)&arg0, 4);
}
