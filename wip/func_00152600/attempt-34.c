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

typedef struct Data {
    u8 pad0[0x80];
    Vec a;
    Vec b;
    Vec c;
} Data;

void func_00152600(char *arg0, Data *arg1) {
    Vec a = arg1->a;
    Vec b = arg1->b;
    Vec c = arg1->c;
    *(u8 *)(arg0 + 0x414) = 1;
    *(Vec *)(arg0 + 0x4A0) = a;
    *(Vec *)(arg0 + 0x4B0) = b;
    *(Vec *)(arg0 + 0x4C0) = c;
}
