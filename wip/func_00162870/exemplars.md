# Exemplars for func_00162870 — the 3 matched functions nearest by address

## func_00163470 @ 0x00163470 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00163470(void) {
}

```

## func_00163480 @ 0x00163480 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
int func_00163480(void) {
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
