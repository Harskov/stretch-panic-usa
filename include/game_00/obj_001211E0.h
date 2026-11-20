#ifndef GAME_00_OBJ_001211E0_H
#define GAME_00_OBJ_001211E0_H
#include "common.h"
/* One of the 0x44-byte entries the object below owns; func_001215E0 looks one up by
   index and func_0014E090 tests the word at +0x18 of the entry it gets back. */
typedef struct Elem_001215E0 {
    /* 0x00 */ u8  unk_0[0x18];
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u8  unk_1A[0x2A];
} Elem_001215E0;

/* The object func_001211E0 initialises and publishes in D_006A66F8; the start-up code
   in unit_0011F5E0 allocates it and passes it back to the unit's functions.
   func_001213F0 builds its table of unk_10 entries at unk_1C and the two single
   entries at unk_20 and unk_24. */
typedef struct Obj_001211E0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ u8  unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ Elem_001215E0 *unk_1C;
    /* 0x20 */ Elem_001215E0 *unk_20;
    /* 0x24 */ Elem_001215E0 *unk_24;
} Obj_001211E0;

extern Obj_001211E0 *D_006A66F8;

/* unit_00120A70.c */
Obj_001211E0 *func_001211E0(Obj_001211E0 *o);
Elem_001215E0 *func_001215E0(Obj_001211E0 *o, s32 i);
#endif
