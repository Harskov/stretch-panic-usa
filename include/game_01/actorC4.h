#ifndef GAME_01_ACTORC4_H
#define GAME_01_ACTORC4_H
#include "types.h"
/* The second parameter of func_00159860 and func_0015B540: both pass it and the
   address of its +0x80 to func_00131B30, and both test whether the word at +0x54
   of the object at +0xC4 is 4. */
typedef struct Info {
    u8 unk_00[0x54];
    s32 unk_54;
} Info;

typedef struct Actor {
    u8 unk_00[0x80];
    u8 unk_80[0x44];
    Info *unk_C4;
} Actor;
#endif
