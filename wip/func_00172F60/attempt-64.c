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
    s32 *a;
    s32 *b;
    s32 n;
    s32 m;

    b = &D_006B3700;
    n = 0;
    do {
        n++;
        *b = 0;
        b++;
    } while (n < 0x5F);

    (&D_006B3880)[0] = 0;
    (&D_006B3888)[0] = 0;

    a = &D_00601BD0;
    b = &D_006B3580;
    m = 0;
    do {
        m++;
        *b = *a;
        a++;
        b++;
    } while (m != 0x1C);

    a = &D_00601BD0;
    b = &D_006B3580;
    m = 0;
    do {
        m++;
        b[0x1C] = *a;
        a++;
        b++;
    } while (m != 0x1C);

    a = &D_00601BD0;
    b = &D_006B3580;
    m = 0;
    do {
        m++;
        b[0x38] = *a;
        a++;
        b++;
    } while (m != 0x1C);

    a = &D_006B3580;
    m = 0;
    do {
        a[0x54] = 0;
        m++;
        a++;
    } while (m != 0xB);
}
