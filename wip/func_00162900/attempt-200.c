#include "common.h"

/* The 48 bytes copied in one go: three quads loaded before the first store. */
typedef struct Quad3 {
    u128 unk_00;
    u128 unk_10;
    u128 unk_20;
} Quad3;

typedef struct Dst {
    u8 unk_00[0x28C];
    u8 unk_28C;
    u8 unk_28D[0x83];
    Quad3 unk_310;
} Dst;

typedef struct Src {
    u8 unk_00[0x80];
    Quad3 unk_80;
} Src;

void func_00162900(Dst *d, Src *s)
{
    d->unk_28C = 1;
    d->unk_310 = s->unk_80;
}
