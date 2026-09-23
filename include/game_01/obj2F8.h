#ifndef GAME_01_OBJ2F8_H
#define GAME_01_OBJ2F8_H
#include "types.h"
/* The object with a backup pair for the two words at +0x64/+0x68, agreed by
   func_0016E740 and func_0016E760: func_0016E740 copies +0x64/+0x68 into
   +0x2F8/+0x2FC and func_0016E760 copies them back, so the two functions are the
   save and restore halves of one operation on one layout.

   The same object carries a state: func_00179DF0, func_00179E80, func_0017A3D0,
   func_0017A5B0, func_0017A640 and func_0017A950 each store a state number at
   +0x2B0 (0, 1, 4, 5, 6, 7), a count at +0x178 and a word at +0x180, and clear
   +0x2B4..+0x2BC. func_0017A3D0, func_0017A5B0, func_0017A640 and func_0017A950
   then pass the object unchanged to func_0016E760, and func_0017B170, which stores
   a vtable at +0x00 and writes +0x64/+0x68, is the only caller of both
   func_00179DF0 and func_0016E740. The words stored at +0x180 are the bit patterns
   of 0.5, 1.0 and 2.0, stored from integer registers, so the field stays s32. */
typedef struct Obj2F8 {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x44];
    s32 unk_64;
    s32 unk_68;
    unsigned char unk_6C[0x10C];
    s32 unk_178;
    unsigned char unk_17C[4];
    s32 unk_180;
    unsigned char unk_184[0x12C];
    s32 unk_2B0;
    s32 unk_2B4;
    s32 unk_2B8;
    s32 unk_2BC;
    unsigned char unk_2C0[0x30];
    s32 unk_2F0;
    unsigned char unk_2F4[4];
    s32 unk_2F8;
    s32 unk_2FC;
    unsigned char unk_300[0x1E9];
    u8 unk_4E9;
    unsigned char unk_4EA[0x26];
    u128 unk_510;
} Obj2F8;
#endif
