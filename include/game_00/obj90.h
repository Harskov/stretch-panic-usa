#ifndef GAME_00_OBJ90_H
#define GAME_00_OBJ90_H
#include "types.h"
/* The object behind the function-pointer table D_0069C2C0 and the tables in
   D_0069D4B0 that repeat its slots: func_0012BA70 and func_0012BA80, two adjacent
   slots, return member addresses in it (no function written so far reads either
   member, so their types are not known); func_0012B2D0, another slot, copies out the
   word at 0xE4. */
typedef struct Obj90 {
    unsigned char unk_00[0x90];
    u8 unk_90;
    unsigned char unk_91[0xF];
    u8 unk_A0;
    unsigned char unk_A1[0x43];
    /* 0xE4 */ s32 unk_E4;
} Obj90;
#endif
