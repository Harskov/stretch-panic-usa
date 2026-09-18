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
    float t = o->unk_AC;
    float s = o->unk_A8;
    o->unk_A8 = s + t;
    t = o->unk_A4;
    s = o->unk_A0;
    o->unk_A0 = s - t;
    if (o->unk_A0 <= 0.0f) {
        o->flags = o->flags | 0x10000;
    }
}
