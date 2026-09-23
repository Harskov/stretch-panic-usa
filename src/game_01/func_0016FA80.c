#include "common.h"

extern s32 D_00601A50;

s32 func_0016FA80(s32 mask)
{
    D_00601A50 = D_00601A50 * 5 + 1;
    return (D_00601A50 >> 8) & mask;
}
