void func_001668D0(void *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_a1;

    temp_a1 = arg0->unkF4;
    switch (temp_a1) {                              /* irregular */
    case 0:
        arg0->unkFC = 0.0f;
        arg0->unkF8 = 0;
        arg0->unkF4 = (s32) (arg0->unkF4 + 1);
        /* fallthrough */
    case 1:
        temp_f2 = arg0->unkFC;
        temp_f1 = temp_f2 + (0.041666668f * (2.0f - temp_f2));
        arg0->unkFC = temp_f1;
        if (!(temp_f1 < 1.75f)) {
            arg0->unkF4 = (s32) (arg0->unkF4 + 1);
            return;
        }
        return;
    case 2:
        temp_f2_2 = arg0->unkFC;
        arg0->unkFC = (f32) (temp_f2_2 + (0.03125f * (1.0f - temp_f2_2)));
        break;
    }
}
