typedef void (*Handler)(void *, int);

typedef struct Node {
    Handler *methods;
    unsigned char pad[0x14];
    struct Node *next;
} Node;

extern Node *D_006B3880;

void func_0016C720(int arg1) {
    Node *p = D_006B3880;
    while (p != 0) {
        void (*h)(void *, int) = p->methods[6];
        h(p, arg1);
        p = p->next;
    }
}
