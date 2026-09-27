#include "common.h"

extern f32 func_0012E8E0(Vec *in, Vec *out);

void func_0014EB90(void *arg0, Vec *in, register Vec *out)
{
    Vec dir;
    register Vec *d;
    register f32 s;
    f32 len;

    len = func_0012E8E0(in, &dir);
    if (len < 0.083333336f) {
        s = 0.083333336f;
        d = &dir;
        asm {
            mfc1 v0, s
            lqc2 vf1, 0(d)
            qmtc2.ni v0, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(out)
        }
    } else if (len > 0.16666667f) {
        s = 0.16666667f;
        d = &dir;
        asm {
            mfc1 v0, s
            lqc2 vf1, 0(d)
            qmtc2.ni v0, vf2
            vmulx.xyz vf1, vf1, vf2x
            sqc2 vf1, 0(out)
        }
    }
}
