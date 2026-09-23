class Sub {
public:
    virtual void m0(int);
};

struct Obj {
    unsigned char pad[0x114];
    Sub *unk_114;
};

extern "C" void func_0015D4E0(Obj *arg0);

void func_0015D4E0(Obj *arg0)
{
    Sub *temp_a0 = arg0->unk_114;
    if (temp_a0 != 0) {
        temp_a0->m0(1);
    }
}
