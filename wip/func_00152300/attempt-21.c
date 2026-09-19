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
    f32 f370;
    f32 f374;
    f32 f378;
    f32 f37C;
    s32 i380;
    f32 f384;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v1;
    Vec v2;
    u8 pad0[0x30];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
    f32 f64;
    s32 i68;
    s32 i6C;
    s32 i70;
} Dst;

void func_00152300(Src *arg0, Dst *arg1) {
    arg0->unk314 = 0;
    arg1->f50 = arg0->f370;
    arg1->f54 = arg0->f374;
    arg1->f58 = arg0->f378;
    arg1->f5C = arg0->f37C;
    arg1->v0 = arg0->v0;
    arg1->v1 = arg0->v1;
    arg1->v2 = arg0->v2;
    arg1->v2.x = -arg1->v2.x;
    arg1->v2.y = -arg1->v2.y;
    arg1->v2.z = -arg1->v2.z;
    arg1->i60 = arg0->i380;
    arg1->f64 = arg0->f384;
    arg1->i68 = 0;
    arg1->i6C = 0;
    arg1->i70 = 0;
}
