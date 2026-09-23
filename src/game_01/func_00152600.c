#include "common.h"
#include "game_01/obj80.h"

typedef struct Obj4A0 {
    u8 unk_00[0x414];
    u8 unk_414;
    u8 unk_415[0x8B];
    Quad3 unk_4A0;
} Obj4A0;

void func_00152600(Obj4A0 *d, Obj80 *s)
{
    d->unk_414 = 1;
    d->unk_4A0 = s->unk_80;
}
