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
    u8 pad0[0x140];
    Vec v140;
    u8 pad1[0x10];
    Vec v150;
    Vec v160;
    Vec v170;
    u8 pad2[0xE0];
    u8 b250;
    u8 pad3[0x1C3];
    f32 f414;
    u8 pad4[0x5B];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
} Src;
