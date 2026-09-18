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

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x1F0];
    u128 unk_230;
    u128 unk_240;
    unsigned char unk_250[0x40];
    f32 unk_290;
    f32 unk_294;
    f32 unk_298;
    f32 unk_29C;
} Obj;

void func_00159820(Obj *o, f32 *out) {
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    o->unk_230 = o->unk_10;
    o->unk_240 = o->unk_30;
    a = o->unk_290;
    b = o->unk_294;
    c = o->unk_298;
    d = o->unk_29C;
    out[3] = d;
    out[2] = c;
    out[1] = b;
    out[0] = a;
}
