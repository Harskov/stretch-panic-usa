typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

extern s32 D_006A6B88;

void func_001705E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    register f32 *p;
    register f32 *q;
    register f32 *r;
    register f32 *s;
    register f32 *t;
    register f32 *u;
    f32 sp0[4];
    f32 sp10[4];
    f32 sp20[4];
    s32 v1;
    s32 t1;
    s32 t2;
    s32 t5;
    s32 t6;
    s32 t7;
    s32 t8;
    s32 t0;

    t0 = arg4;
    t1 = arg2;
    t2 = 0;
    v1 = arg0 - 1;
    t5 = arg3 + (arg2 << 4);
    t6 = t0;
    t7 = arg3 + (((t1 + 1) & v1) << 4);
    t8 = arg3 + (((arg2 + arg1 - 1) & v1) << 4);

    *(u128 *)sp0 = *(u128 *)(D_006A6B88 + 0x140);
    *(u128 *)t6 = *(u128 *)t5;

    p = (f32 *)t5;
    q = (f32 *)sp0;
    r = (f32 *)sp10;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(q)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(r)
    }

    s = (f32 *)t8;
    t = (f32 *)t7;
    u = (f32 *)sp20;
    asm {
        lqc2 vf1, 0(s)
        lqc2 vf2, 0(t)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(u)
    }

    t6 += 16;
    asm {
        lqc2 vf1, 0(r)
        lqc2 vf2, 0(u)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(t6)
    }

    t2 = 1;
    t1 = (t1 + 1) & v1;

    while (t2 != arg1) {
        t7 = arg3 + (t1 << 4);
        t8 = t0 + (t2 << 5);
        *(u128 *)t8 = *(u128 *)t7;

        p = (f32 *)t7;
        q = (f32 *)sp0;
        r = (f32 *)sp10;
        asm {
            lqc2 vf1, 0(p)
            lqc2 vf2, 0(q)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(r)
        }

        t6 = (t1 + 1) & v1;
        t1 = (t1 - 1) & v1;
        s = (f32 *)(arg3 + (t6 << 4));
        t = (f32 *)(arg3 + (t1 << 4));
        u = (f32 *)sp20;
        asm {
            lqc2 vf1, 0(s)
            lqc2 vf2, 0(t)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(u)
        }

        t1 = t8 + 16;
        asm {
            lqc2 vf1, 0(r)
            lqc2 vf2, 0(u)
            vopmula.xyz ACC, vf1, vf2
            vopmsub.xyz vf3, vf2, vf1
            sqc2 vf3, 0(t1)
        }

        t2 += 1;
        t1 = t6;
    }

    t0 += t2 << 5;
    t5 = arg3 + (t1 << 4);
    *(u128 *)t0 = *(u128 *)t5;

    p = (f32 *)t5;
    q = (f32 *)sp0;
    r = (f32 *)sp10;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(q)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(r)
    }

    s = (f32 *)(arg3 + (arg2 << 4));
    t = (f32 *)(arg3 + (((t1 - 1) & (arg0 - 1)) << 4));
    u = (f32 *)sp20;
    asm {
        lqc2 vf1, 0(s)
        lqc2 vf2, 0(t)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(u)
    }

    t6 = t0 + 16;
    asm {
        lqc2 vf1, 0(r)
        lqc2 vf2, 0(u)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(t6)
    }
}
