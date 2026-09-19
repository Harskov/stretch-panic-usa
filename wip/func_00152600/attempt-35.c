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

typedef struct State {
    u8 pad0[0x414];
    u8 flag;
    u8 pad1[0x8B];
    Vec a;
    Vec b;
    Vec c;
} State;

void func_00152600(State *arg0, State *arg1) {
    arg0->flag = 1;
    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
}
