#include "common.h"

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    int limit;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    int old;

    o->unk_E0 += o->unk_A8;
    o->unk_E4 += o->unk_E8;
    if (o->unk_E4 < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    old = o->unk_EC;
    o->unk_EC = old + 1;
    return old < o->limit;
}
