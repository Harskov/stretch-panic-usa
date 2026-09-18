typedef struct Obj {
    unsigned char unk_00[0x60];
    int flags;
    unsigned char unk_64[0x3C];
    float unk_A0;
    float unk_A4;
    float unk_A8;
    float unk_AC;
} Obj;

void func_00168630(Obj *o) {
    float d;

    o->unk_A8 += o->unk_AC;
    d = o->unk_A0 - o->unk_A4;
    o->unk_A0 = d;
    if (d <= 0.0f) {
        o->flags |= 0x10000;
    }
}
