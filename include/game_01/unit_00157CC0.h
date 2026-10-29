#ifndef GAME_01_UNIT_00157CC0_H
#define GAME_01_UNIT_00157CC0_H
#include "common.h"
/* The block func_001584D0 reads its settings from: func_00159520 and func_0015BA80 each fill
   one on the stack and pass its address as the second argument. */
typedef struct Sub_001584D0 {
    /* 0x00 */ Quad unk_0;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} Sub_001584D0;

struct Obj_001584D0;
struct Obj_001584D0 *func_001584D0(struct Obj_001584D0 *self, Sub_001584D0 *desc);
#endif
