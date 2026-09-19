void func_0016C260(void) {
    s32 var_a1;

    var_a1 = D_006A6C38;
    if (var_a1 != 0) {
        do {
            var_a1->unk60 = (s32) (var_a1->unk60 | 0x10000);
            var_a1 = var_a1->unk74;
        } while (var_a1 != 0);
    }
}
