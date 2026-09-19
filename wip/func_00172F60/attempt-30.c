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

extern s32 D_00601BD0;
extern s32 D_006B3580;
extern s32 D_006B3700;
extern s32 D_006B3880;
extern s32 D_006B3888;

void func_00172F60(void) {
    s32 *r;
    s32 *s;
    s32 i;

    s = &D_006B3700;
    i = 0;
    do {
        i += 1;
        *s = 0;
        s += 1;
    } while (i < 0x5F);

    D_006B3880 = 0;
    D_006B3888 = 0;

    r = &D_00601BD0;
    s = &D_006B3580;
    i = 0;
    do {
        i += 1;
        *s = *r;
        r += 1;
        s += 1;
    } while (i != 0x1C);

    r = &D_00601BD0;
    s = &D_006B3580;
    i = 0;
    do {
        i += 1;
        s[0x1C] = *r;
        r += 1;
        s += 1;
    } while (i != 0x1C);

    r = &D_00601BD0;
    s = &D_006B3580;
    i = 0;
    do {
        i += 1;
        s[0x38] = *r;
        r += 1;
        s += 1;
    } while (i != 0x1C);

    s = &D_006B3580;
    i = 0;
    do {
        s[0x54] = 0;
        i += 1;
        s += 1;
    } while (i != 0xB);
}
