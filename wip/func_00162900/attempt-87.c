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
    u128 v80;
    u128 v90;
    u128 vA0;
} Src;

typedef struct Dst {
    unsigned char unk_00[0x28C];
    u8 flag;
    unsigned char unk_28D[0x310 - 0x28D];
    u128 v310;
    u128 v320;
    u128 v330;
} Dst;

void func_00162900(Dst *a0, Src *a1) {
    u128 t0;
    u128 t1;
    u128 t2;
    a0->flag = 1;
    t1 = a1->v90;
    t2 = a1->vA0;
    t0 = a1->v80;
    a0->v310 = t0;
    a0->v320 = t1;
    a0->v330 = t2;
}
