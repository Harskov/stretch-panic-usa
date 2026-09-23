#include "common.h"

typedef struct Quad {
    u128 q;
} Quad;

extern Quad D_00601A40;
extern void func_0016EFC0(void *arg0, Quad *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);

void func_0016D620(void *arg0, s32 arg1)
{
    Quad tmp;

    tmp = D_00601A40;
    func_0016EFC0(arg0, &tmp, arg1, 0, 0.75f, 0.0f);
}
