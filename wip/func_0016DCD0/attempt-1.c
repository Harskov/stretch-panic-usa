typedef struct {
    unsigned char pad[0x164];
    int field164;
    int field168;
} Obj;

void func_0016DCD0(Obj *arg0, Obj *arg1) {
    arg0->field164 = arg1->field164;
    arg0->field168 = arg1->field168;
}
