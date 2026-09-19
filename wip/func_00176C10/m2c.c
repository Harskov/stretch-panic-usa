void func_00176C10(void *arg0, s128 *arg1, s128 *arg2) {
    arg0->unkC4 = (s32) ((arg0->unkC4 - 1) & (arg0->unk94 - 1));
    *(arg0->unk9C + (arg0->unkC4 << 5)) = *arg1;
    ((arg0->unkC4 << 5) + arg0->unk9C)->unk10 = (s128) *arg2;
}
