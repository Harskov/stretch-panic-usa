#include "common.h"
#include "game_00/obj_001211E0.h"

typedef struct Obj_0011F5E0 {
    /* 0x00 */ unsigned short unk_0[9];
} Obj_0011F5E0;

typedef struct Obj_0011F5E0_2 {
    unsigned char unk_00[0x18];
    /* 0x18 */ unsigned short unk_18;
    /* 0x1A */ unsigned short unk_1A;
    /* 0x1C */ unsigned short unk_1C;
    /* 0x1E */ unsigned short unk_1E;
    /* 0x20 */ Obj_0011F5E0 unk_20;
    /* 0x32 */ Obj_0011F5E0 unk_32;
} Obj_0011F5E0_2;

typedef struct Obj_00197260 {
    /* 0x00 */ u128 unk_0[2];
} Obj_00197260;

typedef struct Obj_001972A0 {
    /* 0x00 */ f32 unk_0[6];
} Obj_001972A0;

typedef struct Obj_006A6D18 {
    /* 0x00 */ u8 pad_0[0x60];
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
} Obj_006A6D18;

extern char D_0069B250[];

extern char D_0069B270[];

extern char D_0069B290[];

extern char D_0069B2C0[];

extern char D_0069B2E0[];

extern char D_0069B300[];

extern char D_0069B320[];

extern char D_0069B340[];

extern char D_0069B360[];

extern char D_0069BC78[];

extern Obj_00197260 D_00197260;

extern Obj_00197260 D_00197280;

extern Obj_001972A0 D_001972A0;

extern void *D_006A66E8;

extern s32 D_006A6730;

extern s32 *D_006A6D10;

extern Obj_006A6D18 *D_006A6D18;

extern s32 D_006A6D30;

extern s32 D_006A6D38;

s32 sceSifInitRpc(s32 mode);

s32 sceSifRebootIop(const char *img);

s32 sceSifSyncIop(void);

s32 sceCdInit(s32 init_mode);

s32 sceCdMmode(s32 media);

s32 sceCdReadClock(u8 *clock);

s32 sceGsSyncV(s32 mode);

void sceDmaReset(s32 mode);

void sceGsResetPath(void);

void sceGsResetGraph(s16 mode, s16 inter, s16 omode, s16 ffmode);

void sceVpu0Reset(void);

s32 printf(const char *fmt, ...);

void *__nw__FUi(u32 size);

s32 func_0010C610(char *path, s32 arg1, s32 arg2);

void func_00119AA0(u32 arg0);

void func_00121640(void *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_001238D0(void);

void func_0012E6D0(void *arg0);

s32 func_00127FD0(void *arg0);

void func_0013BD60(s32 arg0);

s32 func_0013C510(s32 arg0, char *arg1);

void func_0013C590(s32 arg0, s32 *arg1);

s32 func_0013DBF0(void);

void func_0013E160(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_0013E1A0(s32 arg0);

void func_00145F00(void);

typedef struct Obj_00120A50 {
    /* 0x00 */ u8 pad_0[0x1C];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u8 pad_24[4];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ u8 pad_30[8];
    /* 0x38 */ s32 unk_38;
} Obj_00120A50;

extern s32 D_EF0100;

void func_00100000();

void *func_001006F0(s64 size);

void __dla__FPv(void *p);

typedef struct Obj_001209F0 {
    /* 0x00 */ u8 pad_0[0x3C];
    /* 0x3C */ s32 unk_3C;
} Obj_001209F0;

void func_00117C00();

void __dl__FPv(void *p);

extern s32 D_0069C1B0;

void func_00120830();

typedef struct Obj_001202B0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s32 unk_4;
} Obj_001202B0;

void func_00120230();

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011F5E0);

void func_0011FA00(void)
{
    s32 start = (s32)&D_EF0100;
    s32 base = (s32)func_00100000 + 0x1000;
    s32 end = start + base + 0x1000;

    __dla__FPv(func_001006F0((s64)(0x1FFFFF0 - end)));
}

/* Boot-time set-up: reboots the IOP with the image at D_0069B250, loads four IOP
   modules (retrying with a message until each loads), then seeds func_00119AA0 from
   the CD clock and resets DMA, the GS and VU0. */
void func_0011FA50(void)
{
    u8 clock[8];
    void *o;
    Obj_006A6D18 *p;

    sceSifInitRpc(0);
    while (sceCdInit(0) == 0)
        ;
    sceCdMmode(1);
    while (sceSifRebootIop(D_0069B250) == 0)
        ;
    while (sceSifSyncIop() == 0)
        ;
    sceSifInitRpc(0);
    while (sceCdInit(0) == 0)
        ;
    sceCdMmode(1);

    while (func_0010C610(D_0069B270, 0, 0) < 0)
        printf(D_0069B290);
    while (func_0010C610(D_0069B2C0, 0, 0) < 0)
        printf(D_0069B2E0);
    while (func_0010C610(D_0069B300, 0, 0) < 0)
        printf(D_0069B320);
    while (func_0010C610(D_0069B340, 0, 0) < 0)
        printf(D_0069B360);

    func_0013DBF0();
    func_00145F00();

    if ((o = __nw__FUi(0x28)) != 0)
        func_001211E0(o);
    D_006A66E8 = o;
    func_00121640(D_006A66F8, 0, 1, 1);

    while (sceCdReadClock(clock) == 0)
        sceGsSyncV(0);
    func_00119AA0((clock[5] * 3) << 24 | (clock[3] * 3) << 16 | (clock[2] * 3) << 8 | clock[1] * 3 | 1);

    sceDmaReset(1);
    sceGsResetPath();
    sceGsResetGraph(0, 1, 2, 0);
    sceVpu0Reset();

    func_0012E6D0((void *)0x70000000);
    D_006A6730 = func_00127FD0((void *)0x70000C10);
    *(Obj_00197260 *)0x70003B80 = D_00197260;
    *(Obj_00197260 *)0x70003BA0 = D_00197280;
    *(Obj_001972A0 *)0x70003BC0 = D_001972A0;
    func_0013BD60(3);

    p = D_006A6D18;
    p->unk_60 = 0.0f;
    p->unk_64 = 0.0f;
    p->unk_68 = 0.0f;
    p->unk_6C = 101325.0f;
    p->unk_70 = 5.525f;
    func_0013E160(0, 0, 0, 0, 0, 0, 0);
    func_0013E1A0(0);
    *D_006A6D10 = func_0013C510(0, D_0069BC78);
    func_0013C590(0x10000, &D_006A6D30);
    func_0013C590(0x10000, &D_006A6D38);
    func_001238D0();
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FE50);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_0011FEA0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120100);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120160);

s32 **func_001201D0(s32 **arg0, s16 arg1)
{
    if (arg0 != 0) {
        *arg0 = &D_0069C1B0;
        func_00120830();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120230);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120270);

void func_001202B0(Obj_001202B0 *arg0)
{
    func_00120830();
    arg0->unk_4 = 1;
    func_00120230(arg0);
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001202F0);

void func_00120340(Obj_0011F5E0_2 *p) {
    u16 cur;
    cur = p->unk_32.unk_0[0];
    p->unk_1C = p->unk_20.unk_0[0] ^ cur;
    p->unk_1A = p->unk_1C & cur;
    p->unk_1E = p->unk_1C ^ p->unk_1A;
    p->unk_18 = cur;
    p->unk_20 = p->unk_32;
}

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001203A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001207D0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120830);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_001208A0);

INCLUDE_ASM("asm/nonmatchings/game_00/unit_0011F5E0", func_00120970);

Obj_001209F0 *func_001209F0(Obj_001209F0 *o, s16 flags)
{
    if (o != 0) {
        func_00117C00(o->unk_3C);
        if (flags > 0) {
            __dl__FPv(o);
        }
    }
    return o;
}

void func_00120A50(Obj_00120A50 *o)
{
    o->unk_1C = 0;
    o->unk_22 = 0;
    o->unk_20 = 0;
    o->unk_28 = 1;
    o->unk_2C = 0;
    o->unk_38 = 0;
}
