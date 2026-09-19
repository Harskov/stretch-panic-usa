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
extern u128 D_005A52F0[];
extern u128 D_005A5300[];

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
    u128 unk_5A0;
    u128 unk_5B0;
    u128 unk_5C0;
    u128 unk_5D0;
    u128 unk_5E0;
} Obj;

void func_0014ECF0(Obj *arg0) {
    u128 *src;
    u128 *dst;

    arg0->unk_570 = 0;
    arg0->unk_574 = 0;
    src = D_005A5300;
    arg0->unk_580 = src[0];
    arg0->unk_590 = 1.0f;
    arg0->unk_594 = 0.1f;
    arg0->unk_598 = 0.1f;
    arg0->unk_59C = 1.0f;
    src = D_005A52F0;
    dst = &arg0->unk_5A0;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    D_00567F80 = (s32)dst;
}
