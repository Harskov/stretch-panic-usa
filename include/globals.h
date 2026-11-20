#ifndef GLOBALS_H
#define GLOBALS_H
#include "common.h"
/* The game's global data: every object at a fixed address that the matched code names, declared once,
   in address order, with the types of the objects themselves. An object whose type has its own header
   is declared there, beside the type. */
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Obj_00197260 {
    /* 0x00 */ u128 unk_0[2];
} Obj_00197260;

typedef struct Obj_001972A0 {
    /* 0x00 */ f32 unk_0[6];
} Obj_001972A0;

typedef struct Elem_001A0850 {
    /* 0x00 */ u8 unk_0;
    /* 0x01 */ u8 unk_1;
    /* 0x02 */ u8 unk_2;
    /* 0x03 */ u8 unk_3;
} Elem_001A0850;

typedef struct Obj_001A0840 {
    /* 0x00 */ s32 unk_0;
    u8 pad_4[0xC];
    /* 0x10 */ Elem_001A0850 unk_10[12];
} Obj_001A0840;

typedef union Obj_0012BA80 {
    /* 0x00 */ u128 q0[4];
    /* 0x00 */ f32 unk_0[16];
} Obj_0012BA80;

typedef struct Obj_00546440 {
    /* 0x00 */ char *unk_0;
    /* 0x04 */ char *unk_4;
} Obj_00546440;

typedef struct Obj_005464F0 {
    /* 0x00 */ s32 unk_0;
    /* 0x04 */ s32 unk_4;
    /* 0x08 */ s32 unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} Obj_005464F0;

typedef struct Obj14 {
    /* 0x00 */ char unk_0[0x14];
} Obj14;

typedef struct Obj_00123F70 {
    /* 0x00 */ f32 unk_0;
    /* 0x04 */ f32 unk_4;
    /* 0x08 */ char *unk_8;
    /* 0x0C */ s32 unk_C;
    /* 0x10 */ struct Obj_00123F70 *next;
} Obj_00123F70;

/* The object the global pointer D_006A6B90 holds. Only func_00172410 reaches it so
   far: two float triples at +0x30 and +0x40 that it integrates, each preceded by a
   float (+0x2C, +0x3C) and followed at +0x1C and +0x4C by the two floats it stores
   outright. */
typedef struct Obj6A6B90 {
    unsigned char unk_00[0x1C];
    f32 unk_1C;
    unsigned char unk_20[0xC];
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
} Obj6A6B90;

typedef struct Obj_001318C0 Obj_001318C0;

struct Obj_001318C0 {
    s32 *unk_00;
    u8 pad_04[0x50];
    s32 unk_54;
    s32 unk_58;
    u8 pad_5C[4];
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
    /* 0x6C */ Obj_001318C0 *link_6C;
    /* 0x70 */ Obj_001318C0 *link_70;
    /* 0x74 */ Obj_001318C0 *link_74;
    /* 0x78 */ Obj_001318C0 *link_78;
    /* 0x7C */ Obj_001318C0 *link_7C;
    /* 0x80 */ Obj_001318C0 *link_80;
    /* 0x84 */ Obj_001318C0 *link_84;
    /* 0x88 */ Obj_001318C0 *link_88;
};

typedef struct Obj_00135450 {
    /* 0x00 */ void *unk_0;
    /* 0x04 */ u8 pad_4[0x8C];
    /* 0x90 */ struct Obj_00135450 *link_90;
    /* 0x94 */ struct Obj_00135450 *link_94;
} Obj_00135450;

typedef struct Obj_0014DF80 {
    u8 unk_00[0x60];
    u32 unk_60;
} Obj_0014DF80;

/* The 0x80-byte object func_0013BD60 allocates and publishes in D_006A6D18. */
typedef struct Obj_006A6D18 {
    /* 0x00 */ u8 pad_0[0x60];
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
} Obj_006A6D18;

/*
 * data_game  (0x00197250-0x00699800)
 */
extern Obj_00197260 D_00197260;
extern Obj_00197260 D_00197280;
extern Obj_001972A0 D_001972A0;
extern s32 D_001972C4;
extern s32 D_001972C8;
extern s32 D_001972CC;
extern volatile u64 D_0019F4A0;
extern volatile u64 D_0019F4A8;
extern Obj_001A0840 D_001A0840;
extern u8 D_001A0850[];
extern u8 D_001A0851[];
extern s32 D_001A0970[];
extern Obj_0012BA80 D_001A09E0;
extern s32 D_001A37E0;
extern s32 D_001A37E4;
extern s32 D_001A37E8;
extern s32 D_001A37EC;
extern s32 D_001A37F0;
extern s32 D_001A37F4;
extern s32 D_001A37F8;
extern s32 D_001A37FC;
extern s32 D_001A3800;
extern s32 D_001A3804;
extern s32 D_001A3808;
extern s32 D_001A380C;
extern s32 D_001A3810;
extern s32 D_001A3814;
extern s32 D_001BEE08;
extern Obj_00546440 D_00546440[];
extern Obj_005464F0 D_005464F0[];
extern s32 D_005AFAE0;
extern s32 D_005CFC30;
extern s32 D_005D99A0;
extern s32 D_005D99BC;
extern s32 D_00601A00;
extern Quad D_00601A40;
extern s32 D_00601A50;
extern s32 D_00601A80;
extern s32 D_00601BB0;
extern s32 D_00601BD0[];
extern s32 D_0062FEA0;
extern Quad D_00677D60;

/*
 * rodata_00  (0x00699800-0x0069F800)
 */
extern char D_0069B250[];
extern char D_0069B270[];
extern char gFormat_69B290[];
extern char D_0069B2C0[];
extern char gFormat_69B2E0[];
extern char D_0069B300[];
extern char gFormat_69B320[];
extern char D_0069B340[];
extern char gFormat_69B360[];
extern char gFormat_69B380[];
extern char gFormat_69B3C0[];
extern char gFormat_69B3D8[];
extern char D_0069B800[];
extern char D_0069B820[];
extern s32 gFormat_69B840;
extern s32 gFormat_69B870;
extern char D_0069BC78[];
extern char gFormat_69BDF8[];
extern char gFormat_69BE08[];
extern Obj14 D_0069BE20;
extern char D_0069BE38[];
extern char D_0069BE40[];
extern char D_0069BE50[];
extern Obj14 D_0069BEC0;
extern char D_0069BED8[];
extern s32 D_0069C1B0;
extern s32 D_0069C1C0;
extern s32 D_0069C1E0;
extern s32 D_0069C1F0;
extern s32 D_0069C200;
extern s32 D_0069C250;
extern s32 D_0069C270;
extern s32 D_0069C290;
extern s32 D_0069C300;
extern s32 D_0069C330;
extern s32 D_0069C360;
extern s32 D_0069C390;
extern s32 D_0069C3C0;
extern s32 D_0069C3F0;
extern s32 D_0069C420;
extern s32 D_0069C450;
extern s32 D_0069C480;
extern s32 D_0069C4B0;
extern s32 D_0069C4E0;
extern s32 D_0069C510;
extern s32 D_0069C540;
extern s32 D_0069C5B0;
extern s32 D_0069C5D0;
extern s32 D_0069C5F0;
extern s32 D_0069C610;
extern s32 D_0069C670;
extern s32 D_0069C690;
extern s32 D_0069C6B0;
extern s32 D_0069C6D0;
extern s32 D_0069C6F0;
extern s32 D_0069C708;
extern s32 D_0069C718;
extern s32 D_0069C760;
extern s32 D_0069C780;
extern s32 D_0069C7B0;
extern s32 D_0069C7E0;
extern s32 D_0069C810;
extern s32 D_0069C840;
extern s32 D_0069C870;
extern s32 D_0069C8B0;
extern s32 D_0069C8E0;
extern s32 D_0069C910;
extern s32 D_0069C940;
extern s32 D_0069C970;
extern s32 D_0069C9A0;
extern s32 D_0069C9D0;
extern s32 D_0069CA70;
extern s32 D_0069CAA0;
extern s32 D_0069CAF0;
extern s32 D_0069CB20;
extern s32 D_0069CB50;
extern s32 D_0069CB80;
extern s32 D_0069CBB0;
extern s32 D_0069CBE0;
extern s32 D_0069CC10;
extern s32 D_0069CC40;
extern s32 D_0069CC70;
extern s32 D_0069CCA0;
extern s32 D_0069CCD0;
extern s32 D_0069CDD0;
extern s32 D_0069CEA0;
extern s32 D_0069CED0;
extern s32 D_0069CF00;
extern s32 D_0069CF30;
extern s32 D_0069CF60;
extern s32 D_0069CF90;
extern s32 D_0069CFC0;
extern s32 D_0069D020;
extern s32 D_0069D050;
extern s32 D_0069D080;
extern s32 D_0069D0E0;
extern s32 D_0069D150;
extern s32 D_0069D250;
extern s32 D_0069D280;
extern s32 D_0069D320;
extern s32 D_0069D390;
extern s32 D_0069D3C0;
extern s32 D_0069D3F0;
extern s32 D_0069D420;
extern s32 D_0069D450;
extern s32 D_0069D4B0;
extern s32 D_0069F794;

/*
 * main_bss  (0x0069F800-0x006B3900)
 */
extern void *D_006A66E8;
extern s32 D_006A66F0;
extern s32 D_006A6700;
extern s32 D_006A6704;
extern f32 D_006A6708;
extern s64 D_006A6728;
extern Obj_00123F70 *D_006A6738;
extern s32 D_006A6980;
extern s32 D_006A6990;
extern s32 D_006A6998;
extern s32 D_006A69A0;
extern u8 D_006A69A8;
extern u8 D_006A69B8;
extern u8 D_006A69C0;
extern u8 D_006A69D0;
extern u8 D_006A69D8;
extern u8 D_006A69E0;
extern u8 D_006A69E8;
extern u8 D_006A69F0;
extern s32 D_006A69F8;
extern u8 D_006A6A00[];
extern Obj6A6B90 *D_006A6B90;
extern f32 *D_006A6BA0;
extern f32 *D_006A6BA8;
extern f32 *D_006A6BB8;
extern s32 D_006A6C00;
extern Obj_001318C0 *D_006A6C08;
extern Obj_001318C0 *D_006A6C10[];
extern Obj_001318C0 *D_006A6CB0;
extern Obj_00135450 *D_006A6CF0;
extern s32 D_006A6D00;
extern s32 D_006A6D08;
extern s32 *D_006A6D10;
extern Obj_006A6D18 *D_006A6D18;
extern s32 D_006A6D20;
extern s32 D_006A6D30;
extern s32 D_006A6D38;
extern u8 D_006A6D40[2][0x4000];
extern int D_006AED40[2];
extern int D_006AED48;
extern int D_006AED50;
extern int D_006AED74;
extern s32 D_006AED78;
extern s8 D_006AED80;
extern s32 D_006AEDD0;
extern s32 D_006AEDD8;
extern s32 D_006AEDE0;
extern s32 D_006AEE20;
extern s32 D_006AEE28;
extern s32 D_006AEE30;
extern s32 D_006AEE38;
extern Vec D_006AEE40;
extern u8 D_006AEE58;
extern u8 D_006AEE60;
extern s32 D_006AEE68;
extern s32 D_006AEE70;
extern s32 D_006AEE78;
extern s32 D_006AEE80;
extern s32 D_006AEE88;
extern s32 D_006AEE90;
extern s32 D_006AEE98;
extern s32 D_006AEEA0;
extern s32 D_006AEEA8;
extern s32 D_006AEEB0;
extern s32 D_006AEEB8;
extern s32 D_006AEEC0;
extern s32 D_006AEEC8;
extern s32 D_006AEED0;
extern s32 D_006AEED8;
extern s32 D_006AEEF0;
extern s32 D_006AEEF8;
extern s32 D_006AEF00;
extern s32 D_006AEF08;
extern s32 D_006AEF10;
extern s32 D_006AEF18;
extern s32 D_006AEF20;
extern s32 D_006AEF28;
extern s32 D_006AEF38;
extern s32 D_006AEF40;
extern s32 D_006AEF48;
extern s32 D_006AEF50;
extern s32 D_006AEF58;
extern s32 D_006AEF78;
extern s32 D_006AEF80;
extern s32 D_006AEF88;
extern s32 D_006AEF90;
extern s32 D_006AEFD0;
extern Obj14 D_006AEFE0;
extern s32 D_006AF040;
extern s32 D_006AF050;
extern s32 D_006AF098;
extern s32 D_006AF0A0[];
extern s32 D_006AF0A4[];
extern s32 D_006AF4A0;
extern Vec D_006AF4B0;
extern s32 D_006AF4C0;
extern Obj_0014DF80 *D_006AF4D8;
extern s32 D_006AF4E8;
extern s32 D_006B3580[];
extern s32 D_006B3888;
extern s32 D_006B3890;
extern s32 D_006B38A0;

/*
 * other  (0x00000000-0x00000000)
 */
extern s32 D_EF0100;

#ifdef __cplusplus
}
#endif
#endif /* GLOBALS_H */
