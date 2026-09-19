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
    s32 *a1;
    s32 *a0;
    s32 i;

    a1 = &D_006B3700;
    i = 0;
    do {
        i++;
        *a1 = 0;
        a1++;
    } while (i < 0x5F);

    D_006B3880 = 0;
    D_006B3888 = 0;

    a1 = &D_00601BD0;
    a0 = &D_006B3580;
    i = 0;
    do {
        i++;
        *a0 = *a1;
        a1++;
        a0++;
    } while (i != 0x1C);

    a1 = &D_00601BD0;
    a0 = &D_006B3580;
    i = 0;
    do {
        i++;
        a0[28] = *a1;
        a1++;
        a0++;
    } while (i != 0x1C);

    a1 = &D_00601BD0;
    a0 = &D_006B3580;
    i = 0;
    do {
        i++;
        a0[56] = *a1;
        a1++;
        a0++;
    } while (i != 0x1C);

    a0 = &D_006B3580;
    i = 0;
    do {
        a0[84] = 0;
        i++;
        a0++;
    } while (i != 11);
}
