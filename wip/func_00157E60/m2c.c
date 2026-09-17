void func_00157E60(void *arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0;
    var_v0 = 0;
loop_1:
    if (var_a0->unk70 == 0) {
        return;
    }
    var_v0 += 1;
    var_a0 += 0x40;
    if (var_v0 >= 8) {
        return;
    }
    goto loop_1;
}
