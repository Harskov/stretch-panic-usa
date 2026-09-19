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
    register u128 *rp0 asm("a0");
    register u128 *rp1 asm("a1");
    rp0 = (u128 *)arg0;
    rp1 = (u128 *)arg1;
    *(u8 *)((char *)rp0 + 0x314) = 1;
    rp0[0x3A0 / 16] = rp1[0x80 / 16];
    rp0[0x3B0 / 16] = rp1[0x90 / 16];
    rp0[0x3C0 / 16] = rp1[0xA0 / 16];
}
