#ifndef GAME_01_OBJ1F0_H
#define GAME_01_OBJ1F0_H
#include "types.h"
/* The object whose two quadwords at +0x10 and +0x30 are saved to and restored from
   the backup pair at +0x1F0/+0x200, agreed by func_00159E20, func_0015B500 and
   func_0015BA00. func_0015B500 writes the backup pair from +0x10/+0x30, func_0015BA00
   reads it back, and func_00159E20 restores from a second pair at +0x230/+0x240.
   The flag word at +0x60 takes bit 0x80000 in all three callers' families; it is u32
   because func_00159E20 and func_0015BA00 only ever OR into it. Two vtables reach this
   layout (D_0069CA00 slot +0x20 and D_0069CA40 slots +0x18/+0x20), so it is the shared
   part of a base class, not one class's object. */
typedef struct Sub54 {
    unsigned char unk_00[0x54];
    int unk_54;
} Sub54;

typedef struct Owner1F0 {
    unsigned char unk_00[0x80];
    f32 unk_80;
    unsigned char unk_84[0x44];
    Sub54 *unk_C8;
} Owner1F0;

typedef struct Obj1F0 {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x20];
    u32 unk_60;
    unsigned char unk_64[0x16C];
    u8 unk_1D0;
    unsigned char unk_1D1[7];
    s32 unk_1D8;
    unsigned char unk_1DC[0x14];
    u128 unk_1F0;
    u128 unk_200;
    unsigned char unk_210[0x20];
    u128 unk_230;
    u128 unk_240;
    f32 unk_250;
    f32 unk_254;
    f32 unk_258;
    f32 unk_25C;
    unsigned char unk_260[0x30];
    f32 unk_290;
    f32 unk_294;
    f32 unk_298;
    f32 unk_29C;
} Obj1F0;
#endif
