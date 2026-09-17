void func_001578C0(s32 arg0, s32 arg1) {
    f32 temp_f1;
    void *temp_v1;

    temp_v1 = (arg1 << 6) + arg0;
    temp_v1->unk90 = (f32) (temp_v1->unk90 + temp_v1->unk94);
    temp_v1->unk98 = (f32) (temp_v1->unk98 + temp_v1->unk9C);
    temp_f1 = temp_v1->unkA0 + temp_v1->unkA4;
    temp_v1->unkA0 = temp_f1;
    if (temp_f1 < 0.0f) {
        temp_v1->unk70 = 0;
    }
}
