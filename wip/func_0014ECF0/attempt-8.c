typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

extern s32 D_00567F80;
extern u128 D_005A52F0[5];
extern u128 D_005A5300[1];

typedef struct Init {
    u128 q;
} Init;

typedef struct Obj {
    u8 pad0[0x570];
    s32 unk_570;
    s32 unk_574;
    u8 pad1[8];
    u128 unk_580;
    f32 unk_590;
    f32 unk_594;
    f32 unk_598;
    f32 unk_59C;
    Init init[5];
} Obj;

void func_0014ECF0(Obj *arg0) {
    Init *src;
    Init *dst;

    arg0->unk_570 = 0;
    arg0->unk_574 = 0;
    src = (Init *)D_005A5300;
    arg0->unk_580 = src->q;
    arg0->unk_590 = 1.0f;
    arg0->unk_594 = 0.1f;
    arg0->unk_598 = 0.1f;
    arg0->unk_59C = 1.0f;
    src = (Init *)D_005A52F0;
    dst = arg0->init;
    dst[0].q = src[0].q;
    dst[1].q = src[1].q;
    dst[2].q = src[2].q;
    dst[3].q = src[3].q;
    dst[4].q = src[4].q;
    D_00567F80 = (s32)dst;
}
