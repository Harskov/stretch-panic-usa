typedef struct Fade {
    unsigned char unk_00[0x5C];
    int in_frames;
    int out_frames;
    int state;
    float value;
    float step;
    unsigned char unk_70[4];
    int counter;
} Fade;

int func_00163B60(Fade *f) {
    int ret = 1;

    switch (f->state) {
    case 0:
        f->step = 1.0f / (float)f->in_frames;
        f->counter = 0;
        f->state++;
    case 1:
        if (f->counter < f->in_frames) {
            f->value += f->step;
            f->counter++;
        } else {
            f->state++;
        }
        break;
    case 2:
        f->step = -(1.0f / (float)f->out_frames);
        f->counter = 0;
        f->state++;
    case 3:
        if (f->counter < f->out_frames) {
            f->value += f->step;
            f->counter++;
        } else {
            ret = 0;
        }
        break;
    }
    if (f->value < 0.0f) {
        f->value = 0.0f;
    } else if (f->value > 1.0f) {
        f->value = 1.0f;
    }
    return ret;
}
