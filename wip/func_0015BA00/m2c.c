void func_0015BA00(void *arg0, void *arg1) {
    arg0->unk10 = (s128) arg0->unk1F0;
    arg0->unk30 = (s128) arg0->unk200;
    if (arg1->unkC8->unk54 == 4) {
        arg0->unk60 = (s32) (arg0->unk60 | 0x80000);
    }
    if ((arg1->unk80 != 0.0f) || (arg0->unk1D8 & 2)) {
        arg0->unk60 = (s32) (arg0->unk60 | 0x80000);
    }
}
