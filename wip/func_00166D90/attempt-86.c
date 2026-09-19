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
    float zero = 0.0f;
    float t;
    float a;
    int n;

    a = o->unk_A8;
    o->unk_E0 = a + o->unk_E0;
    t = o->unk_E8 + o->unk_E4;
    o->unk_E4 = t;
    if (t < zero) {
        o->unk_E4 = zero;
    }
    n = o->unk_EC;
    o->unk_EC = n + 1;
    return n < o->unk_AC;
}
