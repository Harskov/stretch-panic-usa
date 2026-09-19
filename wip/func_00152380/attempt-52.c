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
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    arg0->b414 = 0;
    arg1->f50 = arg0->f470;
    arg1->f54 = arg0->f474;
    arg1->f58 = arg0->f478;
    arg1->f5C = arg0->f47C;
    arg1->i60 = arg0->i480;
    arg1->v30 = arg0->v140;
    arg1->v0 = arg0->v250;
    arg1->v10 = arg0->v260;
    arg1->v20 = arg0->v270;
    arg1->v20 = -arg1->v20;
    arg1->v10 = -arg1->v10;
    arg1->v0 = -arg1->v0;
}
