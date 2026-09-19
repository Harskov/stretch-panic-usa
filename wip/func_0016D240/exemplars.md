# Exemplars for func_0016D240 — the 3 matched functions nearest by address

## func_0016C780 @ 0x0016C780 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0016C780(void) {
}

```

## func_0016C710 @ 0x0016C710 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0016C710(void) {
}

```

## func_0016C260 @ 0x0016C260 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
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

```
