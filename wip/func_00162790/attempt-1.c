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

typedef struct Src {
    unsigned char unk_00[0x1B0];
    u128 v1B0;
    unsigned char unk_1C0[0x50];
    u128 v210;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u32 v20;
} Dst;

void func_00162790(Src *a0, Dst *a1) {
    a1->v0 = a0->v210;
    a1->v10 = a0->v1B0;
    a1->v20 = 0x3E440000;
}
