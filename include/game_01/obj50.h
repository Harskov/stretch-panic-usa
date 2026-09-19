#ifndef GAME_01_OBJ50_H
#define GAME_01_OBJ50_H
#include "common.h"
/* The object carrying a position/velocity vector pair at +0x50/+0x60, agreed by
   func_001733C0, func_00173C00 and func_001741B0: all three integrate it with the
   same VU0 macro-mode block (lqc2 pos, lqc2 vel, vadd.xyz, sqc2 pos), all three open
   by scaling +0x70 by +0x74 and +0x74 by +0x78, and all three add a per-frame
   increment into the counter at +0x9C and return 0 once it has fallen to zero. The
   increment is the one field they do not share: func_001733C0 reads it from +0x8C,
   func_00173C00 and func_001741B0 from +0xA0 — different fields of one object, so
   the struct carries both. No function reaches +0x00..+0x4F, +0x84..+0x8B or
   +0x90..+0x9B. */
typedef struct Obj50 {
    unsigned char unk_00[0x50];
    Vec pos;
    Vec vel;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    unsigned char unk_84[8];
    f32 unk_8C;
    unsigned char unk_90[0xC];
    f32 unk_9C;
    f32 unk_A0;
} Obj50;
#endif
