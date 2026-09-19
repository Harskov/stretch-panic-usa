void func_0016DC40(void *arg0, s32 arg1) {
    arg0->unk164 = arg1;
    func_00172A80(arg1);
    arg0->unk168 = (s32) M2C_ERROR(/* Read from unset register $v0 */);
    arg0->unk60 = (s32) (arg0->unk60 | 0x04000000);
}
