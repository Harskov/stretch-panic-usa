# Exemplars for func_001724A0 — the 3 matched functions nearest by address

## func_00172410 @ 0x00172410 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

extern s32 D_006A6B90;

void func_00172410(f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, f32 x5, f32 x6, f32 x7) {
    s32 *p = &D_006A6B90;
    s32 *q = (s32 *)*p;
    *(f32 *)((char *)q + 0x1C) = x6;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x2C) = x6;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x3C) = x7;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x4C) = x7;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x30) = *(f32 *)((char *)q + 0x30) + x0;
    *(f32 *)((char *)q + 0x34) = *(f32 *)((char *)q + 0x34) + x1;
    *(f32 *)((char *)q + 0x38) = *(f32 *)((char *)q + 0x38) + x2;
    q = (s32 *)*p;
    *(f32 *)((char *)q + 0x40) = *(f32 *)((char *)q + 0x40) + x3;
    *(f32 *)((char *)q + 0x44) = *(f32 *)((char *)q + 0x44) + x4;
    *(f32 *)((char *)q + 0x48) = *(f32 *)((char *)q + 0x48) + x5;
}

```

## func_00170C00 @ 0x00170C00 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

extern s32 D_00601A80;

s32 *func_00170C00(s32 arg0) {
    s32 *p = &D_00601A80;
    return p + arg0 * 4;
}

```

## func_00170BE0 @ 0x00170BE0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

extern s32 D_0062FEA0;
extern s32 D_006A6730;
void func_00125D20();

void func_00170BE0(void) {
    func_00125D20(D_006A6730, 0, &D_0062FEA0);
}

```
