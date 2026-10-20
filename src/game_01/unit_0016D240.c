#include "common.h"
#include "types.h"

/* A vtable accessor: six function-pointer tables (D_0069CE00, D_0069D0E0, D_0069D1B0,
   D_0069D2B0, D_0069D320, D_0069D4B0) hold its address, and it returns the address of
   whatever sits at +0xA0 in the object it is called on. No function written so far
   reaches that member, so only its existence is asserted here. */
typedef struct ObjA0 {
    unsigned char unk_00[0xA0];
    u8 unk_A0;
} ObjA0;

typedef struct {
    unsigned char unk_00[0x60];
    u32 unk_60;
    unsigned char unk_64[0x108];
    int unk_16C;
} Obj;

extern Quad D_00601A40;

extern void func_0016EFC0(void *arg0, Quad *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5);

typedef struct Obj_0016D360 {
    unsigned char unk_00[0x10];
    unsigned char unk_10[0x124];
    s32 unk_134;
    f32 unk_138;
    unsigned char unk_13C[0x4];
    unsigned char unk_140[0x120];
    unsigned char unk_260[0x4];
} Obj_0016D360;

typedef struct Src_0016D360 {
    unsigned char unk_00[0x80];
    f32 unk_80;
    unsigned char unk_84[0x3C];
    s32 unk_C0;
} Src_0016D360;

extern void func_0012E9A0(void *arg0, void *arg1, void *arg2, f32 arg3);

void *func_0016D240(ObjA0 *o) {
    return &o->unk_A0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D250);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D2A0);

void func_0016D360(Obj_0016D360 *arg0, Src_0016D360 *arg1)
{
    f32 zero = 0.0f;

    switch (arg1->unk_C0) {
    case 0:
        if (arg1->unk_80 != zero) {
            arg0->unk_134 = 2;
            arg0->unk_138 = 1.0f;
            func_0012E9A0(arg0->unk_10, arg0->unk_260, arg0->unk_140, 0.75f);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D3D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D430);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D510);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D560);

// registers: copy = the local copy of D_00601A40 whose address is passed on
void func_0016D620(void *arg0, s32 arg1)
{
    Quad copy;

    copy = D_00601A40;
    func_0016EFC0(arg0, &copy, arg1, 0, 0.75f, 0.0f);
}

void func_0016D660(void) {
}

void func_0016D670(void) {
}

void func_0016D680(void) {
}

void func_0016D690(Obj *arg0) {
    arg0->unk_16C = 0;
    arg0->unk_60 |= 0x10000;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D6B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0016D240", func_0016D6E0);
