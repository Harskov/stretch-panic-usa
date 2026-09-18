void func_00159E20(void *arg0, void *arg1) {
    s32 var_v1;

    if (arg0->unk1D0 != 0) {
        var_v1 = arg0->unk60 | 0x80000;
        goto block_4;
    }
    if (arg1->unkC8->unk54 == 4) {
        var_v1 = arg0->unk60 | 0x80000;
block_4:
        arg0->unk60 = var_v1;
    }
    arg0->unk10 = (s128) arg0->unk230;
    arg0->unk30 = (s128) arg0->unk240;
}
