#ifndef GAME_01_OBJ3B0_H
#define GAME_01_OBJ3B0_H
#include "common.h"
/* The 0x3B0-byte object func_00159E80 and func_0015BD80 build: operator new, the base
   constructor func_0012AF20 with a table, then the vtable D_0069C510 and a pointer to
   the object's own buffer. */
typedef struct Obj3B0 {
    /* 0x000 */ s32 *unk_0;
    /* 0x004 */ u8 unk_4[0x24];
    /* 0x028 */ u8 *unk_28;
    /* 0x02C */ u8 unk_2C[0x4];
    /* 0x030 */ u8 unk_30[0x380];
} Obj3B0;
#endif
