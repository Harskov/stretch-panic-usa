typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned __int128 u128;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0x10];
    u128 unk_10;
    unsigned char unk_20[0x10];
    u128 unk_30;
    unsigned char unk_40[0x1F0];
    u128 unk_230;
    u128 unk_240;
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
    arg0->unk_230 = arg0->unk_10;
    arg0->unk_240 = arg0->unk_30;
    arg1->x = arg0->unk_250;
    arg1->y = arg0->unk_254;
    arg1->z = arg0->unk_258;
    arg1->w = arg0->unk_25C;
}
