typedef struct Node {
    unsigned char pad[0x18];
    void **vtable;
    unsigned char pad2[0x2C];
    struct Node *next;
} Node;

extern Node *D_006B3880;

void func_0016C720(int arg1) {
    Node *p = D_006B3880;
    if (p != 0) {
        do {
            ((void (*)(Node *, int))p->vtable[6])(p, arg1);
            p = p->next;
        } while (p != 0);
    }
}
