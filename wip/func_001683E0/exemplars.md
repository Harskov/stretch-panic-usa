# Exemplars for func_001683E0 — the 3 matched functions nearest by address

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

## func_001636C0 @ 0x001636C0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Vec {
    float x;
    float y;
    float z;
    float w;
} Vec;

typedef struct Obj {
    unsigned char unk_00[0x10];
    Vec pos;
    Vec vel;
    unsigned char unk_30[0x24];
    float unk_54;
    float unk_58;
} Obj;

int func_001636C0(Obj *o) {
    register Vec *v;
    register Vec *p;
    float a;
    float b;

    p = &o->pos;
    v = &o->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    b = o->unk_58;
    a = o->unk_54;
    a = a - b;
    o->unk_54 = a;
    if (a <= 0.0f) {
        return 0;
    }
    return 1;
}

```
