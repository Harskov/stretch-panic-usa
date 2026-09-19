typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

typedef struct Ent {
    u8 pad0[0x10];
    Vec v10;
    Vec v20;
    u8 pad30[0x50 - 0x30];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    f32 f60;
    f32 f64;
} Ent;

void func_0017EC80(Ent *arg0)
{
    register Vec *v;
    register Vec *p;
    f32 t;
    f32 s;

    p = &arg0->v10;
    v = &arg0->v20;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    s = 0.95f;
    asm {
        lqc2 vf1, 0(v)
        qmtc2.ni v0, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(v)
    }
    arg0->f50 = arg0->f50 * (0.95f + arg0->f54);
    arg0->f54 = arg0->f54 * 0.75f;
    arg0->f58 = arg0->f58 * (0.999f + arg0->f5C);
    arg0->f5C = arg0->f5C * 0.75f;
    t = arg0->f60 + arg0->f64;
    arg0->f60 = t;
    if (t <= 0.0f) {
        return;
    }
}
