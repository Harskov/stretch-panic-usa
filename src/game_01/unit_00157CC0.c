#include "common.h"
#include "game_01/pool70.h"

typedef struct Obj {
    unsigned char unk_00[0x54];
    int count;
} Obj;

extern void func_00158130(Obj270 *p, s32 i);

extern s32 D_0069C9A0;

void func_00172E80();

void __dl__FPv(void *);

typedef struct Obj_00158690 {
    unsigned char unk_0[0x50];
    int unk_50;
} Obj_00158690;

typedef struct Obj_006A6730 {
    unsigned char unk_0[0x378];
    int unk_378;
    unsigned char unk_37C[0x184];
    int unk_500[1];
} Obj_006A6730;

extern Obj_006A6730 *D_006A6730;

extern int D_006A6D18;

void func_0013BD20();

void func_0013BFB0();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157CC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157D60);

void func_00157DF0(Obj270 *p)
{
    s32 i;

    if (p->unk_50 != 0) {
        for (i = 0; i < 8; i++) {
            if (p->unk_70[i].unk_0 != 0) {
                func_00158130(p, i);
            }
        }
    }
}

int func_00157E60(Obj270 *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->unk_70[i].unk_0 == 0) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00157EA0);

void func_001580D0(Obj270 *p, int i) {
    p->unk_70[i].unk_20 += p->unk_70[i].unk_24;
    p->unk_70[i].unk_28 += p->unk_70[i].unk_2C;
    p->unk_70[i].unk_30 += p->unk_70[i].unk_34;
    if (p->unk_70[i].unk_30 < 0.0f) {
        p->unk_70[i].unk_0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158130);

s32 **func_00158470(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C9A0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001584D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001585F0);

int func_00158670(Obj *o) {
    return o->count-- > 0;
}

void func_00158690(Obj_00158690 *arg0) {
    func_0013BD20(arg0->unk_50, D_006A6730->unk_500[D_006A6730->unk_378]);
    func_0013BFB0(D_006A6D18, arg0->unk_50);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_001586E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00157CC0", func_00158B70);
