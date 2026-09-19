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
    Vec *src;
    Vec *dst;
    *(u8 *)(arg0 + 0x314) = 1;
    src = (Vec *)(arg1 + 0x80);
    dst = (Vec *)(arg0 + 0x3A0);
    *dst = *src;
    dst++;
    src++;
    *dst = *src;
    dst++;
    src++;
    *dst = *src;
}
