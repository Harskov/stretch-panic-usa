#include "common.h"

typedef struct Entry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8  unk_10[0x8];
    f32 unk_18;
    u8  unk_1C[0x4];
} Entry;

typedef struct Holder {
    u8 unk_00[0x60];
    Entry *unk_60;
} Holder;

typedef struct Obj {
    u8 unk_00[0x530];
    s32 unk_530[2];
    u8 unk_538[2];
    u8 unk_53A[0x32];
    Holder *unk_56C;
} Obj;

extern s32 *D_006A6D10;
extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

void func_0014E490(Obj *o, s32 kind, f32 v)
{
    s32 i;
    s32 n;
    s32 lo;
    s32 code;

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

    n = (s32)v;
    for (i = 0; i < 2; i++) {
        lo = o->unk_530[i];
        if (n < lo || lo + 2 < n) {
            o->unk_538[i] = 0;
        } else if (o->unk_538[i] == 0) {
            o->unk_538[i] = 1;
            code = (i & 1) ? 2 : 3;
            o->unk_56C->unk_60->unk_18 = 0.6f;
            o->unk_56C->unk_60->unk_00 =
                func_0013DF50(o->unk_56C->unk_60->unk_00, D_006A6D10[1], code,
                              o->unk_56C->unk_60->unk_04, o->unk_56C->unk_60->unk_0C,
                              o->unk_56C->unk_60->unk_08);
        }
    }
}
