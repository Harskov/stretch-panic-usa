typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Node {
    u8 pad[0x90];
    struct Node *next;
    u8 pad2[0x310 - 0x94];
    u128 unk_310;
} Node;

extern Node *D_006AF4C8;

void func_0014EAB0(u128 *arg1) {
    Node *p = *(Node **)0x006AF4C8;
    while (p != 0) {
        *arg1 = p->unk_310;
        p = p->next;
        arg1 = arg1 + 1;
    }
}
