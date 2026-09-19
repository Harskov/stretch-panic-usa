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
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Dst;

void func_00152380(char *arg0, Dst *arg1) {
    *(u8 *)(arg0 + 0x414) = 0;
    arg1->f50 = *(f32 *)(arg0 + 0x470);
    arg1->f54 = *(f32 *)(arg0 + 0x474);
    arg1->f58 = *(f32 *)(arg0 + 0x478);
    arg1->f5C = *(f32 *)(arg0 + 0x47C);
    arg1->i60 = *(s32 *)(arg0 + 0x480);
    arg1->v30 = *(u128 *)(arg0 + 0x140);
    arg1->v0 = *(u128 *)(arg0 + 0x250);
    arg1->v10 = *(u128 *)(arg0 + 0x260);
    arg1->v20 = *(u128 *)(arg0 + 0x270);
    arg1->f50 = -arg1->f50;
    arg1->f54 = -arg1->f54;
    arg1->f58 = -arg1->f58;
}
