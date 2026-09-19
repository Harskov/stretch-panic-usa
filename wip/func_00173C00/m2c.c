void func_00173C00(void *arg0) {
    arg0->unk70 = (f32) (arg0->unk70 * arg0->unk74);
    arg0->unk74 = (f32) (arg0->unk74 * arg0->unk78);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
    arg0->unk9C = (f32) (arg0->unk9C + arg0->unkA0);
    if (!(arg0->unkA0 <= 0.0f) && !(arg0->unk9C <= 1.0f)) {
        arg0->unk9C = 1.0f;
        arg0->unkA0 = 0.0f;
    }
    if (arg0->unk9C <= 0.0f) {

    }
}
