#ifndef GAME_01_POOL70_H
#define GAME_01_POOL70_H
/* The 8-entry, 0x40-byte slot array embedded at +0x70 of its owner, agreed by
   func_00157650, func_001578C0, func_001580D0 and func_00157E60: the in-use byte at
   +0x0 of a slot (tested by func_00157650 and func_00157E60, cleared by func_001578C0
   and func_001580D0), and the interleaved position/velocity floats at +0x20..+0x37
   (integrated by func_001578C0 and func_001580D0). Of the owner's first 0x70 bytes
   only the byte at +0x50 is reached: func_00157DF0 tests it before walking the slots. */
typedef struct Slot40 {
    /* 0x00 */ unsigned char unk_0;
    unsigned char unk_01[0x1F];
    /* 0x20 */ float unk_20;
    /* 0x24 */ float unk_24;
    /* 0x28 */ float unk_28;
    /* 0x2C */ float unk_2C;
    /* 0x30 */ float unk_30;
    /* 0x34 */ float unk_34;
    unsigned char unk_38[8];
} Slot40;

typedef struct Obj270 {
    unsigned char unk_00[0x50];
    unsigned char unk_50;
    unsigned char unk_51[0x1F];
    /* 0x70 */ Slot40 unk_70[8];
} Obj270;
#endif
