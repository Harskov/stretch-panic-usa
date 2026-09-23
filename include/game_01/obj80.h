#ifndef GAME_01_OBJ80_H
#define GAME_01_OBJ80_H
#include "types.h"
/* The object whose 48 bytes at +0x80 are copied whole into another object by
   func_001525D0, func_00152600 and func_00162900: each sets a byte flag on the
   destination, then loads all three quadwords before the first store. */
typedef struct Quad3 {
    u128 unk_00;
    u128 unk_10;
    u128 unk_20;
} Quad3;

typedef struct Obj80 {
    u8 unk_00[0x80];
    Quad3 unk_80;
} Obj80;
#endif
