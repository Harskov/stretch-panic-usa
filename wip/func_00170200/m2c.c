void func_00170200(void *arg0, void *arg1, s32 arg2, void *arg3) {
    f32 temp_f3;
    f32 var_f0;

    if (arg2 >= 0) {
        var_f0 = (f32) arg2;
    } else {
        var_f0 = 2.0f * (f32) (((u32) arg2 >> 1) | (arg2 & 1));
    }
    temp_f3 = 2.0f + var_f0;
    arg3->unk0 = (f32) (arg1->unk0 * (-arg0->unk0 / temp_f3));
    arg3->unk4 = (f32) (arg1->unk4 * (-arg0->unk4 / temp_f3));
    arg3->unk8 = (f32) (arg1->unk8 * (-arg0->unk8 / temp_f3));
    arg3->unkC = (f32) (arg1->unkC * (-arg0->unkC / temp_f3));
}
