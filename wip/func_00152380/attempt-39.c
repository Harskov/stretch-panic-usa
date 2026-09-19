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

typedef struct Src {
    u8 pad0[0x414];
    u8 b414;
    u8 pad1[0x5B];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
    u8 pad2[0x108];
    u128 v140;
    u8 pad3[0x100];
    u128 v250;
    u128 v260;
    u128 v270;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Dst;

void func_00152380(Src *src, Dst *dst) {
    f32 q = src->f470;
    f32 r = src->f474;
    f32 s = src->f478;
    f32 t = src->f47C;
    src->b414 = 0;
    dst->f50 = q;
    dst->f54 = r;
    dst->f58 = s;
    dst->f5C = t;
    dst->i60 = src->i480;
    dst->v30 = src->v140;
    dst->v0 = src->v250;
    dst->v10 = src->v260;
    dst->v20 = src->v270;
    dst->f50 = -dst->f50;
    dst->f54 = -dst->f54;
    dst->f58 = -dst->f58;
}
