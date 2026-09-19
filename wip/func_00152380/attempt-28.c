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

typedef struct Out {
    Vec v0;
    Vec v10;
    Vec v20;
    Vec v30;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Out;

void func_00152380(u8 *src, Out *dst) {
    Vec temp;

    src[0x414] = 0;
    dst->f50 = *(f32 *)(src + 0x470);
    dst->f54 = *(f32 *)(src + 0x474);
    dst->f58 = *(f32 *)(src + 0x478);
    dst->f5C = *(f32 *)(src + 0x47C);
    dst->i60 = *(s32 *)(src + 0x480);
    dst->v30 = *(u128 *)(src + 0x140);
    dst->v0 = *(u128 *)(src + 0x250);
    dst->v10 = *(u128 *)(src + 0x260);
    dst->v20 = *(u128 *)(src + 0x270);
    dst->v20.x = -dst->v20.x;
    dst->v20.y = -dst->v20.y;
    dst->v20.z = -dst->v20.z;
}
