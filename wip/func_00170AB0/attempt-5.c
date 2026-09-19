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

void func_00170AB0(void)
{
    s32 *base;
    s32 temp_a0;
    s32 temp_a0_2;

    base = (s32 *)D_006A6730;
    temp_a0 = base[0xD8] | 0x400;
    *(u8 *)((char *)base + 0x90) = 1;
    *(s64 *)((char *)base + 0x70) = (*(s64 *)((char *)base + 0x70) & ~1) | ((temp_a0 & 0x1000) >> 12);
    *(u8 *)((char *)base + 0x90) = 1;
    *(s64 *)((char *)base + 0x70) = (*(s64 *)((char *)base + 0x70) & ~0x4000) | (((temp_a0 & 0x2000) >> 13) << 14);
    base[0xD4] = base[0xD4] | (((temp_a0 ^ base[0xD8]) & 0xF) << 4);
    base[0xD8] = temp_a0;
    base = (s32 *)D_006A6730;
    temp_a0_2 = base[0xD8] & ~0x110;
    *(u8 *)((char *)base + 0x90) = 1;
    *(s64 *)((char *)base + 0x70) = (*(s64 *)((char *)base + 0x70) & ~1) | ((temp_a0_2 & 0x1000) >> 12);
    *(u8 *)((char *)base + 0x90) = 1;
    *(s64 *)((char *)base + 0x70) = (*(s64 *)((char *)base + 0x70) & ~0x4000) | (((temp_a0_2 & 0x2000) >> 13) << 14);
    base[0xD4] = base[0xD4] | (((temp_a0_2 ^ base[0xD8]) & 0xF) << 4);
    base[0xD8] = temp_a0_2;
    func_00127840(D_006A6730, 0, 1, 0, 0);
}
