#include "common.h"

/* The 48 bytes copied in one go: three quads loaded before the first store. */
typedef struct Quad3 {
    u128 unk_00;
    u128 unk_10;
    u128 unk_20;
} Quad3;

typedef struct Obj3A0 {
    u8 unk_00[0x314];
    u8 unk_314;
    u8 unk_315[0x8B];
    Quad3 unk_3A0;
} Obj3A0;

typedef struct Obj80 {
    u8 unk_00[0x80];
    Quad3 unk_80;
} Obj80;

void func_001525D0(Obj3A0 *d, Obj80 *s)
{
    d->unk_314 = 1;
    d->unk_3A0 = s->unk_80;
}
