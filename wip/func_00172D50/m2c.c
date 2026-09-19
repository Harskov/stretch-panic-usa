void func_00172D50(void *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 temp_v1;

    temp_v1 = arg1 << 5;
    (temp_v1 + arg0->unk60)->unk10 = (f32) (12.566371f * (fparg0 * fparg0));
    (temp_v1 + arg0->unk60)->unk14 = fparg1;
    (temp_v1 + arg0->unk60)->unk18 = fparg2;
    func_0013BFB0(arg0);
}
