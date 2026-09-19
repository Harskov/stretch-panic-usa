extern s32 D_00601A50;

int func_0016FA80(int arg0) {
    D_00601A50 = D_00601A50 * 5 + 1;
    return (D_00601A50 >> 8) & arg0;
}
