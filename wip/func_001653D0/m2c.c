void func_001653D0(void *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;

    temp_f2 = arg0->unk50;
    temp_f2_2 = temp_f2 - (temp_f2 * arg0->unk54);
    arg0->unk50 = temp_f2_2;
    arg0->unk90 = (f32) (arg0->unk90 + temp_f2_2);
    temp_f1 = arg0->unk94 - arg0->unk5C;
    arg0->unk94 = temp_f1;
    if (temp_f1 <= 0.0f) {

    }
}
