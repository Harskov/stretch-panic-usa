#include "common.h"
typedef struct Child Child;
typedef struct Vtbl { u8 unk_00[0x8]; void (*unk_08)(Child *, s32); } Vtbl;
struct Child { Vtbl *vtbl; };
typedef struct Obj { u8 unk_00[0xB0]; Child *unk_B0; } Obj;
void func_00159EE0(Obj *o)
{
    Child *c;
    c = o->unk_B0;
    if (c != 0) {
        (*c->vtbl->unk_08)(c, 1);
    }
}
