void func_00172F60(void) {
    s32 *var_a0_2;
    s32 *var_a1;
    s32 *var_a1_2;
    s32 *var_a1_3;
    s32 *var_a1_4;
    s32 *var_a2;
    s32 *var_a2_2;
    s32 *var_a2_3;
    s32 var_a0;
    s32 var_a1_5;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;

    var_a1 = &D_006B3700;
    var_a0 = 0;
    do {
        var_a0 += 1;
        *var_a1 = 0;
        var_a1 += 4;
    } while (var_a0 < 0x5F);
    var_a1_2 = &D_00601BD0;
    D_006B3880 = 0;
    var_a2 = &D_006B3580;
    D_006B3888 = 0;
    var_a3 = 0;
    do {
        var_a3 += 1;
        *var_a2 = *var_a1_2;
        var_a1_2 += 4;
        var_a2 += 4;
    } while (var_a3 != 0x1C);
    var_a1_3 = &D_00601BD0;
    var_a2_2 = &D_006B3580;
    var_a3_2 = 0;
    do {
        var_a3_2 += 1;
        var_a2_2->unk70 = (s32) *var_a1_3;
        var_a1_3 += 4;
        var_a2_2 += 4;
    } while (var_a3_2 != 0x1C);
    var_a1_4 = &D_00601BD0;
    var_a2_3 = &D_006B3580;
    var_a3_3 = 0;
    do {
        var_a3_3 += 1;
        var_a2_3->unkE0 = (s32) *var_a1_4;
        var_a1_4 += 4;
        var_a2_3 += 4;
    } while (var_a3_3 != 0x1C);
    var_a0_2 = &D_006B3580;
    var_a1_5 = 0;
    do {
        var_a0_2->unk150 = 0;
        var_a1_5 += 1;
        var_a0_2 += 4;
    } while (var_a1_5 != 0xB);
}
