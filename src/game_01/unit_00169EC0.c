#include "common.h"
#include "game_00/unit_0012DF10.h"

typedef struct Obj_0016B1D0 {
    u8 unk_0[0x40];
    Vec unk_40;
    u8 pad_50[0x100];
    Vec unk_150;
    u8 pad_160[0x10];
    Vec unk_170;
} Obj_0016B1D0;


void func_0012E8E0(Vec *a, Vec *out);

f32 func_0012E950(Vec *a, Vec *b);

void func_0012E9E0(Vec *a, Vec *b, Vec *c, f32 t);

void func_0012E8A0(Vec *a);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_00169EC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A0A0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A4F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A550);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A6C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016A970);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016ACC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B000);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B170);

void func_0016B1D0(Obj_0016B1D0 *arg0) {
    Vec v;
    register Vec *pv;
    register Vec *pa;

    v.x = -arg0->unk_170.x;
    v.y = -arg0->unk_170.y;
    v.z = -arg0->unk_170.z;
    pv = &v;
    pa = &arg0->unk_150;
    asm {
        lqc2 vf1, 0(pv)
        lqc2 vf2, 0(pa)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(pv)
        lqc2 vf1, 0(pa)
        lqc2 vf2, 0(pv)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(pv)
    }
    func_0012E9A0(&arg0->unk_40, &v, &arg0->unk_40, 0.049087387f);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B250);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B480);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B5F0);

void func_0016B680(void) {
}

int func_0016B690(void) {
    return 0;
}

void func_0016B6A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B6B0);

void func_0016B730(Vec *arg0, Vec *arg1, Vec *arg2) {
    Vec v;

    func_0012E8E0(arg0, &v);
    func_0012E9E0(arg1, &v, arg2, func_0012E950(&v, arg1));
    func_0012E8A0(arg2);
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B790);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016B960);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169EC0", func_0016BC10);
