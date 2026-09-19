typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xA8];
    f32 unk_A8;
    f32 unk_AC;
    unsigned char unk_B0[0x30];
    f32 unk_E0;
    f32 unk_E4;
    f32 unk_E8;
    s32 unk_EC;
} Obj;

int func_00166D90(Obj *o) {
    f32 t;

    o->unk_E0 = o->unk_E0 + o->unk_A8;
    t = o->unk_E4 + o->unk_E8;
    o->unk_E4 = t;
    if (t < 0.0f) {
        o->unk_E4 = 0.0f;
    }
    o->unk_EC = o->unk_EC + 1;
    return o->unk_EC - 1 < o->unk_AC;
}
