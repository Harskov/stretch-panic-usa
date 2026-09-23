#include "common.h"
#include "game_01/obj80.h"

typedef struct Dst {
    u8 unk_00[0x28C];
    u8 unk_28C;
    u8 unk_28D[0x83];
    Quad3 unk_310;
} Dst;

void func_00162900(Dst *d, Obj80 *s)
{
    d->unk_28C = 1;
    d->unk_310 = s->unk_80;
}
