typedef struct Node {
    unsigned char pad[0x60];
    int flags;
    unsigned char pad2[0x10];
    struct Node *next;
} Node;

extern Node *D_006A6C38;

void func_0016C260(void) {
    Node *p = D_006A6C38;
    if (p != 0) {
        do {
            p->flags |= 0x10000;
            p = p->next;
        } while (p != 0);
    }
}
