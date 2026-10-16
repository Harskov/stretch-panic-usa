#include "common.h"

typedef struct Obj_001211E0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ u8  unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} Obj_001211E0;

extern Obj_001211E0 *D_006A66F8;


void func_00121250(Obj_001211E0 *o);

typedef struct Sub_001216E0 {
    /* 0x00 */ u8 unk_0[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u8 unk_1C[0x20];
    /* 0x3C */ s32 unk_3C;
} Sub_001216E0;

typedef struct Obj_001216E0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ u8 unk_4[0xC];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Sub_001216E0 *unk_14;
} Obj_001216E0;

extern char D_0069B3C0[];

s32 scePadInit(s32 mode);

s32 scePadPortOpen(s32 port, s32 slot, s32 addr);

s32 printf(const char *fmt, ...);

void func_00120A50(Sub_001216E0 *e);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120A70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120C00);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120CE0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120D90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DF0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120E30);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120E70);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121100);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001211C0);

// probably the pad handler's constructor (it starts libpad): the one instance is published in D_006A66F8,
// and a failed scePadInit hangs rather than returning
Obj_001211E0 *func_001211E0(Obj_001211E0 *o)
{
    D_006A66F8 = o;
    if (scePadInit(0) == 0) {
        while (1) {}
    }
    o->unk_18 = 0;
    o->unk_0  = 0;
    o->unk_4  = 0;
    o->unk_8  = 0;
    o->unk_C  = 0;
    o->unk_10 = 0;
    o->unk_14 = 0;
    o->unk_1C = 0;
    func_00121250(o);
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121250);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001213F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001214F0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001215A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_001215E0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121640);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00121690);

/* When bit 0 of unk_0 is set: scePadInit, then scePadPortOpen for each of the
   unk_10 entries, hanging on a failure; the bit is cleared afterwards. */
void func_001216E0(Obj_001216E0 *o)
{
    s32 port;
    s32 slot;
    s32 i;

    if (o->unk_0 & 1) {
        if (scePadInit(0) == 0) {
            while (1) {
            }
        }
        for (i = 0; i < o->unk_10; i++) {
            port = o->unk_14[i].unk_14;
            slot = o->unk_14[i].unk_18;
            func_00120A50(&o->unk_14[i]);
            if (scePadPortOpen(port, slot, o->unk_14[i].unk_3C) == 0) {
                printf(D_0069B3C0);
                while (1) {
                }
            }
        }
        o->unk_0 &= ~1;
    }
}
