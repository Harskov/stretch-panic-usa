typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xA8];
    float unk_A8;
    int unk_AC;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    float f;
    float g;
    int n;

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
