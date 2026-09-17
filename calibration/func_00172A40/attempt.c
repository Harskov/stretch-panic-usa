int func_00172A40(int *flag, int *timer) {
    if (*timer == 0) {
        return 0;
    }
    (*timer)--;
    if (*timer == 0) {
        *flag = 0;
    }
    return 1;
}
