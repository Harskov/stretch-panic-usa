void func_0016F790(s32 arg0, s32 *arg2) {
    s32 temp_a3;

    temp_a3 = *arg2;
    switch (temp_a3) {                              /* irregular */
    case 2:
        return;
    case 1:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
        if (D_006AEE60 != 0) {
            *arg2 += 1;
        }
        return;
    case 0:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v1) */);
        if ((D_006AEE58 | D_006AEE60) != 0) {
            *arg2 += 1;
        }
        return;
    }
}
