#ifndef GAME_01_OBJ530_H
#define GAME_01_OBJ530_H
#include "types.h"
/* The object with two thresholds at +0x530 and two latch bytes at +0x538:
   func_0014E460 clears both pairs, func_0014E490 sets the thresholds by kind and
   latches a byte when the value falls in a threshold's window. The holder at +0x56C
   points to an Entry array; func_0016BED0 reaches the same array through a Holder
   passed directly and calls func_0013DF50 with the same four Entry words. */
typedef struct Entry {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    u8  unk_10[0x8];
    f32 unk_18;
    u8  unk_1C[0x4];
} Entry;

typedef struct Holder {
    u8 unk_00[0x60];
    Entry *unk_60;
} Holder;

typedef struct Obj530 {
    u8 unk_00[0x530];
    s32 unk_530[2];
    u8 unk_538[2];
    u8 unk_53A[0x32];
    Holder *unk_56C;
} Obj530;
#endif
