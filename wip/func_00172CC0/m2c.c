void func_00172CC0(void *arg0, s32 arg1, f32 fparg0) {
    s32 temp_a3;

    temp_a3 = arg1 << 5;
    (temp_a3 + arg0->unk60)->unk10 = 0x459D1463;
    (temp_a3 + arg0->unk60)->unk14 = 0x40A00000;
    (temp_a3 + arg0->unk60)->unk18 = fparg0;
    func_0013BFB0(arg0, 0x459D1463, temp_a3);
}
