typedef struct PadBuf {
    unsigned short b[9];
} PadBuf;

typedef struct PadState {
    unsigned char unk_00[0x18];
    unsigned short now;
    unsigned short pressed;
    unsigned short changed;
    unsigned short released;
    PadBuf old;
    PadBuf cur;
} PadState;

void func_00120340(PadState *p) {
    p->changed = p->old.b[0] ^ p->cur.b[0];
    p->pressed = p->changed & p->cur.b[0];
    p->released = p->changed ^ p->pressed;
    p->now = p->cur.b[0];
    p->old = p->cur;
}
