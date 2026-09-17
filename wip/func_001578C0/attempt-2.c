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

void func_001578C0(Pool *p, int i) {
    Slot *s = &p->slots[i];

    s->pos_x += s->vel_x;
    s->pos_y += s->vel_y;
    s->pos_z += s->vel_z;
    if (s->pos_z < 0.0f) {
        s->active = 0;
    }
}
