# Exemplars for func_00151060 — the 3 matched functions nearest by address

## func_00151460 @ 0x00151460 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

void func_00151460(char *arg0, s32 arg1, f32 fparg0) {
    *(u32 *)(arg0 + 0x60) |= 0x04000000;
    *(s32 *)(arg0 + 0x410) = arg1;
    *(f32 *)(arg0 + 0x414) = fparg0;
    *(u8 *)(arg0 + 0x418) = 0;
    *(s32 *)(arg0 + 0x420) = 0;
    *(s32 *)(arg0 + 0x424) = 0;
    *(s32 *)(arg0 + 0x428) = 0;
    *(f32 *)(arg0 + 0x42C) = 1.0f;
}

```

## func_001514A0 @ 0x001514A0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

void func_001514A0(char *arg0, s32 arg1, Vec *arg2, f32 fparg0) {
    *(u32 *)(arg0 + 0x60) |= 0x04000000;
    *(s32 *)(arg0 + 0x410) = arg1;
    *(f32 *)(arg0 + 0x414) = fparg0;
    *(u8 *)(arg0 + 0x418) = 1;
    *(u128 *)(arg0 + 0x420) = *(u128 *)arg2;
}

```

## func_001518B0 @ 0x001518B0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_001518B0(void) {
}

```
