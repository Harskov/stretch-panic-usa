typedef struct Obj {
    unsigned char unk_00[0x10];
    float pos[4];
    float vel[4];
    unsigned char unk_30[0x24];
    float height;
    float fall;
} Obj;

/* target adds pos += vel with VU0 macro-mode ops (lqc2/vadd.xyz/sqc2); no plain-C form yet */
int func_001636C0(Obj *o) {
    o->pos[0] += o->vel[0];
    o->pos[1] += o->vel[1];
    o->pos[2] += o->vel[2];
    o->height -= o->fall;
    if (o->height <= 0.0f) {
        return 0;
    }
    return 1;
}
