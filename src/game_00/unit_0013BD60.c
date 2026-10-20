#include "common.h"

extern int D_006AED40[2];

extern int D_006AED48;

extern int D_006AED50;

extern int D_006AED74;

int sceSifInitRpc(int mode);

int sceSifBindRpc(int *rd, unsigned int rpc_id, unsigned int mode);

extern s32 D_006AEDD8;

typedef struct Obj0013BF30 {
    u8 unk_0[0x10];
    Vec unk_10;
} Obj0013BF30;

extern s32 D_0069C708;

void __dl__FPv();

extern s32 D_0069C250;

extern s32 D_0069C760;

extern s32 D_006AEDD0;

void func_0013DE10();

int func_0013DDA0();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BD60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BDF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BE60);

s32 **func_0013BEE0(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C708;
        if (arg1 > 0) {
            // !FAKE: the original is a C++ destructor calling operator delete(this); the argument register still holds this, so the call passes nothing
            __dl__FPv();
        }
    }
    return arg0;
}

void func_0013BF30(register Obj0013BF30 *o, register Vec *m)
{
    register Vec *p;

    p = &o->unk_10;
    asm {
        lq t0, 0(m)
        lq t1, 0x10(m)
        lq t2, 0x20(m)
        lqc2 vf4, 0x30(m)
        vmove.xyzw vf5, vf4
        vsub.xyz vf4, vf4, vf4
        vmove.xyzw vf9, vf4
        qmfc2.ni t3, vf4
        pextlw t4, t1, t0
        pextuw t5, t1, t0
        pextlw t6, t3, t2
        pextuw t7, t3, t2
        pcpyld t0, t6, t4
        pcpyud t1, t4, t6
        pcpyld t2, t7, t5
        qmtc2.ni t0, vf6
        qmtc2.ni t1, vf7
        qmtc2.ni t2, vf8
        vmulax.xyz ACC, vf6, vf5x
        vmadday.xyz ACC, vf7, vf5y
        vmaddz.xyz vf4, vf8, vf5z
        vsub.xyz vf4, vf9, vf4
        lqc2 vf5, 0(p)
        sq t0, 0x30(o)
        sq t1, 0x40(o)
        vsub.xyz vf5, vf4, vf5
        sq t2, 0x50(o)
        sqc2 vf4, 0(p)
        vnop
        sqc2 vf5, 0x10(p)
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BFB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C1C0);

// binds the RPC client D_006AED50 to the IOP server 0x534D5300, retrying until the server answers.
// D_006AED74 is 0x24 into D_006AED50, probably the client data's server pointer, which the bind fills
int func_0013C250(void)
{
    int i;

    sceSifInitRpc(0);
    do {
        if (sceSifBindRpc(&D_006AED50, 0x534D5300, 0) < 0)
            return -1;
    } while (D_006AED74 == 0);

    for (i = 0; i < 2; i++)
        D_006AED40[i] = 0;

    D_006AED48 = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C2E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C420);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C510);

int func_0013C590(s32 arg0, s32 *arg1)
{
    s32 buf[8];

    buf[1] = 0;
    buf[2] = 1;
    buf[3] = arg0 * 2;
    arg1[0] = func_0013DDA0(buf);
    buf[1] = 1;
    buf[2] = 5;
    buf[3] = 0x18000;
    arg1[1] = func_0013DDA0(buf);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C620);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C6D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C7A0);

void func_0013C7D0(s32 arg0)
{
    s32 buf[2];

    buf[0] = (D_006AEDD0 & 1) + 2;
    buf[1] = arg0 | (arg0 << 16);
    func_0013DE10(buf);
    buf[0] = 1;
    func_0013DE10(buf);
}

void func_0013C820(s32 arg0)
{
    D_006AEDD8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D060);

s32 **func_0013D220(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C760;
        if (arg0 != 0) {
            *arg0 = &D_0069C250;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D280);
