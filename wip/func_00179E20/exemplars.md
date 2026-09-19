# Exemplars for func_00179E20 — the 3 matched functions nearest by address

## func_00179DF0 @ 0x00179DF0 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct Ent {
    u8 pad0[0x64];
    s32 i64;
    s32 i68;
    u8 pad6C[0x178 - 0x6C];
    s32 i178;
    u8 pad17C[0x180 - 0x17C];
    s32 i180;
    u8 pad184[0x2B0 - 0x184];
    s32 i2B0;
    s32 i2B4;
    s32 i2B8;
    s32 i2BC;
    u8 pad2C0[0x2F0 - 0x2C0];
    s32 i2F0;
} Ent;

void func_00179DF0(Ent *arg0)
{
    arg0->i2B0 = 0;
    arg0->i178 = 0xA;
    arg0->i180 = 0;
    arg0->i2BC = 0;
    arg0->i2B8 = 0;
    arg0->i2B4 = 0;
    arg0->i64 = 0;
    arg0->i68 = 0x40;
    arg0->i2F0 = 0;
}

```

## func_00179E80 @ 0x00179E80 (score 100.0, mwcps2-2.3.3-000906 -O3,p -sdatathreshold 0)

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

typedef struct Ent {
    u8 pad0[0x10];
    /* +0x10 is read 16 bytes wide into +0x510, so it is a 128-bit field, not
       part of the leading padding (K1 section 8: the pinned compiler emits
       lq/sq only for a 128-bit type). */
    u128 v10;
    u8 pad20[0x64 - 0x20];
    s32 i64;
    s32 i68;
    u8 pad6C[0x178 - 0x6C];
    s32 i178;
    u8 pad17C[0x180 - 0x17C];
    s32 i180;
    u8 pad184[0x2B0 - 0x184];
    s32 i2B0;
    s32 i2B4;
    s32 i2B8;
    s32 i2BC;
    u8 pad2C0[0x4E9 - 0x2C0];
    u8 b4E9;
    u8 pad4EA[0x510 - 0x4EA];
    u128 v510;
} Ent;

void func_00179E80(Ent *arg0)
{
    arg0->i2B0 = 1;
    arg0->i178 = 0;
    arg0->i180 = 0x3F000000;
    arg0->i2BC = 0;
    arg0->i2B8 = 0;
    arg0->i2B4 = 0;
    arg0->i64 = 0;
    arg0->i68 = 0;
    arg0->b4E9 = 0;
    arg0->v510 = arg0->v10;
}

```

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
