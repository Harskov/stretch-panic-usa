typedef struct Node Node;

typedef void (*Handler)(Node *, int);

typedef struct Node {
    Handler vtable[1];
    unsigned char pad[0x14];
    Node *next;
} Node;

extern Node *D_006B3880;

void func_0016C720(int arg1) {
    Node *p = D_006B3880;
    while (p != 0) {
        p->vtable[6](p, arg1);
        p = p->next;
    }
}
