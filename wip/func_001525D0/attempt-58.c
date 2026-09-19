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

void func_001525D0(char *arg0, char *arg1) {
    u8 *dst = (u8 *)arg0;
    u8 *src = (u8 *)arg1;
    u128 a, b, c;
    a = *(u128 *)(src + 0x80);
    b = *(u128 *)(src + 0x90);
    c = *(u128 *)(src + 0xA0);
    dst[0x314] = 1;
    *(u128 *)(dst + 0x3A0) = a;
    *(u128 *)(dst + 0x3B0) = b;
    *(u128 *)(dst + 0x3C0) = c;
}
