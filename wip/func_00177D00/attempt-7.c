typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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

extern u128 D_00698C00[];
extern u128 D_00698C50[];
extern u128 D_00698CA0[];
extern u128 D_00698CF0[];
extern s32 D_0069D0E0;
void func_0017B170();

typedef struct Rc {
    u8 pad[0x10];
    void *ptr;
} Rc;

typedef struct Obj {
    u8 pad0[0x354];
    Rc *s354;
    Rc *s358;
    Rc *s35C;
    Rc *s360;
    Rc *s364;
    Rc *s368;
    Rc *s36C;
    Rc *s370;
    Rc *s374;
    Rc *s378;
    Rc *s37C;
    u8 pad1[0x4EC - 0x380];
    f32 f4EC;
    f32 f4F0;
    f32 f4F4;
    f32 f4F8;
    f32 f4FC;
    f32 f500;
    u8 pad2[0x5C0 - 0x504];
    u128 v5C0;
    u128 v5D0;
    u128 v5E0;
    u128 v5F0;
    u128 v600;
    u128 v610;
    u128 v620;
    u128 v630;
    u128 v640;
    u128 v650;
    u128 v660;
    u128 v670;
    u128 v680;
    u128 v690;
    u128 v6A0;
    u128 v6B0;
    u128 v6C0;
    u128 v6D0;
    u128 v6E0;
    u128 v6F0;
    void *p700;
    void *p704;
    void *p708;
    void *p70C;
    void *p710;
    void *p714;
    void *p718;
    void *p71C;
    void *p720;
    void *p724;
    void *p728;
    void *p72C;
    void *p730;
    void *p734;
    void *p738;
    void *p73C;
} Obj;

void func_00177D00(Obj *arg0, f32 f12, f32 f13, f32 f14)
{
    u128 *src;
    void *t9;
    void *t8;
    void *t7;
    void *v3;
    void *p;

    func_0017B170();
    *(void **)arg0 = &D_0069D0E0;
    arg0->f4F8 = 9.0f;
    arg0->f4FC = 0.001f;
    arg0->f500 = 0.003f;
    if (f12 == 0.0f) {
        arg0->f4EC = 3.0f;
    }
    if (f13 == 0.0f) {
        arg0->f4F0 = 5.0f;
    }
    if (f14 == 0.0f) {
        arg0->f4F4 = 7.0f;
    }
    src = D_00698C00;
    arg0->v5C0 = src[0];
    arg0->v5D0 = src[1];
    arg0->v5E0 = src[2];
    arg0->v5F0 = src[3];
    arg0->v600 = src[4];
    t9 = &arg0->v5C0;
    src = D_00698C50;
    arg0->v610 = src[0];
    arg0->v620 = src[1];
    arg0->v630 = src[2];
    arg0->v640 = src[3];
    arg0->v650 = src[4];
    t8 = &arg0->v610;
    t7 = &arg0->v660;
    v3 = &arg0->v6B0;
    src = D_00698CA0;
    arg0->v660 = src[0];
    arg0->v670 = src[1];
    arg0->v680 = src[2];
    arg0->v690 = src[3];
    arg0->v6A0 = src[4];
    src = D_00698CF0;
    arg0->v6B0 = src[0];
    arg0->v6C0 = src[1];
    arg0->v6D0 = src[2];
    arg0->v6E0 = src[3];
    arg0->v6F0 = src[4];
    arg0->p700 = t9;
    arg0->p704 = t9;
    arg0->p708 = t8;
    arg0->p70C = t8;
    arg0->p710 = t8;
    arg0->p714 = t7;
    arg0->p718 = t8;
    arg0->p71C = v3;
    arg0->p720 = t8;
    arg0->p724 = t8;
    arg0->p728 = t8;
    arg0->p72C = t9;
    arg0->p730 = t8;
    arg0->p734 = t9;
    arg0->p738 = t7;
    arg0->p73C = t7;
    p = (void *)((u8 *)arg0 + 0x700);
    arg0->s354->ptr = p;
    arg0->s358->ptr = (void *)((u8 *)arg0 + 0x704);
    arg0->s35C->ptr = (void *)((u8 *)arg0 + 0x714);
    arg0->s360->ptr = (void *)((u8 *)arg0 + 0x738);
    arg0->s364->ptr = (void *)((u8 *)arg0 + 0x73C);
    arg0->s368->ptr = (void *)((u8 *)arg0 + 0x720);
    arg0->s36C->ptr = (void *)((u8 *)arg0 + 0x724);
    arg0->s370->ptr = (void *)((u8 *)arg0 + 0x728);
    arg0->s374->ptr = (void *)((u8 *)arg0 + 0x730);
    arg0->s378->ptr = (void *)((u8 *)arg0 + 0x70C);
    arg0->s37C->ptr = (void *)((u8 *)arg0 + 0x710);
}
