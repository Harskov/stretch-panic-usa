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
    u128 v0;
    u128 v1;
    u128 v2;
    u8 pad3[0x10];
    u8 unk314;
    u8 pad4[0x43];
    Vec f370;
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
    Src *s = a0;
    a0 = 0;
    s->unk314 = 0;
    a1->f50 = s->f370.x;
    a1->f54 = s->f370.y;
    a1->f58 = s->f370.z;
    a1->f5C = s->f370.w;
    a1->v0 = s->v0;
    a1->v1 = s->v1;
    a1->v2 = s->v2;
    ((Vec *)&a1->v2)->x = -((Vec *)&a1->v2)->x;
    ((Vec *)&a1->v2)->y = -((Vec *)&a1->v2)->y;
    ((Vec *)&a1->v2)->z = -((Vec *)&a1->v2)->z;
    a1->i60 = s->i380;
    a1->f64 = s->f384;
    a1->i68 = 0;
    a1->i6C = 0;
    a1->i70 = 0;
}
