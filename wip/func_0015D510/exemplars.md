# Exemplars for func_0015D510 — the 3 matched functions nearest by address

## func_0015BA00 @ 0x0015BA00 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int128 u128;
typedef float f32;

typedef struct Sub {
    unsigned char unk_00[0x54];
    int unk_54;
} Sub;

typedef struct Arg1 {
    unsigned char unk_00[0x80];
    f32 unk_80;
    unsigned char unk_84[0x44];
    Sub *unk_C8;
} Arg1;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x20];
    int unk_60;
    unsigned char unk_64[0x174];
    int unk_1D8;
    unsigned char unk_1DC[0x14];
    u128 unk_1F0;
    u128 unk_200;
} Obj;

void func_0015BA00(Obj *arg0, Arg1 *arg1) {
    f32 zero;

    arg0->unk_10 = arg0->unk_1F0;
    arg0->unk_30 = arg0->unk_200;
    if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    zero = 0.0f;
    if ((arg1->unk_80 != zero) || (arg0->unk_1D8 & 2)) {
        arg0->unk_60 |= 0x80000;
    }
}

```

## func_0015B500 @ 0x0015B500 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int128 u128;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x1B0];
    u128 unk_1F0;
    u128 unk_200;
    unsigned char unk_210[0x40];
    f32 unk_250;
    f32 unk_254;
    f32 unk_258;
    f32 unk_25C;
} Obj;

typedef struct Out {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Out;

void func_0015B500(Obj *arg0, Out *arg1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    arg0->unk_1F0 = arg0->unk_10;
    arg0->unk_200 = arg0->unk_30;
    f3 = arg0->unk_250;
    f2 = arg0->unk_254;
    f1 = arg0->unk_258;
    f0 = arg0->unk_25C;
    arg1->x = f3;
    arg1->y = f2;
    arg1->z = f1;
    arg1->w = f0;
    (void)f0;
    (void)f1;
    (void)f2;
    (void)f3;
}

```

## func_00159F20 @ 0x00159F20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
float func_00159F20(void) {
    return 0.0f;
}

```
