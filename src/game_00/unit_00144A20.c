#include "common.h"
#include "types.h"

typedef struct M128 {
    /* 0x00 */ __int128 unk_0[8];
} M128;

typedef struct Obj {
    unsigned char unk_00[0x90];
    /* 0x90 */ M128 unk_90;
    unsigned char unk_110[0x3C];
    /* 0x14C */ unsigned char unk_14C;
} Obj;

extern s32 D_006A6730;

void func_00125260();

void func_00127BA0();

extern s32 D_0069C7B0;

void func_00172E80();

void __dl__FPv(void *);

typedef struct Obj_00145790 {
    /* 0x00 */ s32 *unk_0;
    unsigned char unk_4[0x10C];
    /* 0x110 */ f32 unk_110;
    /* 0x114 */ f32 unk_114;
    /* 0x118 */ f32 unk_118;
    unsigned char unk_11C[0x34];
    /* 0x150 */ unsigned char unk_150[4];
} Obj_00145790;

extern s32 D_0069C8B0;

void func_0013BC80();

void func_001319D0();

extern s32 D_006A6D18;

void func_0012D430();

void func_0012D450(Vec *, f32, f32, f32);

void func_0013BD20();

void func_0013BFB0();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144A20);

s32 **func_00144C20(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C7B0;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144C80);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144E00);

void func_00144FA0(void) {
    func_00125260(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00144FD0);

void func_00145140(void) {
}

void func_00145150(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145160);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_001454D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_001455F0);

Obj_00145790 *func_00145790(Obj_00145790 *self, s16 flags) {
    if (self != 0) {
        self->unk_0 = &D_0069C8B0;
        func_0013BC80(self->unk_150, -1);
        func_001319D0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145800);

void func_001459B0(Obj_00145790 *o) {
    Vec m[5];

    func_0012D430(m);
    func_0012D450(m, o->unk_110, o->unk_114, o->unk_118);
    func_0013BD20(o->unk_150, m);
    func_0013BFB0(D_006A6D18, o->unk_150);
}

void func_00145A10(Obj *o, M128 *dst) {
    *dst = o->unk_90;
    o->unk_14C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00144A20", func_00145A40);

void func_00145A70(void) {
}

int func_00145A80(void) {
    return 0;
}
