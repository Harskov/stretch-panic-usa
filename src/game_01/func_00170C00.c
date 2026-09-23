#include "common.h"

extern s32 D_00601A80;

s32 *func_00170C00(s32 arg0) {
    s32 *p = &D_00601A80;
    return p + arg0 * 4;
}
