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
    unsigned int v;
    int result;

    o->unk_E0 += o->unk_A8;
    f = o->unk_E8 + o->unk_E4;
    if (f < 0.0f) {
        f = 0.0f;
    }
    o->unk_E4 = f;
    v = o->unk_EC;
    o->unk_EC = v + 1;
    result = v < o->unk_AC;
    return result;
}
