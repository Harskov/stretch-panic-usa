#include "common.h"
#include "game_01/rec10.h"
#include "game_01/obj530.h"

typedef struct Node {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x10];
    struct Node *next;
} Node;

extern s32 *D_006A6D10;

extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

extern Node *D_006A6C38;

Rec10 *func_0016BDF0(Rec10 *arg0) {
    arg0->unk_00 = 0;
    arg0->unk_04 = 0;
    arg0->unk_08 = 0;
    arg0->unk_0C = 0;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016BE10);

void func_0016BE80(Rec10 *arg0, s32 arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04 = 0;
    arg0->unk_08 = arg1;
    arg0->unk_0C = 0;
}

u8 func_0016BEA0(Rec10 *arg0) {
    return arg0->unk_0C;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016BEB0);

void func_0016BED0(s32 mode, u32 flags, Holder *o, s32 idx, f32 v)
{
    s32 sel;
    u8 big;
    s32 code;
    f32 f;

    if (v > 0.9f) {
        big = 1;
    } else {
        big = 0;
    }
    if (mode == 0) {
        if (flags & 0x20000) {
            f = 0.85f;
            sel = 0;
            code = big ? 0xD : 0xE;
        } else if (flags & 0x8000000) {
            f = 1.0f;
            sel = 0;
            code = big ? 0xF : 0x10;
        } else {
            f = 1.0f;
            sel = 0;
            code = big ? 0xB : 0xC;
        }
    } else {
        switch (mode) {
        case 1:
        case 2:
        case 4:
            f = 1.0f;
            code = 0x15;
            sel = 0;
            break;
        case 3:
            f = 1.0f;
            code = 0x16;
            sel = 0;
            break;
        }
    }
    o->unk_60[idx].unk_18 = f;
    o->unk_60[idx].unk_00 = func_0013DF50(o->unk_60[idx].unk_00, D_006A6D10[sel], code,
                                          o->unk_60[idx].unk_04, o->unk_60[idx].unk_0C,
                                          o->unk_60[idx].unk_08);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C150);

void func_0016C260(void) {
    Node *p = D_006A6C38;
    if (p != 0) {
        do {
            p->flags |= 0x10000;
            p = p->next;
        } while (p != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C2A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C3B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016BDF0", func_0016C480);
