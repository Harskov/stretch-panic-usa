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

extern s32 D_006AF0A0[];
extern s32 D_006AF0A4[];
extern s32 D_006AF4A0;

void func_00151820(s32 arg0) {
    s32 idx;
    s32 t;

    if (arg0 > 0) {
        t = D_006AF4A0 + 0x5A;
        idx = t & 0x7F;
        if (t < 0) {
            if (idx != 0) {
                idx -= 0x80;
            }
        }
        D_006AF0A0[idx * 2] += arg0;
    }
    if (arg0 < 0) {
        t = D_006AF4A0 + 0x10;
        if (t < 0) {
            idx = t & 0x7F;
            if (idx != 0) {
                idx -= 0x80;
            }
        } else {
            idx = t & 0x7F;
        }
        D_006AF0A4[idx * 2] += arg0;
    }
}
