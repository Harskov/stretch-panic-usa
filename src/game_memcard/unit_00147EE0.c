#include "common.h"
#include "game_memcard/unit_001463F0.h"

extern s32 D_006AEF90;

void func_00146700();

void func_00147EE0(void)
{
    func_00146700(&D_006AEF90);
}

s32 func_00147EF0(s32 arg0, const void *arg1, s32 arg2)
{
    s32 r;

    r = func_001467E0(arg0, arg1, arg2);
    if (r >= 0)
        r = 0;
    return r;
}

s32 func_00147F20(s32 arg0)
{
    s32 r;

    r = func_001468E0(arg0);
    if (r == 0 || r == -3)
        return r;
    return -1;
}

s32 func_00147F50(const char *arg0)
{
    return func_00146600(arg0);
}
