typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int128 u128;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x1B0];
    u128 unk_1F0;
    u128 unk_200;
    unsigned char unk_210[0x40];
    f32 unk_250;
    f32 unk_254;
    f32 unk_258;
    f32 unk_25C;
} Obj;

typedef struct Out {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Out;

void func_0015B500(Obj *arg0, Out *arg1) {
    f32 f3;
    f32 f2;
    f32 f1;
    f32 f0;

    arg0->unk_1F0 = arg0->unk_10;
    arg0->unk_200 = arg0->unk_30;
    f3 = arg0->unk_250;
    f2 = arg0->unk_254;
    f1 = arg0->unk_258;
    f0 = arg0->unk_25C;
    arg1->x = f3;
    arg1->y = f2;
    arg1->z = f1;
    arg1->w = f0;
}
