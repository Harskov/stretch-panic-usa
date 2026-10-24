#include "common.h"

extern void __dl__FPv(void *p);

int func_0015E070(Vec *a, Vec *diff, Vec *b, void *c, Vec *out);

void func_0012E9A0(Vec *a, Vec *b, Vec *c, f32 d);

void func_0015D510(void) {
}

void func_0015D520(void) {
}

int func_0015D530(void) {
    return 0;
}

void func_0015D540(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D550);

void *func_0015D600(void *p, s16 flags)
{
    if (p != 0) {
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D650);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015D850);

int func_0015D9C0(Vec *a, void *arg1)
{
    Vec hit[3];
    Vec diff;
    register Vec *p = a;
    register Vec *q = a + 1;
    register Vec *r = &diff;

    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(q)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(r)
    }
    if (func_0015E070(a, &diff, a + 1, arg1, hit) != 0) {
        func_0012E9A0(a, &hit[1], a, 0.03125f + hit[2].x);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015DA40);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015DC70);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_0015D510", func_0015DF00);
