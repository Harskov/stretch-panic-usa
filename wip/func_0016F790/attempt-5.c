typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

extern u8 D_006AEE40[];
extern u8 D_006AEE58;
extern u8 D_006AEE60;

void func_0016F790(u8 *arg0, u8 *arg1, s32 *arg2)
{
    s32 mode = *arg2;

    if (mode == 2) {
        return;
    }
    if (mode == 1) {
        register u8 *v;
        register u8 *p;
        p = arg0 + 0x10;
        v = D_006AEE40;
        asm {
            lqc2 vf1, 0(v)
            lqc2 vf2, 0(arg1)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(p)
        }
        if (D_006AEE60 != 0) {
            *arg2 = *arg2 + 1;
        }
        return;
    }
    if (mode == 0) {
        register u8 *v;
        register u8 *p;
        p = arg0 + 0x10;
        v = D_006AEE40;
        asm {
            lqc2 vf1, 0(v)
            lqc2 vf2, 0(arg1)
            vadd.xyz vf1, vf1, vf2
            sqc2 vf1, 0(p)
        }
        if ((D_006AEE58 | D_006AEE60) != 0) {
            *arg2 = *arg2 + 1;
        }
        return;
    }
}
