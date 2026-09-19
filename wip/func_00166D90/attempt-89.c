typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xA8];
    f32 unk_A8;
    s32 unk_AC;
    unsigned char unk_B0[0x30];
    f32 unk_E0;
    f32 unk_E4;
    f32 unk_E8;
    s32 unk_EC;
} Obj;

s32 func_00166D90(Obj *o)
{
    f32 f;
    f32 g;
    s32 n;

    o->unk_E0 += o->unk_A8;
    g = o->unk_E8;
    f = o->unk_E4 + g;
    o->unk_E4 = f;
    if (f < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    n = o->unk_EC;
    o->unk_EC = n + 1;
    return n < o->unk_AC;
}
