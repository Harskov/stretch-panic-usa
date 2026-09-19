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
    s32 *r5;
    s32 *r6;
    s32 r4;
    s32 r7;

    r5 = &D_006B3700;
    r4 = 0;
    do {
        r4++;
        *r5 = 0;
        r5++;
    } while (r4 < 0x5F);

    (&D_006B3880)[0] = 0;
    (&D_006B3888)[0] = 0;

    r5 = &D_00601BD0;
    r6 = &D_006B3580;
    r7 = 0;
    do {
        r7++;
        *r6 = *r5;
        r5++;
        r6++;
    } while (r7 != 0x1C);

    r5 = &D_00601BD0;
    r6 = &D_006B3580;
    r7 = 0;
    do {
        r7++;
        r6[0x1C] = *r5;
        r5++;
        r6++;
    } while (r7 != 0x1C);

    r5 = &D_00601BD0;
    r6 = &D_006B3580;
    r7 = 0;
    do {
        r7++;
        r6[0x38] = *r5;
        r5++;
        r6++;
    } while (r7 != 0x1C);

    r6 = &D_006B3580;
    r7 = 0;
    do {
        r6[0x54] = 0;
        r7++;
        r6++;
    } while (r7 != 0xB);
}
