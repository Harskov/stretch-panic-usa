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

typedef struct Src {
    u8 pad0[0x250];
    Vec v250;
    Vec v260;
    Vec v270;
    u8 pad280[0x314 - 0x280];
    u8 f314;
    u8 pad315[0x370 - 0x315];
    f32 f370;
    f32 f374;
    f32 f378;
    f32 f37C;
    s32 f380;
    f32 f384;
} Src;

typedef struct Dst {
    Vec v0;
    Vec v10;
    Vec v20;
    u8 pad30[0x50 - 0x30];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 f60;
    f32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
} Dst;

void func_00152300(Src *src, Dst *dst) {
    dst->v0 = src->v250;
    dst->v10 = src->v260;
    dst->v20 = src->v270;
    dst->v20.x = -dst->v20.x;
    dst->v20.y = -dst->v20.y;
    dst->v20.z = -dst->v20.z;
    src->f314 = 0;
    dst->f50 = src->f370;
    dst->f54 = src->f374;
    dst->f58 = src->f378;
    dst->f5C = src->f37C;
    dst->f60 = src->f380;
    dst->f64 = src->f384;
    dst->f68 = 0;
    dst->f6C = 0;
    dst->f70 = 0;
}
