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

typedef struct Obj {
    u8 pad0[0x314];
    u8 flag314;
    u8 pad315[0x3A0 - 0x315];
    Vec v0;
    Vec v1;
    Vec v2;
} Obj;

void func_001525D0(Obj *arg0, Obj *arg1) {
    arg0->flag314 = 1;
    arg0->v0 = arg1->v0;
    arg0->v1 = arg1->v1;
    arg0->v2 = arg1->v2;
}
