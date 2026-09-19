#ifndef GAME_01_OBJ2F8_H
#define GAME_01_OBJ2F8_H
#include "types.h"
/* The object with a backup pair for the two words at +0x64/+0x68, agreed by
   func_0016E740 and func_0016E760: func_0016E740 copies +0x64/+0x68 into
   +0x2F8/+0x2FC and func_0016E760 copies them back, so the two functions are the
   save and restore halves of one operation on one layout. No function reaches
   +0x00..+0x63 or +0x6C..+0x2F7. */
typedef struct Obj2F8 {
    unsigned char unk_00[0x64];
    s32 unk_64;
    s32 unk_68;
    unsigned char unk_6C[0x28C];
    s32 unk_2F8;
    s32 unk_2FC;
} Obj2F8;
#endif
