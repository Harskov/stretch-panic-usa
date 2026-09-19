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

void func_00152300(Src *a0, char *a1) {
    Vec *v;
    a0->unk314 = 0;
    *(f32 *)(a1 + 0x50) = a0->f370;
    *(f32 *)(a1 + 0x54) = a0->f374;
    *(f32 *)(a1 + 0x58) = a0->f378;
    *(f32 *)(a1 + 0x5C) = a0->f37C;
    *(u128 *)(a1 + 0x00) = a0->v0;
    *(u128 *)(a1 + 0x10) = a0->v1;
    *(u128 *)(a1 + 0x20) = a0->v2;
    v = (Vec *)(a1 + 0x20);
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
    *(s32 *)(a1 + 0x60) = a0->i380;
    *(f32 *)(a1 + 0x64) = a0->f384;
    *(s32 *)(a1 + 0x68) = 0;
    *(s32 *)(a1 + 0x6C) = 0;
    *(s32 *)(a1 + 0x70) = 0;
}
