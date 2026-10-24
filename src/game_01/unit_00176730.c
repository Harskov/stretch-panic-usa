#include "common.h"
#include "types.h"

typedef union Obj_00176730 {
    /* 0x00 */ u128 unk_0;
    /* 0x00 */ Vec vec0;
    /* 0x00 */ s32 i0[4];
} Obj_00176730;

extern s32 D_0069D080;

typedef struct Ent {
    void *unk_0;          /* 0x00 */
    u8 pad04[0x4C];      /* 0x04 */
    s32 unk50;           /* 0x50 */
    u8 pad54[0xC];       /* 0x54 */
    Obj_00176730 unk_60;         /* 0x60 */
    u8 pad70[0x40];      /* 0x70 */
    Quad unk_B0;          /* 0xB0 */
    f32 unkC0;           /* 0xC0 */
    f32 unkC4;           /* 0xC4 */
} Ent;

void func_00172DA0(Ent *, s32, s32);

extern s32 D_006A6730;

void func_00127BA0();

void func_00172E80();

void __dl__FPv(void *);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_001767A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_001768B0);

void func_00176A00(void) {
    func_00127BA0(D_006A6730);
    func_00127BA0(D_006A6730);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176A30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176B40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176BB0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176C10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176C60);

void func_00176F30(void) {
}

void func_00176F40(void) {
}

int func_00176F50(void) {
    return 0;
}

void func_00176F60(void)
{
}

void func_00176F70(void)
{
}

Ent *func_00176F80(Ent *e, s32 a1, s32 a2, Quad *v1, Quad *v2, f32 f0, f32 f1)
{

    func_00172DA0(e, a1, 0);
    e->unk_0 = &D_0069D080;
    e->unk50 = a2;
    e->unk_60.unk_0 = v1->unk_0;
    e->unk_60.i0[3] = 0;
    e->unk_B0 = *v2;
    e->unkC0 = f0;
    e->unkC4 = f1;
    return e;
}

s32 **func_00177020(s32 **self, s16 flags) {
    if (self != 0) {
        *self = &D_0069D080;
        func_00172E80(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
