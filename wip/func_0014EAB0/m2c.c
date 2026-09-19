void func_0014EAB0(s128 *arg1) {
    s128 *var_a1;
    s32 var_a0;

    var_a1 = arg1;
    var_a0 = D_006AF4C8;
    if (var_a0 != 0) {
        do {
            *var_a1 = var_a0->unk310;
            var_a0 = var_a0->unk90;
            var_a1 += 0x10;
        } while (var_a0 != 0);
    }
}
