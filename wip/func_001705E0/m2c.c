void func_001705E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ? sp20;
    ? sp10;
    s32 temp_v1;
    s32 var_t1;
    s32 var_t2;

    *sp = D_006A6B88->unk140;
    *(M2C_ERROR(/* Read from unset register $t0 */) + (0 << 5)) = *(arg3 + (arg2 * 0x10));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t5) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t4) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t3) */);
    temp_v1 = arg0 - 1;
    var_t1 = (arg2 + 1) & temp_v1;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t8) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t7) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t5) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t5) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($t6) */);
    var_t2 = 1;
loop_3:
    if (var_t2 != arg1) {
        *(M2C_ERROR(/* Read from unset register $t0 */) + (var_t2 << 5)) = *(arg3 + (var_t1 * 0x10));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t7) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t4) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t3) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t6) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t5) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t3) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t5) */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($t1) */);
        var_t2 += 1;
        var_t1 = (var_t1 + 1) & temp_v1;
        goto loop_3;
    }
    *(M2C_ERROR(/* Read from unset register $t0 */) + (var_t2 << 5)) = *(arg3 + (var_t1 * 0x10));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t3) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t2) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($a0) */);
}
