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
    unsigned char unk_40[0x250];
    f32 unk_290;
    f32 unk_294;
    f32 unk_298;
    f32 unk_29C;
} Obj;

typedef struct Out {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Out;

void func_00159820(Obj *o, Out *out) {
    o->unk_230 = o->unk_10;
    o->unk_240 = o->unk_30;
    out->x = o->unk_290;
    out->y = o->unk_294;
    out->z = o->unk_298;
    out->w = o->unk_29C;
}
