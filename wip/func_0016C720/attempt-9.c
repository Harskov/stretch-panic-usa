typedef struct Node Node;

typedef struct Vtbl {
    unsigned char pad[0x18];
    void (*unk18)(Node *, int);
} Vtbl;

struct Node {
    Vtbl *vtbl;
    unsigned char pad[0x44];
    Node *next;
};

extern Node *D_006B3880;
extern void (*func)(Node *, int);

int func_0016C720(int arg1) {
    Node *p = D_006B3880;
    if (p != 0) {
        do {
            func = p->vtbl->unk18;
            func(p, arg1);
            p = p->next;
        } while (p != 0);
    }
    return 0;
}
