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

typedef struct Dst {
    u8 pad0[0xB4];
    s32 iB4;
    s32 iB8;
    u8 padBC[4];
    s32 iC0;
} Dst;

void func_00179D80(Dst *arg0, Vec *arg1, Vec *arg2, Vec *arg3, f32 fparg0)
{
    s32 count;
    s32 i;
    s32 mask;
    register Vec *a;
    register Vec *b;
    register Vec *c;
    register u32 f;

    count = arg0->iB4;
    i = arg0->iC0;
    f = *(u32 *)&fparg0;
    do {
        a = (Vec *)((u8 *)arg1 + (i << 4));
        b = (Vec *)((u8 *)arg2 + (i << 4));
        c = (Vec *)((u8 *)arg3 + (i << 4));
        asm {
            lqc2 vf1, 0(a)
            lqc2 vf2, 0(b)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(c)
        }
        asm {
            lqc2 vf1, 0(b)
            qmtc2.ni f, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(b)
        }
        mask = arg0->iB8;
        i = (i + 1) & (mask - 1);
    } while (--count != 0);
}
