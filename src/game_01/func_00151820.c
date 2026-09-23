#include "common.h"

extern s32 D_006AF0A0[];
extern s32 D_006AF0A4[];
extern s32 D_006AF4A0;

void func_00151820(s32 arg0) {
    s32 idx;

    if (arg0 > 0) {
        D_006AF0A0[((D_006AF4A0 + 0x5A) % 128) * 2] += arg0;
    }
    if (arg0 < 0) {
        D_006AF0A4[((D_006AF4A0 + 0x10) % 128) * 2] += arg0;
    }
}
