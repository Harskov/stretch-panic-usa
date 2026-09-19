typedef struct {
    unsigned char pad[0x134];
    int field134;
} Obj;

void func_0016DC40(Obj *arg0, int arg1);

void func_0016DC30(Obj *arg0) {
    func_0016DC40(arg0, arg0->field134);
}
