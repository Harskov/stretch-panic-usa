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
    register u128 *sp;
    register u128 *dp;
    d[0x314] = 1;
    sp = (u128 *)(s + 0x80);
    dp = (u128 *)(d + 0x3A0);
    dp[0] = sp[0];
    dp[1] = sp[1];
    dp[2] = sp[2];
}
