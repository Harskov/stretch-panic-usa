typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0016F670();

void func_0016D510(u8 *arg0) {
    s32 temp_a2;
    f32 f14;
    f32 f12;
    f32 f13;

    temp_a2 = *(s32 *)(arg0 + 0x60);
    f14 = 1.0e-7f;
    f12 = 0.02f;
    f13 = 0.99f;
    *(s32 *)(arg0 + 0x60) = temp_a2 | 0x01000000;
    func_0016F670(temp_a2, *(s32 *)(arg0 + 0xE4), f12, f13, f14);
}
