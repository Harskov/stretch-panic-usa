void func_00165800(void *arg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    s32 temp_v1;

    temp_v1 = arg0->unkF8;
    switch (temp_v1) {                              /* irregular */
    case 0:
        arg0->unkF0 = 0.0f;
        arg0->unkF4 = (f32) (1.0f / (f32) arg0->unkFC);
        arg0->unkF8 = (s32) (arg0->unkF8 + 1);
        /* fallthrough */
    case 1:
        temp_f1 = arg0->unkF0 + arg0->unkF4;
        arg0->unkF0 = temp_f1;
        if (!(temp_f1 < 1.0f)) {
            arg0->unkF0 = 1.0f;
            arg0->unkF4 = 0.0f;
            arg0->unkF8 = (s32) (arg0->unkF8 + 1);
        }
    default:
block_13:
        temp_f1_2 = arg0->unkC0 + arg0->unkC4;
        arg0->unkC0 = temp_f1_2;
        if (temp_f1_2 < 0.0f) {
            arg0->unkC0 = 0.0f;
            arg0->unkCC = (f32) (arg0->unkCC + arg0->unkC4);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
        return;
    case 2:
        if (arg0->unk100 <= 0) {
            arg0->unkF4 = (f32) -(1.0f / (f32) arg0->unk104);
            arg0->unkF8 = (s32) (arg0->unkF8 + 1);
        }
        arg0->unk100 = (s32) (arg0->unk100 - 1);
        goto block_13;
    case 3:
        temp_f1_3 = arg0->unkF0 + arg0->unkF4;
        arg0->unkF0 = temp_f1_3;
        if (temp_f1_3 <= 0.0f) {
            arg0->unkF0 = 0.0f;
            return;
        }
        goto block_13;
    }
}
