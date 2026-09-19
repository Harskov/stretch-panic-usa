# Exemplars for func_0016C710 — the 3 matched functions nearest by address

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

## func_0016BEA0 @ 0x0016BEA0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    unsigned char unkC;
} S;

unsigned char func_0016BEA0(S *arg0) {
    return arg0->unkC;
}

```

## func_0016BE80 @ 0x0016BE80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct {
    int unk0;
    int unk4;
    int unk8;
    char unkC;
} S;

void func_0016BE80(S *arg0, int arg1) {
    arg0->unk0 = 1;
    arg0->unk4 = 0;
    arg0->unk8 = arg1;
    arg0->unkC = 0;
}

```
