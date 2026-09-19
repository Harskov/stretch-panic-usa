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

extern s32 D_00601A80;

void *func_00170C00(s32 arg0) {
    return (void *)((s32)&D_00601A80 + (arg0 << 4));
}
