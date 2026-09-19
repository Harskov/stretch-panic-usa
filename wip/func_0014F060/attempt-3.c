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

typedef struct Obj {
    u8 pad0[0x30];
    u128 unk_30;
    u8 pad40[0x14C - 0x40];
    s32 unk_14C;
    s32 unk_150;
    u8 pad154[0x2B0 - 0x154];
    u128 unk_2B0;
    u8 pad2C0[0x378 - 0x2C0];
    s32 unk_378;
    u8 pad37C[0x3A0 - 0x37C];
    u128 unk_3A0;
    u128 unk_3B0;
    u8 pad3C0[0x3C4 - 0x3C0];
    s32 unk_3C4;
    u8 pad3C8[0x3D0 - 0x3C8];
    s32 unk_3D0;
    u8 pad3D4[0x400 - 0x3D4];
    f32 unk_400;
    f32 unk_404;
    f32 unk_408;
    f32 unk_40C;
} Obj;

void func_0014F060(Obj *arg0, Vec *arg1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    arg0->unk_3A0 = arg0->unk_2B0;
    arg0->unk_3B0 = arg0->unk_30;
    if (arg0->unk_378 & 2) {
        arg0->unk_3C4 = arg0->unk_150;
        arg0->unk_3D0 = 2;
    } else {
        arg0->unk_3C4 = arg0->unk_14C;
        arg0->unk_3D0 = 0;
    }
    f3 = arg0->unk_400;
    f2 = arg0->unk_404;
    f1 = arg0->unk_408;
    f0 = arg0->unk_40C;
    arg1->x = f3;
    arg1->y = f2;
    arg1->z = f1;
    arg1->w = f0;
}
