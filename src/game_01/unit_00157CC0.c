#include "common.h"
#include "game_01/pool70.h"
#include "game_01/unit_00157CC0.h"

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

typedef struct Elem_001584D0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} Elem_001584D0;

typedef struct Obj70 {
    u8 unk_0[0x60];
    /* 0x60 */ Elem_001584D0 *unk_60;
    u8 unk_64[0xC];
} Obj70;

typedef struct Obj_001584D0 {
    /* 0x00 */ s32 *unk_0;
    u8 unk_4[0xC];
    /* 0x10 */ Quad unk_10;
    u8 unk_20[0x30];
    /* 0x50 */ Obj70 *unk_50;
    /* 0x54 */ s32 unk_54;
} Obj_001584D0;

void * __nw__FUi(u32);

void func_0013BB20(s32 *, s32);

s32 func_0013DF50(s32, s32, s32, s32, s32, s32);

void func_00172DA0();

extern s32 D_0069C9D0;

extern s32 *D_006A6D10;

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

/* Probably a constructor: the base set-up, the vtable at +0x0 (the destructor
   func_00158470 stores its sibling table), then a 0x70-byte part built and filled
   from the description at arg1. 12.566371f is 4*pi, times the square of a radius. */
// !FAKE: the reference keeps this in a stack slot and reloads it on every use, as a C++ constructor's this would be; volatile is the C spelling that reproduces the reloads
Obj_001584D0 *func_001584D0(Obj_001584D0 *volatile self, Sub_001584D0 *desc)
{
    void *part;
    Obj70 *owned;

    func_00172DA0(self, 0x38, 0);
    self->unk_0 = &D_0069C9D0;
    self->unk_10 = desc->unk_0;
    if ((part = __nw__FUi(0x70)) != 0) {
        func_0013BB20(part, 1);
    }
    self->unk_50 = part;
    self->unk_50->unk_60->unk_10 = 12.566371f * (desc->unk_10 * desc->unk_10);
    self->unk_50->unk_60->unk_18 = desc->unk_14;
    self->unk_50->unk_60->unk_14 = desc->unk_18;
    owned = self->unk_50;
    owned->unk_60->unk_0 = func_0013DF50(owned->unk_60->unk_0, D_006A6D10[desc->unk_1C], desc->unk_20,
                                         owned->unk_60->unk_4, owned->unk_60->unk_C, owned->unk_60->unk_8);
    self->unk_54 = desc->unk_24;
    return self;
}

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
