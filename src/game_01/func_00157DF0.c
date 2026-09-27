#include "common.h"
#include "game_01/pool70.h"

extern void func_00158130(Pool70 *p, s32 i);

void func_00157DF0(Pool70 *p)
{
    s32 i;

    if (p->unk_50 != 0) {
        for (i = 0; i < 8; i++) {
            if (p->slots[i].active != 0) {
                func_00158130(p, i);
            }
        }
    }
}
