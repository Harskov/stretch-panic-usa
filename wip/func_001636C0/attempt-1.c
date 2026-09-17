typedef struct Obj {
    unsigned char unk_00[0x10];
    float pos[4];
    float vel[4];
    unsigned char unk_30[0x24];
    float height;
    float fall;
} Obj;

int func_001636C0(Obj *o) {
    float *p = o->pos;
    float *v = o->vel;

    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    o->height -= o->fall;
    if (o->height <= 0.0f) {
        return 0;
    }
    return 1;
}
