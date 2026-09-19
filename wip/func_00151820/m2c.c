void func_00151820(s32 arg0) {
    s32 *temp_a1_2;
    s32 *temp_a1_4;
    s32 temp_a1;
    s32 temp_a1_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_v1;
    s32 var_v1_2;

    if (arg0 > 0) {
        temp_a1 = D_006AF4A0 + 0x5A;
        var_v1 = temp_a1 & 0x7F;
        if (temp_a1 < 0) {
            var_a1 = var_v1 * 8;
            if (var_v1 != 0) {
                var_v1 -= 0x80;
                goto block_4;
            }
        } else {
block_4:
            var_a1 = var_v1 * 8;
        }
        temp_a1_2 = &D_006AF0A0 + var_a1;
        *temp_a1_2 += arg0;
    }
    if (arg0 < 0) {
        temp_a1_3 = D_006AF4A0 + 0x10;
        var_v1_2 = temp_a1_3 & 0x7F;
        if (temp_a1_3 < 0) {
            var_a1_2 = var_v1_2 * 8;
            if (var_v1_2 != 0) {
                var_v1_2 -= 0x80;
                goto block_10;
            }
        } else {
block_10:
            var_a1_2 = var_v1_2 * 8;
        }
        temp_a1_4 = &D_006AF0A4 + var_a1_2;
        *temp_a1_4 += arg0;
    }
}
