#include "common.h"

typedef struct Child Child;

typedef struct Vtbl {
    u8 unk_00[0x8];
    void (*unk_08)(Child *, s32);
} Vtbl;

struct Child {
    Vtbl *vtbl;
};

typedef struct Obj {
    u8 unk_00[0x114];
    Child *unk_114;
} Obj;

void func_0015D4E0(Obj *o)
{
    Child *c;

    c = o->unk_114;
    if (c != 0) {
        c->vtbl->unk_08(c, 1);
    }
}
