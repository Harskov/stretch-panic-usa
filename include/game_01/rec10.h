#ifndef GAME_01_REC10_H
#define GAME_01_REC10_H
#include "types.h"
/* The 0x10-byte record agreed by func_0016BDF0, func_0016BE80 and func_0016BEA0:
   three words at +0x00/+0x04/+0x08 and a byte at +0x0C. func_0016BDF0 clears all
   four, func_0016BE80 sets +0x00 to 1, +0x04 to 0, +0x08 from its argument and
   clears +0x0C, and func_0016BEA0 returns +0x0C. The byte is unsigned: func_0016BEA0
   reads it with `lbu` (wip/func_0016BEA0/target.s @ 0x0016BEA4); the other two only
   store zero into it, which does not discriminate. */
typedef struct Rec10 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0C;
} Rec10;
#endif
