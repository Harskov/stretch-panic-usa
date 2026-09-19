void func_00177D00(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    void *temp_t7;
    void *temp_t8;
    void *temp_t9;

    func_0017B170();
    arg0->unk0 = &D_0069D0E0;
    arg0->unk4F8 = 0x41100000;
    arg0->unk4FC = 0x3A83126F;
    arg0->unk500 = 0x3B449BA6;
    if (fparg0 == 0.0f) {
        arg0->unk4EC = 0x40400000;
    }
    if (fparg1 == 0.0f) {
        arg0->unk4F0 = 0x40A00000;
    }
    if (fparg2 == 0.0f) {
        arg0->unk4F4 = 0x40E00000;
    }
    arg0->unk5C0 = (s128) D_00698C00.unk0;
    arg0->unk5D0 = (s128) D_00698C00.unk10;
    arg0->unk5E0 = (s128) D_00698C00.unk20;
    arg0->unk5F0 = (s128) D_00698C00.unk30;
    temp_t9 = arg0 + 0x5C0;
    arg0->unk600 = (s128) D_00698C00.unk40;
    temp_t8 = arg0 + 0x610;
    temp_t7 = arg0 + 0x660;
    arg0->unk610 = (s128) D_00698C50.unk0;
    arg0->unk620 = (s128) D_00698C50.unk10;
    arg0->unk630 = (s128) D_00698C50.unk20;
    arg0->unk640 = (s128) D_00698C50.unk30;
    arg0->unk650 = (s128) D_00698C50.unk40;
    arg0->unk660 = (s128) D_00698CA0.unk0;
    arg0->unk670 = (s128) D_00698CA0.unk10;
    arg0->unk680 = (s128) D_00698CA0.unk20;
    arg0->unk690 = (s128) D_00698CA0.unk30;
    arg0->unk6A0 = (s128) D_00698CA0.unk40;
    arg0->unk6B0 = (s128) D_00698CF0.unk0;
    arg0->unk6C0 = (s128) D_00698CF0.unk10;
    arg0->unk6D0 = (s128) D_00698CF0.unk20;
    arg0->unk6E0 = (s128) D_00698CF0.unk30;
    arg0->unk6F0 = (s128) D_00698CF0.unk40;
    arg0->unk700 = temp_t9;
    arg0->unk704 = temp_t9;
    arg0->unk708 = temp_t8;
    arg0->unk70C = temp_t8;
    arg0->unk710 = temp_t8;
    arg0->unk714 = temp_t7;
    arg0->unk718 = temp_t8;
    arg0->unk71C = (void *) (arg0 + 0x6B0);
    arg0->unk720 = temp_t8;
    arg0->unk724 = temp_t8;
    arg0->unk728 = temp_t8;
    arg0->unk72C = temp_t9;
    arg0->unk730 = temp_t8;
    arg0->unk734 = temp_t9;
    arg0->unk738 = temp_t7;
    arg0->unk73C = temp_t7;
    arg0->unk354->unk10 = (void *) (arg0 + 0x700);
    arg0->unk358->unk10 = (void *) (arg0 + 0x704);
    arg0->unk35C->unk10 = (void *) (arg0 + 0x714);
    arg0->unk360->unk10 = (void *) (arg0 + 0x738);
    arg0->unk364->unk10 = (void *) (arg0 + 0x73C);
    arg0->unk368->unk10 = (void *) (arg0 + 0x720);
    arg0->unk36C->unk10 = (void *) (arg0 + 0x724);
    arg0->unk370->unk10 = (void *) (arg0 + 0x728);
    arg0->unk374->unk10 = (void *) (arg0 + 0x730);
    arg0->unk378->unk10 = (void *) (arg0 + 0x70C);
    arg0->unk37C->unk10 = (void *) (arg0 + 0x710);
}
