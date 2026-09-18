# Exemplars for func_00159F20 — the 3 matched functions nearest by address

## func_00159F10 @ 0x00159F10 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void *func_00159F10(char *p) {
    return p + 0x10;
}

```

## func_00159E20 @ 0x00159E20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int128 u128;

typedef struct Sub {
    unsigned char unk_00[0x54];
    int unk_54;
} Sub;

typedef struct Inner {
    unsigned char unk_00[0xC8];
    Sub *unk_C8;
} Inner;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x20];
    u32 unk_60;
    unsigned char unk_64[0x16C];
    u8 unk_1D0;
    unsigned char unk_1D1[0x5F];
    u128 unk_230;
    u128 unk_240;
} Obj;

void func_00159E20(Obj *arg0, Inner *arg1) {
    if (arg0->unk_1D0 != 0) {
        arg0->unk_60 |= 0x80000;
    } else if (arg1->unk_C8->unk_54 == 4) {
        arg0->unk_60 |= 0x80000;
    }
    arg0->unk_10 = arg0->unk_230;
    arg0->unk_30 = arg0->unk_240;
}

```

## func_00159330 @ 0x00159330 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void *func_00159330(char *p) {
    return p + 0x1E0;
}

```
