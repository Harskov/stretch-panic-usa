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

typedef struct Dst {
    f32 pad_00[3];
    f32 ix;
    f32 pad_10;
    f32 pad_14;
    f32 iy;
    f32 pad_1C;
    f32 pad_20;
    f32 iz;
    f32 pad_28;
    f32 pad_2C;
    f32 pad_30;
    f32 pad_34;
    f32 pad_38;
    f32 pad_3C;
    f32 pad_40;
    f32 pad_44;
    f32 pad_48;
    f32 pad_4C;
    f32 pad_50;
    f32 pad_54;
    f32 pad_58;
    f32 pad_5C;
} Dst;

void func_00152380(u8 *src, Dst *dst) {
    src[0x414] = 0;
    dst->pad_50 = *(f32 *)(src + 0x470);
    dst->pad_54 = *(f32 *)(src + 0x474);
    dst->pad_58 = *(f32 *)(src + 0x478);
    dst->pad_5C = *(f32 *)(src + 0x47C);
    *(s32 *)(dst + 0x30) = *(s32 *)(src + 0x160);
    *(Vec *)(dst + 0x10) = *(Vec *)(src + 0x250);
    dst->ix = -dst->ix;
    dst->iy = -dst->iy;
    dst->iz = -dst->iz;
}
