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

typedef struct Vec16A {
    u128 v[3];
} Vec16A;

typedef struct Vec16B {
    u128 v[3];
} Vec16B;

void func_00152600(char *arg0, char *arg1) {
    Vec16A *a = (Vec16A *)(arg0 + 0x4A0);
    Vec16B *b = (Vec16B *)(arg1 + 0x80);
    *(u8 *)(arg0 + 0x414) = 1;
    a->v[0] = b->v[0];
    a->v[1] = b->v[1];
    a->v[2] = b->v[2];
}
