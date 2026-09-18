typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct Obj {
    unsigned char unk_00[0xA0];
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    unsigned char unk_C8[0x4];
    f32 unk_CC;
    unsigned char unk_D0[0x20];
    f32 unk_F0;
    f32 unk_F4;
    s32 unk_F8;
    s32 unk_FC;
    s32 unk_100;
    s32 unk_104;
} Obj;

void func_00165800(Obj *o) {
    s32 state = o->unk_F8;

    switch (state) {
    case 0:
        o->unk_F0 = 0.0f;
        o->unk_F4 = 1.0f / (f32)o->unk_FC;
        o->unk_F8 = o->unk_F8 + 1;
        /* fallthrough */
    case 1:
        o->unk_F0 = o->unk_F0 + o->unk_F4;
        if (o->unk_F0 < 1.0f) {
            break;
        }
        o->unk_F0 = 1.0f;
        o->unk_F4 = 0.0f;
        o->unk_F8 = o->unk_F8 + 1;
        break;
    case 2:
        if (o->unk_100 <= 0) {
            o->unk_F4 = -(1.0f / (f32)o->unk_104);
            o->unk_F8 = o->unk_F8 + 1;
        }
        o->unk_100 = o->unk_100 - 1;
        break;
    case 3:
        o->unk_F0 = o->unk_F0 + o->unk_F4;
        if (o->unk_F0 <= 0.0f) {
            o->unk_F0 = 0.0f;
            return;
        }
        break;
    default:
        break;
    }

    o->unk_C0 = o->unk_C0 + o->unk_C4;
    if (o->unk_C0 < 0.0f) {
        o->unk_C0 = 0.0f;
        o->unk_CC = o->unk_CC + o->unk_C4;
    }

    {
        register f32 *p;
        register f32 *v;
        p = &o->unk_A0;
        v = &o->unk_B0;
        asm {
            lqc2 vf1, 0(p)
            lqc2 vf2, 0(v)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(p)
        }
    }
}
