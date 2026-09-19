void func_00172DA0(void *arg0, s32 arg1, u8 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;

    arg0->unk0 = &D_0069CE70;
    arg0->unk10 = (s128) *(s128 *)0x70000BE0;
    arg0->unk20 = (s128) *(s128 *)0x70000BE0;
    arg0->unk30 = arg1;
    arg0->unk34 = (s32) D_006B3888;
    D_006B3888 += 1;
    arg0->unk3C = (s32) (&D_006B3700)[arg0->unk30];
    arg0->unk38 = 0;
    (&D_006B3700)[arg0->unk30] = (s32) arg0;
    temp_v0 = arg0->unk3C;
    if (temp_v0 != 0) {
        temp_v0->unk38 = arg0;
    }
    arg0->unk40 = arg2;
    if (arg0->unk40 != 0) {
        arg0->unk48 = (s32) D_006B3880;
        arg0->unk44 = 0;
        D_006B3880 = (s32) arg0;
        temp_v0_2 = arg0->unk48;
        if (temp_v0_2 != 0) {
            temp_v0_2->unk44 = arg0;
        }
    }
}
