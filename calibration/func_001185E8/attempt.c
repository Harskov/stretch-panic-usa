int func_001185E8(int unused, int *dst, unsigned char *src, int n) {
    int local;
    int *p;

    p = dst ? dst : &local;
    if (src == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    *p = *src;
    return *src != 0;
}
