typedef struct {
    int unk0;
    int unk4;
    int unk8;
    char unkC;
} S;

void func_0016BE10(S *arg0) {
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
        arg0->unkC = (arg0->unk4 & 1) != 0;
        break;
    }
}
