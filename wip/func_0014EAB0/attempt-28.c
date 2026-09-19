typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef unsigned __int128 u128;

typedef struct Node {
    u8 pad[0x90];
    struct Node *next;
    u8 pad2[0x310 - 0x94];
    u128 unk_310;
} Node;

extern Node *D_006AF4C8;

void func_0014EAB0(u128 *arg1) {
    Node *p;
    u128 *dst;
    dst = arg1;
    p = D_006AF4C8;
    while (p != 0) {
        *dst = p->unk_310;
        p = p->next;
        dst += 1;
    }
}
