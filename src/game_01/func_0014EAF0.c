typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

typedef struct Node {
    u8 pad[0x60];
    s32 flags;
    u8 pad2[0x90 - 0x64];
    struct Node *next;
} Node;

extern Node *D_006AF4C8;

void func_0014EAF0(void) {
    Node *p = D_006AF4C8;
    while (p != 0) {
        p->flags |= 4;
        p = p->next;
    }
}
