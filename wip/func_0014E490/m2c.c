void func_0014E490(void *arg0, s32 arg1) {
    ? var_a2;
    s32 temp_a0;
    s32 temp_s1;
    s32 var_s0;
    s32 var_v1;
    void *temp_a0_2;
    void *temp_s3;
    void *temp_v1;
    void *var_v1_2;

    if (arg1 != 0x25) {
        var_v1 = 0x14;
        switch (arg1) {                             /* irregular */
        default:
            var_v1 = 0x14;
            if (arg1 != 0x26) {
                var_v1 = 0x3E7;
                arg0->unk530 = 0x3E7;
            } else {
                arg0->unk530 = 0;
            }
            break;
        case 25:
            arg0->unk530 = 0xA;
            var_v1 = 0x1E;
            break;
        case 27:
            arg0->unk530 = 0xA;
            var_v1 = 0x28;
            break;
        case 6:
            var_v1 = 0x14;
            /* fallthrough */
        case 5:
            arg0->unk530 = 0;
            break;
        }
    } else {
        arg0->unk530 = 0xA;
        var_v1 = 0x28;
    }
    arg0->unk534 = var_v1;
    temp_s1 = M2C_ERROR(/* Read from unset register $f0 */);
    var_s0 = 0;
loop_29:
    if (var_s0 < 2) {
        temp_a0 = ((var_s0 * 4) + arg0)->unk530;
        var_v1_2 = var_s0 + arg0;
        if (temp_s1 >= temp_a0) {
            if ((temp_a0 + 2) >= temp_s1) {
                temp_a0_2 = var_s0 + arg0;
                if (temp_a0_2->unk538 == 0) {
                    temp_a0_2->unk538 = 1U;
                    var_a2 = 3;
                    if (var_s0 & 1) {
                        var_a2 = 2;
                    }
                    arg0->unk56C->unk60->unk18 = 0x3F19999A;
                    temp_s3 = arg0->unk56C;
                    temp_v1 = temp_s3->unk60;
                    func_0013DF50(temp_v1->unk0, D_006A6D10->unk4, var_a2, temp_v1->unk4);
                    temp_s3->unk60->unk0 = (s32) M2C_ERROR(/* Read from unset register $v0 */);
                }
            } else {
                var_v1_2 = var_s0 + arg0;
                goto block_27;
            }
        } else {
block_27:
            var_v1_2->unk538 = 0;
        }
        var_s0 += 1;
        goto loop_29;
    }
}
