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
    s32 t;
    s32 i;
    s32 *p;
    s32 off;

    if (arg0 > 0) {
        t = D_006AF4A0;
        off = t + 0x5A;
        i = off & 0x7F;
        if (off < 0) {
            if (i != 0) {
                i = i - 0x80;
            }
        }
        p = (s32 *)((char *)&D_006AF0A0 + i * 8);
        *p = arg0 + *p;
    }
    if (arg0 < 0) {
        t = D_006AF4A0;
        off = t + 0x10;
        i = off & 0x7F;
        if (off < 0) {
            if (i != 0) {
                i = i - 0x80;
            }
        }
        p = (s32 *)((char *)&D_006AF0A4 + i * 8);
        *p = arg0 + *p;
    }
}
