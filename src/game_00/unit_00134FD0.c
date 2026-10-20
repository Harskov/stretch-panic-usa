#include "common.h"

extern s32 D_0069C6D0;

void func_001355E0();

void __dl__FPv(void *);

extern s32 D_0069C6F0;

typedef struct Obj_00135570 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u8 pad_4[8];
    /* 0x0C */ struct Obj_00135570 *unk_C;
    /* 0x10 */ struct Obj_00135570 *unk_10;
    /* 0x14 */ struct Obj_00135570 **unk_14;
    /* 0x18 */ struct Obj_00135570 *unk_18;
    /* 0x1C */ struct Obj_00135570 *unk_1C;
    /* 0x20 */ struct Obj_00135570 **unk_20;
} Obj_00135570;

extern s32 D_0069C6B0;

extern s32 D_0069C690;

extern s32 D_0069C670;

extern s32 D_0069C540;

typedef struct Obj_00135450 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u8 pad_4[0x8C];
    /* 0x90 */ struct Obj_00135450 *unk_90;
    /* 0x94 */ struct Obj_00135450 *unk_94;
} Obj_00135450;

extern Obj_00135450 *D_006A6CF0;

void func_001318C0();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00134FD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135190);

Obj_00135450 *func_00135450(Obj_00135450 *o)
{
    func_001318C0(o);
    o->unk_0 = &D_0069C540;
    o->unk_90 = D_006A6CF0;
    o->unk_94 = 0;
    D_006A6CF0 = o;
    if (o->unk_90 != 0) {
        o->unk_90->unk_94 = o;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001354B0);

Obj_00135570 *func_00135570(Obj_00135570 *o, Obj_00135570 **head_a, Obj_00135570 **head_b)
{
    o->unk_0 = &D_0069C6F0;
    o->unk_14 = head_a;
    o->unk_20 = head_b;
    o->unk_C = *o->unk_14;
    o->unk_10 = 0;
    *o->unk_14 = o;
    if (o->unk_C != 0) {
        o->unk_C->unk_10 = o;
    }
    o->unk_18 = *o->unk_20;
    o->unk_1C = 0;
    *o->unk_20 = o;
    if (o->unk_18 != 0) {
        o->unk_18->unk_1C = o;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001355E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001356A0);

s32 **func_00135710(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C6D0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135770);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001357D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135C70);

s32 **func_00135CC0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C6B0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

s32 func_00135D20(void)
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00135D30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00136440);

s32 **func_00136490(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C690;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001364F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001365F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_001368A0);

s32 **func_001368F0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C670;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00134FD0", func_00136950);
