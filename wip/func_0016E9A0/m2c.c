void func_0016E9A0(void *arg0) {
    s32 temp_a3;
    s32 temp_t0;
    s32 var_t1;

    var_t1 = 0;
loop_3:
    if (var_t1 != arg0->unkE8) {
        temp_t0 = var_t1 * 0x30;
        temp_a3 = var_t1 * 0x10;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($a2) */);
        var_t1 += 1;
        *(arg0->unkEC + temp_t0) = *(arg0->unkFC + temp_a3);
        *(arg0->unk100 + temp_a3) = *(arg0->unkFC + temp_a3);
        *(arg0->unk104 + temp_a3) = (temp_t0 + arg0->unkEC)->unk10;
        goto loop_3;
    }
}
