void func_0016E790(void *arg0, void *arg1, s32 arg2) {
    s32 temp_a0;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s2;

    var_a2 = arg2;
    var_s2 = arg1;
    var_s0 = 0;
    var_s1 = 0;
    var_s3 = 0;
loop_4:
    temp_a0 = arg0->unkE8;
    if (var_s0 != temp_a0) {
        *(arg0->unkFC + var_s1) = *(s128 *)0x70000BE0;
        *(arg0->unk100 + var_s1) = *(s128 *)0x70000BE0;
        *(arg0->unk104 + var_s1) = *(s128 *)0x70000BE0;
        (arg0->unkEC + var_s3)->unk20 = (f32) (arg0->unk50 * var_s2->unk0);
        func_00100810(0x40, 0x70000BE0, var_a2);
        if (M2C_ERROR(/* Read from unset register $v0 */) != 0) {
            *M2C_ERROR(/* Read from unset register $v0 */) = &D_0069C300;
            *M2C_ERROR(/* Read from unset register $v0 */) = &D_0069C480;
            M2C_ERROR(/* Read from unset register $v0 */)->unk30 = (s32) var_s2->unk4;
            M2C_ERROR(/* Read from unset register $v0 */)->unk4 = 0;
            temp_v1 = M2C_ERROR(/* Read from unset register $v0 */)->unk30;
            M2C_ERROR(/* Read from unset register $v0 */)->unk10 = (s128) temp_v1->unk0;
            M2C_ERROR(/* Read from unset register $v0 */)->unk20 = (s128) temp_v1->unk10;
        }
        var_a2 = 1;
        (arg0->unkEC + var_s3)->unk24 = (s32) M2C_ERROR(/* Read from unset register $v0 */);
        var_s2 += 8;
        var_s0 += 1;
        (arg0->unkEC + var_s3)->unk28 = 1;
        var_s3 += 0x30;
        *(arg0->unkF0 + var_s1) = 0;
        (arg0->unkF0 + var_s1)->unk4 = 1;
        (arg0->unkF0 + var_s1)->unk8 = 0x3F800000;
        temp_v1_2 = arg0->unkF0 + var_s1;
        var_s1 += 0x10;
        temp_v1_2->unkC = 2;
        goto loop_4;
    }
    arg0->unkF8->unk0 = temp_a0;
    arg0->unkF8->unk4 = (s32) arg0->unkEC;
    arg0->unkF8->unk8 = (s32) arg0->unkF0;
    arg0->unkF8->unkC = (s32) arg0->unkF4;
}
