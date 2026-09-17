typedef struct Obj {
    unsigned char unk_00[0xA0];
    float pos[4];
    float vel[4];
    float y;
    float vy;
    unsigned char unk_C8[4];
    float z;
    unsigned char unk_D0[0x20];
    float t;
    float step;
    int state;
    int in_frames;
    int hold;
    int out_frames;
} Obj;

/* target ends with pos += vel through VU0 macro-mode ops (lqc2/vadd.xyz/sqc2); no plain-C form yet */
int func_00165800(Obj *o) {
    switch (o->state) {
    case 0:
        o->t = 0.0f;
        o->step = 1.0f / (float)o->in_frames;
        o->state++;
    case 1:
        o->t += o->step;
        if (!(o->t < 1.0f)) {
            o->t = 1.0f;
            o->step = 0.0f;
            o->state++;
        }
        break;
    case 2:
        if (o->hold <= 0) {
            o->step = -(1.0f / (float)o->out_frames);
            o->state++;
        }
        o->hold--;
        break;
    case 3:
        o->t += o->step;
        if (o->t <= 0.0f) {
            o->t = 0.0f;
            return 0;
        }
        break;
    }
    o->y += o->vy;
    if (o->y < 0.0f) {
        o->y = 0.0f;
        o->z += o->vy;
    }
    o->pos[0] += o->vel[0];
    o->pos[1] += o->vel[1];
    o->pos[2] += o->vel[2];
    return 1;
}
