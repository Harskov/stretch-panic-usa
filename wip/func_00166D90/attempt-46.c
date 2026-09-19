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
    unsigned char unk_AC[0x34];
    float unk_E0;
    float unk_E4;
    float unk_E8;
    int unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    float a;
    float b;
    int old;

    a = o->unk_A8;
    b = o->unk_E0;
    o->unk_E0 = b + a;
    a = o->unk_E8;
    b = o->unk_E4;
    b = b + a;
    o->unk_E4 = b;
    if (b < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    old = o->unk_EC;
    o->unk_EC = old + 1;
    return old < o->unk_AC[0];
}
