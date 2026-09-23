#include "common.h"

typedef struct Ctrl {
    u8 unk_00[0x60];
    u32 unk_60;
} Ctrl;

typedef struct Obj {
    u8 unk_00[0x64];
    u32 unk_64;
    u32 unk_68;
    u8 unk_6C[0x2F8];
    s32 unk_364;
} Obj;

extern Ctrl *D_006AF4D8;
extern void func_0014EAF0(Obj *arg0);

void func_0014EB30(Obj *arg0)
{
    func_0014EAF0(arg0);
    arg0->unk_364 = 0;
    arg0->unk_64 |= 1;
    arg0->unk_68 |= 7;
    if (D_006AF4D8 != 0) {
        D_006AF4D8->unk_60 |= 0x10000;
    }
}
