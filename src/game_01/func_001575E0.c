#include "common.h"

typedef struct Slot {
    u8 unk_00;
    u8 unk_01[0x3F];
} Slot;

typedef struct Obj {
    u8 unk_00[0x50];
    u8 unk_50;
    u8 unk_51[0x1F];
    Slot unk_70[8];
} Obj;

extern void func_00157920(Obj *arg0, s32 arg1);

void func_001575E0(Obj *arg0)
{
    s32 i;

    if (arg0->unk_50 != 0) {
        for (i = 0; i < 8; i++) {
            if (arg0->unk_70[i].unk_00 != 0) {
                func_00157920(arg0, i);
            }
        }
    }
}
