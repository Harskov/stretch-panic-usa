void func_00179D80(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    s32 var_t1;

    var_t1 = arg0->unkB4;
loop_2:
    if (var_t1 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t2) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($t0) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($t0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyz $vf1, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($t0) */);
        var_t1 -= 1;
        goto loop_2;
    }
}
