#ifndef GAME_01_SCRATCHPAD_H
#define GAME_01_SCRATCHPAD_H
#include "common.h"
/* 0x70000000 is the Emotion Engine's scratchpad RAM. The quadword at +0xBE0 in it is
   loaded whole by func_0016D8A0 and by nine functions between func_001496C0 and
   func_0014D930, and func_0016FA20 returns its address. */
#define SPR_QUAD ((Quad *)0x70000BE0)
#endif
