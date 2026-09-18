typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Vec {
    float x;
    float y;
    float z;
    float w;
} Vec;

typedef struct Obj {
    unsigned char unk_00[0x10];
    Vec pos;
    Vec vel;
    unsigned char unk_30[0x24];
    float unk_54;
    float unk_58;
} Obj;

int func_001636C0(Obj *o) {
    register Vec *v;
    register Vec *p;

    p = &o->pos;
    v = &o->vel;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    o->unk_54 = o->unk_54 - o->unk_58;
    if (o->unk_54 <= 0.0f) {
        return 0;
    }
    return 1;
}
