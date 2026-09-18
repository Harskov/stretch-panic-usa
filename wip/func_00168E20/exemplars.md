# Exemplars for func_00168E20 — the 3 matched functions nearest by address

## func_00168630 @ 0x00168630 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef struct Obj {
    unsigned char unk_00[0x60];
    int flags;
    unsigned char unk_64[0x3C];
    float unk_A0;
    float unk_A4;
    float unk_A8;
    float unk_AC;
} Obj;

void func_00168630(Obj *o) {
    float a;
    float b;

    o->unk_A8 += o->unk_AC;
    b = o->unk_A4;
    a = o->unk_A0;
    o->unk_A0 = a - b;
    if (a - b <= 0.0f) {
        o->flags |= 0x10000;
    }
}

```

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
