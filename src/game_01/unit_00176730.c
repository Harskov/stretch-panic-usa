#include "common.h"

typedef union QuadI {
    u128 q;
    Vec v;
    s32 i[4];
} QuadI;

extern s32 D_0069D080;

typedef struct Ent {
    void *vtbl;          /* 0x00 */
    u8 pad04[0x4C];      /* 0x04 */
    s32 unk50;           /* 0x50 */
    u8 pad54[0xC];       /* 0x54 */
    QuadI vec60;         /* 0x60 */
    u8 pad70[0x40];      /* 0x70 */
    Quad vecB0;          /* 0xB0 */
    f32 unkC0;           /* 0xC0 */
    f32 unkC4;           /* 0xC4 */
} Ent;

void func_00172DA0(Ent *, s32, s32);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176730);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_001767A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_001768B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00176A00);

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
    e->vtbl = &D_0069D080;
    e->unk50 = a2;
    e->vec60.q = v1->q;
    e->vec60.i[3] = 0;
    e->vecB0 = *v2;
    e->unkC0 = f0;
    e->unkC4 = f1;
    return e;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00176730", func_00177020);
