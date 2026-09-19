typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

extern s32 D_006A6730;
void func_00127840();

void func_00170980(void)
{
    s32 *base;
    s32 a0;
    s32 a0b;
    s64 v;
    f32 f;

    f = 0.0f;
    base = (s32 *)D_006A6730;

    a0 = *(s32 *)((char *)base + 0x360) | 0x400;

    *(u8 *)((char *)base + 0x90) = 1;
    v = *(s64 *)((char *)base + 0x70);
    v = (v & ~1) | ((s64)((a0 & 0x1000) >> 12));
    *(s64 *)((char *)base + 0x70) = v;

    *(u8 *)((char *)base + 0x90) = 1;
    v = *(s64 *)((char *)base + 0x70);
    v = (v & ~0x4000) | ((s64)(((a0 & 0x2000) >> 13) << 14));
    *(s64 *)((char *)base + 0x70) = v;

    *(s32 *)((char *)base + 0x350) |= ((a0 ^ *(s32 *)((char *)base + 0x360)) & 0xF) << 4;
    *(s32 *)((char *)base + 0x360) = a0;

    a0b = *(s32 *)((char *)base + 0x360) & ~0x110;

    *(u8 *)((char *)base + 0x90) = 1;
    v = *(s64 *)((char *)base + 0x70);
    v = (v & ~1) | ((s64)((a0b & 0x1000) >> 12));
    *(s64 *)((char *)base + 0x70) = v;

    *(u8 *)((char *)base + 0x90) = 1;
    v = *(s64 *)((char *)base + 0x70);
    v = (v & ~0x4000) | ((s64)(((a0b & 0x2000) >> 13) << 14));
    *(s64 *)((char *)base + 0x70) = v;

    *(s32 *)((char *)base + 0x350) |= ((a0b ^ *(s32 *)((char *)base + 0x360)) & 0xF) << 4;
    *(s32 *)((char *)base + 0x360) = a0b;

    func_00127840(D_006A6730, 0, 2, 0, 0);
}
