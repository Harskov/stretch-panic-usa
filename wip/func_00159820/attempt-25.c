typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 v10;
    unsigned char unk_20[0x10];
    u128 v30;
    unsigned char unk_40[0x250];
    f32 f290;
    f32 f294;
    f32 f298;
    f32 f29C;
    u128 v230;
    u128 v240;
} Obj;

void func_00159820(Obj *a0, f32 *a1) {
    a0->v230 = a0->v10;
    a0->v240 = a0->v30;
    a1[0] = a0->f290;
    a1[1] = a0->f294;
    a1[2] = a0->f298;
    a1[3] = a0->f29C;
}
