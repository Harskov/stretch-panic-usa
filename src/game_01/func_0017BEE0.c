#include "common.h"

typedef struct Obj16C {
    u8 pad0[0x16C];
    s32 i16C;
} Obj16C;

void func_0017AFC0();

void func_0017BEE0(Obj16C *arg0)
{
    arg0->i16C = 0;
    func_0017AFC0();
}
