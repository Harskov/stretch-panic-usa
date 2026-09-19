typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_006AF090;

typedef struct {
    unsigned char pad[0x260];
    f32 vec[4];
    f32 field26C;
} Obj;

void func_0016D9F0(Obj *arg0, f32 *arg1)
{
    register f32 *p;
    register f32 *v;

    p = (f32 *)(D_006AF090 + 0x10);
    v = arg1;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(v)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0x260(arg0)
    }
    arg0->field26C = 1.0f;
}
