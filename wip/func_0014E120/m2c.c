void func_0014E120(void *arg0) {
    s32 var_v0;

    if (arg0->unk60 & 0x40) {
        if (!(arg0->unkB8 < 100.0f)) {
            var_v0 = 0x14;
        } else {
            var_v0 = 0x17;
            if (arg0->unkBC != 0) {
                var_v0 = 0x16;
            }
        }
        arg0->unk364 = var_v0;
    }
}
