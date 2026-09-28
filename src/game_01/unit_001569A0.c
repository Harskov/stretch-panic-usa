#include "common.h"
#include "game_01/pool70.h"

typedef struct Slot {
    u8 unk_00;
    u8 unk_01[0x3F];
} Slot;

typedef struct Obj {
    u8 unk_00[0x50];
    u8 unk_50;
    u8 unk_51[0x1F];
    Slot unk_70[8];
} Obj;

typedef struct Slot_00157650 {
    unsigned char unk_00[0x40];
} Slot_00157650;

extern void func_00157920(Obj *arg0, s32 arg1);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_001569A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00156A70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00156B40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00156DC0);

void func_00156E20(void) {
}

void func_00156E30(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00156E40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157010);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157070);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_001571D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_001574B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157550);

void func_001575E0(Obj *arg0)
{
    s32 i;

    if (arg0->unk_50 != 0) {
        for (i = 0; i < 8; i++) {
            if (arg0->unk_70[i].unk_00 != 0) {
                func_00157920(arg0, i);
            }
        }
    }
}

int func_00157650(Slot_00157650 *s) {
    int i;

    for (i = 0; i < 8; i++) {
        if (s->unk_00[0x70] == 0) {
            return i;
        }
        s++;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157690);

void func_001578C0(Pool70 *p, int i) {
    p->slots[i].pos_x += p->slots[i].vel_x;
    p->slots[i].pos_y += p->slots[i].vel_y;
    p->slots[i].pos_z += p->slots[i].vel_z;
    if (p->slots[i].pos_z < 0.0f) {
        p->slots[i].active = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157920);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001569A0", func_00157C60);
