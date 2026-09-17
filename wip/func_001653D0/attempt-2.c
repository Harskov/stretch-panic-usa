typedef struct Obj {
    unsigned char unk_00[0x50];
    float speed;
    float drag;
    unsigned char unk_58[4];
    float fall;
    unsigned char unk_60[0x30];
    float pos;
    float height;
} Obj;

int func_001653D0(Obj *o) {
    int alive = 1;

    o->speed = o->speed - o->speed * o->drag;
    o->pos += o->speed;
    o->height -= o->fall;
    if (o->height <= 0.0f) {
        alive = 0;
    }
    return alive;
}
