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

extern s32 D_006A6B90;

void func_00172410(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5, f32 x6, f32 x7) {
    s32 *p = &D_006A6B90;
    s32 *q = (s32 *)*p;
    *(f32 *)((char *)q + 0x1C) = x6;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x2C) = x6;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x3C) = x7;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x4C) = x7;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x30) = *(f32 *)((char *)q + 0x30) + x0;
    *(f32 *)((char *)q + 0x34) = *(f32 *)((char *)q + 0x34) + x1;
    *(f32 *)((char *)q + 0x38) = *(f32 *)((char *)q + 0x38) + x2;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x40) = *(f32 *)((char *)q + 0x40) + x3;
    *(f32 *)((char *)q + 0x44) = *(f32 *)((char *)q + 0x44) + x4;
    *(f32 *)((char *)q + 0x48) = *(f32 *)((char *)q + 0x48) + x5;
}
