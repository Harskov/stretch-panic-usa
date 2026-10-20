#include "common.h"

extern s32 D_006A6D00;

extern void *__nw__FUi(u32 size);

void func_00135C70();

extern s32 D_0069C5D0;

void func_001355E0();

void __dl__FPv(void *);

extern s32 D_0069C5B0;

void func_00135570();

typedef struct Obj_0013AC50 {
    s32 *unk_0;
    u8 unk_4[0x20];
    s32 unk_24;
} Obj_0013AC50;

typedef struct Obj_0013A880 {
    s32 *unk_0;
    u8 unk_4[0x2C];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
} Obj_0013A880;

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A120);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A2E0);

Obj_0013A880 *func_0013A880(Obj_0013A880 *self)
{
    func_00135570(self);
    self->unk_0 = &D_0069C5D0;
    self->unk_30 = 0x3F800000;
    self->unk_34 = 0x3F800000;
    self->unk_38 = 0x3F800000;
    self->unk_3C = 0x3F000000;
    self->unk_40 = 0;
    self->unk_44 = 0x42700000;
    self->unk_48 = 0;
    self->unk_4C = 0x3F800000;
    return self;
}

s32 **func_0013A8E0(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C5D0;
        func_001355E0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013A940);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AA50);

Obj_0013AC50 *func_0013AC50(Obj_0013AC50 *self)
{
    func_00135570(self);
    self->unk_0 = &D_0069C5B0;
    self->unk_24 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AC90);

s32 func_0013AD30(void)
{
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AD40);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013AFE0);

void *func_0013B080(void)
{
    void *obj;

    if ((obj = __nw__FUi(0x50)) != 0) {
        func_00135C70(obj, D_006A6D00 + 0x100, D_006A6D00 + 0x10C);
    }
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B0D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B100);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B160);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0013A120", func_0013B190);
