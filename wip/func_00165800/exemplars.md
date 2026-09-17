# Exemplars for func_00165800 — the 3 matched functions nearest by address

## func_00164E80 @ 0x00164E80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Ent {
    unsigned char used;
    unsigned char unk_01[0x2F];
} Ent;

typedef struct Obj {
    unsigned char unk_00[0x50];
    int count;
    unsigned char unk_54[0x14];
    Ent *arr;
} Obj;

Ent *func_00164E80(Obj *o) {
    int i;

    for (i = 0; i < o->count; i++) {
        if (o->arr[i].used == 0) {
            return &o->arr[i];
        }
    }
    return 0;
}

```

## func_00157650 @ 0x00157650 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Slot {
    unsigned char unk_00[0x40];
} Slot;

int func_00157650(Slot *s) {
    int i;

    for (i = 0; i < 8; i++) {
        if (s->unk_00[0x70] == 0) {
            return i;
        }
        s++;
    }
    return -1;
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
