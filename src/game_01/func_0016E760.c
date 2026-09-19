typedef struct {
    unsigned char pad[0x64];
    int field64;
    int field68;
    unsigned char pad2[0x28C];
    int field2F8;
    int field2FC;
} Obj;

void func_0016E760(Obj *arg0) {
    arg0->field64 = arg0->field2F8;
    arg0->field68 = arg0->field2FC;
}
