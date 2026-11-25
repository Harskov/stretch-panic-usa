#include "common.h"

typedef struct Obj0013BD20 {
    u8 pad0[0x10];
    /* 0x10 */ Vec unk_10;
    /* 0x20 */ Vec unk_20;
    /* 0x30 */ Vec unk_30[3];
} Obj0013BD20;

extern s32 D_006A6D00;

void *__nw__FUi(u32 size);

void func_00138F80(void *obj, s32 a, s32 b, f32 x, f32 y);

typedef struct Obj_0013BC80 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x5C];
    /* 0x60 */ void *unk_60;
    u8 pad_64[0x4];
    /* 0x68 */ struct Obj_0013BC80 *link_68;
    /* 0x6C */ struct Obj_0013BC80 *link_6C;
} Obj_0013BC80;

extern s32 D_0069C718;

extern s32 D_006A6D08;

void __dla__FPv(void *p);

void __dl__FPv(void *p);

typedef struct Obj_0013B350 {
    /* 0x00 */ s32 *unk_0;
    u8 pad_4[0x60];
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
    u8 pad_6C[0x24];
    /* 0x90 */ void *unk_90;
    /* 0x94 */ void *unk_94;
    /* 0x98 */ void *unk_98;
    /* 0x9C */ void *unk_9C;
    /* 0xA0 */ void *unk_A0;
    /* 0xA4 */ void *unk_A4;
    u8 pad_A8[0x8];
    /* 0xB0 */ Vec unk_B0;
    /* 0xC0 */ Vec unk_C0;
    /* 0xD0 */ Vec unk_D0;
    /* 0xE0 */ Vec unk_E0;
    /* 0xF0 */ f32 unk_F0;
    /* 0xF4 */ f32 unk_F4;
    /* 0xF8 */ f32 unk_F8;
    u8 pad_FC[0x4];
    /* 0x100 */ s32 unk_100;
    /* 0x104 */ s32 unk_104[12];
} Obj_0013B350;

extern s32 D_0069C580;

void func_001318C0(void *obj, s32 a, s32 b);

void func_00139ED0(void *obj, s32 *a, s32 *b);

void func_001356A0(void *obj, s32 *a, s32 *b);

void func_001368A0(void *obj, s32 *a, s32 *b);

void func_00136440(void *obj, s32 *a, s32 *b);

void func_0013A880(void *obj, s32 *a, s32 *b);

void func_0013AC50(void *obj, s32 *a, s32 *b);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B1F0);

void *func_0013B220(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x50)) != 0) {
        func_00138F80(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x120, 240.0f, -136.0f);
    }
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B280);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B2B0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B320);

/* Sets up the object, publishes it in D_006A6D00, then builds its six parts, each handed
   the word at +0x100 and one slot of the table after it. */
Obj_0013B350 *func_0013B350(Obj_0013B350 *arg0)
{
    // !FAKE: the object pointer is kept in a stack slot and reread after every store through it; only a volatile local reproduces that, and the plain copy self stands for the single reread the bytes share between two uses
    Obj_0013B350 * volatile o = arg0;
    Obj_0013B350 *self;
    void *obj;
    s32 i;

    func_001318C0(o, 0x24, 0);
    o->unk_0 = &D_0069C580;
    self = o;
    D_006A6D00 = (s32)self;
    self->unk_64 = 0;
    o->unk_68 = 0;
    o->unk_B0.x = 0.0f;
    o->unk_B0.y = 0.0f;
    o->unk_B0.z = 0.0f;
    o->unk_B0.w = 0.0f;
    o->unk_C0.x = 0.75f;
    o->unk_C0.y = 0.75f;
    o->unk_C0.z = 0.75f;
    o->unk_C0.w = 0.5f;
    o->unk_D0.x = 1.0f;
    o->unk_D0.y = 1.0f;
    o->unk_D0.z = 1.0f;
    o->unk_D0.w = 0.5f;
    o->unk_E0.x = 0.0f;
    o->unk_E0.y = 0.0f;
    o->unk_E0.z = 0.0f;
    o->unk_E0.w = 0.0f;
    o->unk_F0 = 1.0f;
    o->unk_F4 = 0.0f;
    o->unk_F8 = 0.0f;
    o->unk_100 = 0;
    for (i = 0; i < 12; i++) {
        o->unk_104[i] = 0;
    }

    if ((obj = __nw__FUi(0x170)) != 0) {
        self = o;
        func_00139ED0(obj, &self->unk_100, &self->unk_104[4]);
    }
    o->unk_90 = obj;
    if ((obj = __nw__FUi(0x48)) != 0) {
        self = o;
        func_001356A0(obj, &self->unk_100, &self->unk_104[0]);
    }
    o->unk_94 = obj;
    if ((obj = __nw__FUi(0x34)) != 0) {
        self = o;
        func_001368A0(obj, &self->unk_100, &self->unk_104[3]);
    }
    o->unk_98 = obj;
    if ((obj = __nw__FUi(0x38)) != 0) {
        self = o;
        func_00136440(obj, &self->unk_100, &self->unk_104[9]);
    }
    o->unk_9C = obj;
    if ((obj = __nw__FUi(0x50)) != 0) {
        self = o;
        func_0013A880(obj, &self->unk_100, &self->unk_104[10]);
    }
    o->unk_A0 = obj;
    if ((obj = __nw__FUi(0x28)) != 0) {
        self = o;
        func_0013AC50(obj, &self->unk_100, &self->unk_104[11]);
    }
    o->unk_A4 = obj;
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B590);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B720);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013B7A0);

void func_0013BAE0(void) {
}

void func_0013BAF0(void) {
}

int func_0013BB00(void) {
    return 0;
}

void func_0013BB10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013B1F0", func_0013BB20);

/* Probably a destructor in the compiler's shape: the word at +0x0 is reset, the array at
   +0x60 freed with delete[], the object unlinked from a two-way list whose head is
   D_006A6D08, and the storage freed when the flag argument is positive. */
Obj_0013BC80 *func_0013BC80(Obj_0013BC80 *o, s16 arg1)
{
    if (o != 0) {
        o->unk_0 = &D_0069C718;
        __dla__FPv(o->unk_60);
        if (o->link_6C != 0)
            o->link_6C->link_68 = o->link_68;
        if (o->link_68 != 0)
            o->link_68->link_6C = o->link_6C;
        else
            D_006A6D08 = (s32)o->link_6C;
        if (arg1 > 0)
            __dl__FPv(o);
    }
    return o;
}

void func_0013BD20(Obj0013BD20 *o, register Vec *m)
{
    register Vec *p;

    p = &o->unk_10;
    asm {
        lqc2 vf1, 0x30(m)
        lqc2 vf2, 0(p)
        vsub.xyz vf2, vf1, vf2
        lqc2 vf3, 0(m)
        lqc2 vf4, 0x10(m)
        lqc2 vf5, 0x20(m)
        sqc2 vf1, 0(p)
        sqc2 vf2, 0x10(p)
        sqc2 vf3, 0x20(p)
        sqc2 vf4, 0x30(p)
        sqc2 vf5, 0x40(p)
    }
}
