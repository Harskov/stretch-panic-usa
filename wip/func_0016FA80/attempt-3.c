extern s32 D_00601A50;

int func_0016FA80(int arg0) {
    s32 v;
    D_00601A50 = D_00601A50 * 5 + 1;
    v = D_00601A50;
    return (v >> 8) & arg0;
}
