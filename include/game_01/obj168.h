#ifndef GAME_01_OBJ168_H
#define GAME_01_OBJ168_H
#include "types.h"
/* The object holding the counter pair at +0x164/+0x168, agreed by func_0016DC80 and
   func_0016DCD0: func_0016DC80 counts +0x168 down and, when it reaches zero, clears
   bit 0x04000000 of the flag word at +0x60 and zeroes +0x164; func_0016DCD0 copies
   both words from one object of this layout to another. func_0016DC30 passes the
   object and its word at +0x134 to func_0016DC40, which stores that word at +0x164. The flag word at +0x60 is the
   offset Obj1F0 (include/game_01/obj1F0.h) also carries a flag word at, but no
   function reaches both layouts, so they are kept apart. */
typedef struct Obj168 {
    unsigned char unk_00[0x60];
    u32 flags;
    unsigned char unk_64[0xD0];
    s32 unk_134;
    unsigned char unk_138[0x2C];
    s32 unk_164;
    s32 unk_168;
} Obj168;

void func_0016DC40(Obj168 *arg0, s32 arg1);
#endif
