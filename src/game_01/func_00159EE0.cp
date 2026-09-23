class Sub {
public:
    virtual void m0(int);
};

struct Obj {
    unsigned char pad[0xB0];
    Sub *unk_B0;
};

extern "C" void func_00159EE0(Obj *arg0);

void func_00159EE0(Obj *arg0)
{
    Sub *temp_a0 = arg0->unk_B0;
    if (temp_a0 != 0) {
        temp_a0->m0(1);
    }
}
