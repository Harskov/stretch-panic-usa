typedef struct {
    int unk0;
    int unk4;
    int unk8;
    char unkC;
} S;

void func_0016BE10(S *arg0) {
    int v;

    switch (arg0->unk0) {
    case 0:
        arg0->unkC = 0;
        break;
    case 1:
        arg0->unk4 = arg0->unk4 + 1;
        if (arg0->unk4 >= arg0->unk8) {
            arg0->unk0 = 0;
            arg0->unkC = 0;
        }
        v = arg0->unk4 & 1;
        arg0->unkC = v == 0 ? 0 : 1;
        break;
    }
}
