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
    float unk_AC;
    unsigned char unk_B0[0x30];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    float f1;
    float f2;
    int v1;

    f2 = o->unk_A8;
    f1 = o->unk_E0;
    o->unk_E0 = f1 + f2;
    f2 = o->unk_E8;
    f1 = o->unk_E4;
    f1 = f1 + f2;
    o->unk_E4 = f1;
    if (f1 < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    v1 = o->unk_EC + 1;
    o->unk_EC = v1;
    return v1 - 1 < o->unk_AC;
}
