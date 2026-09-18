void func_00168630(void *arg0) {
    f32 temp_f1;

    arg0->unkA8 = (f32) (arg0->unkA8 + arg0->unkAC);
    temp_f1 = arg0->unkA0 - arg0->unkA4;
    arg0->unkA0 = temp_f1;
    if (temp_f1 <= 0.0f) {
        arg0->unk60 = (s32) (arg0->unk60 | 0x10000);
    }
}
