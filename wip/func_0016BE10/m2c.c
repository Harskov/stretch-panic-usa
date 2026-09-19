void func_0016BE10(void *arg0) {
    s32 temp_a1;

    temp_a1 = arg0->unk0;
    switch (temp_a1) {                              /* irregular */
    case 0:
        arg0->unkC = 0;
        return;
    case 1:
        arg0->unk4 = (s32) (arg0->unk4 + 1);
        if (arg0->unk4 >= arg0->unk8) {
            arg0->unk0 = 0;
            arg0->unkC = 0;
        }
        arg0->unkC = (s8) (!(arg0->unk4 & 1) ? 0 : 1);
        return;
    }
}
