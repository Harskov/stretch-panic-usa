#include "common.h"
#include "game_01/objC0.h"

typedef struct Obj {
    unsigned char unk_00[0x60];
    int flags;
    unsigned char unk_64[0x3C];
    float unk_A0;
    float unk_A4;
    float unk_A8;
    float unk_AC;
} Obj;

extern void func_001683F0(void *arg0, ObjC0 *arg1);

extern void func_00168470(void);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00167ED0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168080);

void func_00168360(void *arg0, ObjC0 *arg1)
{
    switch (arg1->unk_C0) {
    case 2:
        func_001683F0(arg0, arg1);
        break;
    }
}

/* The first parameter is not read. */
s32 func_001683A0(void *arg0, ObjC0 *o)
{
    switch (o->unk_C0) {
    case 6:
        func_00168470();
        break;
    }
    return 0;
}

void func_001683E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_001683F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168470);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168530);

void func_00168630(Obj *o) {
    float a;
    float b;

    o->unk_A8 += o->unk_AC;
    b = o->unk_A4;
    a = o->unk_A0;
    o->unk_A0 = a - b;
    if (a - b <= 0.0f) {
        o->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168680);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_001688F0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168BF0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168DE0);

void func_00168E20(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_00168E30);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00167ED0", func_001690A0);
