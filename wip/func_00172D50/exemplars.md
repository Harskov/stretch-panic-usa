# Exemplars for func_00172D50 — the 3 matched functions nearest by address

## func_00172BF0 @ 0x00172BF0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

```c
void func_00172BF0(void) {
}

```

## func_00172A80 @ 0x00172A80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

extern s32 D_00601BB0;

s32 func_00172A80(s32 arg0) {
    s32 *p = &D_00601BB0;
    return p[arg0];
}

```

## func_00172A40 @ 0x00172A40 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

s32 func_00172A40(s32 *arg0, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = *arg1;
    if (temp_v0 != 0) {
        *arg1 = temp_v0 - 1;
        if (*arg1 == 0) {
            *arg0 = 0;
        }
        return 1;
    }
    return 0;
}

```
