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

extern s32 D_006A6B88;

void func_001705E0(int n, int count, int start, u128 *verts)
{
    register u128 *v;
    register u128 *p;
    register u128 *q;
    u128 base;
    u128 a;
    u128 b;
    u128 c;
    int i;
    int idx;
    int prev;
    int next;
    int mask;

    base = *(u128 *)(D_006A6B88 + 0x140);
    mask = n - 1;
    idx = (start + 1) & mask;
    prev = (start + count - 1) & mask;

    v = verts + start;
    p = verts + idx;
    q = verts + prev;

    *(u128 *)v = *(u128 *)p;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(sp)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(sp)
    }
    asm {
        lqc2 vf1, 0(q)
        lqc2 vf2, 0(sp)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(sp)
    }
    asm {
        lqc2 vf1, 0(sp)
        lqc2 vf2, 0(sp)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(v)
    }

    for (i = 1; i != count; i++) {
        next = (idx + 1) & mask;
        prev = (idx - 1) & mask;
        v = verts + i;
        p = verts + next;
        q = verts + prev;
        *(u128 *)v = *(u128 *)p;
        asm {
            lqc2 vf1, 0(p)
            lqc2 vf2, 0(sp)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(sp)
        }
        asm {
            lqc2 vf1, 0(q)
            lqc2 vf2, 0(sp)
            vsub.xyz vf1, vf1, vf2
            sqc2 vf1, 0(sp)
        }
        asm {
            lqc2 vf1, 0(sp)
            lqc2 vf2, 0(sp)
            vopmula.xyz ACC, vf1, vf2
            vopmsub.xyz vf3, vf2, vf1
            sqc2 vf3, 0(v)
        }
        idx = next;
    }

    v = verts + i;
    p = verts + idx;
    q = verts + ((idx - 1) & mask);
    *(u128 *)v = *(u128 *)p;
    asm {
        lqc2 vf1, 0(p)
        lqc2 vf2, 0(sp)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(sp)
    }
    asm {
        lqc2 vf1, 0(q)
        lqc2 vf2, 0(sp)
        vsub.xyz vf1, vf1, vf2
        sqc2 vf1, 0(sp)
    }
    asm {
        lqc2 vf1, 0(sp)
        lqc2 vf2, 0(sp)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        sqc2 vf3, 0(v)
    }
}
