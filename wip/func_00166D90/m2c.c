void func_00166D90(void *arg0) {
    f32 temp_f1;

    arg0->unkE0 = (f32) (arg0->unkE0 + arg0->unkA8);
    temp_f1 = arg0->unkE4 + arg0->unkE8;
    arg0->unkE4 = temp_f1;
    if (temp_f1 < 0.0f) {
        arg0->unkE4 = 0.0f;
    }
    arg0->unkEC = (s32) (arg0->unkEC + 1);
}
