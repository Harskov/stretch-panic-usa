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
    s32 *p;
    s32 *q;
    s32 n;

    p = &D_006B3700;
    n = 0x5F;
    do {
        *p = 0;
        n -= 1;
        p += 1;
    } while (n != 0);

    D_006B3880 = 0;
    D_006B3888 = 0;

    p = &D_00601BD0;
    q = &D_006B3580;
    n = 0x1C;
    do {
        *q = *p;
        n -= 1;
        p += 1;
        q += 1;
    } while (n != 0);

    p = &D_00601BD0;
    q = &D_006B3580;
    n = 0x1C;
    do {
        q[0x1C] = *p;
        n -= 1;
        p += 1;
        q += 1;
    } while (n != 0);

    p = &D_00601BD0;
    q = &D_006B3580;
    n = 0x1C;
    do {
        q[0x38] = *p;
        n -= 1;
        p += 1;
        q += 1;
    } while (n != 0);

    q = &D_006B3580;
    n = 0xB;
    do {
        q[0x54] = 0;
        n -= 1;
        q += 1;
    } while (n != 0);
}
