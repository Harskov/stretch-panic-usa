typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef unsigned __int128 u128;

typedef struct Vec4 {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Vec4;

typedef struct Node {
    u8 pad[0x90];
    struct Node *next;
    u8 pad2[0x310 - 0x94];
    Vec4 unk_310;
} Node;

extern Node *D_006AF4C8;

void func_0014EAB0(Vec4 *arg1) {
    Node *p = D_006AF4C8;
    if (p != 0) {
        do {
            *arg1 = p->unk_310;
            p = p->next;
            arg1++;
        } while (p != 0);
    }
}
