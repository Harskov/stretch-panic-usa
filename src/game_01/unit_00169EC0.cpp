#include "common.h"

class Sub {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

struct Obj_0016A4F0 {
    u8 unk_0[0x94];
    Sub *unk_94[1];
};

extern "C" void func_0016A4F0(Obj_0016A4F0 *arg0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_00169EC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A0A0);

void func_0016A4F0(Obj_0016A4F0 *arg0) {
    int i;

    // !FAKE: probably a loop over a one-element array written i < 1; only the test i == 0 compiles to the branch the bytes take
    for (i = 0; i == 0; i++) {
        Sub *s = arg0->unk_94[i];
        if (s != 0) {
            s->m2();
        }
    }
}
