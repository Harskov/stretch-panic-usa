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
    s32 i;
    s32 j;
    s32 k;

    if (arg0 > 0) {
        i = D_006AF4A0 + 0x5A;
        j = i & 0x7F;
        if (i < 0 && j != 0) {
            j -= 0x80;
        }
        *(s32 *)((char *)&D_006AF0A0 + j * 8) += arg0;
    }
    if (arg0 < 0) {
        k = D_006AF4A0 + 0x10;
        j = k & 0x7F;
        if (k < 0 && j != 0) {
            j -= 0x80;
        }
        *(s32 *)((char *)&D_006AF0A4 + j * 8) += arg0;
    }
}
