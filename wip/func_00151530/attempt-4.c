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

void func_00151530(char *arg0, Vec *arg1, Vec *arg2) {
    register Vec *p;
    register Vec *q;
    Vec tmp;
    Vec out;
    register Vec *r;
    register Vec *t;

    p = (Vec *)(arg0 + 0x1C0);
    q = (Vec *)(arg0 + 0x1D0);

    tmp = *(Vec *)0x70000BE0;
    *(Vec *)0x0 = tmp;

    out = *arg1;
    out.x -= p->x;
    out.y -= p->y;
    out.z -= p->z;
    tmp = out;

    out.x = p->y * tmp.z - p->z * tmp.y;
    out.y = p->z * tmp.x - p->x * tmp.z;
    out.z = p->x * tmp.y - p->y * tmp.x;
    *(Vec *)0x0 = out;

    out.x = out.x * 0.049087387f;
    out.y = out.y * 0.049087387f;
    out.z = out.z * 0.049087387f;
    r = (Vec *)0x0;
    *r = out;

    out = *arg2;
    out.x -= q->x;
    out.y -= q->y;
    out.z -= q->z;
    tmp = out;

    out.x = q->y * tmp.z - q->z * tmp.y;
    out.y = q->z * tmp.x - q->x * tmp.z;
    out.z = q->x * tmp.y - q->y * tmp.x;
    *(Vec *)0x0 = out;

    out.x = out.x * 0.098174774f;
    out.y = out.y * 0.098174774f;
    out.z = out.z * 0.098174774f;
    t = (Vec *)0x0;
    *t = out;

    arg0 += 0x40;
    *(Vec *)arg0 = *(Vec *)arg0 + out;
}
