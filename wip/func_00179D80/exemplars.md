# Exemplars for func_00179D80 — the 3 matched functions nearest by address

## func_00179D30 @ 0x00179D30 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Src {
    u128 v0;
    u128 v1;
    u128 v2;
    u128 v3;
    f32 f40;
    s32 i44;
    s32 i48;
} Src;

typedef struct Dst {
    u8 pad0[0x10];
    u128 v0;
    u8 pad20[0x10];
    u128 v1;
    u8 pad40[0x50];
    u128 v2;
    u128 v3;
    f32 fB0;
    s32 iB4;
    s32 iB8;
    s32 iBC;
    s32 iC0;
} Dst;

void func_00179D30(Dst *arg0, Src *arg1)
{
    arg0->v0 = arg1->v0;
    arg0->v1 = arg1->v1;
    arg0->v2 = arg1->v2;
    arg0->v3 = arg1->v3;
    arg0->fB0 = arg1->f40;
    arg0->iB4 = 1;
    arg0->iB8 = arg1->i44;
    arg0->iBC = arg1->i48;
    arg0->iC0 = 0;
}

```

## func_00179D20 @ 0x00179D20 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00179D20(void)
{
}

```

## func_00179D10 @ 0x00179D10 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
int func_00179D10(void)
{
    return 0;
}

```
