void func_0016DC80(void *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk168;
    if (temp_v0 != 0) {
        arg0->unk168 = (s32) (temp_v0 - 1);
        if (arg0->unk168 == 0) {
            arg0->unk60 = (s32) (arg0->unk60 & 0xFBFFFFFF);
            arg0->unk164 = 0;
        }
    }
}
