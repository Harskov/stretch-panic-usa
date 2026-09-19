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
    u128 v0;
    u128 v1;
    u128 v2;
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
    u128 v0;
    u128 v1;
    Vec v2;
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

void func_00152300(Src *arg0, Dst *arg1) {
    arg0->f314 = 0;
    arg1->f50 = arg0->f37C;
    arg1->f54 = arg0->f378;
    arg1->f58 = arg0->f374;
    arg1->f5C = arg0->f370;
    *(u128 *)&arg1->v0 = arg0->v0;
    *(u128 *)&arg1->v1 = arg0->v1;
    *(u128 *)&arg1->v2 = arg0->v2;
    arg1->v2.x = -arg1->v2.x;
    arg1->v2.y = -arg1->v2.y;
    arg1->v2.z = -arg1->v2.z;
    arg1->f60 = arg0->f380;
    arg1->f64 = arg0->f384;
    arg1->f68 = 0;
    arg1->f6C = 0;
    arg1->f70 = 0;
}
