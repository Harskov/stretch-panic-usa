void func_00160940(void *arg0) {
    f32 temp_f2;

    if (arg0->unk30 != 0) {

    } else {
        temp_f2 = arg0->unk28;
        arg0->unk28 = (f32) (temp_f2 + (0.083333336f * (0.5f - temp_f2)));
        arg0->unk2C = (f32) (arg0->unk2C + -0.0125f);
    }
    if (arg0->unk2C <= 0.0f) {

    }
}
