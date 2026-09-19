#include "common.h"

extern s32 D_00601BD0[];
extern s32 D_006B3580[];
extern s32 D_006B3700[];
extern s32 D_006B3880;
extern s32 D_006B3888;

void func_00172F60(void)
{
    s32 i;

    for (i = 0; i < 0x5F; i++) {
        D_006B3700[i] = 0;
    }

    D_006B3880 = 0;
    D_006B3888 = 0;

    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x1C] = D_00601BD0[i];
    }
    for (i = 0; i != 0x1C; i++) {
        D_006B3580[i + 0x38] = D_00601BD0[i];
    }
    for (i = 0; i != 0xB; i++) {
        D_006B3580[i + 0x54] = 0;
    }
}
