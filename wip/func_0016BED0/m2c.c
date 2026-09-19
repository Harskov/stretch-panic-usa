void func_0016BED0(s32 arg0, s32 arg1, void *arg2, s32 arg3, f32 fparg0) {
    s32 temp_s0;
    s32 temp_t0;
    s32 var_v0;
    void *temp_s1;
    void *temp_t1;
    void *var_a2;

    var_a2 = arg2;
    temp_s1 = var_a2;
    if (!(fparg0 <= 0.9f)) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }
    temp_t0 = var_v0 & 0xFF;
    switch (arg0) {                                 /* irregular */
    case 0:
        if (arg1 & 0x20000) {
            var_a2 = (temp_t0 == 0) ? (void *)0xE : (void *)0xD;
        } else if (arg1 & 0x08000000) {
            var_a2 = (temp_t0 == 0) ? (void *)0x10 : (void *)0xF;
        } else {
            var_a2 = (temp_t0 == 0) ? (void *)0xC : (void *)0xB;
        }
        break;
    case 2:
    case 1:
        /* fallthrough */
    case 4:
        var_a2 = (void *)0x15;
        break;
    case 3:
        var_a2 = (void *)0x16;
        break;
    }
    temp_s0 = arg3 << 5;
    (temp_s0 + temp_s1->unk60)->unk18 = (f32) M2C_ERROR(/* Read from unset register $f1 */);
    temp_t1 = temp_s1->unk60 + temp_s0;
    func_0013DF50(temp_t1->unk0, *(D_006A6D10 + (M2C_ERROR(/* Read from unset register $v1 */) * 4)), var_a2, temp_t1->unk4);
    *(temp_s1->unk60 + temp_s0) = M2C_ERROR(/* Read from unset register $v0 */);
}
