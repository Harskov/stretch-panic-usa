typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    float unk_AC;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    float f;

    o->unk_E0 += o->unk_A8;
    f = o->unk_E4 + o->unk_E8;
    o->unk_E4 = f;
    if (f < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    o->unk_EC++;
    return *(&o->unk_EC - 1) < o->unk_AC;
}
