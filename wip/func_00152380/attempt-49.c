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

typedef struct Src {
    u8 pad0[0x30];
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    s32 i40;
    u8 pad1[0x4];
    u128 v50;
    u8 pad2[0x10];
    u128 v70;
    u8 pad3[0xC0];
    u128 v140;
    u8 pad4[0x10];
    u128 v250;
    u128 v260;
    u128 v270;
    u8 pad5[0x1A0];
    u8 b414;
    u8 pad6[0x5B];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    u128 v40;
    u128 v50;
    u128 v60;
    u128 v70;
    f32 f80;
    f32 f84;
    f32 f88;
    f32 f8C;
    s32 i90;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    arg0->b414 = 0;
    arg1->f80 = arg0->f470;
    arg1->f84 = arg0->f474;
    arg1->f88 = arg0->f478;
    arg1->f8C = arg0->f47C;
    arg1->i90 = arg0->i480;
    arg1->v30 = arg0->v140;
    arg1->v0 = arg0->v250;
    arg1->v10 = arg0->v260;
    arg1->v20 = arg0->v270;
    *(f32 *)((char *)arg1 + 0x20) = -*(f32 *)((char *)arg1 + 0x20);
    *(f32 *)((char *)arg1 + 0x24) = -*(f32 *)((char *)arg1 + 0x24);
    *(f32 *)((char *)arg1 + 0x28) = -*(f32 *)((char *)arg1 + 0x28);
}
