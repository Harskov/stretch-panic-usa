#ifndef GAME_00_OBJ_001211E0_H
#define GAME_00_OBJ_001211E0_H
#include "common.h"
/* The object func_001211E0 initialises and publishes in D_006A66F8; the start-up code
   in unit_0011F5E0 allocates it and passes it back to the unit's functions. */
typedef struct Obj_001211E0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ u8  unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} Obj_001211E0;

extern Obj_001211E0 *D_006A66F8;

Obj_001211E0 *func_001211E0(Obj_001211E0 *o);
#endif
