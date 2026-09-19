# Exemplars for func_0014E490 — the 3 matched functions nearest by address

## func_0014E460 @ 0x0014E460 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;

extern void func_0014E460();

void func_0014E460(char *arg0) {
    s32 i;

    i = 0;
    do {
        *(s32 *)(arg0 + i * 4 + 0x530) = 0;
        *(u8 *)(arg0 + i + 0x538) = 0;
        i += 1;
    } while (i < 2);
}

```

## func_0014DF80 @ 0x0014DF80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
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
    u8 pad2[0x364 - 0x64];
    s32 unk_364;
    u8 pad3[0x4D0 - 0x368];
    f32 unk_4D0;
} Node;

void func_0014DF80(Node *arg0) {
    if (arg0->flags & 4) {
        if (arg0->unk_4D0 < 0.415625f) {
            arg0->unk_364 = 0xE;
        }
        if (arg0->unk_4D0 < 0.115625f) {
            arg0->unk_364 = 0xD;
        }
    }
}

```

## func_0014EA70 @ 0x0014EA70 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
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

void func_0014EA70(s32 arg0, u128 *arg1) {
    Node *p;
    p = D_006AF4C8;
    while (p != 0) {
        p->unk_A0 = *arg1;
        p->unk_98 = 1;
        p = p->next;
    }
}

```
