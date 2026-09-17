typedef struct Obj {
    unsigned char unk_00[0x70];
    unsigned char active;
    unsigned char unk_71[0x1F];
    float pos_x;
    float vel_x;
    float pos_y;
    float vel_y;
    float pos_z;
    float vel_z;
} Obj;

typedef struct Part {
    unsigned char unk_00[0x40];
} Part;

void func_001580D0(Part *base, unsigned int i) {
    Obj *o = (Obj *)(base + i);

    o->pos_x += o->vel_x;
    o->pos_y += o->vel_y;
    o->pos_z += o->vel_z;
    if (o->pos_z < 0.0f) {
        o->active = 0;
    }
}
