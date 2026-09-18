# Exemplars for func_00159330 — the 3 matched functions nearest by address

## func_00158670 @ 0x00158670 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Obj {
    unsigned char unk_00[0x54];
    int count;
} Obj;

int func_00158670(Obj *o) {
    return o->count-- > 0;
}

```

## func_001580D0 @ 0x001580D0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Slot {
    unsigned char active;
    unsigned char unk_01[0x1F];
    float pos_x;
    float vel_x;
    float pos_y;
    float vel_y;
    float pos_z;
    float vel_z;
    unsigned char unk_38[8];
} Slot;

typedef struct Pool {
    unsigned char unk_00[0x70];
    Slot slots[8];
} Pool;

void func_001580D0(Pool *p, int i) {
    p->slots[i].pos_x += p->slots[i].vel_x;
    p->slots[i].pos_y += p->slots[i].vel_y;
    p->slots[i].pos_z += p->slots[i].vel_z;
    if (p->slots[i].pos_z < 0.0f) {
        p->slots[i].active = 0;
    }
}

```

## func_00157E60 @ 0x00157E60 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Slot {
    unsigned char used;
    unsigned char unk_01[0x3F];
} Slot;

typedef struct Pool {
    unsigned char unk_00[0x70];
    Slot slots[8];
} Pool;

int func_00157E60(Pool *p) {
    int i;

    for (i = 0; i < 8; i++) {
        if (p->slots[i].used == 0) {
            return i;
        }
    }
    return -1;
}

```
