#ifndef GAME_00_OBJ90_H
#define GAME_00_OBJ90_H
#include "types.h"
/* The object behind the function-pointer table D_0069C2C0 and the tables in
   D_0069D4B0 that repeat its slots: func_0012BA70 and func_0012BA80, two adjacent
   slots, return member addresses in it. No matched function reads either member,
   so their types are not known. */
typedef struct Obj90 {
    unsigned char unk_00[0x90];
    u8 unk_90;
    unsigned char unk_91[0xF];
    u8 unk_A0;
} Obj90;
#endif
