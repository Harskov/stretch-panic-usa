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
    u8 pad0[0x470];
    f32 f470;
    f32 f474;
    f32 f478;
    f32 f47C;
    s32 i480;
    u8 pad1[0x10C];
    u128 v140;
    u8 pad2[0x100];
    u128 v250;
    u128 v260;
    u128 v270;
} Src;

typedef struct Dst {
    u128 v0;
    u128 v10;
    u128 v20;
    u128 v30;
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    s32 i60;
} Dst;

void func_00152380(Src *arg0, Dst *arg1) {
    u8 zero = 0;
    arg0->f470 = arg0->f470;
    arg0->f474 = arg0->f474;
    arg0->f478 = arg0->f478;
    arg0->f47C = arg0->f47C;
    arg0->i480 = arg0->i480;
    arg0->v140 = arg0->v140;
    arg0->v250 = arg0->v250;
    arg0->v260 = arg0->v260;
    arg0->v270 = arg0->v270;
    arg0->pad0[0x414] = zero;
    arg1->f50 = arg0->f470;
    arg1->f54 = arg0->f474;
    arg1->f58 = arg0->f478;
    arg1->f5C = arg0->f47C;
    arg1->i60 = arg0->i480;
    arg1->v30 = arg0->v140;
    arg1->v0 = arg0->v250;
    arg1->v10 = arg0->v260;
    arg1->v20 = arg0->v270;
    arg1->f50 = -arg1->f50;
    arg1->f54 = -arg1->f54;
    arg1->f58 = -arg1->f58;
}
