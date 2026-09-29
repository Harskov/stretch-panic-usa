#ifndef GAME_01_NODE90_H
#define GAME_01_NODE90_H
#include "types.h"
/* The objects on the list headed by D_006AF4C8, linked through +0x90 and walked by
   func_0014EA70 (stores a quadword at +0xA0 and sets the byte at +0x98),
   func_0014EAB0 (collects the quadword at +0x310) and func_0014EAF0 (sets bit 4 of
   the flag word at +0x60). func_0014DF80 tests that bit and sets the state word at
   +0x364 from the float at +0x4D0; func_0014EB30 calls func_0014EAF0 with its object,
   clears +0x364 and sets bits in +0x64/+0x68: the same object. */
typedef struct ListNode {
    u8 unk_00[0x60];
    s32 flags;
    u32 unk_64;
    u32 unk_68;
    u8 unk_6C[0x24];
    struct ListNode *next;
    u8 unk_94[4];
    u8 unk_98;
    u8 unk_99[7];
    u128 unk_A0;
    u8 unk_B0[0x260];
    u128 unk_310;
    u8 unk_320[0x44];
    s32 unk_364;
    u8 unk_368[0x168];
    f32 unk_4D0;
} ListNode;

extern ListNode *D_006AF4C8;

void func_0014EAF0(ListNode *arg0);
#endif
