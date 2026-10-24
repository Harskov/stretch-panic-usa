#include "common.h"

typedef struct E64 {
    /* 0x00 */ __int128 unk_0[4];
} E64;

typedef struct Src {
    unsigned char unk_00[4];
    /* 0x04 */ E64 *unk_4;
} Src;

typedef struct Ctx {
    unsigned char unk_00[8];
    /* 0x08 */ Src *unk_8;
    int count;
    /* 0x10 */ E64 *unk_10;
} Ctx;

typedef struct Obj_00131620 {
    unsigned char unk_00[0xC];
    u8 unk_C;
} Obj_00131620;

typedef struct Obj_001313B0 {
    /* 0x00 */ u8 unk_0[0x8];
    /* 0x08 */ s32 unk_8;
} Obj_001313B0;

typedef struct Obj_00131450 {
    /* 0x00 */ u8 unk_0[0x8];
    /* 0x08 */ s32 unk_8;
} Obj_00131450;

typedef struct Obj_001314F0 {
    /* 0x00 */ u8 unk_0[0x8];
    /* 0x08 */ s32 unk_8;
} Obj_001314F0;

extern s32 D_0069C300;

extern s32 D_0069C390;

extern void __dl__FPv(void *);

extern s32 D_0069C3C0;

extern s32 D_0069C3F0;

extern s32 D_0069C480;

extern s32 D_0069C450;

extern void __dla__FPv(void *);

s32 **func_001313B0(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C390;
        if (arg0 != 0) {
            *arg0 = &D_0069C300;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

s32 func_00131410(Obj_001313B0 *o)
{
    return o->unk_8;
}

void func_00131420(void) {
}

void func_00131430(void) {
}

void func_00131440(void) {
}

s32 **func_00131450(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C3C0;
        if (arg0 != 0) {
            *arg0 = &D_0069C300;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

s32 func_001314B0(Obj_00131450 *o)
{
    return o->unk_8;
}

void func_001314C0(void) {
}

void func_001314D0(void) {
}

void func_001314E0(void) {
}

s32 **func_001314F0(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C3F0;
        if (arg0 != 0) {
            *arg0 = &D_0069C300;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

s32 func_00131550(Obj_001314F0 *o)
{
    return o->unk_8;
}

void func_00131560(void) {
}

void func_00131570(void) {
}

void func_00131580(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131590);

/* A slot of the function-pointer table D_0069C420. Only the member's address is
   taken, so its type is not known. */
void *func_00131620(Obj_00131620 *o) {
    return &o->unk_C;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_001313B0", func_00131630);

s32 **func_001316B0(s32 **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_0069C450;
        __dla__FPv(arg0[4]);
        if (arg0 != 0) {
            *arg0 = &D_0069C300;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

/* Shares the function-pointer table D_0069C450 with func_00131740, so both are
   called on the same object. */
int *func_00131730(Ctx *c) {
    return &c->count;
}

void func_00131740(Ctx *c) {
    int i;

    for (i = 0; i < c->count; i++) {
        c->unk_10[i] = c->unk_8->unk_4[i];
    }
}

s32 **func_001317A0(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C480;
        if (arg0 != 0) {
            *arg0 = &D_0069C300;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
