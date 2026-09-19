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
    u128 *p = (u128 *)(arg1 + 0x80);
    u128 *q = (u128 *)(arg0 + 0x3A0);
    register u128 x0;
    register u128 x1;
    register u128 x2;
    x0 = p[0];
    x1 = p[1];
    x2 = p[2];
    *(u8 *)(arg0 + 0x314) = 1;
    q[0] = x0;
    q[1] = x1;
    q[2] = x2;
}
