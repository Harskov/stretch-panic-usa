class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(int);
};

class Node : public Base {
public:
    unsigned char pad[0x44];
    Node *next;
};

extern Node *D_006B3880;

extern "C" int func_0016C720(int arg0, int arg1);

int func_0016C720(int arg0, int arg1)
{
    Node *p;

    for (p = D_006B3880; p != 0; p = p->next) {
        p->m4(arg1);
    }
    return 0;
}
