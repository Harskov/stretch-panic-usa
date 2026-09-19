#include "types.h"

/* The object the global pointer D_006A6B90 holds. Only this function reaches it so
   far, so the layout stays local: two float triples at +0x30 and +0x40 that this
   function integrates, each preceded by a float (+0x2C, +0x3C) and followed at +0x1C
   and +0x4C by the two floats it stores outright. */
typedef struct Obj6A6B90 {
    unsigned char unk_00[0x1C];
    f32 unk_1C;
    unsigned char unk_20[0xC];
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} Obj6A6B90;

extern Obj6A6B90 *D_006A6B90;

void func_00172410(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5, f32 x6, f32 x7) {
    Obj6A6B90 *q;

    D_006A6B90->unk_1C = x6;
    D_006A6B90->unk_2C = x6;
    D_006A6B90->unk_3C = x7;
    D_006A6B90->unk_4C = x7;
    q = D_006A6B90;
    q->unk_30 = q->unk_30 + x0;
    q->unk_34 = q->unk_34 + x1;
    q->unk_38 = q->unk_38 + x2;
    q = D_006A6B90;
    q->unk_40 = q->unk_40 + x3;
    q->unk_44 = q->unk_44 + x4;
    q->unk_48 = q->unk_48 + x5;
}
