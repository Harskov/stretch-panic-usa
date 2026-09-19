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
    u8 pad1[0x100];
    Vec v250;
    Vec v260;
    Vec v270;
    u8 pad2[0x200];
    u8 b414;
    u8 pad3[0x5B];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
} Src;

typedef struct Dst {
    Vec v0;
    Vec v10;
    Vec v20;
    Vec v30;
    u8 pad0[0x10];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    u8 *src = (u8 *)arg0;
    u8 *dst = (u8 *)arg1;
    *(u8 *)(src + 0x414) = 0;
    *(f32 *)(dst + 0x50) = *(f32 *)(src + 0x470);
    *(f32 *)(dst + 0x54) = *(f32 *)(src + 0x474);
    *(f32 *)(dst + 0x58) = *(f32 *)(src + 0x478);
    *(f32 *)(dst + 0x5C) = *(f32 *)(src + 0x47C);
    *(s32 *)(dst + 0x60) = *(s32 *)(src + 0x480);
    *(u128 *)(dst + 0x30) = *(u128 *)(src + 0x140);
    *(u128 *)(dst + 0x00) = *(u128 *)(src + 0x250);
    *(u128 *)(dst + 0x10) = *(u128 *)(src + 0x260);
    *(u128 *)(dst + 0x20) = *(u128 *)(src + 0x270);
    *(f32 *)(dst + 0x20) = -*(f32 *)(dst + 0x20);
    *(f32 *)(dst + 0x24) = -*(f32 *)(dst + 0x24);
    *(f32 *)(dst + 0x28) = -*(f32 *)(dst + 0x28);
}
