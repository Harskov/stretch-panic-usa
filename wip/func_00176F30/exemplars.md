# Exemplars for func_00176F30 — the 3 matched functions nearest by address

## func_001741B0 @ 0x001741B0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct {
    u8 pad0[0x50];
    f32 x50;
    f32 x54;
    f32 x58;
    f32 x5C;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    f32 x9C;
    f32 xA0;
} Obj;

s32 func_001741B0(Obj *arg0) {
    register f32 *v;
    register f32 *p;
    f32 t;
    s32 r;

    arg0->x70 = arg0->x70 * arg0->x74;
    arg0->x74 = arg0->x74 * arg0->x78;

    p = &arg0->x50;
    v = &arg0->x60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->xA0;
    arg0->x9C = arg0->x9C + t;

    if (!(arg0->xA0 <= 0.0f) && !(arg0->x9C <= 1.0f)) {
        arg0->x9C = 1.0f;
        arg0->xA0 = 0.0f;
    }

    r = 1;
    if (arg0->x9C <= 0.0f) {
        r = 0;
    }
    return r;
}

```

## func_00173C00 @ 0x00173C00 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct {
    u8 pad0[0x50];
    f32 x50;
    f32 x54;
    f32 x58;
    f32 x5C;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    f32 x9C;
    f32 xA0;
} Obj;

s32 func_00173C00(Obj *arg0) {
    register f32 *v;
    register f32 *p;
    f32 t;
    s32 r;

    arg0->x70 = arg0->x70 * arg0->x74;
    arg0->x74 = arg0->x74 * arg0->x78;

    p = &arg0->x50;
    v = &arg0->x60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    t = arg0->xA0;
    arg0->x9C = arg0->x9C + t;

    if (!(arg0->xA0 <= 0.0f) && !(arg0->x9C <= 1.0f)) {
        arg0->x9C = 1.0f;
        arg0->xA0 = 0.0f;
    }

    r = 1;
    if (arg0->x9C <= 0.0f) {
        r = 0;
    }
    return r;
}

```

## func_001733C0 @ 0x001733C0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct {
    u8 pad0[0x50];
    f32 x50;
    f32 x54;
    f32 x58;
    f32 x5C;
    f32 x60;
    f32 x64;
    f32 x68;
    f32 x6C;
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x8];
    f32 x8C;
    u8 pad90[0x8];
    f32 x98;
    f32 x9C;
} Obj;

s32 func_001733C0(Obj *arg0) {
    register f32 *v;
    register f32 *p;
    f32 t;
    s32 r;

    arg0->x70 = arg0->x70 * arg0->x74;
    arg0->x74 = arg0->x74 * arg0->x78;
    arg0->x7C = arg0->x7C * arg0->x80;
    t = arg0->x8C;
    arg0->x9C = arg0->x9C + t;

    p = &arg0->x50;
    v = &arg0->x60;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }

    r = 1;
    if (arg0->x9C <= 0.0f) {
        r = 0;
    }
    return r;
}

```
