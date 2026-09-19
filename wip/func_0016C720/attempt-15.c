typedef void (*Handler)(void *, int);

typedef struct Node {
    Handler vtable;
    unsigned char pad[0x14];
    void **methods;
    unsigned char pad2[0x2C];
    struct Node *next;
} Node;

extern Node *D_006B3880;

void func_0016C720(int arg1) {
    Node *p = D_006B3880;
    while (p != 0) {
        Handler h = p->methods[6];
        h(p, arg1);
        p = p->next;
    }
}
