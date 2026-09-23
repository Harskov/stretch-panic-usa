#include "common.h"
#include "game_01/obj530.h"

extern s32 *D_006A6D10;
extern s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

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
