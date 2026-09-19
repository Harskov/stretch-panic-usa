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

extern s32 D_006A6730;

void func_001502A0(void *arg0, s32 arg1) {
    u8 *base;
    u8 *t0;
    u8 *t1;

    if (arg1 != 3) {
        return;
    }
    base = (u8 *)D_006A6730;
    t0 = *(u8 **)(base + 0x378 * 4 + 0x500);
    *(u128 *)((u8 *)arg0 + 0x230) = *(u128 *)(t0 + 0x0);
    *(u128 *)((u8 *)arg0 + 0x240) = *(u128 *)(t0 + 0x10);
    *(u128 *)((u8 *)arg0 + 0x250) = *(u128 *)(t0 + 0x20);
    *(u128 *)((u8 *)arg0 + 0x260) = *(u128 *)(t0 + 0x30);
    *(u128 *)((u8 *)arg0 + 0x270) = *(u128 *)(t0 + 0x40);
    t1 = *(u8 **)(base + 0x378 * 4 + 0x500);
    *(u128 *)((u8 *)arg0 + 0x280) = *(u128 *)(t1 + 0x0);
    *(u128 *)((u8 *)arg0 + 0x290) = *(u128 *)(t1 + 0x10);
    *(u128 *)((u8 *)arg0 + 0x2A0) = *(u128 *)(t1 + 0x20);
}
