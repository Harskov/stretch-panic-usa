void func_001636C0(void *arg0) {
    f32 temp_f1;

    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
    temp_f1 = arg0->unk54 - arg0->unk58;
    arg0->unk54 = temp_f1;
    if (temp_f1 <= 0.0f) {

    }
}
