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
} Obj;

void func_00159820(Obj *a0, f32 *a1) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    *(u128 *)((char *)a0 + 0x230) = a0->v10;
    *(u128 *)((char *)a0 + 0x240) = a0->v30;
    f3 = a0->f290;
    f2 = a0->f294;
    f1 = a0->f298;
    f0 = a0->f29C;
    a1[0] = f3;
    a1[1] = f2;
    a1[2] = f1;
    a1[3] = f0;
    (void)f0;
    (void)f1;
    (void)f2;
    (void)f3;
}
