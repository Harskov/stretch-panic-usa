typedef struct Slot {
    unsigned char used;
    unsigned char unk_01[0x3F];
} Slot;

typedef struct Pool {
    unsigned char unk_00[0x70];
    Slot slots[8];
} Pool;

int func_00157E60(Pool *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->slots[i].used == 0) {
            return i;
        }
    }
    return -1;
}
