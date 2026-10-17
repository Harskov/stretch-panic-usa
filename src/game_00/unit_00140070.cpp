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

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140070);

void func_001401F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140200);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_001404D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140B90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140D30);

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
