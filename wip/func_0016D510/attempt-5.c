typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0016F670();

void func_0016D510(u8 *arg0) {
    s32 temp_a2;

    temp_a2 = *(s32 *)(arg0 + 0x60);
    *(s32 *)(arg0 + 0x60) = temp_a2 | 0x01000000;
    func_0016F670(temp_a2, *(s32 *)(arg0 + 0xE4), 0x3CA3D70A, 0x3F7D70A4, 0x33D6BF95);
}
