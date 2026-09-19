void func_00125C90(void *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    arg0->unk110 = 1;
    arg0->unkF0 = (s64) (((s64) (((arg2 << 0xC) | ((arg1 * 2) | ((bitwise s32) (128.0f * fparg0) * 0x10))) << 0x20) >> 0x20) | (arg0->unkF0 & ~0x3FFE));
}
