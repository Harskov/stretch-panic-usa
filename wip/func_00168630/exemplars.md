# Exemplars for func_00168630 — the 3 matched functions nearest by address

## func_001683E0 @ 0x001683E0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_001683E0(void) {
}

```

## func_001653D0 @ 0x001653D0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Obj {
    unsigned char unk_00[0x50];
    float speed;
    float drag;
    unsigned char unk_58[4];
    float fall;
    unsigned char unk_60[0x30];
    float pos;
    float height;
} Obj;

int func_001653D0(Obj *o) {
    int alive = 1;

    o->speed = o->speed - o->speed * o->drag;
    o->pos += o->speed;
    o->height -= o->fall;
    if (o->height <= 0.0f) {
        alive = 0;
    }
    return alive;
}

```

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
