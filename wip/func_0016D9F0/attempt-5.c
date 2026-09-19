typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_006AF090;

void func_0016D9F0(u8 *arg0, u8 *arg1)
{
    register u8 *v;
    register u8 *p;
    u8 *a2;

    a2 = (u8 *)D_006AF090;
    v = arg0 + 0x260;
    a2 = a2 + 0x10;
    p = arg1;
    asm {
        lqc2 vf1, 0(a2)
        lqc2 vf2, 0(p)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(v)
    }
    *(u32 *)(arg0 + 0x26C) = 0x3F800000;
}
