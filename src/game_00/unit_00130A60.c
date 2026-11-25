#include "common.h"

typedef struct Obj_00130A60 {
    Vec unk_0;
    f32 unk_10;
    f32 unk_14;
} Obj_00130A60;

f32 func_0012E870();

f32 func_0012E8A0(Vec *arg0);

void func_0012E9A0(Obj_00130A60 *arg0, Vec *arg1, Vec *arg2, f32 arg3);

f32 func_0012E950(Vec *arg0, Vec *arg1);

int func_00130A60(Obj_00130A60 *arg0, Obj_00130A60 *arg1) {
    f32 limit;

    limit = arg1->unk_14 + (arg0->unk_14 + 2.0f * arg0->unk_10 * arg1->unk_10);
    return func_0012E870(arg1, arg0) < limit;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130AD0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130D80);

/* Stores arg1 - arg0 (xyz) in arg3, then goes on only when func_0012E8A0 of that
   difference is within the sum of the two unk_10 values; probably a reach test
   between two bounded objects. */
s32 func_00130E10(Obj_00130A60 *arg0, Obj_00130A60 *arg1, void *arg2, Vec *arg3) {
    register Vec *dst = arg3;
    register Obj_00130A60 *p1 = arg1;
    register Obj_00130A60 *p0 = arg0;
    Vec v;

    asm {
        lqc2 vf1, 0(p1)
        lqc2 vf2, 0(p0)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(dst)
    }
    if (!(func_0012E8A0(dst) <= p0->unk_10 + p1->unk_10))
        return 0;
    func_0012E9A0(p0, dst, &v, p0->unk_10);
    dst->w = -func_0012E950(&v, dst);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00130EB0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00130A60", func_00131240);

int func_001312F0(void) {
    return 0;
}

int func_00131300(void) {
    return 0;
}

int func_00131310(void) {
    return 0;
}

int func_00131320(void) {
    return 0;
}

int func_00131330(void) {
    return 0;
}

int func_00131340(void) {
    return 0;
}

int func_00131350(void) {
    return 0;
}

int func_00131360(void) {
    return 0;
}

int func_00131370(void) {
    return 0;
}

int func_00131380(void) {
    return 0;
}

int func_00131390(void) {
    return 0;
}

int func_001313A0(void) {
    return 0;
}
