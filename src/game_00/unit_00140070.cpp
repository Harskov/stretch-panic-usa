#include "common.h"

class Sub_00140F10 {
public:
    virtual void m0(int);
};

struct Obj_00140F10 {
    unsigned char pad[0x280];
    Sub_00140F10 *unk_280;
};

extern "C" void func_00140F10(Obj_00140F10 *arg0);

extern "C" void func_001401F0(void);

struct Obj_00140D30 {
    u8 unk_0[0x290];
    Quad unk_290;
    Quad unk_2A0;
    Quad unk_2B0;
};

struct Obj_006A6B94 {
    u8 unk_0[0xF0];
    Quad unk_F0;
    Quad unk_100;
    Quad unk_110;
};

extern "C" Obj_006A6B94 *D_006A6B94;

extern "C" void func_00140D30(Obj_00140D30 *arg0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140070);

void func_001401F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140200);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_001404D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140B90);

void func_00140D30(Obj_00140D30 *arg0)
{
    D_006A6B94->unk_F0 = arg0->unk_290;
    D_006A6B94->unk_100 = arg0->unk_2A0;
    D_006A6B94->unk_110 = arg0->unk_2B0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140D70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140E20);

// registers: sub = the object held at unk_280, called through its vtable
void func_00140F10(Obj_00140F10 *arg0)
{
    Sub_00140F10 *sub = arg0->unk_280;
    if (sub != 0) {
        sub->m0(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140F40);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00141000);
