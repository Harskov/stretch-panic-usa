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

typedef struct Obj {
    u8 unk_00[0x60];
    Entry *unk_60;
} Obj;

extern s32 *D_006A6D10;
extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

void func_0016BED0(s32 mode, u32 flags, Obj *o, s32 idx, f32 v)
{
    u8 big;
    s32 code;
    s32 sel;
    f32 f;

    big = v > 0.9f;
    if (mode == 0) {
        if (flags & 0x20000) {
            f = 0.85f;
            code = big ? 0xD : 0xE;
            sel = 0;
        } else if (flags & 0x8000000) {
            f = 1.0f;
            code = big ? 0xF : 0x10;
            sel = 0;
        } else {
            f = 1.0f;
            code = big ? 0xB : 0xC;
            sel = 0;
        }
    } else if (mode == 3) {
        f = 1.0f;
        code = 0x16;
        sel = 0;
    } else if (mode == 4 || mode == 2 || mode == 1) {
        f = 1.0f;
        code = 0x15;
        sel = 0;
    }
    o->unk_60[idx].unk_18 = f;
    o->unk_60[idx].unk_00 = func_0013DF50(o->unk_60[idx].unk_00, D_006A6D10[sel], code,
                                          o->unk_60[idx].unk_04, o->unk_60[idx].unk_0C,
                                          o->unk_60[idx].unk_08);
}
