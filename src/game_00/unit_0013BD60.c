#include "common.h"

extern int D_006AED40[2];

extern int D_006AED48;

extern int D_006AED50;

extern int D_006AED74;

int sceSifInitRpc(int mode);

int sceSifBindRpc(int *rd, unsigned int rpc_id, unsigned int mode);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BD60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BDF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BE60);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BEE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BF30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013BFB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C1C0);

// initialize SIF RPC, bind to 0x534D5300, and clear globals once bound
int func_0013C250(void)
{
    int i;
    int *p;

    sceSifInitRpc(0);
    do {
        if (sceSifBindRpc(&D_006AED50, 0x534D5300, 0) < 0)
            return -1;
    } while (D_006AED74 == 0);

    p = D_006AED40;
    i = 0;
    do {
        i++;
        *p = 0;
        p++;
    } while (i < 2);

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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C820);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013C830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D060);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D220);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013BD60", func_0013D280);
