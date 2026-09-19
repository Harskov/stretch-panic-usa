typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

void func_00151530(char *arg0, Vec *arg1, Vec *arg2)
{
    register Vec *p;
    register Vec *q;
    register Vec *t;
    register Vec *a;
    register Vec *b;
    Vec *frame;

    a = arg1;
    b = arg2;
    p = (Vec *)(arg0 + 0x1C0);
    q = (Vec *)(arg0 + 0x1D0);

    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(p)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(t)
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(t)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(t)
    }

    asm {
        lqc2 vf1, 0(t)
        qmtc2.ni v0, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(t)
    }

    asm {
        lqc2 vf1, 0(b)
        lqc2 vf2, 0(q)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(t)
        lqc2 vf1, 0(q)
        lqc2 vf2, 0(t)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(t)
    }

    asm {
        lqc2 vf1, 0(t)
        qmtc2.ni v0, vf2
        vmulx.xyz vf1, vf1, vf2x
        sqc2 vf1, 0(t)
    }

    a = (Vec *)(arg0 + 0x40);
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(t)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0(a)
    }

    frame = (Vec *)0x70000BE0;
}
