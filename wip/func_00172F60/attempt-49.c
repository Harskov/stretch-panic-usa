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
    s32 *ptr;
    s32 *src;
    s32 i;
    s32 j;

    ptr = &D_006B3700;
    i = 0;
    do {
        i += 1;
        *ptr = 0;
        ptr += 1;
    } while (i < 0x5F);

    D_006B3880 = 0;
    D_006B3888 = 0;

    src = &D_00601BD0;
    ptr = &D_006B3580;
    j = 0;
    do {
        j += 1;
        *ptr = *src;
        src += 1;
        ptr += 1;
    } while (j != 0x1C);

    src = &D_00601BD0;
    ptr = &D_006B3580;
    j = 0;
    do {
        j += 1;
        ptr[28] = *src;
        src += 1;
        ptr += 1;
    } while (j != 0x1C);

    src = &D_00601BD0;
    ptr = &D_006B3580;
    j = 0;
    do {
        j += 1;
        ptr[56] = *src;
        src += 1;
        ptr += 1;
    } while (j != 0x1C);

    ptr = &D_006B3580;
    i = 0;
    do {
        ptr[84] = 0;
        i += 1;
        ptr += 1;
    } while (i != 11);
}
