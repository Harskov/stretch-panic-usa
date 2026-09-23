#include "common.h"

void func_001522E0(char *arg0, char *arg1) {
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = *(f32 *)(arg0 + 0x410) * *(f32 *)(arg0 + 0x410);
}
