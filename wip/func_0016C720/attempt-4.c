typedef struct Node Node;

typedef struct Vtbl {
    unsigned char pad[0x18];
    void (*unk18)(Node *, int);
} Vtbl;

struct Node {
    Vtbl *vtbl;
    unsigned char pad[0x40];
    Node *arg;
    Node *next;
};

extern Node *D_006B3880;

int func_0016C720(int arg1) {
    Node *p = D_006B3880;
    if (p != 0) {
        do {
            p->vtbl->unk18(p, arg1);
            p = p->next;
        } while (p != 0);
    }
    return 0;
}
