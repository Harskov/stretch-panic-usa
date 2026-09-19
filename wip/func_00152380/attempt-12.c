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

void func_00152380(char *arg0, char *arg1) {
    Vec *src = (Vec *)(arg0 + 0x250);
    Vec *dst = (Vec *)arg1;
    Vec *dst2 = (Vec *)(arg1 + 0x10);
    Vec *dst3 = (Vec *)(arg1 + 0x20);
    Vec *dst4 = (Vec *)(arg1 + 0x30);

    *(u8 *)(arg0 + 0x414) = 0;
    *(f32 *)(arg1 + 0x50) = *(f32 *)(arg0 + 0x470);
    *(f32 *)(arg1 + 0x54) = *(f32 *)(arg0 + 0x474);
    *(f32 *)(arg1 + 0x58) = *(f32 *)(arg0 + 0x478);
    *(f32 *)(arg1 + 0x5C) = *(f32 *)(arg0 + 0x47C);
    *(s32 *)(arg1 + 0x60) = *(s32 *)(arg0 + 0x480);
    *dst4 = *(Vec *)(arg0 + 0x140);
    *dst = src[0];
    *dst2 = src[1];
    *dst3 = src[2];
    dst3->x = -dst3->x;
    dst3->y = -dst3->y;
    dst3->z = -dst3->z;
}
