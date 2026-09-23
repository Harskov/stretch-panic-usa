#ifndef GAME_01_NODE90_H
#define GAME_01_NODE90_H
#include "types.h"
/* The objects on the list headed by D_006AF4C8, linked through +0x90 and walked by
   func_0014EA70 (stores a quadword at +0xA0 and sets the byte at +0x98),
   func_0014EAB0 (collects the quadword at +0x310) and func_0014EAF0 (sets bit 4 of
   the flag word at +0x60). */
typedef struct ListNode {
    u8 unk_00[0x60];
    s32 flags;
    u8 unk_64[0x2C];
    struct ListNode *next;
    u8 unk_94[4];
    u8 unk_98;
    u8 unk_99[7];
    u128 unk_A0;
    u8 unk_B0[0x260];
    u128 unk_310;
} ListNode;

extern ListNode *D_006AF4C8;
#endif
