typedef struct Sub {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
} Sub;

typedef struct Arg0 {
    unsigned char pad[0xF8];
    Sub *sub;
} Arg0;

typedef struct Arg1 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    unsigned char pad[0xC0 - 0x10];
    int unkC0;
} Arg1;

void func_0016D250(Arg0 *arg0, Arg1 *arg1) {
    Sub *s;
    if (arg1->unkC0 != 0) {
        return;
    }
    s = arg0->sub;
    arg1->unk0 = s->unk0;
    arg1->unk4 = s->unk4;
    arg1->unk8 = s->unk8;
    arg1->unkC = s->unkC;
}
