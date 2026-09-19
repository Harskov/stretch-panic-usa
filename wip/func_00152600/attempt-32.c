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

typedef struct Blk {
    Vec v0;
    Vec v1;
    Vec v2;
} Blk;

void func_00152600(char *arg0, char *arg1) {
    *(u8 *)(arg0 + 0x414) = 1;
    *(Blk *)(arg0 + 0x4A0) = *(Blk *)(arg1 + 0x80);
}
