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
    u128 v2;
    u8 pad0[0x2C];
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

void func_00152300(Src *a0, Dst *a1) {
    Vec *v;
    a0->unk314 = 0;
    a1->f50 = a0->f370;
    a1->f54 = a0->f374;
    a1->f58 = a0->f378;
    a1->f5C = a0->f37C;
    a1->v0 = a0->v0;
    a1->v1 = a0->v1;
    a1->v2 = a0->v2;
    v = (Vec *)&a1->v2;
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
    a1->i60 = a0->i380;
    a1->f64 = a0->f384;
    a1->i68 = 0;
    a1->i6C = 0;
    a1->i70 = 0;
}
