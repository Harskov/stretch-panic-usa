typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;
typedef unsigned __int128 u128;

typedef struct Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec;

extern s32 D_0069D080;
void func_00172DA0();

typedef struct Ent {
    void *vtbl;          /* 0x00 */
    u8 pad04[0x4C];      /* 0x04 */
    s32 unk50;           /* 0x50 */
    u8 pad54[0x8];       /* 0x54 */
    Vec vec60;           /* 0x60 */
    s32 unk6C;           /* 0x6C */
    u8 pad70[0x40];      /* 0x70 */
    Vec vecB0;           /* 0xB0 */
    f32 unkC0;           /* 0xC0 */
    f32 unkC4;           /* 0xC4 */
} Ent;

Ent *func_00176F80(Ent *e, s32 a1, s32 a2, Vec *v1, Vec *v2, f32 f0, f32 f1)
{
    u128 t1;
    u128 t2;

    func_00172DA0(0);
    e->vtbl = &D_0069D080;
    e->unk50 = a2;
    t1 = *(u128 *)v1;
    *(u128 *)&e->vec60 = t1;
    e->unk6C = 0;
    t2 = *(u128 *)v2;
    *(u128 *)&e->vecB0 = t2;
    e->unkC0 = f0;
    e->unkC4 = f1;
    return e;
}
