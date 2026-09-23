#ifndef GAME_01_OBJ430_H
#define GAME_01_OBJ430_H
#include "types.h"
/* The object initialised by the pair func_00151460 and func_001514A0, agreed by
   both: each sets bit 0x04000000 of the word at +0x60, stores an s32 at +0x410
   and an f32 at +0x414, and writes a discriminator byte at +0x418 (0 in
   func_00151460, 1 in func_001514A0) before filling the 16 bytes at +0x420. The
   two functions are the two variants of one initialisation on one layout. No
   function reaches +0x00..+0x5F, +0x64..+0x40F or +0x419..+0x41F.

   The 16 bytes at +0x420 are reached at two widths, so the field is a union:
   func_00151460 writes the four words separately (0, 0, 0, 1.0f) and
   func_001514A0 copies all sixteen at once as one 128-bit quadword (lq/sq). This is a noted conflict, not a second
   struct laid over the first.

   func_001522E0 also reads +0x410, as an f32 rather than the s32 stored here,
   and reaches +0x140 and +0x270, which no function here reaches. One shared
   offset with a conflicting type is not evidence of the same object, so that
   function keeps its own view until a caller links them. */
typedef union Quad420 {
    u128 q;
    struct {
        s32 unk_00;
        s32 unk_04;
        s32 unk_08;
        f32 unk_0C;
    } w;
} Quad420;

typedef struct Obj430 {
    u8 unk_00[0x60];
    u32 unk_60;
    u8 unk_64[0x3AC];
    s32 unk_410;
    f32 unk_414;
    u8 unk_418;
    u8 unk_419[0x7];
    Quad420 unk_420;
} Obj430;
#endif
