#include "common.h"
#include "game_01/pool70.h"

typedef struct Obj {
    unsigned char unk_00[0x54];
    int count;
} Obj;

extern void func_00158130(Pool70 *p, s32 i);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157D60);

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

int func_00157E60(Pool70 *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->slots[i].active == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157EA0);

void func_001580D0(Pool70 *p, int i) {
    p->slots[i].pos_x += p->slots[i].vel_x;
    p->slots[i].pos_y += p->slots[i].vel_y;
    p->slots[i].pos_z += p->slots[i].vel_z;
    if (p->slots[i].pos_z < 0.0f) {
        p->slots[i].active = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158130);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158470);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001584D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001585F0);

int func_00158670(Obj *o) {
    return o->count-- > 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158690);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001586E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158B70);
