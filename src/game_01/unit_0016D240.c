#include "common.h"
#include "types.h"

/* A vtable accessor: six function-pointer tables (D_0069CE00, D_0069D0E0, D_0069D1B0,
   D_0069D2B0, D_0069D320, D_0069D4B0) hold its address, and it returns the address of
   whatever sits at +0xA0 in the object it is called on. No matched function reaches
   that member, so only its existence is asserted here. */
typedef struct ObjA0 {
    unsigned char unk_00[0xA0];
    u8 unk_A0;
} ObjA0;

typedef struct Quad {
    u128 q;
} Quad;

typedef struct {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x108];
    int field16C;
} Obj;

extern Quad D_00601A40;

extern void func_0016EFC0(void *arg0, Quad *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);

void *func_0016D240(ObjA0 *o) {
    return &o->unk_A0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D250);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D2A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D360);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D3D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D430);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D560);

void func_0016D620(void *arg0, s32 arg1)
{
    Quad tmp;

    tmp = D_00601A40;
    func_0016EFC0(arg0, &tmp, arg1, 0, 0.75f, 0.0f);
}

void func_0016D660(void) {
}

void func_0016D670(void) {
}

void func_0016D680(void) {
}

void func_0016D690(Obj *arg0) {
    arg0->field16C = 0;
    arg0->flags |= 0x10000;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D6B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D6E0);
