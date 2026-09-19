typedef struct {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x108];
    int field16C;
} Obj;

void func_0016D690(Obj *arg0) {
    arg0->field16C = 0;
    arg0->flags |= 0x10000;
}
