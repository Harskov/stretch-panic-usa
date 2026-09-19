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
    s32 v;
    s32 idx;

    if (arg0 > 0) {
        v = D_006AF4A0;
        idx = v + 0x5A;
        v = idx & 0x7F;
        if (idx < 0) {
            if (v != 0) {
                v -= 0x80;
            }
        }
        *(s32 *)((char *)&D_006AF0A0 + v * 8) += arg0;
    }
    if (arg0 < 0) {
        v = D_006AF4A0;
        idx = v + 0x10;
        v = idx & 0x7F;
        if (idx < 0) {
            if (v != 0) {
                v -= 0x80;
            }
        }
        *(s32 *)((char *)&D_006AF0A4 + v * 8) += arg0;
    }
}
