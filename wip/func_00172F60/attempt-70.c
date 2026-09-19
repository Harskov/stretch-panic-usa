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
    s32 *dst;
    s32 *src;
    s32 n;
    s32 m;

    src = &D_006B3700;
    n = 0;
    do {
        n++;
        *src = 0;
        src++;
    } while (n < 0x5F);

    (&D_006B3880)[0] = 0;
    (&D_006B3888)[0] = 0;

    dst = &D_00601BD0;
    src = &D_006B3580;
    m = 0;
    do {
        m++;
        *src = *dst;
        dst++;
        src++;
    } while (m != 0x1C);

    dst = &D_00601BD0;
    src = &D_006B3580;
    m = 0;
    do {
        m++;
        src[0x1C] = *dst;
        dst++;
        src++;
    } while (m != 0x1C);

    dst = &D_00601BD0;
    src = &D_006B3580;
    m = 0;
    do {
        m++;
        src[0x38] = *dst;
        dst++;
        src++;
    } while (m != 0x1C);

    src = &D_006B3580;
    m = 0;
    do {
        src[0x54] = 0;
        m++;
        src++;
    } while (m != 0xB);
}
