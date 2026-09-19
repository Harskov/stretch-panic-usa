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
    float g;
    int v;
    int r;

    o->unk_E0 += o->unk_A8;
    g = o->unk_E8;
    f = o->unk_E4;
    o->unk_E4 = f + g;
    if (f + g < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    v = o->unk_EC;
    r = o->unk_AC;
    o->unk_EC = v + 1;
    return v < r;
}
