#include "common.h"
#include "game_01/obj80.h"

typedef struct Obj3A0 {
    u8 unk_00[0x314];
    u8 unk_314;
    u8 unk_315[0x8B];
    Quad3 unk_3A0;
} Obj3A0;

void func_001525D0(Obj3A0 *d, Obj80 *s)
{
    d->unk_314 = 1;
    d->unk_3A0 = s->unk_80;
}
