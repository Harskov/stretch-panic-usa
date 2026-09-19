typedef struct {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x100];
    int field164;
    int field168;
} Obj;

int func_0016DC80(Obj *arg0) {
    int v = arg0->field168;
    if (v == 0) {
        return 0;
    }
    arg0->field168 = v - 1;
    if (arg0->field168 == 0) {
        arg0->flags &= 0xFBFFFFFF;
        arg0->field164 = 0;
        return 1;
    }
    return 1;
}
