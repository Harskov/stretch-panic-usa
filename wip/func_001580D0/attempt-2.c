typedef struct Slot {
    unsigned char active;
    unsigned char unk_01[0x1F];
    float pos_x;
    float vel_x;
    float pos_y;
    float vel_y;
    float pos_z;
    float vel_z;
    unsigned char unk_38[8];
} Slot;

typedef struct Pool {
    unsigned char unk_00[0x70];
    Slot slots[8];
} Pool;

void func_001580D0(Pool *p, int i) {
    p->slots[i].pos_x += p->slots[i].vel_x;
    p->slots[i].pos_y += p->slots[i].vel_y;
    p->slots[i].pos_z += p->slots[i].vel_z;
    if (p->slots[i].pos_z < 0.0f) {
        p->slots[i].active = 0;
    }
}
