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

void func_00140F10(Obj_00140F10 *arg0)
{
    Sub_00140F10 *temp_a0 = arg0->unk_280;
    if (temp_a0 != 0) {
        temp_a0->m0(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00140F40);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00140070", func_00141000);
