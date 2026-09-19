void func_0017EC80(void *arg0) {
    f32 temp_f1;

    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmulx.xyz $vf1, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
    arg0->unk50 = (f32) (arg0->unk50 * (0.97f + arg0->unk54));
    arg0->unk54 = (f32) (arg0->unk54 * 0.75f);
    arg0->unk58 = (f32) (arg0->unk58 * (0.999f + arg0->unk5C));
    arg0->unk5C = (f32) (arg0->unk5C * 0.75f);
    temp_f1 = arg0->unk60 + arg0->unk64;
    arg0->unk60 = temp_f1;
    if (temp_f1 <= 0.0f) {

    }
}
