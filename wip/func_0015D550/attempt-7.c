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

typedef struct {
    u128 v0;
    u128 v1;
    u128 v2;
    u128 v3;
    u128 v4;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5C;
    u32 f60;
    u32 f64;
    u32 f68;
    u32 f6C;
    u128 v70;
    u128 v80;
    u32 f90;
    u128 vA0;
    u128 vB0;
    u128 vC0;
} Obj;

void func_0015D550(Obj *arg0) {
    u128 *pBE0 = (u128 *)0x70000BE0;
    u128 *pB80 = (u128 *)0x70000B80;
    u128 *pBA0 = (u128 *)0x70000BA0;
    u128 *pBC0 = (u128 *)0x70000BC0;

    arg0->v0 = *pBE0;
    arg0->v1 = *pBE0;
    arg0->v2 = *pB80;
    arg0->v3 = *pBA0;
    arg0->v4 = *pBC0;
    arg0->f50 = 0;
    arg0->f54 = 0xBF800000;
    arg0->f58 = 0x3F800000;
    arg0->f5C = 0x3F000000;
    arg0->f60 = 0x3E800000;
    arg0->f64 = 0;
    arg0->f68 = 0x3E800000;
    arg0->f6C = 0x3F400000;
    arg0->v70 = *pBE0;
    arg0->v80 = *pBE0;
    arg0->f90 = 0;
    arg0->vA0 = *pBA0;
    arg0->vB0 = *pBE0;
    arg0->vC0 = *pBE0;
}
