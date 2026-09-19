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

void func_00152600(char *a0, char *a1) {
    register u128 a3;
    register u128 a2;
    register u128 v1;

    *(u8 *)(a0 + 0x414) = 1;
    a3 = *(u128 *)(a1 + 0x80);
    a2 = *(u128 *)(a1 + 0x90);
    v1 = *(u128 *)(a1 + 0xA0);
    *(u128 *)(a0 + 0x4A0) = a3;
    *(u128 *)(a0 + 0x4B0) = a2;
    *(u128 *)(a0 + 0x4C0) = v1;
}
