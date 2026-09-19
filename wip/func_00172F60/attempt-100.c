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
    s32 i;

    q = &D_006B3700;
    i = 0;
    do {
        i += 1;
        *q = 0;
        q += 1;
    } while (i < 0x5F);

    p = &D_00601BD0;
    D_006B3880 = 0;
    q = &D_006B3580;
    D_006B3888 = 0;
    i = 0;
    do {
        i += 1;
        *q = *p;
        p += 1;
        q += 1;
    } while (i != 0x1C);

    p = &D_00601BD0;
    q = &D_006B3580;
    i = 0;
    do {
        i += 1;
        q[0x1C] = *p;
        p += 1;
        q += 1;
    } while (i != 0x1C);

    p = &D_00601BD0;
    q = &D_006B3580;
    i = 0;
    do {
        i += 1;
        q[0x38] = *p;
        p += 1;
        q += 1;
    } while (i != 0x1C);

    q = &D_006B3580;
    i = 0;
    do {
        q[0x54] = 0;
        i += 1;
        q += 1;
    } while (i != 0xB);
}
