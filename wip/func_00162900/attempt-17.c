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
    unsigned char unk_00[0x80];
    u128 v0;
    u128 v1;
    u128 v2;
} Src;

typedef struct Dst {
    unsigned char unk_00[0x28C];
    u8 flag;
    unsigned char unk_28D[0x310 - 0x28D];
    u128 v0;
    u128 v1;
    u128 v2;
} Dst;

void func_00162900(Dst *arg0, Src *arg1) {
    u128 a;
    u128 b;
    u128 c;

    arg0->flag = 1;
    a = arg1->v0;
    b = arg1->v1;
    c = arg1->v2;
    arg0->v2 = c;
    arg0->v1 = b;
    arg0->v0 = a;
}
