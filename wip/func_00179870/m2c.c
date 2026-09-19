void func_00179870(s128 *arg0, void *arg1) {
    s128 *temp_v1_2;
    s128 var_v1;
    void *temp_v1;

    temp_v1 = arg1->unkD0;
    if (temp_v1 != NULL) {
        var_v1 = temp_v1->unk10;
    } else {
        temp_v1_2 = arg1->unkD4;
        if (temp_v1_2 != NULL) {
            var_v1 = *temp_v1_2;
        } else {
            var_v1 = arg1->unkE0;
        }
    }
    *arg0 = var_v1;
}
