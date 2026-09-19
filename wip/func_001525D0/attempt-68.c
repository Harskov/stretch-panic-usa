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

void func_001525D0(char *arg0, char *arg1) {
    struct Vec128 {
        u32 a;
        u32 b;
        u32 c;
        u32 d;
    };
    struct Vec128 *src = (struct Vec128 *)(arg1 + 0x80);
    struct Vec128 *dst = (struct Vec128 *)(arg0 + 0x3A0);
    *(u8 *)(arg0 + 0x314) = 1;
    dst[2] = src[2];
    dst[1] = src[1];
    dst[0] = src[0];
}
