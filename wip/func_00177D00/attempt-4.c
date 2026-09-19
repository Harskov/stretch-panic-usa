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

extern s32 D_00698C00;
extern s32 D_00698C50;
extern s32 D_00698CA0;
extern s32 D_00698CF0;
extern s32 D_0069D0E0;
void func_0017B170();

typedef struct Sub {
    u8 pad[0x10];
    void *ptr;
} Sub;

typedef struct Obj {
    u8 pad0[0x354];
    Sub *s354;
    Sub *s358;
    Sub *s35C;
    Sub *s360;
    Sub *s364;
    Sub *s368;
    Sub *s36C;
    Sub *s370;
    Sub *s374;
    Sub *s378;
    Sub *s37C;
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
    Sub *sub;
    u128 *src;
    void *t9;
    void *t8;
    void *t7;
    void *v3;

    func_0017B170();
    sub = (Sub *)arg0;
    *(void **)sub->pad = &D_0069D0E0;
    *(f32 *)((u8 *)sub + 0x4F8) = 9.0f;
    *(f32 *)((u8 *)sub + 0x4FC) = 0.001f;
    *(f32 *)((u8 *)sub + 0x500) = 0.003f;
    if (f12 == 0.0f) {
        *(f32 *)((u8 *)sub + 0x4EC) = 3.0f;
    }
    if (f13 == 0.0f) {
        *(f32 *)((u8 *)sub + 0x4F0) = 5.0f;
    }
    if (f14 == 0.0f) {
        *(f32 *)((u8 *)sub + 0x4F4) = 7.0f;
    }
    t9 = (void *)((u8 *)sub + 0x5C0);
    src = (u128 *)&D_00698C00;
    *(u128 *)((u8 *)sub + 0x5C0) = src[0];
    *(u128 *)((u8 *)sub + 0x5D0) = src[1];
    *(u128 *)((u8 *)sub + 0x5E0) = src[2];
    *(u128 *)((u8 *)sub + 0x5F0) = src[3];
    *(u128 *)((u8 *)sub + 0x600) = src[4];
    t8 = (void *)((u8 *)sub + 0x610);
    src = (u128 *)&D_00698C50;
    *(u128 *)((u8 *)sub + 0x610) = src[0];
    *(u128 *)((u8 *)sub + 0x620) = src[1];
    *(u128 *)((u8 *)sub + 0x630) = src[2];
    *(u128 *)((u8 *)sub + 0x640) = src[3];
    *(u128 *)((u8 *)sub + 0x650) = src[4];
    t7 = (void *)((u8 *)sub + 0x660);
    v3 = (void *)((u8 *)sub + 0x6B0);
    src = (u128 *)&D_00698CA0;
    *(u128 *)((u8 *)sub + 0x660) = src[0];
    *(u128 *)((u8 *)sub + 0x670) = src[1];
    *(u128 *)((u8 *)sub + 0x680) = src[2];
    *(u128 *)((u8 *)sub + 0x690) = src[3];
    *(u128 *)((u8 *)sub + 0x6A0) = src[4];
    src = (u128 *)&D_00698CF0;
    *(u128 *)((u8 *)sub + 0x6B0) = src[0];
    *(u128 *)((u8 *)sub + 0x6C0) = src[1];
    *(u128 *)((u8 *)sub + 0x6D0) = src[2];
    *(u128 *)((u8 *)sub + 0x6E0) = src[3];
    *(u128 *)((u8 *)sub + 0x6F0) = src[4];
    *(void **)((u8 *)sub + 0x700) = t9;
    *(void **)((u8 *)sub + 0x704) = t9;
    *(void **)((u8 *)sub + 0x708) = t8;
    *(void **)((u8 *)sub + 0x70C) = t8;
    *(void **)((u8 *)sub + 0x710) = t8;
    *(void **)((u8 *)sub + 0x714) = t7;
    *(void **)((u8 *)sub + 0x718) = t8;
    *(void **)((u8 *)sub + 0x71C) = v3;
    *(void **)((u8 *)sub + 0x720) = t8;
    *(void **)((u8 *)sub + 0x724) = t8;
    *(void **)((u8 *)sub + 0x728) = t8;
    *(void **)((u8 *)sub + 0x72C) = t9;
    *(void **)((u8 *)sub + 0x730) = t8;
    *(void **)((u8 *)sub + 0x734) = t9;
    *(void **)((u8 *)sub + 0x738) = t7;
    *(void **)((u8 *)sub + 0x73C) = t7;
    *(void **)((u8 *)sub->pad + 0x364) = (void *)((u8 *)sub + 0x700);
    *(void **)((u8 *)sub->pad + 0x368) = (void *)((u8 *)sub + 0x704);
    *(void **)((u8 *)sub->pad + 0x36C) = (void *)((u8 *)sub + 0x714);
    *(void **)((u8 *)sub->pad + 0x370) = (void *)((u8 *)sub + 0x738);
    *(void **)((u8 *)sub->pad + 0x374) = (void *)((u8 *)sub + 0x73C);
    *(void **)((u8 *)sub->pad + 0x378) = (void *)((u8 *)sub + 0x720);
    *(void **)((u8 *)sub->pad + 0x37C) = (void *)((u8 *)sub + 0x724);
    *(void **)((u8 *)sub->pad + 0x380) = (void *)((u8 *)sub + 0x728);
    *(void **)((u8 *)sub->pad + 0x384) = (void *)((u8 *)sub + 0x730);
    *(void **)((u8 *)sub->pad + 0x388) = (void *)((u8 *)sub + 0x70C);
    *(void **)((u8 *)sub->pad + 0x38C) = (void *)((u8 *)sub + 0x710);
}
