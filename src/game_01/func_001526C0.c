#include "common.h"

typedef struct Obj {
    u8 unk_00[0x2C0];
    Vec unk_2C0;
    u8 unk_2D0[0xD0];
    Vec unk_3A0;
} Obj;

extern Vec D_006AF4B0;
extern void func_0012E9A0(Vec *a, Vec *b, Vec *out, f32 t);

Vec *func_001526C0(Obj *o)
{
    func_0012E9A0(&o->unk_3A0, &o->unk_2C0, &D_006AF4B0, 0.75f);
    return &D_006AF4B0;
}
