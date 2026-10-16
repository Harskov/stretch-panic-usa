#include "common.h"
#include "game_01/pool70.h"

typedef struct Obj {
    unsigned char unk_00[0x54];
    int count;
} Obj;

extern void func_00158130(Obj270 *p, s32 i);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157D60);

void func_00157DF0(Obj270 *p)
{
    s32 i;

    if (p->unk_50 != 0) {
        for (i = 0; i < 8; i++) {
            if (p->unk_70[i].unk_0 != 0) {
                func_00158130(p, i);
            }
        }
    }
}

int func_00157E60(Obj270 *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->unk_70[i].unk_0 == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157EA0);

void func_001580D0(Obj270 *p, int i) {
    p->unk_70[i].unk_20 += p->unk_70[i].unk_24;
    p->unk_70[i].unk_28 += p->unk_70[i].unk_2C;
    p->unk_70[i].unk_30 += p->unk_70[i].unk_34;
    if (p->unk_70[i].unk_30 < 0.0f) {
        p->unk_70[i].unk_0 = 0;
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
