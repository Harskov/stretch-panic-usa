#include "common.h"
typedef struct Child Child;
typedef void (*Method)(Child *, s32);
struct Child { Method *vtbl; };
typedef struct Obj { u8 unk_00[0xB0]; Child *unk_B0; } Obj;
void func_00159EE0(Obj *o)
{
    Child *c;
    c = o->unk_B0;
    if (c != 0) {
        c->vtbl[2](c, 1);
    }
}
