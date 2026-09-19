typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Src {
    u8 pad0[0x250];
    u128 v0;
    u128 v1;
    u128 v2;
    u8 pad3[0x10];
    u8 unk314;
    u8 pad4[0x5B];
    Vec v370;
    s32 i380;
    f32 f384;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v1;
    u128 v2;
    Vec v20;
    u8 pad20[0x20];
    Vec v50;
    s32 i60;
    f32 f64;
    s32 i68;
    s32 i6C;
    s32 i70;
} Dst;

void func_00152300(Src *arg0, Dst *arg1) {
    u128 u;
    arg0->unk314 = 0;
    arg1->v50 = arg0->v370;
    arg1->v0 = arg0->v0;
    arg1->v1 = arg0->v1;
    u = arg0->v2;
    arg1->v2 = u;
    arg1->v20.x = -arg1->v20.x;
    arg1->v20.y = -arg1->v20.y;
    arg1->v20.z = -arg1->v20.z;
    arg1->i60 = arg0->i380;
    arg1->f64 = arg0->f384;
    arg1->i68 = 0;
    arg1->i6C = 0;
    arg1->i70 = 0;
}
