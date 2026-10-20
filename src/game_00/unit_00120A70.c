#include "common.h"
#include "game_00/obj_001211E0.h"


void func_00121250(Obj_001211E0 *o);

typedef struct Sub_001216E0 {
    /* 0x00 */ u8 unk_0[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u8 unk_24[0x18];
    /* 0x3C */ s32 unk_3C;
} Sub_001216E0;

typedef struct Obj_001216E0 {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 unk_4[0xC];
    /* 0x10 */ s32 count;
    /* 0x14 */ Sub_001216E0 *unk_14;
} Obj_001216E0;

extern char gFormat_69B3C0[];

s32 scePadInit(s32 mode);

s32 scePadPortOpen(s32 port, s32 slot, s32 addr);

s32 printf(const char *fmt, ...);

void func_00120A50(Sub_001216E0 *e);

s32 scePadGetState(s32 port, s32 slot);

s32 scePadInfoMode(s32 port, s32 slot, s32 term, s32 offs);

s32 scePadInfoPressMode(s32 port, s32 slot);

s32 scePadRead(s32 port, s32 slot, u8 *rdata);

extern char gFormat_69B380[];

void func_0011FE50(Sub_001216E0 *e);

void func_0011FEA0(Sub_001216E0 *e, u8 *rdata);

typedef struct Obj_001211C0 {
    /* 0x00 */ u8 unk_0[0x28];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ u8 unk_2C[4];
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
} Obj_001211C0;

typedef struct Obj_00120CE0 {
    /* 0x00 */ u8 unk_0[0x22];
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ s32 flags_24;
    /* 0x28 */ s32 flags_28;
    /* 0x2C */ s32 flags_2C;
} Obj_00120CE0;

typedef struct Obj_00121100 {
    /* 0x00 */ u8 unk_0[0x24];
    /* 0x24 */ s32 flags;
    /* 0x28 */ s32 unk_28;
} Obj_00121100;

s32 func_00120E70(s32 arg0);

/* Polls one pad: its libpad state, the terminal id of the connected controller
   (0x41, 0x53, 0x73 or 0x79), then the button bytes; a failed scePadRead hangs. */
void func_00120A70(Sub_001216E0 *e)
{
    u8 rdata[32];
    s32 id;
    s32 exid;

    e->unk_1C = scePadGetState(e->unk_14, e->unk_18);
    if (e->unk_1C == 0) {
        e->unk_20 = 0;
    } else if (e->unk_1C == 2) {
        id = scePadInfoMode(e->unk_14, e->unk_18, 1, 0);
        if (id != 0) {
            exid = scePadInfoMode(e->unk_14, e->unk_18, 2, 0);
            if (exid > 0) {
                id = exid;
            }
        }
        if (id == 4) {
            e->unk_20 = 0x41;
        } else if (id == 7) {
            e->unk_20 = 0x53;
        } else {
            e->unk_20 = 0x41;
        }
    } else if (e->unk_1C == 6) {
        if (scePadInfoPressMode(e->unk_14, e->unk_18) == 1) {
            e->unk_20 = 0x79;
        } else {
            e->unk_20 = 0x73;
        }
    }

    if (e->unk_1C == 2 || e->unk_1C == 6) {
        if (scePadRead(e->unk_14, e->unk_18, rdata) == 0) {
            printf(gFormat_69B380);
            while (1) {
            }
        }
        e->unk_22 = (rdata[0] << 8) | rdata[1];
        func_0011FEA0(e, rdata);
    } else {
        e->unk_22 = 0;
        func_0011FE50(e);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120C00);

void func_00120CE0(Obj_00120CE0 *o)
{
    s32 v;

    v = o->flags_28;
    if (v & 1) {
        o->flags_28 = v & ~1;
        o->flags_2C = o->flags_2C | 1;
    }
    if (!(o->flags_2C & 1)) {
        if (o->unk_22 == 0x41) {
            v = o->flags_24;
            if (v & 1) {
                o->flags_24 = v & ~1;
                o->flags_28 = o->flags_28 | 6;
            }
        } else if (o->unk_22 != 0) {
            v = o->flags_24;
            if (!(v & 1)) {
                o->flags_24 = v | 1;
                o->flags_28 = o->flags_28 | 6;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120D90);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DC0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120DF0);

void func_00120E30(s32 arg0)
{
    do {
    } while (func_00120E70(arg0) == 0);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_00120A70", func_00120E70);

/* Sets or clears bit 0 and bit 1 of unk_24 from the two arguments; each actual change sets bit 0 of unk_28
   (probably a changed marker). */
void func_00121100(Obj_00121100 *o, s32 arg1, s32 arg2)
{
    if (arg1 != 0) {
        if (!(o->flags & 1)) {
            o->flags |= 1;
            o->unk_28 |= 1;
        }
    } else {
        if (o->flags & 1) {
            o->flags &= ~1;
            o->unk_28 |= 1;
        }
    }
    if (arg2 != 0) {
        if (!(o->flags & 2)) {
            o->flags |= 2;
            o->unk_28 |= 1;
        }
    } else {
        if (o->flags & 2) {
            o->flags &= ~2;
            o->unk_28 |= 1;
        }
    }
}

void func_001211C0(Obj_001211C0 *o, u8 arg1, u8 arg2)
{
    o->unk_30 = arg1;
    o->unk_31 = arg2;
    o->unk_28 |= 8;
}

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

    if (o->flags & 1) {
        if (scePadInit(0) == 0) {
            while (1) {
            }
        }
        for (i = 0; i < o->count; i++) {
            port = o->unk_14[i].unk_14;
            slot = o->unk_14[i].unk_18;
            func_00120A50(&o->unk_14[i]);
            if (scePadPortOpen(port, slot, o->unk_14[i].unk_3C) == 0) {
                printf(gFormat_69B3C0);
                while (1) {
                }
            }
        }
        o->flags &= ~1;
    }
}
