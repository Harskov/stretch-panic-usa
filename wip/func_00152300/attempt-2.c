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

void func_00152300(char *arg0, char *arg1) {
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;

    *(u8 *)(arg0 + 0x314) = 0;
    f3 = *(f32 *)(arg0 + 0x370);
    f2 = *(f32 *)(arg0 + 0x374);
    f1 = *(f32 *)(arg0 + 0x378);
    f0 = *(f32 *)(arg0 + 0x37C);
    *(f32 *)(arg1 + 0x50) = f3;
    *(f32 *)(arg1 + 0x54) = f2;
    *(f32 *)(arg1 + 0x58) = f1;
    *(f32 *)(arg1 + 0x5C) = f0;
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x250);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x260);
    *(u128 *)(arg1 + 0x20) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = -*(f32 *)(arg1 + 0x20);
    *(f32 *)(arg1 + 0x24) = -*(f32 *)(arg1 + 0x24);
    *(f32 *)(arg1 + 0x28) = -*(f32 *)(arg1 + 0x28);
    *(s32 *)(arg1 + 0x60) = *(s32 *)(arg0 + 0x380);
    *(f32 *)(arg1 + 0x64) = *(f32 *)(arg0 + 0x384);
    *(s32 *)(arg1 + 0x68) = 0;
    *(s32 *)(arg1 + 0x6C) = 0;
    *(s32 *)(arg1 + 0x70) = 0;
}
