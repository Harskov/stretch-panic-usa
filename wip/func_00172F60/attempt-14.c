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
    s32 i;

    a = &D_006B3700;
    i = 0;
    do {
        i += 1;
        *a = 0;
        a += 1;
    } while (i < 0x5F);

    a = &D_00601BD0;
    b = &D_006B3580;
    D_006B3880 = 0;
    D_006B3888 = 0;
    i = 0;
    do {
        i += 1;
        *b = *a;
        a += 1;
        b += 1;
    } while (i != 0x1C);

    a = &D_00601BD0;
    b = &D_006B3580;
    i = 0;
    do {
        i += 1;
        b[0x1C] = *a;
        a += 1;
        b += 1;
    } while (i != 0x1C);

    a = &D_00601BD0;
    b = &D_006B3580;
    i = 0;
    do {
        i += 1;
        b[0x38] = *a;
        a += 1;
        b += 1;
    } while (i != 0x1C);

    b = &D_006B3580;
    i = 0;
    do {
        b[0x54] = 0;
        i += 1;
        b += 1;
    } while (i != 0xB);
}
