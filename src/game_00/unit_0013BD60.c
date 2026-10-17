#include "common.h"

extern int D_006AED40[2];

extern int D_006AED48;

extern int D_006AED50;

extern int D_006AED74;

int sceSifInitRpc(int mode);

int sceSifBindRpc(int *rd, unsigned int rpc_id, unsigned int mode);

extern s32 D_006AEDD8;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BD60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BDF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BE60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BEE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BF30);

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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C620);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C6D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C7A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C7D0);

void func_0013C820(s32 arg0)
{
    D_006AEDD8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D060);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D220);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D280);
