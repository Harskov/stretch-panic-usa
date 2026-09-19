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
    u8 pad0[0x414];
    u8 b414;
    u8 pad1[0x5B];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
    u8 pad2[0x100];
    u128 v250;
    u128 v260;
    u128 v270;
} Src;

void func_00152380(Src *arg0, char *arg1) {
    arg0->b414 = 0;
    *(f32 *)(arg1 + 0x50) = arg0->f470;
    *(f32 *)(arg1 + 0x54) = arg0->f474;
    *(f32 *)(arg1 + 0x58) = arg0->f478;
    *(f32 *)(arg1 + 0x5C) = arg0->f47C;
    *(s32 *)(arg1 + 0x60) = arg0->i480;
    *(u128 *)(arg1 + 0x30) = *(u128 *)((char *)arg0 + 0x140);
    *(u128 *)(arg1 + 0x0) = arg0->v250;
    *(u128 *)(arg1 + 0x10) = arg0->v260;
    *(u128 *)(arg1 + 0x20) = arg0->v270;
    *(f32 *)(arg1 + 0x20) = -*(f32 *)(arg1 + 0x20);
    *(f32 *)(arg1 + 0x24) = -*(f32 *)(arg1 + 0x24);
    *(f32 *)(arg1 + 0x28) = -*(f32 *)(arg1 + 0x28);
}
