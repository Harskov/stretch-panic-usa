#include "common.h"

s32 func_00172A40(s32 *arg0, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = *arg1;
    if (temp_v0 != 0) {
        *arg1 = temp_v0 - 1;
        if (*arg1 == 0) {
            *arg0 = 0;
        }
        return 1;
    }
    return 0;
}
