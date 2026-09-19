void func_001733C0(void *arg0) {
    arg0->unk70 = (f32) (arg0->unk70 * arg0->unk74);
    arg0->unk74 = (f32) (arg0->unk74 * arg0->unk78);
    arg0->unk7C = (f32) (arg0->unk7C * arg0->unk80);
    arg0->unk9C = (f32) (arg0->unk9C + arg0->unk8C);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
    if (arg0->unk9C <= 0.0f) {

    }
}
