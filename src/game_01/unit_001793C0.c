#include "common.h"
#include "game_01/obj2F8.h"

typedef struct Node {
    u8 pad[0x10];
    u128 v;
} Node;

typedef struct Holder {
    u8 pad[0xD0];
    Node *n0;
    Node *n1;
    u8 pad2[8];
    u128 v;
} Holder;

typedef struct Src {
    u128 v0;
    u128 v1;
    u128 v2;
    u128 v3;
    f32 f40;
    s32 i44;
    s32 i48;
} Src;

typedef struct Dst {
    u8 pad0[0x10];
    u128 v0;
    u8 pad20[0x10];
    u128 v1;
    u8 pad40[0x50];
    u128 v2;
    u128 v3;
    f32 fB0;
    s32 iB4;
    s32 iB8;
    s32 iBC;
    s32 iC0;
} Dst;

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_001793C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179610);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179690);

void func_00179870(u128 *out, Holder *h)
{
    Node *n = h->n0;
    if (n != 0) {
        *out = n->v;
    } else {
        n = h->n1;
        if (n != 0) {
            *out = *(u128 *)n;
        } else {
            *out = h->v;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_001798B0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179A80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179AC0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179B20);

void func_00179CF0(void)
{
}

void func_00179D00(void)
{
}

int func_00179D10(void)
{
    return 0;
}

void func_00179D20(void)
{
}

void func_00179D30(Dst *arg0, Src *arg1)
{
    arg0->v0 = arg1->v0;
    arg0->v1 = arg1->v1;
    arg0->v2 = arg1->v2;
    arg0->v3 = arg1->v3;
    arg0->fB0 = arg1->f40;
    arg0->iB4 = 1;
    arg0->iB8 = arg1->i44;
    arg0->iBC = arg1->i48;
    arg0->iC0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179D80);

void func_00179DF0(Obj2F8 *arg0)
{
    arg0->unk_2B0 = 0;
    arg0->unk_178 = 0xA;
    arg0->unk_180 = 0;
    arg0->unk_2BC = 0;
    arg0->unk_2B8 = 0;
    arg0->unk_2B4 = 0;
    arg0->unk_64 = 0;
    arg0->unk_68 = 0x40;
    arg0->unk_2F0 = 0;
}
