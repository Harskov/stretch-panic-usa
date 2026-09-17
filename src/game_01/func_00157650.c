typedef struct Slot {
    unsigned char unk_00[0x40];
} Slot;

int func_00157650(Slot *s) {
    int i;

    for (i = 0; i < 8; i++) {
        if (s->unk_00[0x70] == 0) {
            return i;
        }
        s++;
    }
    return -1;
}
