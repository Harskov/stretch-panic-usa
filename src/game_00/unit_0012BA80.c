#include "common.h"
#include "game_00/obj90.h"

extern s32 D_0069C360;

void func_001319D0();

void __dl__FPv(void *);

typedef union Mtx {
    u128 q[4];
    f32 f[16];
} Mtx;

extern Mtx D_001A09E0;

extern f32 *D_006A6BA0;

extern f32 *D_006A6BA8;

extern f32 *D_006A6BB0;

extern f32 *D_006A6BB8;

extern f32 *D_006A6BC0;

extern f32 *D_006A6BC8;

extern f32 *D_006A6BD0;

extern f32 *D_006A6BD8;

typedef struct Obj_0012C4B0 {
    u8 unk_0[0x190];
    Vec unk_190;
    Vec unk_1A0;
    Vec unk_1B0;
    Vec unk_1C0;
} Obj_0012C4B0;

extern f32 func_0012E970(Vec *a, Vec *b);

void *func_0012BA80(Obj90 *o) {
    return &o->unk_A0;
}

void func_0012BA90(void) {
}

void func_0012BAA0(void) {
}

f32 func_0012BAB0(void) {
    return 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012BAC0);

s32 **func_0012BD70(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069C360;
        func_001319D0(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012BDD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012C380);

int func_0012C4B0(Obj_0012C4B0 *arg0, Vec *arg1)
{
    if (func_0012E970(arg1, &arg0->unk_190) > 0.0f)
        return 0;
    if (func_0012E970(arg1, &arg0->unk_1A0) > 0.0f)
        return 0;
    if (func_0012E970(arg1, &arg0->unk_1B0) > 0.0f)
        return 0;
    if (func_0012E970(arg1, &arg0->unk_1C0) > 0.0f)
        return 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012C590);

void func_0012C660(void) {
}

void func_0012C670(void) {
}

int func_0012C680(void) {
    return 0;
}

void func_0012C690(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012C6A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0012BA80", func_0012C6E0);

void func_0012C710(f32 *arg0) {
    Mtx m;
    f32 *src;
    f32 v;
    s32 i;

    m = D_001A09E0;
    src = m.f;
    D_006A6BB8 = arg0 + 16;
    D_006A6BC0 = arg0 + 32;
    D_006A6BC8 = arg0 + 48;
    D_006A6BB0 = arg0;
    D_006A6BD0 = arg0 + 64;
    D_006A6BD8 = arg0 + 80;
    D_006A6BA0 = arg0 + 96;
    D_006A6BA8 = D_006A6BA0;
    for (i = 0; i < 16; i++) {
        v = *src;
        D_006A6BD8[i] = v;
        src++;
        D_006A6BD0[i] = v;
        D_006A6BC8[i] = v;
        D_006A6BC0[i] = v;
    }
}
