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

void func_001522E0(char *arg0, char *arg1) {
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = *(f32 *)(arg0 + 0x410) * *(f32 *)(arg0 + 0x410);
}
