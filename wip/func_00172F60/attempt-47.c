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
    s32 *src;
    s32 *dst;
    s32 count;
    s32 j;

    dst = &D_006B3700;
    j = 0;
    do {
        j++;
        *dst = 0;
        dst++;
    } while (j < 0x5F);

    D_006B3880 = 0;
    D_006B3888 = 0;

    src = &D_00601BD0;
    dst = &D_006B3580;
    count = 0;
    do {
        count++;
        *dst = *src;
        src++;
        dst++;
    } while (count != 0x1C);

    src = &D_00601BD0;
    dst = &D_006B3580;
    count = 0;
    do {
        count++;
        dst[28] = *src;
        src++;
        dst++;
    } while (count != 0x1C);

    src = &D_00601BD0;
    dst = &D_006B3580;
    count = 0;
    do {
        count++;
        dst[56] = *src;
        src++;
        dst++;
    } while (count != 0x1C);

    dst = &D_006B3580;
    j = 0;
    do {
        dst[84] = 0;
        j++;
        dst++;
    } while (j != 11);
}
