void func_00152500(void *arg0, void *arg1) {
    s32 var_v1;
    void *temp_a2;

    temp_a2 = arg1->unkC8;
    if (temp_a2->unk68 & 0x20) {
        arg0->unk480 = (s32) temp_a2->unk58;
        arg0->unk470 = (f32) arg1->unkA0;
        arg0->unk474 = (f32) arg1->unkA4;
        arg0->unk478 = (f32) arg1->unkA8;
        arg0->unk47C = (f32) arg1->unkAC;
        arg0->unk484 = 0;
        arg0->unk4A0 = (s128) arg1->unk80;
        arg0->unk4C0 = (s128) arg1->unk80;
        var_v1 = arg0->unk2E4 | 0x800;
    } else {
        arg0->unk310 = (s32) temp_a2->unk60;
        arg0->unk380 = (s32) arg1->unkC8->unk58;
        arg0->unk370 = (f32) arg1->unkA0;
        arg0->unk374 = (f32) arg1->unkA4;
        arg0->unk378 = (f32) arg1->unkA8;
        arg0->unk37C = (f32) arg1->unkAC;
        arg0->unk384 = 0;
        arg0->unk3A0 = (s128) arg1->unk80;
        arg0->unk3C0 = (s128) arg1->unk80;
        arg0->unk3B0 = (s128) arg1->unk90;
        var_v1 = arg0->unk2E4 | 0x400;
    }
    arg0->unk2E4 = var_v1;
}
