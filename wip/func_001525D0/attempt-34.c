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

typedef struct Src {
    u8 pad0[0x80];
    Vec a;
    Vec b;
    Vec c;
} Src;

typedef struct Dst {
    u8 pad0[0x314];
    u8 flag314;
    u8 pad315[0x3A0 - 0x315];
    Vec a;
    Vec b;
    Vec c;
} Dst;

void func_001525D0(Dst *arg0, Src *arg1) {
    arg0->flag314 = 1;
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
}
