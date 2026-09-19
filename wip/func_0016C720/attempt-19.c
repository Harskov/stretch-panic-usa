typedef struct Node Node;

typedef void (*Handler)(Node *, int);

typedef struct Node {
    Handler vtable[6];
    unsigned char pad[0x10];
    Node *next;
} Node;

extern Node *D_006B3880;

void func_0016C720(int arg1) {
    Node *p = D_006B3880;
    while (p != 0) {
        p->vtable[3](p, arg1);
        p = p->next;
    }
}
