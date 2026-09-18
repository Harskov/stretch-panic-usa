void func_00162870(void *arg0, void *arg1) {
    void *temp_a2;

    temp_a2 = arg1->unkC8;
    if ((temp_a2->unk68 & 0x10) && !(temp_a2->unk60 & 0x20000)) {
        arg0->unk288 = (s32) temp_a2->unk60;
        arg0->unk2F0 = (s32) arg1->unkC8->unk58;
        arg0->unk2E0 = (f32) arg1->unkA0;
        arg0->unk2E4 = (f32) arg1->unkA4;
        arg0->unk2E8 = (f32) arg1->unkA8;
        arg0->unk2EC = (f32) arg1->unkAC;
        arg0->unk2F4 = 0;
        arg0->unk310 = (s128) arg1->unk80;
        arg0->unk330 = (s128) arg1->unk80;
        arg0->unk60 = (s32) (arg0->unk60 | 2);
    }
}
