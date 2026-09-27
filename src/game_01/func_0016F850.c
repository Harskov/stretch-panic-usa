#include "common.h"

typedef struct Inner {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} Inner;

typedef struct Mid {
    u8 unk_00[0x60];
    Inner *unk_60;
} Mid;

typedef struct Obj {
    u8 unk_00[0x10C];
    Mid *unk_10C;
} Obj;

extern s32 *D_006A6D10;
extern s32 func_0013DF50(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

void func_0016F850(Obj *o)
{
    Mid *m;

    o->unk_10C->unk_60->unk_10 = 12566371.0f;
    o->unk_10C->unk_60->unk_14 = 1000.0f;
    o->unk_10C->unk_60->unk_18 = 1.0f;
    m = o->unk_10C;
    m->unk_60->unk_00 = func_0013DF50(m->unk_60->unk_00, *D_006A6D10, 0x13,
                                      m->unk_60->unk_04, m->unk_60->unk_0C, m->unk_60->unk_08);
}
