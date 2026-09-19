typedef signed int s32;

extern s32 D_00601BD0;
extern s32 D_006B3580;
extern s32 D_006B3700;
extern s32 D_006B3880;
extern s32 D_006B3888;

void func_00172F60(void) {
    s32 j;
    s32 *p;
    s32 *q;

    p = &D_006B3700;
    j = 0;
    do {
        j += 1;
        *p = 0;
        p += 1;
    } while (j < 0x5F);

    D_006B3880 = 0;
    D_006B3888 = 0;

    p = &D_006B3580;
    q = &D_00601BD0;
    j = 0;
    do {
        j += 1;
        *p = *q;
        q += 1;
        p += 1;
    } while (j != 0x1C);

    p = &D_006B3580;
    q = &D_00601BD0;
    j = 0;
    do {
        j += 1;
        p[0x1C] = *q;
        q += 1;
        p += 1;
    } while (j != 0x1C);

    p = &D_006B3580;
    q = &D_00601BD0;
    j = 0;
    do {
        j += 1;
        p[0x38] = *q;
        q += 1;
        p += 1;
    } while (j != 0x1C);

    p = &D_006B3580;
    j = 0;
    do {
        p[0x54] = 0;
        j += 1;
        p += 1;
    } while (j != 0xB);
}
