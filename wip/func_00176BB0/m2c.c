void func_00176BB0(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = arg0->unkC0;
    if (temp_v1 == 0) {
        temp_v1_2 = arg0->unkC8;
        if (temp_v1_2 != arg0->unk94) {
            arg0->unkC8 = (s32) (temp_v1_2 + 1);
        }
    } else {
        temp_v0 = arg0->unkC8;
        if (temp_v0 != 0) {
            arg0->unkC8 = (s32) (temp_v0 - 1);
        } else if (temp_v1 == -1) {

        }
    }
}
