typedef float f32;
typedef int s32;
typedef unsigned int u32;

void func_00170200(f32 *a0, f32 *a1, s32 a2, f32 *a3)
{
    f32 f0;
    f32 f3;
    f32 f2;

    f2 = -a0[0];
    if (a2 >= 0) {
        f0 = (f32)a2;
    } else {
        f0 = (f32)((u32)(a2 >> 1) | (a2 & 1));
        f0 = f0 + f0;
    }
    f3 = 2.0f + f0;
    a3[0] = a1[0] * (f2 / f3);
    a3[1] = a1[1] * (-a0[1] / f3);
    a3[2] = a1[2] * (-a0[2] / f3);
    a3[3] = a1[3] * (-a0[3] / f3);
}
