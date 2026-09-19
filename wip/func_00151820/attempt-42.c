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

extern s32 D_006AF0A0;
extern s32 D_006AF0A4;
extern s32 D_006AF4A0;

void func_00151820(s32 arg0) {
    s32 x;
    s32 idx;

    if (arg0 > 0) {
        x = D_006AF4A0;
        x += 0x5A;
        idx = x & 0x7F;
        if (x < 0) {
            if (idx != 0) {
                idx -= 0x80;
            }
        }
        idx *= 8;
        *(s32 *)((char *)&D_006AF0A0 + idx) += arg0;
    }
    if (arg0 < 0) {
        x = D_006AF4A0;
        x += 0x10;
        idx = x & 0x7F;
        if (x < 0) {
            if (idx != 0) {
                idx -= 0x80;
            }
        }
        idx *= 8;
        *(s32 *)((char *)&D_006AF0A4 + idx) += arg0;
    }
}
