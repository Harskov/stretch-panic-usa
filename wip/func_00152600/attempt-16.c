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

void func_00152600(char *arg0, char *arg1) {
    u128 v0;
    u128 v1;
    u128 v2;

    *(u8 *)(arg0 + 0x414) = 1;
    v0 = *(u128 *)(arg1 + 0xA0);
    v2 = *(u128 *)(arg1 + 0x90);
    v1 = *(u128 *)(arg1 + 0x80);
    *(u128 *)(arg0 + 0x4A0) = v1;
    *(u128 *)(arg0 + 0x4B0) = v2;
    *(u128 *)(arg0 + 0x4C0) = v0;
}
