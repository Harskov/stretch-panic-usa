typedef int s32;

extern s32 D_006AF4D0;
extern s32 D_006AF4D4;

int func_00161980(void) {
    int r;

    if (D_006AF4D0 == 1 && D_006AF4D4 == 1) {
        return 1;
    }
    if (D_006AF4D0 == 0) {
        r = 2;
    } else if (D_006AF4D4 == 0) {
        r = 0;
    } else {
        r = 2;
    }
    return r;
}
