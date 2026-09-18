# Exemplars for func_0015D530 — the 3 matched functions nearest by address

## func_0015D520 @ 0x0015D520 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0015D520(void) {
}

```

## func_0015D510 @ 0x0015D510 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0015D510(void) {
}

```

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
