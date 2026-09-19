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

void func_001525D0(void *arg0, void *arg1) {
    u8 *d = (u8 *)arg0;
    u8 *s = (u8 *)arg1;
    d[0x314] = 1;
    *(u128 *)(d + 0x3A0) = *(u128 *)(s + 0x80);
    *(u128 *)(d + 0x3B0) = *(u128 *)(s + 0x90);
    *(u128 *)(d + 0x3C0) = *(u128 *)(s + 0xA0);
}
