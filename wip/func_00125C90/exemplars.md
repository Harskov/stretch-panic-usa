# Exemplars for func_00125C90 — the 3 matched functions nearest by address

## func_00131740 @ 0x00131740 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct E64 {
    __int128 q[4];
} E64;

typedef struct Src {
    unsigned char unk_00[4];
    E64 *arr;
} Src;

typedef struct Ctx {
    unsigned char unk_00[8];
    Src *src;
    int count;
    E64 *dst;
} Ctx;

void func_00131740(Ctx *c) {
    int i;

    for (i = 0; i < c->count; i++) {
        c->dst[i] = c->src->arr[i];
    }
}

```

## func_00145A10 @ 0x00145A10 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct M128 {
    __int128 q[8];
} M128;

typedef struct Obj {
    unsigned char unk_00[0x90];
    M128 m;
    unsigned char unk_110[0x3C];
    unsigned char flag;
} Obj;

void func_00145A10(Obj *o, M128 *dst) {
    *dst = o->m;
    o->flag = 0;
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
