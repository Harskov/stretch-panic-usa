#include "common.h"

typedef struct Ent {
    /* 0x00 */ unsigned char unk_0;
    unsigned char unk_01[0x2F];
} Ent;

typedef struct Obj {
    unsigned char unk_00[0x50];
    int count;
    unsigned char unk_54[0x14];
    /* 0x68 */ Ent *unk_68;
} Obj;

extern s32 D_0069CB50;

void func_00172E80();

void __dl__FPv(void *);

Ent *func_00164E80(Obj *o);

void func_00164930(Obj *o, Ent *e);

typedef struct Obj_00164690 {
    /* 0x00 */ s32 *unk_0;
    unsigned char unk_04[0x64];
    /* 0x68 */ void *unk_68;
} Obj_00164690;

extern s32 D_0069CB80;

void __dla__FPv(void *);

typedef struct Obj_00165090 {
    /* 0x00 */ s32 *unk_0;
    unsigned char unk_04[0x80];
    /* 0x84 */ void *unk_84;
} Obj_00165090;

extern s32 D_0069CBB0;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164040);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164100);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164200);

s32 **func_00164520(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069CB50;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164580);

Obj_00164690 *func_00164690(Obj_00164690 *self, s16 flags) {
    if (self != 0) {
        self->unk_0 = &D_0069CB80;
        __dla__FPv(self->unk_68);
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164700);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_001647D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164930);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164A80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164B10);

Ent *func_00164E80(Obj *o) {
    int i;

    for (i = 0; i < o->count; i++) {
        if (o->unk_68[i].unk_0 == 0) {
            return &o->unk_68[i];
        }
    }
    return 0;
}

void func_00164EE0(Obj *o) {
    Ent *e = func_00164E80(o);

    if (e != 0) {
        func_00164930(o, e);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00164F20);

Obj_00165090 *func_00165090(Obj_00165090 *self, s16 flags) {
    if (self != 0) {
        self->unk_0 = &D_0069CBB0;
        __dla__FPv(self->unk_84);
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00164040", func_00165100);
