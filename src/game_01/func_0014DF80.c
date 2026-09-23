#include "common.h"

typedef struct Node {
    u8 pad[0x60];
    s32 flags;
    u8 pad2[0x364 - 0x64];
    s32 unk_364;
    u8 pad3[0x4D0 - 0x368];
    f32 unk_4D0;
} Node;

void func_0014DF80(Node *arg0) {
    if (arg0->flags & 4) {
        if (arg0->unk_4D0 < 0.415625f) {
            arg0->unk_364 = 0xE;
        }
        if (arg0->unk_4D0 < 0.115625f) {
            arg0->unk_364 = 0xD;
        }
    }
}
