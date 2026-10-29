#include "common.h"
#include "game_01/obj1F0.h"
#include "game_01/actorC4.h"
#include "game_01/scratchpad.h"
#include "game_01/unit_00157CC0.h"

typedef struct Obj {
    u8 unk_00[0x10];
    u128 unk_10;
    u8 unk_20[0x10];
    u128 unk_30;
    u8 unk_40[0x20];
    u32 unk_60;
    u8 unk_64[0x16C];
    u8 unk_1D0;
    u8 unk_1D1[0x5F];
    u128 unk_230;
    u128 unk_240;
    u8 unk_250[0x40];
    u8 unk_290[0x10];
} Obj;

void func_00159E20(Obj1F0 *arg0, ObjCC *arg1);

extern s32 func_00131B30(Obj *arg0, void *arg1, f32 *arg2, ObjC8 *arg3, void *arg4);

extern s32 D_005CFC30;

extern s32 D_0069C510;

void func_0012AF20();

void * __nw__FUi(u32);

typedef struct Obj3B0 {
    void *unk_0;
    u8 unk_4[0x24];
    void *unk_28;
    u8 unk_2C[4];
    u8 unk_30[0x380];
} Obj3B0;

typedef struct Obj_00159E80 {
    u8 unk_0[0xB0];
    Obj3B0 *unk_B0;
} Obj_00159E80;

/* the object whose quadword at +0x10 is passed to func_0016B960 and copied whole */
typedef struct Obj_00159520 {
    u8 unk_00[0x10];
    /* 0x10 */ Quad unk_10;
} Obj_00159520;

typedef struct Obj_006A6988 {
    s32 unk_0;
    s32 unk_4;
} Obj_006A6988;

extern Obj_006A6988 *D_006A6988;

extern u8 D_006A69D8;

void func_0012AA10(f32, void *, s32);

void func_0016B960(Quad *arg0, f32 arg1);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00158C80);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00158FD0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_001591C0);

void *func_00159330(Obj1F0 *o) {
    return &o->unk_1E0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159340);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159370);

void func_00159400(Obj1F0 *arg0, ObjCC *arg1)
{
    switch (arg1->unk_C0) {
    case 0:
        func_00159E20(arg0, arg1);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159430);

/* fills a parameter block from the scratchpad quadword at 0x70000BE0, then refills it from
   the object's quadword at +0x10 and hands it to the 0x60-byte object operator new returns */
void func_00159520(Obj_00159520 *arg0)
{
    Sub_001584D0 params;
    void *obj;

    params.unk_0 = *SPR_QUAD;
    params.unk_10 = 10.0f;
    params.unk_14 = 1.0f;
    params.unk_18 = 0.25f;
    params.unk_1C = 0;
    params.unk_20 = 2;
    params.unk_24 = 0x40;
    if (D_006A69D8 != 0) {
        func_0012AA10(0.7f, &D_006A6988->unk_4, 8);
    }
    func_0016B960(&arg0->unk_10, 1.0f);
    params.unk_0 = arg0->unk_10;
    params.unk_10 = 6.0f;
    params.unk_14 = 1.0f;
    params.unk_1C = 0;
    params.unk_20 = 0x12;
    params.unk_24 = 0x78;
    if ((obj = __nw__FUi(0x60)) != 0) {
        func_001584D0(obj, &params);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159650);

void func_00159820(Obj1F0 *a0, f32 *a1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    a0->unk_230 = a0->unk_10;
    a0->unk_240 = a0->unk_30;
    f3 = a0->unk_290;
    f2 = a0->unk_294;
    f1 = a0->unk_298;
    f0 = a0->unk_29C;
    a1[0] = f3;
    a1[1] = f2;
    a1[2] = f1;
    a1[3] = f0;
    (void)f0;
    (void)f1;
    (void)f2;
    (void)f3;
}

// registers: out = the f32 func_00131B30 writes through its third argument
s32 func_00159860(Obj *arg0, ObjC8 *arg1)
{
    f32 out;

    arg0->unk_230 = arg0->unk_10;
    arg0->unk_240 = arg0->unk_30;
    if (func_00131B30(arg0, arg0->unk_290, &out, arg1, arg1->unk_80) != 0) {
        if (arg0->unk_1D0 != 0) {
            arg0->unk_60 |= 0x80000;
        } else if (arg1->unk_C4->unk_54 == 4) {
            arg0->unk_60 |= 0x80000;
        }
        arg0->unk_10 = arg0->unk_230;
        arg0->unk_30 = arg0->unk_240;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159920);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159B10);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00158C80", func_00159BF0);

void func_00159E20(Obj1F0 *arg0, ObjCC *arg1) {
    if (arg0->unk_1D0 != 0) {
        arg0->unk_60 |= 0x80000;
    } else if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    arg0->unk_10 = arg0->unk_230;
    arg0->unk_30 = arg0->unk_240;
}

void func_00159E80(Obj_00159E80 *arg0)
{
    Obj3B0 *p;

    if ((p = __nw__FUi(0x3B0)) != 0) {
        func_0012AF20(p, &D_005CFC30);
        p->unk_0 = &D_0069C510;
        p->unk_28 = &p->unk_30;
    }
    arg0->unk_B0 = p;
}
