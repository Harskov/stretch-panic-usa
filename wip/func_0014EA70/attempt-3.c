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
    u8 pad0[0x90];
    struct Node *next;
    u8 pad94[0x98 - 0x94];
    u8 unk_98;
    u8 pad99[0xA0 - 0x99];
    u128 unk_A0;
} Node;

extern Node *D_006AF4C8;

void func_0014EA70(u128 *arg1) {
    Node *p;
    u128 v = *arg1;
    p = D_006AF4C8;
    while (p != 0) {
        p->unk_A0 = v;
        p->unk_98 = 1;
        p = p->next;
    }
}
