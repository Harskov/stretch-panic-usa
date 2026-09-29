#include "common.h"

class Inner {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Obj {
    unsigned char unk_00[0x50];
    Inner *field_50;
};

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_001784A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178520);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178630);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178770);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178810);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178880);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178990);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178AE0);

extern "C" void func_00178B10(Obj *p)
{
    p->field_50->m2();
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178B30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178DC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178E20);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178E60);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178EF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00178FC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_001790E0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001784A0", func_00179360);
