# Exemplars for func_00179D10 — the 3 matched functions nearest by address

## func_00179D00 @ 0x00179D00 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00179D00(void)
{
}

```

## func_00179CF0 @ 0x00179CF0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00179CF0(void)
{
}

```

## func_00179870 @ 0x00179870 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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
    u8 pad[0x10];
    u128 v;
} Node;

typedef struct Holder {
    u8 pad[0xD0];
    Node *n0;
    Node *n1;
    u8 pad2[8];
    u128 v;
} Holder;

void func_00179870(u128 *out, Holder *h)
{
    Node *n = h->n0;
    if (n != 0) {
        *out = n->v;
    } else {
        n = h->n1;
        if (n != 0) {
            *out = *(u128 *)n;
        } else {
            *out = h->v;
        }
    }
}

```
