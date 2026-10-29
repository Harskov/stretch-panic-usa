#include "common.h"
#include "game_01/obj430.h"

extern s32 D_006AF0A0[];

extern s32 D_006AF0A4[];

extern s32 D_006AF4A0;

void func_00152040();

typedef struct Obj_001514D0 {
    u8 unk_00[0x10];
    u8 unk_10[0x20];
    u128 unk_30;
    u8 unk_40[0x300];
    u8 unk_340[0x218];
    s32 unk_558;
} Obj_001514D0;

s32 func_0016BEB0(s32 arg0);

void func_0012E9A0(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0);

typedef struct Obj_001517A0 {
    u8 unk_00[0x60];
    /* 0x60 */ u32 unk_60;
    u8 unk_64[0x58];
    /* 0xBC */ u8 unk_BC;
} Obj_001517A0;

extern s32 D_006A6D20;

extern s32 D_006AEDE0;

void func_0013C7A0();

void func_0013C830();

void func_0013DEA0();

void func_0016C260();

void *__nw__FUi(u32);

void * func_0013B220(void);

void func_0013BB20(s32 *, s32);

extern s32 D_005AFAE0;

extern s32 D_0069C300;

extern s32 D_0069C3F0;

void func_00152700();

void func_00152960();

void func_001672B0();

typedef struct Obj_0069C3F0 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ void *unk_8;
} Obj_0069C3F0;

typedef struct Elem_0013BB20 {
    u8 unk_00[0x10];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    u8 unk_1C[0x4];
} Elem_0013BB20;

typedef struct Obj_0013BB20 {
    u8 unk_00[0x60];
    /* 0x60 */ Elem_0013BB20 *unk_60;
} Obj_0013BB20;

typedef struct Obj_001518C0 {
    u8 unk_00[0x64];
    /* 0x064 */ Obj_0069C3F0 *unk_64;
    u8 unk_68[0x18];
    /* 0x080 */ u8 unk_80[0x478];
    /* 0x4F8 */ void *unk_4F8;
    /* 0x4FC */ void *unk_4FC;
    /* 0x500 */ s32 unk_500;
    /* 0x504 */ Obj_0013BB20 *unk_504;
} Obj_001518C0;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001510C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001512B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_001513D0);

void func_00151460(Obj430 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 0;
    arg0->unk_420.w0.unk_00 = 0;
    arg0->unk_420.w0.unk_04 = 0;
    arg0->unk_420.w0.unk_08 = 0;
    arg0->unk_420.w0.unk_0C = 1.0f;
}

void func_001514A0(Obj430 *arg0, s32 arg1, const Quad420 *arg2, f32 fparg0) {
    arg0->unk_60 |= 0x04000000;
    arg0->unk_410 = arg1;
    arg0->unk_414 = fparg0;
    arg0->unk_418 = 1;
    arg0->unk_420.unk_0 = arg2->unk_0;
}

void func_001514D0(Obj_001514D0 *arg0, Quad *arg1) {
    if (func_0016BEB0(arg0->unk_558) != 0) {
        func_0012E9A0(arg0->unk_10, arg0->unk_340, arg0->unk_10, -0.125f);
        arg0->unk_30 = arg1->unk_0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151530);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151600);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151730);

/* allocates and initialises a 0x250-byte object unless the byte at +0xBC is set,
   then sets bit 0x40 of the word at +0x60; the allocation and the call on it
   probably stand for a C++ new-expression with func_0013C830 as its constructor */
void func_001517A0(Obj_001517A0 *arg0) {
    void *p;

    func_0016C260();
    func_0013DEA0(0x20);
    func_0013C7A0(D_006A6D20);
    if (arg0->unk_BC == 0) {
        if ((p = __nw__FUi(0x250)) != 0) {
            func_0013C830(p, 0x13, 0, 0, &D_006AEDE0);
        }
    }
    arg0->unk_60 |= 0x40;
}

void func_00151820(s32 arg0) {
    s32 idx;

    if (arg0 > 0) {
        D_006AF0A0[((D_006AF4A0 + 0x5A) % 128) * 2] += arg0;
    }
    if (arg0 < 0) {
        D_006AF0A4[((D_006AF4A0 + 0x10) % 128) * 2] += arg0;
    }
}

void func_001518B0(void) {
}

/* builds the object's three owned sub-objects and returns the object itself; the
   allocations followed by a call on the result probably stand for C++ new-expressions,
   the first with its constructor inlined (two table stores: the base's, then its own) */
// !FAKE: probably a constructor whose this lives in a stack slot and is reloaded before every use;
// only a volatile parameter gives that spill in C
Obj_001518C0 *func_001518C0(Obj_001518C0 *volatile arg0, s32 arg1) {
    Obj_0069C3F0 *o;
    void *p;

    func_00152960(arg0);
    if ((o = __nw__FUi(0xC)) != 0) {
        o->unk_0 = &D_0069C300;
        o->unk_0 = &D_0069C3F0;
        o->unk_8 = &D_005AFAE0;
        o->unk_4 = 0;
    }
    arg0->unk_64 = o;
    func_00152700(arg0, arg1);
    if ((p = __nw__FUi(0x490)) != 0) {
        func_001672B0(p, arg0->unk_80);
    }
    arg0->unk_4F8 = p;
    arg0->unk_4FC = func_0013B220();
    arg0->unk_500 = -1;
    if ((p = __nw__FUi(0x70)) != 0) {
        func_0013BB20(p, 3);
    }
    arg0->unk_504 = p;
    /* 1256.6371f is 400 pi */
    arg0->unk_504->unk_60[0].unk_10 = 1256.6371f;
    arg0->unk_504->unk_60[0].unk_18 = 1.0f;
    arg0->unk_504->unk_60[0].unk_14 = 0.25f;
    arg0->unk_504->unk_60[1].unk_10 = 1256.6371f;
    arg0->unk_504->unk_60[1].unk_18 = 1.0f;
    arg0->unk_504->unk_60[1].unk_14 = 0.25f;
    arg0->unk_504->unk_60[2].unk_10 = 1256.6371f;
    arg0->unk_504->unk_60[2].unk_18 = 1.0f;
    arg0->unk_504->unk_60[2].unk_14 = 0.25f;
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151A40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001510C0", func_00151AF0);

void func_00152030(void) {
    func_00152040();
}
