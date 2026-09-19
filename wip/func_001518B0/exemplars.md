# Exemplars for func_001518B0 — the 3 matched functions nearest by address

## func_00152030 @ 0x00152030 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00152040();

void func_00152030(void) {
    func_00152040();
}

```

## func_001522E0 @ 0x001522E0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

void func_001522E0(char *arg0, char *arg1) {
    *(u128 *)(arg1 + 0x0) = *(u128 *)(arg0 + 0x140);
    *(u128 *)(arg1 + 0x10) = *(u128 *)(arg0 + 0x270);
    *(f32 *)(arg1 + 0x20) = *(f32 *)(arg0 + 0x410) * *(f32 *)(arg0 + 0x410);
}

```

## func_00152630 @ 0x00152630 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_0012E9E0();

void func_00152630(char *arg0) {
    char *p = arg0 + 0x70;
    func_0012E9E0(p, p, p);
}

```
