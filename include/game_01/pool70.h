#ifndef GAME_01_POOL70_H
#define GAME_01_POOL70_H
/* The 8-entry, 0x40-byte slot array embedded at +0x70 of its owner, agreed by
   func_00157650, func_001578C0, func_001580D0 and func_00157E60: the in-use byte at
   +0x0 of a slot (tested by func_00157650 and func_00157E60, cleared by func_001578C0
   and func_001580D0), and the interleaved position/velocity floats at +0x20..+0x37
   (integrated by func_001578C0 and func_001580D0). The owner's first 0x70 bytes are
   not reached by any matched function. */
typedef struct Slot40 {
    unsigned char active;
    unsigned char unk_01[0x1F];
    float pos_x;
    float vel_x;
    float pos_y;
    float vel_y;
    float pos_z;
    float vel_z;
    unsigned char unk_38[8];
} Slot40;

typedef struct Pool70 {
    unsigned char unk_00[0x70];
    Slot40 slots[8];
} Pool70;
#endif
