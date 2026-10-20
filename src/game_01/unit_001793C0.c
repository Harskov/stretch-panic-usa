#include "common.h"
#include "game_01/obj2F8.h"

typedef struct Node {
    u8 pad[0x10];
    /* 0x10 */ u128 unk_10;
} Node;

typedef struct Holder {
    u8 pad[0xD0];
    /* 0xD0 */ Node *unk_D0;
    /* 0xD4 */ Node *unk_D4;
    u8 pad2[8];
    /* 0xE0 */ u128 unk_E0;
} Holder;

typedef struct Src {
    u128 v0;
    /* 0x10 */ u128 v10;
    /* 0x20 */ u128 v20;
    /* 0x30 */ u128 v30;
    f32 f40;
    s32 i44;
    s32 i48;
} Src;

typedef struct Dst {
    u8 pad0[0x10];
    /* 0x10 */ u128 v10;
    u8 pad20[0x10];
    /* 0x30 */ u128 v30;
    u8 pad40[0x50];
    /* 0x90 */ u128 v90;
    /* 0xA0 */ u128 vA0;
    f32 fB0;
    s32 iB4;
    s32 iB8;
    s32 iBC;
    s32 iC0;
} Dst;

extern s32 D_0069D280;

void func_001318C0();

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_001793C0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179610);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_00179690);

void func_00179870(u128 *out, Holder *h)
{
    Node *n = h->unk_D0;
    if (n != 0) {
        *out = n->unk_10;
    } else {
        n = h->unk_D4;
        if (n != 0) {
            *out = *(u128 *)n;
        } else {
            *out = h->unk_E0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_001793C0", func_001798B0);

void **func_00179A80(void **arg0, s32 arg1)
{
    func_001318C0(arg0, 0x23, arg1);
    *arg0 = &D_0069D280;
    return arg0;
}

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
    arg0->v10 = arg1->v0;
    arg0->v30 = arg1->v10;
    arg0->v90 = arg1->v20;
    arg0->vA0 = arg1->v30;
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
