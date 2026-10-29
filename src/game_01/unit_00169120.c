#include "common.h"

typedef struct Sub_00169930 {
    /* 0x00 */ u8 pad_0[0x10];
    /* 0x10 */ Quad unk_10;
    /* 0x20 */ u8 pad_20[0x30];
    /* 0x50 */ u8 unk_50;
} Sub_00169930;

typedef struct Elem_00169930 {
    /* 0x00 */ f32 unk_0;
    /* 0x04 */ f32 unk_4;
    /* 0x08 */ f32 unk_8;
    /* 0x0C */ u8 pad_C[4];
    /* 0x10 */ Vec unk_10;
    /* 0x20 */ Sub_00169930 *unk_20;
    /* 0x24 */ u8 pad_24[0xC];
} Elem_00169930;

typedef struct Obj_00169930 {
    /* 0x000 */ u8 pad_0[0x60];
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ u8 pad_64[0x2C];
    /* 0x090 */ u8 unk_90[0x50];
    /* 0x0E0 */ Elem_00169930 unk_E0[2];
    /* 0x140 */ s32 unk_140;
} Obj_00169930;

void * __nw__FUi(u32);

f32 cosf(f32);

f32 sinf(f32);

void func_0012CA60(void *, Vec *, Quad *);

void func_00163A90(void *, Quad *, s32, s32, s32, s32, f32);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_00169120);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_001692B0);

void func_00169590(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_001695A0);

void func_001696B0(void) {
}

void func_001696C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_001696D0);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_00169870);

/* Steps the angle of both elements, places each on its circle (sin, cos) through
   func_0012CA60, and every fourth call spawns a 0x80-byte object at the result. */
int func_00169930(Obj_00169930 *o)
{
    Quad q;
    Sub_00169930 *sub;
    void *p;
    s32 i;

    for (i = 0; i < 2; i++) {
        o->unk_E0[i].unk_4 += o->unk_E0[i].unk_8;
        o->unk_E0[i].unk_10.x = o->unk_E0[i].unk_0 * sinf(o->unk_E0[i].unk_4);
        o->unk_E0[i].unk_10.z = o->unk_E0[i].unk_0 * cosf(o->unk_E0[i].unk_4);
        func_0012CA60(o->unk_90, &o->unk_E0[i].unk_10, &q);
        sub = o->unk_E0[i].unk_20;
        sub->unk_10 = q;
        sub->unk_50 = 1;
        if ((o->unk_140 & 3) == 0) {
            p = __nw__FUi(0x80);
            if (p != 0) {
                func_00163A90(p, &q, 1, 0, 2, 0x10, 0.33333334f);
            }
        }
    }
    o->unk_140++;
    return !(o->unk_60 & 0x10000);
}

void func_00169A40(void) {
}

void func_00169A50(void) {
}

void func_00169A60(void) {
}

int func_00169A70(void) {
    return 0;
}

void func_00169A80(void) {
}

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_00169A90);

INCLUDE_ASM("asm/nonmatchings/game_01/unit_00169120", func_00169E00);
