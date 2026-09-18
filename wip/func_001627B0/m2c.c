void func_001627B0(void *arg0, void *arg1) {
    arg0->unk28C = 0;
    arg1->unk50 = (f32) arg0->unk2E0;
    arg1->unk54 = (f32) arg0->unk2E4;
    arg1->unk58 = (f32) arg0->unk2E8;
    arg1->unk5C = (f32) arg0->unk2EC;
    arg1->unk0 = (s128) arg0->unk190;
    arg1->unk10 = (s128) arg0->unk1A0;
    arg1->unk20 = (s128) arg0->unk1B0;
    arg1->unk20 = (f32) -(bitwise f32) arg1->unk20;
    arg1->unk24 = (f32) -arg1->unk24;
    arg1->unk28 = (f32) -arg1->unk28;
    arg1->unk60 = (s32) arg0->unk2F0;
    arg1->unk64 = (f32) arg0->unk2F4;
    if (arg0->unk274 & 4) {
        arg1->unk68 = 2;
        arg1->unk6C = 4;
        arg1->unk70 = 0x3F800000;
        arg0->unk274 = (s32) (arg0->unk274 & ~4);
        return;
    }
    arg1->unk68 = 0;
    arg1->unk6C = 0;
    arg1->unk70 = 0;
}
