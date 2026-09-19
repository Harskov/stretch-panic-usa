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

typedef struct Sub {
    u8 pad0[0x58];
    s32 unk58;
    u8 pad5C[0x4];
    s32 unk60;
    u8 pad64[0x4];
    s32 unk68;
} Sub;

typedef struct Arg1 {
    u8 pad0[0x80];
    Vec vec80;
    Vec vec90;
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    f32 unkAC;
    u8 padB0[0x18];
    Sub *unkC8;
} Arg1;

typedef struct Arg0 {
    u8 pad0[0x2E4];
    s32 unk2E4;
    u8 pad2E8[0x28];
    s32 unk310;
    u8 pad314[0x5C];
    f32 unk370;
    f32 unk374;
    f32 unk378;
    f32 unk37C;
    s32 unk380;
    s32 unk384;
    u8 pad388[0x18];
    Vec unk3A0;
    Vec unk3B0;
    Vec unk3C0;
    u8 pad3D0[0xA0];
    f32 unk470;
    f32 unk474;
    f32 unk478;
    f32 unk47C;
    s32 unk480;
    s32 unk484;
    u8 pad488[0x18];
    Vec unk4A0;
    Vec unk4C0;
} Arg0;

void func_00152500(Arg0 *arg0, Arg1 *arg1) {
    Sub *s = arg1->unkC8;
    if (s->unk68 & 0x20) {
        arg0->unk480 = s->unk58;
        arg0->unk470 = arg1->unkA0;
        arg0->unk474 = arg1->unkA4;
        arg0->unk478 = arg1->unkA8;
        arg0->unk47C = arg1->unkAC;
        arg0->unk484 = 0;
        arg0->unk4A0 = arg1->vec80;
        arg0->unk4C0 = arg1->vec80;
        arg0->unk2E4 |= 0x800;
        return;
    }
    arg0->unk310 = s->unk60;
    arg0->unk380 = arg1->unkC8->unk58;
    arg0->unk370 = arg1->unkA0;
    arg0->unk374 = arg1->unkA4;
    arg0->unk378 = arg1->unkA8;
    arg0->unk37C = arg1->unkAC;
    arg0->unk384 = 0;
    arg0->unk3A0 = arg1->vec80;
    arg0->unk3C0 = arg1->vec80;
    arg0->unk3B0 = arg1->vec90;
    arg0->unk2E4 |= 0x400;
}
