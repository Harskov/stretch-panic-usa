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
    u8 pad0[0x80];
    Vec a;
    Vec b;
    Vec c;
} Src;

void func_00152600(char *arg0, Src *arg1) {
    *(u8 *)(arg0 + 0x414) = 1;
    asm {
        lq $a3, 0x80($a1)
        lq $a2, 0x90($a1)
        lq $v1, 0xA0($a1)
        sq $a3, 0x4A0($a0)
        sq $a2, 0x4B0($a0)
        sq $v1, 0x4C0($a0)
    }
}
