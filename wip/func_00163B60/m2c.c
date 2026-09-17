void func_00163B60(void *arg0) {
    f32 temp_f1;
    s32 temp_a1;
    s32 var_v1;

    temp_a1 = arg0->unk64;
    switch (temp_a1) {                              /* irregular */
    case 0:
        arg0->unk6C = (f32) (1.0f / (f32) arg0->unk5C);
        arg0->unk74 = 0;
        arg0->unk64 = (s32) (arg0->unk64 + 1);
        /* fallthrough */
    case 1:
        if (arg0->unk74 >= arg0->unk5C) {
            arg0->unk64 = (s32) (arg0->unk64 + 1);
        } else {
            arg0->unk68 = (f32) (arg0->unk68 + arg0->unk6C);
            var_v1 = arg0->unk74 + 1;
block_13:
            arg0->unk74 = var_v1;
        }
        break;
    case 2:
        arg0->unk6C = (f32) -(1.0f / (f32) arg0->unk60);
        arg0->unk74 = 0;
        arg0->unk64 = (s32) (arg0->unk64 + 1);
        /* fallthrough */
    case 3:
        if (arg0->unk74 >= arg0->unk60) {

        } else {
            arg0->unk68 = (f32) (arg0->unk68 + arg0->unk6C);
            var_v1 = arg0->unk74 + 1;
            goto block_13;
        }
        break;
    }
    temp_f1 = arg0->unk68;
    if (temp_f1 < 0.0f) {
        arg0->unk68 = 0.0f;
        return;
    }
    if (!(temp_f1 <= 1.0f)) {
        arg0->unk68 = 1.0f;
    }
}
