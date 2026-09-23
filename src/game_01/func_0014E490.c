#include "common.h"
#include "game_01/obj530.h"

extern s32 *D_006A6D10;
extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

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
