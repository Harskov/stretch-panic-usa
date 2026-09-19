# Exemplars for func_0014EAB0 — the 3 matched functions nearest by address

## func_0014EAF0 @ 0x0014EAF0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

```

## func_0014F060 @ 0x0014F060 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Obj {
    u8 pad0[0x30];
    u128 unk_30;
    u8 pad40[0x14C - 0x40];
    s32 unk_14C;
    s32 unk_150;
    u8 pad154[0x2B0 - 0x154];
    u128 unk_2B0;
    u8 pad2C0[0x378 - 0x2C0];
    s32 unk_378;
    u8 pad37C[0x3A0 - 0x37C];
    u128 unk_3A0;
    u128 unk_3B0;
    u8 pad3C0[0x3C4 - 0x3C0];
    s32 unk_3C4;
    u8 pad3C8[0x3D0 - 0x3C8];
    s32 unk_3D0;
    u8 pad3D4[0x400 - 0x3D4];
    Vec unk_400;
} Obj;

void func_0014F060(Obj *arg0, Vec *arg1) {
    arg0->unk_3A0 = arg0->unk_2B0;
    arg0->unk_3B0 = arg0->unk_30;
    if (arg0->unk_378 & 2) {
        arg0->unk_3C4 = arg0->unk_150;
        arg0->unk_3D0 = 2;
    } else {
        arg0->unk_3C4 = arg0->unk_14C;
        arg0->unk_3D0 = 0;
    }
    *arg1 = arg0->unk_400;
}

```

## func_00151060 @ 0x00151060 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0014FFD0();

void func_00151060(void) {
    func_0014FFD0();
}

```
