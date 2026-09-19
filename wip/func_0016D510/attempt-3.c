typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

void func_0016F670();

void func_0016D510(u8 *arg0) {
    s32 temp_a2;
    f32 f14;
    f32 f12;
    f32 f13;

    temp_a2 = *(s32 *)(arg0 + 0x60);
    f14 = 0x33D6BF95;
    *(s32 *)(arg0 + 0x60) = temp_a2 | 0x01000000;
    f12 = 0x3CA3D70A;
    f13 = 0x3F7D70A4;
    func_0016F670(temp_a2, *(s32 *)(arg0 + 0xE4), f12, f13, f14);
}
