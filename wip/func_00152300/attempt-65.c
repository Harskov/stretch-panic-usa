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
    u8 pad0[0x250];
    Vec v250;
    Vec v260;
    Vec v270;
    u8 pad280[0x90];
    u8 b310;
    u8 pad311[0x3];
    u8 b314;
    u8 pad315[0x5B];
    f32 f370;
    f32 f374;
    f32 f378;
    f32 f37C;
    s32 i380;
    f32 f384;
} Src;

typedef struct Dst {
    Vec v0;
    Vec v10;
    Vec v20;
    u8 pad30[0x20];
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
    Dst *d;
    Src *s;

    s = arg0;
    d = arg1;
    s->b314 = 0;
    d->f50 = s->f370;
    d->f54 = s->f374;
    d->f58 = s->f378;
    d->f5C = s->f37C;
    d->v0 = s->v250;
    d->v10 = s->v260;
    d->v20 = s->v270;
    d->v20.x = -d->v20.x;
    d->v20.y = -d->v20.y;
    d->v20.z = -d->v20.z;
    d->i60 = s->i380;
    d->f64 = s->f384;
    d->i68 = 0;
    d->i6C = 0;
    d->i70 = 0;
}
