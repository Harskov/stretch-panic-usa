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
    Vec *src = (Vec *)(arg0 + 0x470);
    Vec *dst = (Vec *)(arg1 + 0x50);
    f32 a, b, c, d;
    arg0[0x414] = 0;
    a = src->x;
    b = src->y;
    c = src->z;
    d = src->w;
    dst->x = a;
    dst->y = b;
    dst->z = c;
    dst->w = d;
    *(s32 *)(arg1 + 0x60) = *(s32 *)(arg0 + 0x480);
    *(u128 *)(arg1 + 0x30) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x00) = *(u128 *)(arg0 + 0x250);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x260);
    *(u128 *)(arg1 + 0x20) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = -*(f32 *)(arg1 + 0x20);
    *(f32 *)(arg1 + 0x24) = -*(f32 *)(arg1 + 0x24);
    *(f32 *)(arg1 + 0x28) = -*(f32 *)(arg1 + 0x28);
}
