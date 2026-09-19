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

typedef struct Three {
    u128 a; /* 0x80 */
    u128 b; /* 0x90 */
    u128 c; /* 0xA0 */
} Three;

typedef struct Dst {
    u8 pad[0x414];
    u128 a; /* 0x414 */
    u8 gap[0x4A0 - 0x414 - 16];
    u128 b; /* 0x4A0 */
    u128 c; /* 0x4B0 */
    u128 d; /* 0x4C0 */
} Dst;

void func_00152600(Dst *arg0, Three *arg1) {
    arg0->a = 1;
    arg0->b = arg1->b;
    arg0->c = arg1->a;
    arg0->d = arg1->c;
}
