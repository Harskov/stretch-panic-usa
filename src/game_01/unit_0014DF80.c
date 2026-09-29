#include "common.h"
#include "game_01/node90.h"
#include "game_01/obj530.h"

typedef struct Ctrl {
    u8 unk_00[0x60];
    u32 unk_60;
} Ctrl;

extern s32 *D_006A6D10;

extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

extern Ctrl *D_006AF4D8;

void func_0014DF80(ListNode *arg0) {
    if (arg0->flags & 4) {
        if (arg0->unk_4D0 < 0.415625f) {
            arg0->unk_364 = 0xE;
        }
        if (arg0->unk_4D0 < 0.115625f) {
            arg0->unk_364 = 0xD;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014DFF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E090);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E120);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E190);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E390);

void func_0014E460(Obj530 *arg0) {
    s32 i;

    i = 0;
    do {
        arg0->unk_530[i] = 0;
        arg0->unk_538[i] = 0;
        i += 1;
    } while (i < 2);
}

void func_0014E490(Obj530 *o, s32 kind, f32 v)
{
    s32 i;
    register f32 fv;
    register f32 f;
    register s32 n;
    s32 lo;
    s32 code;
    Holder *g;
    Holder *h;

    switch (kind) {
    case 0x26:
        o->unk_530[0] = 0;
        o->unk_530[1] = 0x14;
        break;
    case 0x19:
        o->unk_530[0] = 0xA;
        o->unk_530[1] = 0x1E;
        break;
    case 0x1B:
        o->unk_530[0] = 0xA;
        o->unk_530[1] = 0x28;
        break;
    case 6:
    case 5:
        o->unk_530[0] = 0;
        o->unk_530[1] = 0x14;
        break;
    case 0x25:
        o->unk_530[0] = 0xA;
        o->unk_530[1] = 0x28;
        break;
    default:
        o->unk_530[0] = 0x3E7;
        o->unk_530[1] = 0x3E7;
        break;
    }

    fv = v;
    asm {
        cvt.w.s f, fv
        mfc1 n, f
    }
    for (i = 0; i < 2; i++) {
        lo = o->unk_530[i];
        if (n >= lo && n <= lo + 2) {
            if (o->unk_538[i] == 0) {
                o->unk_538[i] = 1;
                if (i & 1) {
                    code = 2;
                } else {
                    code = 3;
                }
                g = o->unk_56C;
                g->unk_60->unk_18 = 0.6f;
                h = o->unk_56C;
                h->unk_60->unk_00 = func_0013DF50(h->unk_60->unk_00, D_006A6D10[1], code,
                                                  h->unk_60->unk_04, h->unk_60->unk_0C,
                                                  h->unk_60->unk_08);
            }
        } else {
            o->unk_538[i] = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E650);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0014DF80", func_0014E7D0);

void func_0014EA70(s32 arg0, u128 *arg1) {
    ListNode *p;
    p = D_006AF4C8;
    while (p != 0) {
        p->unk_A0 = *arg1;
        p->unk_98 = 1;
        p = p->next;
    }
}

void func_0014EAB0(ListNode *arg0, u128 *arg1) {
    ListNode *p = D_006AF4C8;
    while (p != 0) {
        *arg1 = p->unk_310;
        p = p->next;
        arg1++;
    }
}

void func_0014EAF0(ListNode *arg0) {
    ListNode *p = D_006AF4C8;
    while (p != 0) {
        p->flags |= 4;
        p = p->next;
    }
}

void func_0014EB30(ListNode *arg0)
{
    func_0014EAF0(arg0);
    arg0->unk_364 = 0;
    arg0->unk_64 |= 1;
    arg0->unk_68 |= 7;
    if (D_006AF4D8 != 0) {
        D_006AF4D8->unk_60 |= 0x10000;
    }
}
