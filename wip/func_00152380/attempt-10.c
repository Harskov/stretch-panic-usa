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
    u8 pad0[0x470];
    f32 d;
    f32 c;
    f32 b;
    f32 a;
    s32 e;
} Src;

void func_00152380(char *arg0, char *arg1) {
    Src *s;
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;

    s = (Src *)(arg0 + 0x470);
    *(u8 *)(arg0 + 0x414) = 0;
    f3 = s->a;
    f2 = s->b;
    f1 = s->c;
    f0 = s->d;
    *(f32 *)(arg1 + 0x50) = f3;
    *(f32 *)(arg1 + 0x54) = f2;
    *(f32 *)(arg1 + 0x58) = f1;
    *(f32 *)(arg1 + 0x5C) = f0;
    *(s32 *)(arg1 + 0x60) = s->e;
    *(u128 *)(arg1 + 0x30) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x250);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x260);
    *(u128 *)(arg1 + 0x20) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = -*(f32 *)(arg1 + 0x20);
    *(f32 *)(arg1 + 0x24) = -*(f32 *)(arg1 + 0x24);
    *(f32 *)(arg1 + 0x28) = -*(f32 *)(arg1 + 0x28);
}
