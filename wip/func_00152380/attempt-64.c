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
    u8 pad0[0x140];
    u128 v140;
    u8 pad1[0x100];
    u128 v250;
    u128 v260;
    u128 v270;
    u8 pad2[0x200];
    u8 b414;
    u8 pad3[0x5B];
    Vec f470;
    f32 f480;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    u8 pad0[0x10];
    Vec f50;
    f32 f60;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    f32 a, b, c, d;
    arg0->b414 = 0;
    a = arg0->f470.x;
    b = arg0->f470.y;
    c = arg0->f470.z;
    d = arg0->f470.w;
    arg1->f50.x = a;
    arg1->f50.y = b;
    arg1->f50.z = c;
    arg1->f50.w = d;
    arg1->f60 = arg0->f480;
    arg1->v30 = arg0->v140;
    arg1->v0 = arg0->v250;
    arg1->v10 = arg0->v260;
    arg1->v20 = arg0->v270;
    arg1->f50.x = -arg1->f50.x;
    arg1->f50.y = -arg1->f50.y;
    arg1->f50.z = -arg1->f50.z;
}
